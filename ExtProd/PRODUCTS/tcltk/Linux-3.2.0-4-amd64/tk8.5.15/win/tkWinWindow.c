/*
 * tkWinWindow.c --
 *
 *	Xlib emulation routines for Windows related to creating, displaying
 *	and destroying windows.
 *
 * Copyright (c) 1995-1997 Sun Microsystems, Inc.
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 */

#include "tkWinInt.h"

typedef struct ThreadSpecificData {
    int initialized;		/* 0 means table below needs initializing. */
    Tcl_HashTable windowTable;  /* The windowTable maps from HWND to Tk_Window
				 * handles. */
} ThreadSpecificData;
static Tcl_ThreadDataKey dataKey;

/*
 * Forward declarations for functions defined in this file:
 */

static void		NotifyVisibility(XEvent *eventPtr, TkWindow *winPtr);

/*
 *----------------------------------------------------------------------
 *
 * Tk_AttachHWND --
 *
 *	This function binds an HWND and a reflection function to the specified
 *	Tk_Window.
 *
 * Results:
 *	Returns an X Window that encapsulates the HWND.
 *
 * Side effects:
 *	May allocate a new X Window. Also enters the HWND into the global
 *	window table.
 *
 *----------------------------------------------------------------------
 */

Window
Tk_AttachHWND(
    Tk_Window tkwin,
    HWND hwnd)
{
    int new;
    Tcl_HashEntry *entryPtr;
    TkWinDrawable *twdPtr = (TkWinDrawable *) Tk_WindowId(tkwin);
    ThreadSpecificData *tsdPtr = (ThreadSpecificData *)
	    Tcl_GetThreadData(&dataKey, sizeof(ThreadSpecificData));

    if (!tsdPtr->initialized) {
	Tcl_InitHashTable(&tsdPtr->windowTable, TCL_ONE_WORD_KEYS);
	tsdPtr->initialized = 1;
    }

    /*
     * Allocate a new drawable if necessary. Otherwise, remove the previous
     * HWND from from the window table.
     */

    if (twdPtr == NULL) {
	twdPtr = (TkWinDrawable *) ckalloc(sizeof(TkWinDrawable));
	twdPtr->type = TWD_WINDOW;
	twdPtr->window.winPtr = (TkWindow *) tkwin;
    } else if (twdPtr->window.handle != NULL) {
	entryPtr = Tcl_FindHashEntry(&tsdPtr->windowTable,
		(char *)twdPtr->window.handle);
	Tcl_DeleteHashEntry(entryPtr);
    }

    /*
     * Insert the new HWND into the window table.
     */

    twdPtr->window.handle = hwnd;
    entryPtr = Tcl_CreateHashEntry(&tsdPtr->windowTable, (char *)hwnd, &new);
    Tcl_SetHashValue(entryPtr, (ClientData)tkwin);

    return (Window)twdPtr;
}

/*
 *----------------------------------------------------------------------
 *
 * Tk_HWNDToWindow --
 *
 *	This function retrieves a Tk_Window from the window table given an
 *	HWND.
 *
 * Results:
 *	Returns the matching Tk_Window.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */

Tk_Window
Tk_HWNDToWindow(
    HWND hwnd)
{
    Tcl_HashEntry *entryPtr;
    ThreadSpecificData *tsdPtr = (ThreadSpecificData *)
	    Tcl_GetThreadData(&dataKey, sizeof(ThreadSpecificData));

    if (!tsdPtr->initialized) {
	Tcl_InitHashTable(&tsdPtr->windowTable, TCL_ONE_WORD_KEYS);
	tsdPtr->initialized = 1;
    }
    entryPtr = Tcl_FindHashEntry(&tsdPtr->windowTable, (char *) hwnd);
    if (entryPtr != NULL) {
	return (Tk_Window) Tcl_GetHashValue(entryPtr);
    }
    return NULL;
}

/*
 *----------------------------------------------------------------------
 *
 * Tk_GetHWND --
 *
 *	This function extracts the HWND from an X Window.
 *
 * Results:
 *	Returns the HWND associated with the Window.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */

HWND
Tk_GetHWND(
    Window window)
{
    return ((TkWinDrawable *) window)->window.handle;
}

/*
 *----------------------------------------------------------------------
 *
 * TkpPrintWindowId --
 *
 *	This routine stores the string representation of the platform
 *	dependent window handle for an X Window in the given buffer.
 *
 * Results:
 *	Returns the result in the specified buffer.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */

void
TkpPrintWindowId(
    char *buf,			/* Pointer to string large enough to hold the
				 * hex representation of a pointer. */
    Window window)		/* Window to be printed into buffer. */
{
    HWND hwnd = (window) ? Tk_GetHWND(window) : 0;

    /*
     * Use pointer representation, because Win64 is P64 (*not* LP64). Windows
     * doesn't print the 0x for %p, so we do it.
     * bug #2026405: cygwin does output 0x for %p so test and recover.
     */

    sprintf(buf, "0x%p", hwnd);
    if (buf[2] == '0' && buf[3] == 'x')
	sprintf(buf, "%p", hwnd);
}

/*
 *----------------------------------------------------------------------
 *
 * TkpScanWindowId --
 *
 *	Given a string which represents the platform dependent window handle,
 *	produce the X Window id for the window.
 *
 * Results:
 *	The return value is normally TCL_OK; in this case *idPtr will be set
 *	to the X Window id equivalent to string. If string is improperly
 *	formed then TCL_ERROR is returned and an error message will be left in
 *	the interp's result. If the number does not correspond to a Tk Window,
 *	then *idPtr will be set to None.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */

int
TkpScanWindowId(
    Tcl_Interp *interp,		/* Interpreter to use for error reporting. */
    CONST char *string,		/* String containing a (possibly signed)
				 * integer in a form acceptable to strtol. */
    Window *idPtr)		/* Place to store converted result. */
{
    Tk_Window tkwin;
    void *number, *numberPtr = &number;

    /*
     * We want sscanf for the 64-bit check, but if that doesn't work, then
     * Tcl_GetInt manages the error correctly.
     */

    if (
#ifdef _WIN64
	    (sscanf(string, "0x%p", &number) != 1) &&
#endif
	    Tcl_GetInt(interp, string, (int *) numberPtr) != TCL_OK) {
	return TCL_ERROR;
    }

    tkwin = Tk_HWNDToWindow((HWND) number);
    if (tkwin) {
	*idPtr = Tk_WindowId(tkwin);
    } else {
	*idPtr = None;
    }
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * TkpMakeWindow --
 *
 *	Creates a Windows window object based on the current attributes of the
 *	specified TkWindow.
 *
 * Results:
 *	Returns a pointer to a new TkWinDrawable cast to a Window.
 *
 * Side effects:
 *	Creates a new window.
 *
 *----------------------------------------------------------------------
 */

Window
TkpMakeWindow(
    TkWindow *winPtr,
    Window parent)
{
    HWND parentWin;
    int style;
    HWND hwnd;

    if (parent != None) {
	parentWin = Tk_GetHWND(parent);
	style = WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
    } else {
	parentWin = NULL;
	style = WS_POPUP | WS_CLIPCHILDREN;
    }

    /*
     * Create the window, then ensure that it is at the top of the stacking
     * order.
     */

    hwnd = CreateWindowEx(WS_EX_NOPARENTNOTIFY, TK_WIN_CHILD_CLASS_NAME, NULL,
	    (DWORD) style, Tk_X(winPtr), Tk_Y(winPtr), Tk_Width(winPtr),
	    Tk_Height(winPtr), parentWin, NULL, Tk_GetHINSTANCE(), NULL);
    SetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0,
	    SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE);
    return Tk_AttachHWND((Tk_Window)winPtr, hwnd);
}

/*
 *----------------------------------------------------------------------
 *
 * XDestroyWindow --
 *
 *	Destroys the given window.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Sends the WM_DESTROY message to the window and then destroys it the
 *	Win32 resources associated with the window.
 *
 *----------------------------------------------------------------------
 */

int
XDestroyWindow(
    Display *display,
    Window w)
{
    Tcl_HashEntry *entryPtr;
    TkWinDrawable *twdPtr = (TkWinDrawable *)w;
    TkWindow *winPtr = TkWinGetWinPtr(w);
    HWND hwnd = Tk_GetHWND(w);
    ThreadSpecificData *tsdPtr = (ThreadSpecificData *)
	    Tcl_GetThreadData(&dataKey, sizeof(ThreadSpecificData));

    display->request++;

    /*
     * Remove references to the window in the pointer module then release the
     * drawable.
     */

    TkPointerDeadWindow(winPtr);

    entryPtr = Tcl_FindHashEntry(&tsdPtr->windowTable, (char*)hwnd);
    if (entryPtr != NULL) {
	Tcl_DeleteHashEntry(entryPtr);
    }

    ckfree((char *)twdPtr);

    /*
     * Don't bother destroying the window if we are going to destroy the
     * parent later.
     */

    if (hwnd != NULL && !(winPtr->flags & TK_DONT_DESTROY_WINDOW)) {
	DestroyWindow(hwnd);
    }
    return Success;
}

/*
 *----------------------------------------------------------------------
 *
 * XMapWindow --
 *
 *	Cause the given window to become visible.
 *
 * Results:
 *	None
 *
 * Side effects:
 *	Causes the window state to change, and generates a MapNotify event.
 *
 *----------------------------------------------------------------------
 */

int
XMapWindow(
    Display *display,
    Window w)
{
    XEvent event;
    TkWindow *parentPtr;
    TkWindow *winPtr = TkWinGetWinPtr(w);

    display->request++;

    ShowWindow(Tk_GetHWND(w), SW_SHOWNORMAL);
    winPtr->flags |= TK_MAPPED;

    /*
     * Check to see if this window is visible now. If all of the parent
     * windows up to the first toplevel are mapped, then this window and its
     * mapped children have just become visible.
     */

    if (!(winPtr->flags & TK_TOP_HIERARCHY)) {
	for (parentPtr = winPtr->parentPtr; ;
		parentPtr = parentPtr->parentPtr) {
	    if ((parentPtr == NULL) || !(parentPtr->flags & TK_MAPPED)) {
		return Success;
	    }
	    if (parentPtr->flags & TK_TOP_HIERARCHY) {
		break;
	    }
	}
    } else {
	event.type = MapNotify;
	event.xmap.serial = display->request;
	event.xmap.send_event = False;
	event.xmap.display = display;
	event.xmap.event = winPtr->window;
	event.xmap.window = winPtr->window;
	event.xmap.override_redirect = winPtr->atts.override_redirect;
	Tk_QueueWindowEvent(&event, TCL_QUEUE_TAIL);
    }

    /*
     * Generate VisibilityNotify events for this window and its mapped
     * children.
     */

    event.type = VisibilityNotify;
    event.xvisibility.serial = display->request;
    event.xvisibility.send_event = False;
    event.xvisibility.display = display;
    event.xvisibility.window = winPtr->window;
    event.xvisibility.state = VisibilityUnobscured;
    NotifyVisibility(&event, winPtr);
    return Success;
}

/*
 *----------------------------------------------------------------------
 *
 * NotifyVisibility --
 *
 *	This function recursively notifies the mapped children of the
 *	specified window of a change in visibility. Note that we don't
 *	properly report the visibility state, since Windows does not provide
 *	that info. The eventPtr argument must point to an event that has been
 *	completely initialized except for the window slot.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Generates lots of events.
 *
 *----------------------------------------------------------------------
 */

static void
NotifyVisibility(
    XEvent *eventPtr,		/* Initialized VisibilityNotify event. */
    TkWindow *winPtr)		/* Window to notify. */
{
    if (winPtr->atts.event_mask & VisibilityChangeMask) {
	eventPtr->xvisibility.window = winPtr->window;
	Tk_QueueWindowEvent(eventPtr, TCL_QUEUE_TAIL);
    }
    for (winPtr = winPtr->childList; winPtr != NULL;
	    winPtr = winPtr->nextPtr) {
	if (winPtr->flags & TK_MAPPED) {
	    NotifyVisibility(eventPtr, winPtr);
	}
    }
}

/*
 *----------------------------------------------------------------------
 *
 * XUnmapWindow --
 *
 *	Cause the given window to become invisible.
 *
 * Results:
 *	None
 *
 * Side effects:
 *	Causes the window state to change, and generates an UnmapNotify event.
 *
 *----------------------------------------------------------------------
 */

int
XUnmapWindow(
    Display *display,
    Window w)
{
    XEvent event;
    TkWindow *winPtr = TkWinGetWinPtr(w);

    display->request++;

    /*
     * Bug fix: Don't short circuit this routine based on TK_MAPPED because it
     * will be cleared before XUnmapWindow is called.
     */

    ShowWindow(Tk_GetHWND(w), SW_HIDE);
    winPtr->flags &= ~TK_MAPPED;

    if (winPtr->flags & TK_WIN_MANAGED) {
	event.type = UnmapNotify;
	event.xunmap.serial = display->request;
	event.xunmap.send_event = False;
	event.xunmap.display = display;
	event.xunmap.event = winPtr->window;
	event.xunmap.window = winPtr->window;
	event.xunmap.from_configure = False;
	Tk_HandleEvent(&event);
    }
    return Success;
}

/*
 *----------------------------------------------------------------------
 *
 * XMoveResizeWindow --
 *
 *	Move and resize a window relative to its parent.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Repositions and resizes the specified window.
 *
 *----------------------------------------------------------------------
 */

int
XMoveResizeWindow(
    Display *display,
    Window w,
    int x, int y,		/* Position relative to parent. */
    unsigned int width, unsigned int height)
{
    display->request++;
    MoveWindow(Tk_GetHWND(w), x, y, (int) width, (int) height, TRUE);
    return Success;
}

/*
 *----------------------------------------------------------------------
 *
 * XMoveWindow --
 *
 *	Move a window relative to its parent.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Repositions the specified window.
 *
 *----------------------------------------------------------------------
 */

int
XMoveWindow(
    Display *display,
    Window w,
    int x, int y)		/* Position relative to parent */
{
    TkWindow *winPtr = TkWinGetWinPtr(w);

    display->request++;

    MoveWindow(Tk_GetHWND(w), x, y, winPtr->changes.width,
	    winPtr->changes.height, TRUE);
    return Success;
}

/*
 *----------------------------------------------------------------------
 *
 * XResizeWindow --
 *
 *	Resize a window.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Resizes the specified window.
 *
 *----------------------------------------------------------------------
 */

int
XResizeWindow(
    Display *display,
    Window w,
    unsigned int width, unsigned int height)
{
    TkWindow *winPtr = TkWinGetWinPtr(w);

    display->request++;

    MoveWindow(Tk_GetHWND(w), winPtr->changes.x, winPtr->changes.y, (int)width,
	    (int)height, TRUE);
    return Success;
}

/*
 *----------------------------------------------------------------------
 *
 * XRaiseWindow --
 *
 *	Change the stacking order of a window.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Changes the stacking order of the specified window.
 *
 *----------------------------------------------------------------------
 */

int
XRaiseWindow(
    Display *display,
    Window w)
{
    HWND window = Tk_GetHWND(w);

    display->request++;
    SetWindowPos(window, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    return Success;
}

/*
 *----------------------------------------------------------------------
 *
 * XConfigureWindow --
 *
 *	Change the size, position, stacking, or border of the specified
 *	window.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Changes the attributes of the specified window. Note that we ignore
 *	the passed in values and use the values stored in the TkWindow data
 *	structure.
 *
 *----------------------------------------------------------------------
 */

int
XConfigureWindow(
    Display *display,
    Window w,
    unsigned int valueMask,
    XWindowChanges *values)
{
    TkWindow *winPtr = TkWinGetWinPtr(w);
    HWND hwnd = Tk_GetHWND(w);

    display->request++;

    /*
     * Change the shape and/or position of the window.
     */

    if (valueMask & (CWX|CWY|CWWidth|CWHeight)) {
	MoveWindow(hwnd, winPtr->changes.x, winPtr->changes.y,
		winPtr->changes.width, winPtr->changes.height, TRUE);
    }

    /*
     * Change the stacking order of the window.
     */

    if (valueMask & CWStackMode) {
	HWND sibling;

	if ((valueMask & CWSibling) && (values->sibling != None)) {
	    sibling = Tk_GetHWND(values->sibling);
	} else {
	    sibling = NULL;
	}
	TkWinSetWindowPos(hwnd, sibling, values->stack_mode);
    }
    return Success;
}

/*
 *----------------------------------------------------------------------
 *
 * XClearWindow --
 *
 *	Clears the entire window to the current background color.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Erases the current contents of the window.
 *
 *----------------------------------------------------------------------
 */

int
XClearWindow(
    Display *display,
    Window w)
{
    RECT rc;
    HBRUSH brush;
    HPALETTE oldPalette, palette;
    TkWindow *winPtr;
    HWND hwnd = Tk_GetHWND(w);
    HDC dc = GetDC(hwnd);

    palette = TkWinGetPalette(display->screens[0].cmap);
    oldPalette = SelectPalette(dc, palette, FALSE);

    display->request++;

    winPtr = TkWinGetWinPtr(w);
    brush = CreateSolidBrush(winPtr->atts.background_pixel);
    GetWindowRect(hwnd, &rc);
    rc.right = rc.right - rc.left;
    rc.bottom = rc.bottom - rc.top;
    rc.left = rc.top = 0;
    FillRect(dc, &rc, brush);

    DeleteObject(brush);
    SelectPalette(dc, oldPalette, TRUE);
    ReleaseDC(hwnd, dc);
    return Success;
}

/*
 *----------------------------------------------------------------------
 *
 * XChangeWindowAttributes --
 *
 *	This function is called when the attributes on a window are updated.
 *	Since Tk maintains all of the window state, the only relevant value is
 *	the cursor.
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	May cause the mouse position to be updated.
 *
 *----------------------------------------------------------------------
 */

int
XChangeWindowAttributes(
    Display *display,
    Window w,
    unsigned long valueMask,
    XSetWindowAttributes* attributes)
{
    if (valueMask & CWCursor) {
	XDefineCursor(display, w, attributes->cursor);
    }
    return Success;
}

/*
 *----------------------------------------------------------------------
 *
 * TkWinSetWindowPos --
 *
 *	Adjust the stacking order of a window relative to a second window (or
 *	NULL).
 *
 * Results:
 *	None.
 *
 * Side effects:
 *	Moves the specified window in the stacking order.
 *
 *----------------------------------------------------------------------
 */

void
TkWinSetWindowPos(
    HWND hwnd,			/* Window to restack. */
    HWND siblingHwnd,		/* Sibling window. */
    int pos)			/* One of Above or Below. */
{
    HWND temp;

    /*
     * Since Windows does not support Above mode, we place the specified
     * window below the sibling and then swap them.
     */

    if (siblingHwnd) {
	if (pos == Above) {
	    SetWindowPos(hwnd, siblingHwnd, 0, 0, 0, 0,
		    SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE);
	    temp = hwnd;
	    hwnd = siblingHwnd;
	    siblingHwnd = temp;
	}
    } else {
	siblingHwnd = (pos == Above) ? HWND_TOP : HWND_BOTTOM;
    }

    SetWindowPos(hwnd, siblingHwnd, 0, 0, 0, 0,
	    SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOSIZE);
}

/*
 *----------------------------------------------------------------------
 *
 * TkpWindowWasRecentlyDeleted --
 *
 *	Determines whether we know if the window given as argument was
 *	recently deleted. Called by the generic code error handler to handle
 *	BadWindow events.
 *
 * Results:
 *	Always 0. We do not keep this information on Windows.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */

int
TkpWindowWasRecentlyDeleted(
    Window win,
    TkDisplay *dispPtr)
{
    return 0;
}

/*
 * Local Variables:
 * mode: c
 * c-basic-offset: 4
 * fill-column: 78
 * End:
 */
