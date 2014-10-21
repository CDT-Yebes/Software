   $t insert end {A Bird?  A Plane?  TkMan!  (TkPerson?)

 by Tom Phelps 

implemented in Tcl/Tk 8.4
 TkMan icon drawn by Rei Shinozuka
 many other icons taken from the AIcons collection
Compatible with Sun Solaris, SunOS, Hewlett-Packard HP-UX, OSF/1 aka Digital UNIX, DEC Ultrix, AT&T System V, SGI IRIX, Linux, SCO, IBM AIX, FreeBSD, BSDI -- each of which, believe you-me, is in some way different from all the others 

The latest version of TkMan is available via http://tkman.sourceforge.net.

Before reporting a bug, first check the home site to make sure you're using the latest version of TkMan.  If you want to change how a feature works, first check the Preferences dialog. If you send me bug reports and/or suggestions for new features, include your MANPATH, the versions of TkMan, Tcl, Tk, X, and UNIX, your machine and X window manager names, the edited Makefile, a copy of your ~/.tkman file, and the first few lines of the tkman executable.  I'd also be interested in learning where you obtained TkMan.  Send feedback to phelps@ACM.org 


Abstract

TkMan is a graphical, hypertext manual page and Texinfo browser for UNIX. TkMan boasts hypertext links, (optional) outline view of man pages, high quality display and superior navigational interface to Texinfo documents, a novel information visualization mechanism called Notemarks, full text search among man pages and Texinfo,  incremental and regular expression search within pages, regular expression search within Texinfo that shows all matches (not just the next), robustly attached yellow highlight annotations,  a shortcut/hot list,  lists of all pages in user configurable volumes,  a comprehensive Preferences panel, man page versioning support, and unmatched online text formatting and display quality, among many other features.  


Introduction

"I encourage you to use TkMan for reading man pages. ... TkMan provides an extremely pleasant GUI for browsing man pages.  I cannot describe all the nice features of TkMan in this small space.  Instead I will merely say that I now actually look forward to reading man pages as long as I can do it with TkMan."
 -- Don Libes, Exploring Expect, page 21 

TkMan offers many major advantages over man and xman: hypertext links to other man pages (click on a word in the text which corresponds to a man page, and you jump there), and better navigation within long man pages with searches (both incremental and regular expression) and direct jumps to sections of a page.  TkMan also offers some convenience features, like a user-configurable list of commonly used man pages, a one-click printout, and integration of  apropos. 

Furthermore, one may highlight, as if with a yellow marker, arbitrary passages of text in man pages and Texinfo and subsequently jump directly to these passages by selecting an identifying excerpt from a pulldown menu.  (Highlights are robust across changes to page content and movement of the file.)   Pages are optionally given an outlining user interface whereby the text of a section can be collapsed or expanded underneath its header, independently of other sections.  Within otherwise collapsed sections, a variety of Notemarks(TM) can appear.  Notemarks are excerpts from the text showing highlighted text, command-line options, search results, or an excerpt of each paragraph in that section,  shown in context with section headers and other Notemarks. Functioning as a note, a Notemark may itself communicate sufficient information; functioning as a bookmark, it can be clicked on to automatically expand the corresponding section and scroll to that point.  Notemarks densely display numerous immediately available hooks into long texts to expedite identification of a desired passage. 

The Texinfo browser takes a very different approach than any other GNU info brower, and thereby is able to provide a number of advantages not possible in an info-only browser.  (1) TkMan's browser works from the Texinfo source, as opposed to a compiled form that has been formatted for character terminal displays, and therefore can and does provide much better looking text, in multiple fonts (proportionally-spaced for body text, typewriter for computer text, bold and italics, blue hyperlinks for crossreferences, and even a cedilla and a lowered E in TeX).  (2) An outlining interface that continuously gives overview and context to navigation within the document, as opposed to the system of nodes with only immediate neighbors known (next, previous, parent), which, at least for me, very quickly leads to being "lost in info-space".  All this costs disk space of only 2% over the original Texinfo source files, which themselves may be compressed. 

Other features include:
 * full text search of manual pages and Texinfo (with Glimpse)
 * individualized directory-to-volume collection mappings
 * if an old version of the page is available under RCS, optionally show differences: additions as italics, deletions as overstrike, changes as bold italics
 * when multiple pages match the search name, a pulldown list of all matches
 * regular expression searches for manual page names
 * man page name completion
 * when searching for documentation, try Texinfo names too, and   optionally) prefer Texinfo documentation to man page
 * Fuzzy search for man page names if not exact match found   (e.g., "srcolbzart" finds "scrollbar")
 * list of recently added or changed manual pages
 * "history" list of the most recently visited pages
 * preferences panel to control fonts, colors, and many other system settings
 * compatibility with compressed pages (both as source and formatted)
 * diagnostics on your manual page installation
 * helper script retkman that can be used to restart TkMan after changes to the MANPATH in a shell, as from a "package" manager
 * in man page display, elision of those unsightly page headers and footers
 * and, when attempting to print a page available only in formatted form, reverse compilation into [tn]roff source, which can then be reformatted as good-looking PostScript. 


Using TkMan

In the text that follows, click means a quick mouse button click (down and up in less than a quarter of a second), and press means press and hold down the mouse button.  Some widgets in the interface function as buttons when given a click, menus if pressed.  If you want to access the menu, you do not need to wait for the menu itself to appear before dragging down the menu; go ahead and drag down with the mouse, and the interface will catch up to the mouse movement when the menu appears.  You still post menus, by waiting until the menu appears and then releasing the button with the cursor over the menubutton. 


Locating a man page

There are several ways to specify the manual page you desire.  You can type its name into the entry box at the top of the screen and press Return or click the man button.  The name may be just the name of the command or may end with .n or (n), where n specifies in which section to look.  Type in a partial name of three or more letters and type Escape to invoke page name completion. If there was exactly one match, the letters typed in so far will be replaced by the name of the page and its section number; otherwise it will be the longest common prefix of all possible matches. Man pages are matched using regular expressions, so you can use . to match any single character, * to match any (zero or more) of the previous regular expression, [ .. ] to match any single character in the enclosed class; see regexp.n for more information.  For instance, .*mail.*.1 searches section 1 (user commands) for commands with "mail" anywhere in their names. Likewise, one can collect all the various manual pages relating to Perl 5 with perl.*, or see a list of all X window managers with .*wm. If you're running TkMan from a shell and giving it an initial man page name to load up as an argument, use this syntax (adequately quoted for protection from the shell), as opposed to the syntax of the standard man command (which is man section name--that is, the section number comes first, whereas in TkMan it is part of the name. You can specify an initial section of the page to examine by appending to the name a / and a search expression that matches part of a section name; for example,  csh/diag  opens and scrolls to the Diagnostics section of csh immediately upon loading that page. Similarly, appending to the name a question mark and a search pattern will invoke a full text search in the page once it is brought up. 

Whenever you have a man page name in the text display box, whether from apropos, a volume listing or a reference within another man page, you can click on it to hypertext-jump to it.  In point of fact, man pages do not explicitly code man page references, but words that are especially likely to be references are distinguished, though any word may be clicked on to treat it as a man page reference.  Pressing shift while clicking opens up a new viewer box to display the page. 

Usually TkMan searches the colon-separated list of directories in your MANPATH environment variable for the man page, but you may instead provide a path name for the man page by beginning it with  `~', `/', `.' or `..'; this is the way to access a man page which isn't installed in a MANPATH man directory.  File name completion is invoked with Escape. Further, other Tcl interpreters may display a man page in TkMan by sending a message to the function manShowMan with the name of the desired man page, e.g. send tkman manShowMan tcl.n.  If multiple man page names match the specification, the first match (as searched for in MANPATH order) is shown and a pulldown menu appears which contains a list of the other matches.  Return from reading help or a volume listing to the last man page seen with C-m when the focus is in the main text display area. 

apropos information is available by typing the name and hitting Shift-Return or pressing on the man button and dragging down to apropos. The output of apropos is piped through sort and uniq to remove duplicates.  To pass the matches through additional filters, simply give the pipe as in a shell, e.g., `search | grep ^g' (each space character is significant) returns all the search-related commands which begin with the letter g. TkMan relies on the native system to supply apropos information and on some but not all systems (HP-UX but not GNU, for instance), apropos information for all pages in a given section is available by giving the section number in parentheses, e.g., (1) as the apropos search string. 

If it's installed, you will see  in the man menu an entry for full text searching with glimpse. Fuzzy full text is a full text search that finds the "best match" in the absence of an exact match (it uses glimpse's -B option). Glimpse was written by Udi Manber, Sun Wu, and Burra Gopal of the University of Arizona's Department of Computer Science. Glimpse requires only small index files ("typically 2-5% the size of the original text" but larger percentages for smaller amounts of text).  In their performance measurements, "a search for Schwarzkopf allowing two misspelling errors in 5600 files occupying 77MB took 7 seconds on a SUN IPC".  For example, one may search for the string WWW anywhere in any manual page by typing in WWW in the entry line at the top of the screen and clicking on the glimpse button or typing Meta-Return. Escape and C-g can interrupt a search after the current directory is done. To employ glimpse's command line options, simply place them before the search pattern in the entry box, or add them to the default options by editing the man(glimpse) variable in your ~/.tkman startup file (see Customizing TkMan, below). For instance, to search for perl as a full word only and not as part of another word (as in "properly"), case insensitively, glimpse for -wi perl.   Glimpse supports an AND operation denoted by the symbol `;' and an OR operation denoted by the symbol `,'. For example, to search for "insert" and "text" in Programmer Subroutines (volume 3), glimpse for -F \\.3 insert;text. Refer to the glimpse manual page for more information. Note that searching is done on man page source, and that the number of textual excerpts is limited to five per page to guard against frequent hits in a file unbalancing the search, but this means the text you want might be in that page and just not shown in an excerpt. The regular expression used by glimpse automatically sets the intrapage search  expression.  For this reason, the case sensitivity of the glimpsing is set to the same as intrapage regular expression searching. A complete set of matches from the last full text search is available under the Volumes menu.  Searching is done in manual page and Texinfo source, and the matches displayed in the formatted versions, so it is possible to match on formatting or in comments and not have any matches in the formatted version. 

The Paths submenu under the man menu (press and hold down mouse button  on man and drag down, then across)  gives you complete control over which directory hierarchies of your MANPATH are searched for man pages and apropos information.   If you plan more than a couple of operations with this menu, consider tearing it off by releasing the mouse on the dashed line at the top of the menu. If you use a "modules" system to manage software--binaries and their accompanying documentation--that as a side effect changes the MANPATH,  you can update TkMan by typing retkman (see below) in any shell.   

You can call up a listing of all man pages in a volume through the Volumes pulldown menu and then select one to view by clicking on its name. New `pseudo-volumes' can be added, and arbitrary directories may be added to or deleted from a volume listing using tkmandesc commands, described below. In a volume listing, typing a letter jumps to the line in the listing starting with that letter; capital and lower case letters are distinct.   Other special collections are placed in Volumes.  Texinfo and Request for Comments display such lists.  Recently added/changed presents a list of man pages whose time (specifically, ctime) is within the last couple weeks. The title of the Volume menu reflects the current menu, and that volume listing may be quickly recalled by clicking that title button or by typing C-d. 

The last few man pages you looked at can be accessed directly through the History pulldown menu, which is the circular arrow to the right of the name typein box.   The list is sorted top to bottom in order of increasing time since that page was last visited. The Shortcuts menu, the x/+/- to the right of History,  lists your personal favorites and is used just like History, with the additional options of adding the current man page (by clicking +) or removing it (-) from the list.   

(Man pages specified as above are processed through an nroff filter. TkMan can also read raw text from a file or from a command pipeline, which can then be read, searched and highlighted same as a man page.  To read from a file, make the first character in the name a <, as in <~/foo.txt.  To open a pipe, make the first character a | (vertical bar), as in `|gzcat foo.txt.gz' or `|cat ../foo.txt | grep bar' (that's no space after the first |, a space before and after any subsequent ones). After reading a file in this way, the current working directory is set to its directory. Commands are not processed by a shell, but the metacharacters ., .., ~ and $ (for environment variables), are expanded nonetheless.  Typing is eased further by file name completion, bound to Escape.   Lone files (i.e., not part of a pipe) are automatically uncompressed--no need to read compressed files through a zcat pipe. ) 


Working within a man page

The invisible text patch to Tk's text widget enables outlining.  Page section and subsection content can be collapsed and expanded by clicking on the corresponding header.  Opening a section by clicking on its title moves its section title to the top of the screen save for five lines: to the top in order to immediately show the initial text of the section, and save for five lines in order to maintain some orienting context.  Clicking button 3 anywhere in that section toggles its state.  This makes it convenient to expand a section, scroll through it a bit, and then close it up to return to the header overview.  Double clicking button 3 closes up all sections.  Outlining can be tuned, even turned off, via the Preferences dialog under the Occasionals menu (called ...). Outlining doesn't interfere with jumping to a section via the Sections or Highlights menus or during searching, as sections automatically open up as needed.  (Try this: go to text.n and do a regular expression search for pathName; hit <Return> twice.) When mousing about in the text collapsing and expanding sections, a more convenient way to scroll than moving back and forth to and from the scrollbar is to use the keyboard or to drag with button 2 in the text. When a page is displayed as an outline, the number to the right of the section head is the number of lines in that section.  Regular expression searches change this number to the number of hits in that section. 

To the extent it follows conventional formatting, a manual page is parsed to yield its section and subsection titles (which are directly available from the Sections pulldown--the leftmost menu, which appears as a page icon)  and references to other man pages from throughout the page including its SEE ALSO section.   One may jump directly to a section within a man page  by selecting the corresponding menu entry. 

Within a man page or raw text file or pipe, you may add ad hoc highlighting, as though with a yellow marker (underlining on monochrome monitors).  Highlighted regions may then be scrolled to directly through the Highlights pulldown menu.  To highlight a region, select the desired text by clicking button 1, dragging to the far extent of the desired region and releasing the button; Hi changes to a + to indicate that clicking it will highlight that span.  On subsequent text selections, if the selection overlaps one or more existing highlights, Hi changes to a -, indicating that clicking it will remove those highlights.  To remove all the highlights over a large area, close those outline sections and select across collapsed text before clicking -. A shift-click on the menu title tours through all the highlights on the page. A complete set of pages with highlighting is available under the Volumes menu. 

Highlighting information is robust against changes to and reformatting of the page.  Thus you can justify expending some effort in marking up pages with the knowledge that if a man page does change, as when the corresponding software package and its documentation are updated, TkMan will try to reposition them to the corresponding positions in the new pages.  The success of the algorithm can be measured by comparing the "highlights repositioned automatically" vs "highlights unattachable" statistics under Occasionals/Statistics and Information. As of this writing, my personal statistics report that 6866 highlights have been reattached without incident, 614 have been automatically repositioned on a changed page, 38 have been automatically carried forward to a moved page, and a mere 7 were unattachable. Moreover, highlights follow a page if it is moved.  If the current page has no highights and its name matches that of a page with highlights that no longer exists, then what probably happened is that the page was moved and you are asked whether this is indeed the case and thus whether to reassociate the highlights to this new page. Thus, say you have highlighted a number of pages in Tcl 7.6/Tk 4.1. Updating to Tcl/Tk 8.0 will both reassociate the annotation set to the new file name and reposition the annotations within the page--all automatically, asking for permission first. 

Here's how highlight reattachment works. When you highlight a region, the starting and ending positions are saved along with some of the content of the highlighted region and context.   When that page is viewed again, if those positions still match the context, the highlight is attached there (this is an exact match).  If not, the context is searched forward and backward for a match, with the closer match chosen if there are matches in both directions (a repositioned match).   If no match is found with the full context, gradually less and less of it is tried,  reasoning that perhaps the content of the context has been changed (repositioned, but with less confidence, triggering a warning dialog). If still no match is found (an orphan), the highlight is reported at the bottom of the page, where it must be reattached manually before leaving the page or it will be forgotten.  (With TkMan v1.8b3 and earlier, highlights were attached by positions only, and when the page modification date changed, the user had the choice of applying  highlights at those same positions regardless of the text there now or throwing out the highlights wholesale.  Old style highlights are automatically updated to the new style that can be automatically and robustly repositioned.  The next time an old style page is viewed, the old style highlights are applied as before, and from those positions new style highlights are composed.)  The annotation reattachment mechanism is inspired by Stanford's ComMentor system and, post facto, Larry Wall's patch. 

You can move about the man page by using the scrollbar or typing a number of key combinations familiar to Emacs aficionados.  Space and C-v page down; delete and M-v page up.  Return pages down, expanding collapsed outline sections as it encounters them. (vi fans will be happy to hear that C-f and C-b also page down and page up, respectively.) C-n and C-p scroll up and down, respectively, by a single line. M-< goes to the top and M-> to the bottom of the text.  One may "scan" the page, which is to say scroll it up and down with the mouse but without the use of the scrollbar, by dragging on the text display with the middle mouse button pressed.  Like Emacs, C-space will mark one's current location, which can be returned to later with C-x, which exchanges the then-current position with the saved mark; a second C-x swaps back. Following an intradocument hyperlink in Texinfo automatically marks the location of the link source. 

C-s initiates an incremental search.  Subsequently typing a few letters attempts to find a line with that string, starting its search at the current match, if any, or otherwise the topmost visible line.   A second C-s finds the next match of the string typed so far.  (If the current search string is empty, a second C-s retrieves the previous search pattern.) C-r is similar to C-s but searches backwards. Escape or C-g cancels searching. Incremental search can be used to quickly locate a particular command-line option or a particular command in a group (as in csh's long list of internal commands). 

The document map runs alongside the scrollbar.  It has various marks at positions proportional to their position in the document. White bars indicate section and subsection heads, setting the major divisions.  Blue indicates hyperlinks.  Yellow indicates highlights. Orange indicates search hits.  You can click on the document map to scroll to that part of the document, opening the corresponding outline section if necessary.  The document map gives a quick sense of the structure or the page.  I've found it especially useful in display the distribution of search hits. 

At the bottom of the screen, type in a regular expression to search for (see Tcl's regexp command), and hit return or click Search to begin a search.  In the outline view, this closes up all sections and displays the number of hits in each section alongside the corresponding section title. At this point, you can open up a particular section that seems particularly relevant, or keep hitting return to cycle through all matches. Hit C-s or click the down arrow to search for the next occurrence, C-r or the up arrow for previous occurances. 

To quickly search for the current selection, set in any X application,  click Meta-Button-1 or Alt-Button-1 or Control-Button-1 (pick one that doesn't conflict with your window manager) anywhere in the text display.  If no selection is set, the search is made for the word under the cursor. 

The Tab key moves the focus from the man page type-in line to the text view of the man page to the search line and back around.  Shift-Tab jumps about in the opposite direction. 


Other commands

The Occasionals menu, labeled ... at the extreme right,  holds commands and options which you probably won't use frequently.  Help returns to this information screen.  Although virtually made obsolete by TkMan, Kill Trees makes a printout of the current man page on dead, cut, bleached trees, helping to starve the planet of life-giving oxygen.  (This option is enabled only when viewing a manual page.) A list of printers appears in the cascade menu; this list may be edited in Preferences/Misc.  (Even if only one printer is available, it placed in the cascade menu, rather than being directly available.  This is a feature.) (If the [tn]roff source is not available, TkMan asks if it should try to reverse compile the man page.  If successful, this produces much more appealing output than an ASCII dump.)  By default, incremental searching is not case sensitive, but regular expression searching is; these settings can be toggled with the next two menus.  iff upper means that searching is case sensitive if and only if there is at least one uppercase letter in the search expression--that is, all-lowercase searches are not case sensitive; this idea is taken from Emacs. 

As with xman one may instantiate multiple viewers.  When there is more than one viewer you may choose man pages in one viewer and have their contents shown in another.  Use the Output pulldown (which is labelled with the destination viewer number and which appears and disappears as relevant) to direct one viewer's output destination to another.  With this feature one may easily compare two similar man pages for differences, keep one man page always visible, or examine several man pages from a particular volume listing or a SEE ALSO section.  Output only affects the display destination of man pages. 

TkMan builds at startup an internal database of all manual page names in order to quickly search for a particular name. If you install new manual pages or otherwise change the contents of man page directories after TkMan as been started, invoke Rebuild Database. In order to pick up changes in MANPATH, use the companion script retkman, executed from the same command line as that in which the MANPATH was changed. Rebuild Glimpse Database creates and then maintains the index that is used for full text searches.  The Glimpse database is not updated automatically due to the large amount of time it may take, though often Glimpse can incrementally rebuild the index in just a few minutes.  

When exited via the Quit button, TkMan saves its state.  One may guard against losing highlighting, shortcuts and other would-be persistent information without quitting by invoking Checkpoint state to .tkman; Quit, don't update performs the opposite operation. 

At the bottom right corner of the screen, Mono toggles between the proportionally-spaced font and a monospaced one, for use in those man pages that rely on a fixed-width font to align columns.  Quit exits TkMan, of course, after saving some state information (see below).  To exit without saving status information, select the Quit option from the Occasionals (...) menu. 


Texinfo Reader

A special entry under the Volumes menu calls up a list of GNU Texinfo (aka info) books.  As distinct from other Texinfo readers--info, xinfo, tkinfo, and the one built into Emacs--the reader in TkMan interprets the document source file, which can be compressed, rather than the character-formatted version.  This makes possible significantly higher quality page rendering, which is rendered with Tk's expressive text widget. 

Furthermore, TkMan provides a different interface to Texinfo files. Other readers navigate among "nodes".  At a given point, one may be able to go to the next or previous node in sequence or up to the parent node.  In other words, in navigating the "info-space", you only have immediate context information.  At least for me, this leads to being "lost in info-space".  TkMan's Texinfo reader provides an outliner user interface, which gives much more positional context.  The little number to the right of the section title reports the number of subsections it holds.  I think an outlining interface is well matched to the usually highly hierarchically structured Texinfo files. 

Texinfo books can be very large; Elisp's manual is 18MB for example.  Other info readers show parts of corresponding formatted files that consume approximately the same amount of disk space as their source. In contrast, TkMan processes the source files to extract only the hierachy information and caches this on disk; usually this amounts to about 2% of the source file size, after compression (no cacheing takes place if processing can be done in less than 1.5 seconds).  Moreover, main memory use is minimized by loading in only those sections that have been opened for viewing in the outline.  (Actually, for any opened section, the next section is prefetched and preformatted, so that it is immediately available if you're reading consecutive sections.) 

If some stick-in-the-mud sys admin has not enabled TkMan's Texinfo reader, you can set it up for individual use.  In Preferences/Database set Texinfo index directory to the directory in which to find a file named dir.tkman as well as to store one cache file per Texinfo book (regardless of the number of files that comprise it).  This can be the same directory as present Texinfo directory. The dir.tkman file is a list of Texinfo files just like the dir file used by other info readers, except paths are full paths to each top source file.  I've included my dir.tkman as a pattern.  (Texinfo support  could be extended to handle multiple info directories but I don't think that's necessary now as just have one short index files per info manual regardless of how many constituant files the manual has,  whereas before the info directory was lengthened with many files per book.) The Texinfo volume is shown and reports errors in the file. This file read from disk every time it changes so you can dynamically experiment with it without restarting TkMan.  Texinfo files must be suffixed with .texi or .texinfo to be recognized as such.  In fact, a file need not be found in a dir.tkman list; any file with those suffixes are treated as Texinfo files, whether they are "top level" files that recursively include all the others in the book, or not.  Texinfo source files can be compressed.  If you're the effective sys admin for a shared repository as indicated by a writable Texinfo cache directory that is not in your home directory, you can build all the Texinfo cache files via the menu .../Rebuild Database/Texinfo.  Otherwise, cache files are built on demand and added if have you have write permission to the cache directory. 

Searching uses gzgrep (if you have it) to search the full text on disk, maps hits back into sections, and faults them in.  If there are hits in many different sections, rather than fault in all the sections at considerable cost of time and memory, the first 20 or so sections  that have not already been read in are faulted in.  Repeating the search will bring in the next 20 sections with hits and so on until all sections with hits are displayed.  Searching is done in the Texinfo source and results displayed in the formatted text, which can lean to some discrepencies, as for instance references to the program TeX are specified as @TeX{} in the source but appear as TEX (with lowered "E") in the formatted (in this case search for TeX|TEX; searching for text will find both but will also  find numerous occurances of text). 

Texinfo tags not supported: @image, @kbdinputstyle, @macro, @exdent, hyperlinks across Texinfo documents.  Let me know if any of these is heavily used, and where. Also, nested tables and lists can get confused. 


Version Differences

If you care to put your man pages under RCS revision source control, you can optionally have TkMan display a man page with differences--additions, deletions,  changes--from its previous version. (Differences that are simply a matter of formatting tweaks-- not substantive content revisions--are ignored, assuming diff correctly determines the correspondences between old and new text.) For example, for Tk's text widget you can see that in moving from Tk 4.1 to 8.0, support for embedded images is entirely new and mention of the X selection is stricken from the section THE SELECTION, whereas the canvas widget man page has been augmented to mention that windows are always drawn on top and that canvases can be output to a channel, though the channel option isn't separately listed in the list of options for the postscript command.  This information was discovered through a quick scan through of the respective man pages while looking for large patches of italics, bold-italics, and overstrike text. 

The RCS archive is searched for the newest revision that has differences.  This way when you install new documentation you can check it into RCS right away.  This might not be suitable for documentation that is frequently revised, as that for one's own project perhaps.  For these cases, you can specify the exact RCS branch to diff against by associating the symbolic name checkpoint with that branch (see rcs's -n and -N options).  By following a simple routine, you can maintain version information for a large collection of pages belonging to a piece of software as they are updated from version to version: Before installing new pages, rcs -Ncheckpoint on all related pages to set the point against which to compute differences. After installation, ci -l -t'version X.Y' to record them in the RCS archive. 

Version difference information is cached into tiny, compressed files with one line per change plus those lines deleted from the old version.  Like Texinfo cache files, differences cache files are created on demand as one views files, or can be built/updated all at once with the .../Rebuild Database/Man page version (RCS) caches menu.  Version difference information is cached into a subdirectory called RCSdiff under the place where the corresponding cached manual page would be stored, which is either .../man/catn or, if .../man/catn is not writable, in a separate directory tree specifically for this purpose. 

As well, for manual pages with version information, TkMan dynamically introduces a pseudo-section that displays the version log, with hyperlinks that call up older versions.  These older versions can be highlighted as stored as shortcuts. 

Difference information is given on a line by line basis.  (I tried wdiff for word granularity, but wdiff doesn't correctly associate newlines with old text.)  This means that if you're using the long lines option, difference information is rather coarse, on the paragraph level. 

If you're using this option, don't compress the corresponding man page source as RCS doesn't like this.  You can still compress cached formatted pages regardless. 

If you are taking advantage of both Glimpse and man page versioning, you can prevent glimpse from indexing RCS versioning information by giving each RCS directory a chmod -x RCS. 


Preferences

The Preferences... choice in the Occasionals pulldown menu (called ...) brings up a graphical user interface to setting various attributes of TkMan, including fonts, colors, and icons.  Click on a checkbutton at the top of the window to bring up the corresponding group of choices.  After making a set of choices, the Apply button reconfigures the running application to show these changes, OK sets the changes for use now and in the future, Cancel quits the dialog and sets all choices to their settings as of the time Preferences was called up, and Defaults resets the settings in the current group to those set by TkMan out of the box. I suggest touring all the options to discover what all's available,  tweaking to preference along the way. 

The first line in the Fonts group specifies the font to use for the general user interface-- labels on buttons and text in menus.  The first menu in the line labeled Interface sets the font family, the next menu sets the font size, and the last the font styling (normal, bold, italics, bold-italics). Text display makes these settings for the text box in which the manual page contents are displayed.  For listings of all man pages in a particular volume (as chosen with the Volumes menu), you may wish to use a smaller font so that more names fit on the screen at once.  The text added/changed/deleted choices-- which apply only if you are showing man page version differences as described above--use the same font size as Text display. 

Colors sets the foreground and background colors to use for the the general user interface, the buttons of the user interface, and the  manual page text display box.  In addition it sets the color (or, with editing of the .tkman file, font) in which to show various classes of text in the text box, including manual page references, incremental search hits, regular expression search hits, and highlighted regions. 

The See group specifies what information and controls to display. Usually manual page headers and footers are uninteresting and therefore are stripped out, but a canonical header and footer (along the date the page was installed in the man/mann directory  and by whom) to be shown at the bottom of every page can be requested.   In an effort to maximize screen real estate devoted to displaying content, you can choose to hide all menus and buttons (the row with Sections, Highlights, Volumes at top; and Search, Mono, Quit at bottom) until they made are active, either by tabbing into that line or by moving the mouse into that region. This is for the experienced user who knows where things are. Solaris and IRIX systems come with many "subvolumes"--that is volumes with names like "3x" and "4dm" that form subgroupings under the main volumes "3" and "4", respectively--and you make use tkmandesc commands to add your own subvolumes.  You can reduce the length of the main Volumes menu by placing all volumes in such groups as cascaded menus. When a highlighted passage is jumped to via the Highlights menu, some number of lines of back context are included; the exact number of lines is configurable.   Around the man page display area runs a buffer region of a few pixels, the exact width of  which is configurable. 

You have the option to view manual pages as outlines whereby sections and subsections can be collapsed and expanded.  The choices here control the initial outline displayed when a page is first displayed.  You can have all sections collapsed or all expanded, or turn off outlining altogether. More interestingly, you can have all collapsed but for those that match a pattern.  This defaults to match the sections long Names, short Descriptions, Synopsis, Author, and See Also.  The pattern is matched against the name of the section appended with the number of lines in that section. The number of lines is used to expand sections only if they are long enough to be interesting or short enough to leave screen real estate for other sections. 

It is likely that any text you highlighted on a page is important, and you can elect to show this text even inside otherwise collapsed outline sections. In this way, highlighted text can serve as a combination note and "in-place bookmark":  Sometimes just the excerpted lines containing the highlighted text provides sufficient information; if not, click on the highlight and the section will expand and scroll to that text (with a configurable number of lines of back context). You can turn off this option (never), or just excerpt the highlights when the page is first shown (at first),  after which any action that opens or collapses an outline section dismisses the excerpts. Setting the option to always keeps the corresponding category of text always visible  and uses a plain font as opposed to at first's italics. Likewise for manual page references. Likewise for searches, except that searches first close up all outline sections.  It can be helpful to have some words jump out on the page, as for instance words that indicate danger ("warning", "unsafe"), standards conformance ("internationalization", "POSIX"),  pointers to documentation in different formats ("Texinfo", "PostScript", "HTML"),  or system-specific options in general software ("Solaris", "Macintosh"), to name a few. The regular expression on the Autosearch line are automatically found in the manual page and highlighted to immediately grab the eye, on their first character so as not to overwhelm the screen. In general, the more internal structure, like command line options and subcommands, the greater the value of Notemarks.  A second regexp of less urgent strings is also autosearched, but not reported as Notemarks; you see them when viewing that part of the page. Notemarks are another reason to use the outlining interface, for with text collapsed to more or less fit on one screen, you can actually see them all immediately, rather than scrolling (or not) to see them (or not). 

Sometimes even after opening selected sections and showing highlights, some vertical screen real estate remains.  If so, this space is filled with as much information as fits from the highly important Description section, if that section is not already fully expanded, thus maximizing the information for a page that is shown on its first screen. The Excerpt line lists, in priority order, the sections that should be excerpted, either always in their entirity or as there is room on the first screen. Perl 5 man pages aren't very amenable to outlining or excerpting:  they'll often have a couple line NAME section followed by 1000s of lines in DESCRIPTION--effectively putting what would be tens of printed pages into one section.  On the other hand, environ(5),  expect(1), printf(3), Tcl's file(n), and Tk's text(n), canvas(n) and wm(n) work especially well.   

If a page is short enought to fit on the screen in its entirety, outlining is superfluous and not applied.  Also overriding the initial outline settings, the page always scrolls to show the last screen viewed, expanding sections as necessary. 

If a man page has not been formatted by nroff, TkMan must first pipe the source text through nroff.  By turning on Cache formatted (nroff'ed) pages in the Database group, the nroff-formatted text is saved to disk (if possible), thereby eliminating this time-consuming step the next time the man page is read .   The on & compress setting will compress the page, which saves on disk space (often substantially as much of a formatted page is whitespace), but will make it unavailable to other manual pagers that don't handle compression (you may be forced to use a character-based man pager over a dial-up line or during system debugging after a crash).   If you're using groff as your formatter and you have man page source available (sorry SGI, IBM), you have the option to more effectively use screen space by lengthening lines. (Cached pages of various lengths can co-exist:  A page of length n is stored in a directory named .../man/catvolume@n.) When formatting pages to use longer lines, hyphenation is supressed so that searches in the page aren't frustrated by hyphenated words. If you take your manual page source from CD-ROM or run in a network that makes the corresponding cat directories unwritable, you can set a directory to serve as the root of a parallel hierarchy for cached formatted pages. The default setting, /var/catman, makes the whole process conform to  the Linux FSSTND specification, but you can set it to someplace else, say,  /var/cache/man for the FHS 2.0 spec, or to your home directory.  (FHS 2.0 specifies that pages in .../share/man directories be cached in the exact same path as a page of the same name in .../man.  Obviously this leads to conflicts, so that part of the specification is ignored for the sake of cache integrity.) 

Volumes' (recent) choice will show all manual pages that have been added or changed within the past n days.  If you usually use the GNU implementations of standard UNIX utilities, which usually boast enhanced functionality, you can redirect man page references to the GNU version for those that are named by taking the UNIX name and prepending a g (e.g., od => god). If you have this option switched on but have an exceptional case (for instance you want zip, the free file compressor compatible with PKZIP,  and not gzip (which is a superior replacement for compress) prefix the name with a caret (^, as in "^zip"). 

Glimpse works best when searching for relatively uncommon words; guard against getting too many hits by setting the maximum number reported. By default Glimpse indexes are placed at the root of the corresponding man hierarchy, where they can be shared.  For the case when an individual may not have write permission there, a single, unified index can be created and stored locally (though you lose control of it from Paths settings). Unified indexes are faster than distributed.  On the other hand, rebuilding the index generally takes longer, since the distributed version will only have to rebuild the indexes for those directories that changed.  On the third hand, glimpse can usually incrementally rebuild my unified index in just a couple of minutes. For unified indexes and also for "stray cats" (i.e., directories not part of a set of man hierarchy directories), you should specify an auxiliary directory to hold the index. 

As mentioned above, TkMan displays Texinfo books by reading Texinfo source code.  For better performance, TkMan caches indexes into these books, some of which are very long (18MB for Elisp).  Although indexes are relatively small, 2% or so of the original, they still must be stored somewhere, specified here. 

The Window group sets all the options relating to window management, including iconification. The pathnames of the icon bitmap and icon mask should be the full pathnames (beginning with a `/').  If Path name to icon bitmap is set to (default), the internal icon by Rei Shinozuka will be used.  If your window manager has trouble with iconifying and deiconifying TkMan and you are using the (default) setting, try setting the icon to a path. 

Miscellaneous.  By default, man page links are activated by single clicking.  If it is changed to double with Mouse click to activate hyperlink, the first click puts the name in the entry box so that it can be used as the apropos or glimpse pattern as well as for man searching.  This click once to select, twice to launch follows the Macintosh convention. 

TkMan can extract section headers from all manual pages, but only some manual page macros format subsection headers in a way that can be distinguished from ordinary text; if your macros do, turn this option on to add subsections to the Sections menu. If you find that many lines are being interpreted as subsections, turn it back off. The History pulldown, the down arrow to the right of the name typein box, must balance depth of the list against ease of finding an entry; set your own inflection point with this menu.  Tk deviates from Motif behavior slightly, as for instance in highlighting buttons when they're under the cursor and in the file selection box, but you can observe strict Motif behavior. 


Customizing TkMan

There are four levels of configuration. 

(1) Transparent.  Simply use TkMan and it will remember your window size and placement, short cuts, and highlights (if you quit out of TkMan via the Quit button). 

(2) Preferences editor (see Preferences above). 

(3) Configuration file.  Most interesting settings--those  in the Preferences dialogs and more not available there--can be changed by editing one's own ~/.tkman file.  Thus, a single copy of TkMan (i.e., the executable tkman) can be shared, but each user can have his own customized setup.  (The file ~/.tkman is created/rewritten every time one quits TkMan via the Quit button in the lower right corner.  Therefore, to get a ~/.tkman to edit, first run and quit TkMan.  Do not create one from scratch as it will not have the proper format used for saving other persistent information, and your work will be overwritten, which is to say lost.  As well, be careful not to edit a ~/.tkman file only to have it overwritten when a currently running TkMan quits.) 

Options that match the defaults are commented out (i.e., preceded by a #).  This is so that any changes in TkMan defaults will propagate nicely to end users, while maintaining a list of all interesting variables. To override the default settings for these options, first comment in the line. 

The ~/.tkman save file is the place to add or delete colors to the default set, which will subsequently become menu choices in Preferences, by editing in place the variable man(colors).  One may also edit the order of Shortcuts in the man(shortcuts) variable. Other interesting variables include man(highlight), which can be edited to change the background in place of the foreground, or both the foreground and background, or a color and the font as with the following setting:
set man(highlight) {bold-italics -background #ffd8ffffb332} 

Arbitrary Tcl commands, including tkmandesc commands (described below), can be appended to ~/.tkman (after the ### your additions go below line). 

To set absolutely the volume names for which all directories should be searched, edit the parallel arrays on these existing lines:
set man(manList) ...
set man(manTitleList) ...
 Changing the order volumes in these lists (make sure to keep the two lists in parallel correspondence) changes the precedence of matches when two or more pages have the same name: the page found in the earlier volume in this list is show first. 

Additional useful commands include wm(n), which deals with the window manager; bind(n), which changes keyboard and mouse bindings not related to the text display window; options, which sets the X defaults; and text(n), which describes the text widget. 

(4) Source code.  Of course, but if you make generally useful changes or have suggestions for some, please report them back to me so I may share the wealth with the next release. 


Environment

MANPATH 
      Colon-separated list of directory paths in which to search for man pages. Usually the final directory in a path is man, as in /usr/man.  This variable is standard across man pagers, including man(1) and xman(1). 

DISPLAY_DPI 
      Usually the screen DPI is calculated automatically and from this the closest  existing font DPI is chosen.  You can override this calculation by setting  DISPLAY_DPI; common values of screen DPI are 75, 90 and 100. 

TKMAN 
      The environment variable named TKMAN, if it exists, is used to set command line options.  Any options specified explicitly (as from a shell or in a script) override the settings in TKMAN. Any settings made with command-line options apply for the current execution only. Many of these options can be set persistently via the Preferences dialog (under the Occasionals menu). 
       


Command line options

-title title 
      Place title in the window's title bar. 

-geometry WxH+X+Y 
      Specify the geometry for this invocation only.  To assign a persistent geometry, start up TkMan, size and place the window as desired, then (this is important) quit via the Quit button in the lower right corner. 

-iconify and -noiconify 
      Start up iconified or uniconified (the default), respectively. 

-iconname name 
      Use name in place of the uniconified window's title for the icon name. 

-iconbitmap bitmap-path and -iconmask bitmap-path 
      Specify the icon bitmap and its mask. 

-iconposition (+|-)x(+|-)y 
      Place the icon at the given position; -iconposition "" "" cancels any such hints to the window manager. 

-dpi value 
      Use value DPI fonts.  Most X servers have 75 and 100 dpi fonts.   On the same monitor, 100 dpi fonts appear larger. 

-debug or -nodebug 
      Generate (or not) debugging information. 

-startup filename 
      Use filename in place of ~/.tkman as the startup file; "" indictates no startup file. 

-quit save and -quit nosave 
      Specify that the startup file (usually ~/.tkman) should be updated (save) or not (nosave) when quitting by the Quit button. 

-v 
      Show the current version of TkMan and exit immediately thereafter. 

-M path-list
 or -M+ path-list
 or -+M path-list 
      As with man, change the search path for manual pages to the given colon-separated list of directory subtrees.  -M+ appends and -+M prepends these directories to the current list. 

--help Display a list of options. 
       


Key bindings

Key bindings related to the text display box are kept in the sb array in ~/.tkman (for more information on Tcl's arrays, refer to the array(n) man page.  In editing the sb(key,...) keyboard bindings, modifiers MUST be listed in the following order: M (for meta), C (control), A (alt).  DO NOT USE SHIFT.  It is not a general modifier: Some keyboards require shift for different characters, resulting in incompatibilities in bindings.  For instance, set sb(key,M-less) pagestart is a valid binding on keyboards worldwide, whereas set sb(key,MS-less) is not.  For this reason, the status of the shift key is suppressed in matching for bindings.  To make a binding without a modifier key, precede the character by `-', as in set sb(key,-space) pagedown. 


tkmandesc

Like xman, TkMan gives you directory-by-directory control over named volume contents.  Unlike and superior to xman, however, each individual user controls directory-to-volume placement, rather than facing a single specification for each directory tree that must be observed by all. 

By default a matrix is created by taking the product of directories in the MANPATH crossed with volume names, with the yield of each volume containing all the corresponding subdirectories in the MANPATH.  By adding Tcl commands to your ~/.tkman (see above), you may add new volume names and add, move, copy and delete directories to/from/among directories. 

The interface to this functionality takes the form of Tcl commands, so you may need to learn at least pidgin Tcl--particularly the commands that deal with Tcl lists  (including lappend(n), linsert(n), lrange(n), lreplace(n)) and string matching (string(n), match subcommand)--to use this facility to its fullest.  tkmandesc commands are used to handle the nonstandard format of SGI's manual page directories, and the irix_bindings.tcl in the contrib directory is a good source of examples in the use of tkmandesc commands. 

Directory titles and abbreviations are kept in lists.  Abbreviations MUST be unique (capital letters are distinct from lower case), but need not correspond to actual directories.  In fact, volume letters specified here supercede the defaults in identifying a volume in man page searches. 


COMMANDS

The following commands are appended to the file ~/.tkman (see Customizing TkMan, above). 

To recreate a cross product of current section lists:
manDescDefaults
 This cross product is made implicitly before other tkmandesc commands. Almost always this is what one expects.  If it is not, one may suppress the cross product by setting the variable manx(defaults) to a non-null, non-zero value before other tkmandesc commands are invoked. 

To add "pseudo" sections to the current volume name list, at various positions including at end of the list, in alphabetical order, or before or after a specific volume:
manDescAddSects list of (letter, title pairs)
 or manDescAddSects list of (letter, title) pairs sort
 or manDescAddSects list of (letter, title) pairs before sect-letter
 or manDescAddSects list of (letter, title) pairs after sect-letter
 In manual page searches that produce multiple matches, the page found in the earlier volume is the one shown by default. 

To move/copy/delete/add directories:
manDescMove from-list to-list dir-patterns-list
manDescCopy from-list to-list dir-patterns-list
manDescDelete from-list dir-patterns-list
manDescAdd to-list dir-list 

The dir-patterns-list uses the same meta characters as man page searching (see above).  It is matched against MANPATH directories with volume subdirectory appended, as in /usr/man/man3, where /usr/man is a component of the MANPATH and man3 is a volume subdirectory. from-list and to-list are Tcl lists of the unique volume abbreviations (like 1 or 3X); * is an abbreviation for all volumes. 

Adding directories with manDescAdd also makes them available to Glimpse for its indexing. 

Warning: Moving directories from their natural home slightly impairs searching speed when following a reference within a man page.  For instance, say you've moved man pages for X Windows subroutines from their natural home in volume 3 to their own volume called `X'.  Following a reference in XButtonEvent to XAnyEvent(3X11) first searches volume 3; not finding it, TkMan searches all volumes and finally finds it in volume X.  With no hint to look in volume 3 (as given by the 3X11 suffix), the full volume search would have begun straight away.  (Had you clicked in the volume listing for volume X or specified the man page as XButtonEvent.X, volume X would have been searched first, successfully.) 

To help debug tkmandesc scripts, invoke manDescShow to dump to stdout the current correspondence of directories to volumes names. 


EXAMPLES

(1) To collect together all man pages in default volumes 2 and 3 in all directories into a volume called "Programmer Subroutines", add these lines to the tail of ~/.tkman:
manDescAddSects {{p "Programmer Subroutines"}}
manDescMove {2 3} p * 

To place the new section at the same position in the volume pulldown list as volumes 2 and 3:
manDescAddSects {{p "Programmer Subroutines"}} after 2
manDescMove {2 3} p * 

To move only a selected set of directories:
manDescAddSects {{p "Programmer Subroutines"}}
manDescMove * p {/usr/man/man2 /usr/local/man/man3} 

(2) To have a separate volume with all of your and a friend's personal man pages, keeping a duplicate in their default locations:
manDescAddSects {{t "Man Pages de Tom"} {b "Betty Page(s)"}}
manDescCopy *phelps* t *
manDescCopy *page* t * 

(3) To collect the X windows man pages into two sections of their own, one for programmer subroutines and another for the others:
manDescAddSects {{x "X Windows"}} after 1
manDescAddSects {{X "X Subroutines"}} after 3
manDescMove * x *X11*
manDescMove x X *3 

(4) If you never use the programmer subroutines, why not save time and memory by not reading them into the database?
manDescDelete * {*[2348]} (braces prevent Tcl from trying to execute [2348] as a command) 

Alternatively but not equivalently:
manDescDelete {2 3 4 8} * 


tkmandesc vs. xman and SGI

TkMan's tkmandesc capability is patterned after xman's mandesc files.  By placing a mandesc file at the root of a man page directory tree, one may create pseudo volumes and move and copy subdirectories into them.  Silicon Graphics has modified xman so that simply by creating a subdirectory in a regular man subdirectory one creates a new volume.  This is evil.  It violates the individual user's rights to arrange the directory-volume mapping as he pleases, as the mandesc file or subdirectory that spontaneously creates a volume must be observed by all who read that directory.  By contrast, TkMan places the directory-to-volume mapping control in an individual's own ~/.tkman file. This gives the individual complete control and inflicts no pogrom on others who share man page directories.  Therefore, mandesc files are not supported in any way by TkMan. 

One may still share custom setups, however, by sharing the relevant lines of ~/.tkman.  In fact, a tkmandesc version of the standard SGI man page directory setup is included in the contrib directory of the TkMan distribution.  For assistance with SGI-specific directory manipulation, contact Paul Raines (raines@slac.stanford.edu). 


Platform-specific Support

I estimate that fully 75% of my time writing TkMan has been spent not in adding new features but in supporting all the many, gratuitous differences in the various flavors of UNIX.  Amazingly, each is different from every other.  TkMan confronts variations in man page organization, that is, directory structure.  The same percentage holds for PolyglotMan, which deals with variations in the formatting of the pages themselves, things like what character sequence indicates italics and what do page headers and footers look like.  The result of all this work is that you can do a simple installation of TkMan and it will embrace the specifics of your system's manual page installation. 

Here's the classical organization.  The MANPATH environment variable gives a colon-separated list of directory paths, each of which usually but not necessarily ends in a subdirectory named `man'. In each of these directories, the file `whatis' has a line per man page giving its name and a single line description taken from each page's NAME section.  Subdirectories named man[1-9oln] hold the [tn]roff source, and corresponding subdirectories named cat[1-9oln] cache formatted pages.  Within subdirectories, each page given as name.section-number, for example "ls.1".  The page source should always be available; formatted versions are purely optional, and strictly used as a performance enhancement, saving formatting time at runtime.  (Pages that exist in formatted versions only are known as "stray cats".)  Man pages may be compressed, with the type of compression given by a suffix on the file.  Compression can be particularly successful on formatted pages, which contain long strings of spaces. 

Here are all the ways that I can recall that various flavors of UNIX have "improved" the classical organization.  Clearly TkMan can do all that it does without reliance on any extension beyond the classical organization, so how important were these "extensions"? 

SunOS 
   + Just great! 

Solaris 
   + Renaming of `whatis' to `windex', which has an extra field 
   + Nonstandard directory names, e.g., `man1s'. 


Ultrix 
   + Just great (nonstandard tabs in formatted man pages handled by PolyglotMan). 

OSF/1 aka Digital UNIX 
   + Just great ("missing" headers and footers in formatted pages handled by PolyglotMan). 

HP/UX 
   + Compressed page files listed without .Z, which is on its enclosing directory 
   + Concatenates all whatis information into /usr/lib/whatis  

SCO 
   + /etc/default/man configuration file*. 

FreeBSD 

Linux 
   + /etc/man.config or /etc/manpath.config, depending on Linux flavor, configuration file* 
   + FSSTND 

BSDI 
   + Concatenation of all `whatis' files into a single /usr/share/man/whatis.db 
   + Formatted pages given suffix .0 
   + /etc/man.conf configuration file* 

IBM AIX 
   + Have to convert help files from opaque InfoExplorer format to standard /usr/man format. 
   + Have to prevent man pages from being parsed, since they are just simple ASCII files,  only vaguely resembling man pages 

SGI Irix - absolute worst by far 
   + Only pre-formatted pages in /usr/catman 
   + Consequently, doesn't have [tn]roff (what about formatting pages for new software?) 
   + Man sub-subdirectories magically appear as own volumes, with names hidden in their hacked version of xman 
   + Stray cats by default (installs formatted pages only) 
   + Page files named without section but with .z 

* TkMan used to have a variety of ways to set the MANPATH if it was not already set.  The MANPATH is simple to set, is recognized on all flavors of UNIX and all man-related tools, is easily customized, and does everything that these other ways did.  It is now the one and only way to communicate man directories to TkMan. 

For history buffs, here are how a MANPATH would be set if it didn't come from the environment: gmanpath's compiled-in MANPATH, system-specific configuration files (BSDI's /etc/man.conf, Linux's /etc/man.config or /etc/manpath.config, SCO's /etc/default/man), SGI's default /usr/share/catman:/usr/share/man:usr/catman:/usr/man, local default set TkMan's Makefile, calculation from PATH (e.g., /usr/bin:/usr/X11/bin => /usr/man:/usr/X11/man).  (Seriously!) 

What's wrong with configuration files?  BSDI, SCO, and Linux have central configuration files.  One problem is that they're all different from one another and not used by other platforms--and at least some of them are constantly changing.  So general man page-related programs don't know about them, and for TkMan they degenerate into yet another special case.  Not only are these configuration files not portable, they are useless at best or even harmful.  They are useless for a user of any sophistication as he will set MANPATH and PATH to achieve custom control, as opposed the general one-size-fits-all, centrally dictated approach of configuration files.  They are harmful for novice users who will want to customize the MANPATH, as there is now a different way to set it, whereas just following the pattern in a MANPATH setting is straightforward.  Even for novices who wish to remain happily ignorant, system-specific configuration files aren't helpful, because the same effect can be achieved with the universally accepted MANPATH, which can be easily set alongside all the other setup information typically provided for new users.  (Some system-specific configuration files also provided information for deriving a PATH, for which, by the same argument, should be set directly.) 


Multiple Simultaneous OSes

There are several ways to examine the pages from multiple operating systems at the same time.  
   + The simplest is to start up a copy of TkMan in a window running that OS (i.e., on that machine), using the -startup option to give each copy a different ~/.tkman startup file.  Each copy can be given an distinguishing window and icon titles. 
   + If man pages for all systems are available through the file systems mounted on a single machine, you can give a master MANPATH that includes everything.  When a page by that name exists on multiple OSes, a menu labeled ALSO will appear to give access to each one.  Pages can be distinguished in ALSO by their full path names, and when viewed by the full path posted at the top of the window.  You can use the Paths menu under the man menu to focus on just those OSes of interest at the moment. 
   + You can use aliases or short shell scripts to interface to retkman (see below) to restart TkMan with the appropriate MANPATH for whatever OS.  Or you can hack a new menu into TkMan's interface with code in your individual ~/.tkman that lists the available OSes and likewise runs retkman.  


retkman

If you change your MANPATH, either manually or as a side effect of some program, say, a modules system, you can rerun TkMan to pick up the new paths by quitting it and restarting.  The script retkman provides a command that can be used as part of an alias to automatically rerun TkMan as necessary.  If there are multiple instances of TkMan running on different machines, the one restarted is the one on the same machine from which retkman was invoked. 


PolyglotMan

TkMan uses PolyglotMan (formerly known as RosettaMan)  to translate and reformat man pages (see man(5)). PolyglotMan, called rman in its executable form,  takes man pages from most of the popular flavors of UNIX and transforms them into any of a number of text source formats.  Since its inception PolyglotMan accepted formatted pages, and now with version 3.0 interprets [tn]roff source for superior translations. PolyglotMan accepts man pages from SunOS, Sun Solaris, Hewlett-Packard HP-UX, AT&T System V, OSF/1 aka Digital UNIX, DEC Ultrix, SGI IRIX, Linux, FreeBSD, SCO.  It can produce ASCII-only, section headers-only, TkMan, [tn]roff (source), Ensemble, SGML, HTML, MIME, LaTeX, LaTeX2e, RTF, Perl 5 POD.   A modular architecture permits easy addition of additional output formats.  The latest version of PolyglotMan is available from  ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/rman.tar.Z. 


Other Man and Info Viewers

Among man pagers, as far as I know only TkMan has integrated full text search, highlighting, outlining interface and Notemarks, man page versioning display, comprehensive volume listings including lists of recent pages and results of previous full text search, regular expression and fuzzy page name matching, document map, Preferences configuration panel, and is as widely portable, among other features.  In other areas, such as adding hyperlinks, TkMan isn't unique, but it still probably does things better as a result of continually being refined since 1993 with the valuable suggestions and bug reports from thousands of users  (the builtin Statistics and Information page lists some).  Plus, TkMan has the coolest icon.  And it's heaps more fun. 

Below the term Texinfo refers to the source code for GNU documentation, and info to formatted Texinfo (which is compiled to a form suitable for display on a character terminal, or tty).  As far as I know, only TkMan displays from Texinfo source, making possible its considerably higher quality formatting. 

Of the seemingly innumerable man page and info viewers, here are a few of the more interesting ones I have seen: 

xman - man pages 
      Before I wrote TkMan I used xman, and in fact it was xman's lack of hyperlinks that motivated TkMan. Why use it instead? It comes bundled with X Windows (though perhaps not any more), so it's often already installed. 

Emacs' Superman - man pages 
       Why use it instead? It runs on tty's, it's GPL'ed (for those who have that fetish), and agoraphobics who live inside of Emacs won't have to leave the house. 

KDE Help - man pages and GNU info 
      Based on the KDE HTML viewer, the man pager simply calls man(1) and converts roff output to internal format. It converts man page references to hyperlinks.  It won't convert correctly on all systems outside of Linux, and it doesn't remove page headers and footers.  Its Texinfo viewer is based on compiled info, so the formatting is limited to fixed-width fonts.  Why use it instead? Agoraphobics can run an HTML browser within the same system, though it falls short of Netscape. with a uniform look. --> 

tkinfo - GNU info 
      Why use it instead? Smaller and so may be more appropriate for a system's add-on help viewer, installation's a snap, runs on Macintosh  and Microsoft Windows (though who uses Texinfo there?), widely recommended.  

Refer to http://math-www.uni-paderborn.de/~axel/tkinfo/ for a description of many more Texinfo viewers. 


Author

Copyright (C) 1994-2003  Thomas A. Phelps 
initial prototype developed in 1993 at the
 University of California, Berkeley
 Computer Science Division 


More Information

 My article "TkMan: A Man Born Again" appears in the now defunct X Resource, issue 10, pages 33--46.  Here are the section titles: Introduction, Availability, The User Interface, Navigating among Man Pages, Inspecting Individual Man Pages, Customization, Logical Volumes with tkmandesc, Persistency, The RosettaMan Filter, Extensions, Problems, Future Work, Acknowledgements, Bibliography. 

Two Years with TkMan, a retrospective paper that uses TkMan as an example for various techniques for writing faster and more robust Tcl/Tk programs, was named Best Paper of the 1995 Tcl/Tk Workshop. A Berkeley Computer Science Division technical report (CSD-94-802) is a version of the X Resource article before it was butchered by the editor.

Help page last revised on $Date: 1999/08/24 23:12:29 $
}
foreach qq {{h1 1.0 1.38} {tt 10.45 10.73} {sc 12.262 12.269} {tt 12.393 12.401} {tt 12.439 12.444} {tt 12.537 12.551} {h1 15.0 15.8} {sc 17.0 17.741} {h1 20.0 20.12} {i 23.15 23.31} {manref 25.40 25.43} {manref 25.48 25.52} {manref 25.458 25.465} {sc 27.534 27.536} {tt 29.432 29.442} {diffa 34.86 34.106} {diffd 34.108 34.131} {diffc 34.133 34.156} {tt 45.17 45.24} {sc 45.80 45.87} {h1 50.0 50.11} {i 52.26 52.31} {i 52.119 52.124} {h2 55.0 55.19} {tt 57.139 57.145} {tt 57.159 57.162} {tt 57.233 57.234} {i 57.234 57.235} {tt 57.239 57.240} {i 57.240 57.241} {tt 57.241 57.242} {i 57.250 57.251} {tt 57.346 57.352} {tt 57.646 57.647} {tt 57.679 57.680} {tt 57.745 57.746} {tt 57.750 57.751} {manref 57.809 57.817} {manref 57.855 57.865} {manref 57.1030 57.1036} {manref 57.1082 57.1086} {tt 57.1299 57.1302} {tt 57.1321 57.1324} {i 57.1325 57.1332} {i 57.1333 57.1337} {tt 57.1506 57.1507} {tt 57.1583 57.1591} {tt 57.1641 57.1644} {i 59.336 59.398} {sc 61.71 61.78} {tt 61.197 61.200} {tt 61.202 61.205} {tt 61.207 61.210} {tt 61.214 61.218} {sc 61.284 61.291} {tt 61.345 61.351} {manref 61.368 61.371} {tt 61.420 61.424} {tt 61.454 61.464} {tt 61.509 61.536} {sc 61.627 61.634} {tt 61.800 61.803} {tt 63.0 63.7} {tt 63.96 63.99} {tt 63.128 63.135} {tt 63.151 63.158} {tt 63.176 63.180} {tt 63.185 63.189} {tt 63.304 63.320} {tt 63.428 63.429} {i 63.679 63.682} {tt 65.40 65.43} {tt 65.62 65.71} {tt 65.87 65.94} {tt 65.96 65.111} {tt 65.204 65.211} {tt 65.214 65.216} {i 65.686 65.689} {i 65.731 65.734} {tt 65.798 65.805} {tt 65.823 65.834} {tt 65.836 65.842} {tt 65.847 65.850} {tt 65.921 65.928} {tt 65.1065 65.1077} {tt 65.1095 65.1103} {i 65.1177 65.1181} {i 65.1245 65.1249} {tt 65.1286 65.1294} {tt 65.1318 65.1321} {tt 65.1354 65.1357} {tt 65.1365 65.1367} {tt 65.1400 65.1403} {tt 65.1502 65.1521} {manref 65.1536 65.1543} {i 65.1618 65.1624} {tt 65.1879 65.1886} {tt 67.4 67.9} {tt 67.28 67.31} {tt 67.75 67.78} {sc 67.176 67.183} {sc 67.520 67.527} {tt 67.561 67.568} {tt 69.489 69.496} {tt 69.501 69.508} {tt 69.543 69.565} {tt 69.808 69.811} {tt 71.283 71.284} {tt 71.285 71.286} {tt 71.287 71.288} {tt 71.448 71.449} {tt 71.467 71.468} {tt 73.55 73.60} {tt 73.268 73.269} {tt 73.277 73.287} {tt 73.333 73.334} {tt 73.358 73.375} {tt 73.381 73.407} {tt 73.442 73.443} {tt 73.643 73.644} {tt 73.646 73.648} {tt 73.650 73.651} {tt 73.656 73.657} {tt 73.772 73.778} {tt 73.895 73.899} {h2 76.0 76.25} {i 78.447 78.455} {tt 78.772 78.775} {manref 78.953 78.959} {i 78.999 78.1007} {tt 78.1013 78.1021} {sc 80.298 80.306} {tt 82.212 82.214} {tt 82.383 82.385} {tt 82.399 82.400} {tt 82.547 82.549} {tt 82.563 82.564} {tt 82.751 82.752} {tt 84.509 84.547} {tt 86.1536 86.1541} {tt 88.126 88.131} {tt 88.136 88.139} {tt 88.162 88.165} {tt 88.176 88.182} {tt 88.256 88.258} {tt 88.291 88.294} {tt 88.299 88.302} {tt 88.346 88.349} {tt 88.354 88.357} {tt 88.410 88.413} {tt 88.434 88.437} {tt 88.665 88.672} {tt 88.743 88.746} {tt 88.820 88.823} {tt 90.0 90.3} {tt 90.214 90.217} {tt 90.317 90.320} {tt 90.361 90.364} {tt 90.379 90.382} {tt 90.407 90.413} {tt 90.417 90.420} {tt 90.564 90.567} {manref 94.83 94.89} {tt 94.124 94.130} {tt 94.434 94.437} {tt 94.497 94.500} {tt 98.4 98.7} {tt 98.129 98.138} {h2 101.0 101.14} {tt 103.30 103.33} {tt 103.126 103.130} {tt 103.211 103.221} {tt 103.479 103.495} {tt 103.636 103.644} {sc 103.796 103.801} {tt 103.960 103.969} {tt 105.8 105.12} {sc 105.529 105.537} {tt 107.245 107.261} {sc 107.294 107.301} {tt 107.328 107.335} {sc 107.394 107.401} {tt 107.415 107.439} {tt 109.20 109.24} {tt 109.181 109.207} {tt 109.209 109.227} {tt 111.42 111.46} {tt 111.194 111.198} {tt 111.327 111.331} {tt 111.361 111.364} {h2 114.0 114.14} {i 116.58 116.69} {i 116.75 116.79} {manref 116.129 116.133} {manref 116.135 116.140} {manref 116.142 116.148} {tt 116.150 116.196} {tt 122.117 122.137} {tt 122.142 122.165} {tt 122.213 122.222} {tt 122.395 122.404} {tt 122.451 122.454} {i 122.505 122.509} {i 122.528 122.534} {tt 122.559 122.568} {tt 122.1092 122.1097} {tt 122.1101 122.1109} {tt 122.1176 122.1185} {tt 122.1589 122.1617} {manref 124.15 124.21} {i 124.277 124.311} {tt 124.636 124.642} {tt 124.671 124.674} {tt 124.736 124.743} {tt 124.759 124.763} {tt 124.822 124.826} {tt 126.28 126.34} {tt 126.36 126.50} {tt 126.52 126.58} {tt 126.60 126.67} {h2 129.0 129.19} {diffa 131.136 131.145} {diffd 131.147 131.156} {diffc 131.159 131.166} {tt 131.313 131.317} {sc 131.571 131.584} {tt 131.815 131.825} {diffa 131.960 131.967} {diffc 131.969 131.981} {diffd 131.987 131.997} {i 133.374 133.384} {manref 133.407 133.410} {tt 133.413 133.415} {tt 133.420 133.422} {b 133.612 133.618} {tt 133.641 133.657} {b 133.734 133.739} {tt 133.754 133.775} {tt 135.279 135.329} {tt 135.405 135.412} {tt 135.508 135.516} {i 135.516 135.517} {tt 135.528 135.536} {i 135.536 135.537} {manref 139.67 139.72} {tt 139.99 139.104} {tt 143.85 143.92} {tt 143.165 143.177} {h2 146.0 146.11} {tt 148.4 148.18} {tt 148.67 148.70} {tt 148.318 148.323} {tt 148.391 148.393} {tt 148.442 148.448} {tt 148.551 148.559} {b 150.22 150.27} {tt 150.166 150.175} {tt 150.301 150.313} {tt 150.724 150.736} {b 152.0 152.6} {tt 152.222 152.228} {b 154.4 154.7} {tt 154.236 154.243} {i 154.243 154.244} {b 156.44 156.51} {tt 156.326 156.343} {i 156.533 156.582} {tt 158.509 158.514} {tt 158.578 158.586} {tt 158.702 158.708} {tt 158.802 158.810} {tt 158.1325 158.1335} {tt 160.351 160.358} {sc 160.602 160.606} {sc 160.645 160.656} {manref 160.752 160.762} {manref 160.765 160.774} {manref 160.776 160.785} {manref 160.793 160.800} {manref 160.811 160.818} {manref 160.820 160.829} {manref 160.834 160.839} {tt 164.40 164.45} {tt 164.93 164.98} {tt 164.115 164.147} {b 164.155 164.163} {tt 164.175 164.180} {tt 164.316 164.329} {manref 164.670 164.675} {i 164.895 164.896} {tt 164.928 164.939} {i 164.939 164.945} {tt 164.945 164.946} {i 164.946 164.947} {tt 164.1329 164.1340} {tt 164.1454 164.1468} {tt 166.9 166.17} {i 166.100 166.101} {i 166.346 166.347} {i 166.355 166.357} {i 166.361 166.364} {tt 166.455 166.458} {tt 166.517 166.521} {tt 166.559 166.567} {b 172.4 172.10} {tt 172.198 172.222} {tt 172.233 172.242} {tt 172.390 172.399} {b 174.0 174.4} {tt 174.110 174.143} {i 176.97 176.100} {tt 176.236 176.244} {h1 179.0 179.17} {tt 183.149 183.153} {tt 187.152 187.160} {tt 187.219 187.224} {tt 187.301 187.309} {tt 187.366 187.370} {tt 187.426 187.434} {tt 187.678 187.686} {tt 189.71 189.72} {tt 191.4 191.12} {b 191.143 191.159} {tt 191.173 191.184} {tt 191.235 191.249} {tt 191.296 191.310} {i 191.408 191.411} {i 191.435 191.438} {tt 192.0 192.59} {tt 194.91 194.99} {tt 194.111 194.138} {b 196.81 196.85} {b 196.115 196.123} {tt 197.0 197.20} {tt 198.0 198.25} {manref 201.35 201.40} {manref 201.79 201.86} {manref 201.170 201.177} {manref 201.210 201.217} {h2 206.0 206.11} {tt 209.121 209.124} {tt 209.132 209.140} {manref 209.198 209.204} {manref 209.209 209.216} {sc 212.25 212.28} {sc 212.98 212.101} {sc 212.160 212.171} {sc 212.197 212.200} {sc 215.37 215.42} {sc 215.187 215.192} {tt 215.360 215.371} {h2 219.0 219.20} {tt 221.0 221.7} {i 221.7 221.12} {tt 222.12 222.12} {i 222.12 222.17} {tt 224.0 224.10} {i 224.10 224.17} {tt 225.179 225.183} {tt 227.0 227.8} {tt 227.13 227.23} {tt 230.0 230.10} {i 230.10 230.14} {tt 231.10 231.10} {i 231.10 231.14} {tt 233.0 233.12} {i 233.12 233.23} {tt 233.28 233.38} {i 233.38 233.49} {tt 236.0 236.26} {tt 237.44 237.63} {tt 239.0 239.5} {i 239.5 239.10} {i 240.10 240.15} {sc 240.16 240.19} {tt 242.0 242.6} {tt 242.10 242.18} {tt 245.0 245.9} {i 245.9 245.17} {tt 246.10 246.10} {i 246.10 246.18} {tt 246.31 246.39} {tt 248.0 248.10} {tt 248.15 248.27} {tt 249.45 249.53} {tt 249.74 249.78} {tt 249.88 249.94} {tt 249.117 249.121} {tt 251.0 251.2} {tt 254.0 254.3} {i 254.3 254.12} {tt 255.4 255.8} {i 255.8 255.17} {tt 256.4 256.8} {i 256.8 256.17} {tt 257.14 257.17} {tt 257.117 257.120} {tt 257.133 257.136} {tt 259.0 259.6} {h2 263.0 263.12} {tt 265.61 265.63} {tt 265.73 265.81} {manref 265.134 265.142} {tt 265.169 265.180} {tt 265.249 265.250} {tt 265.263 265.264} {tt 265.276 265.277} {tt 265.449 265.477} {tt 265.529 265.548} {tt 265.722 265.749} {h2 268.0 268.9} {tt 270.5 270.9} {tt 270.110 270.114} {sc 272.75 272.82} {sc 272.195 272.202} {tt 272.236 272.244} {manref 274.177 274.187} {manref 274.189 274.199} {manref 274.201 274.210} {manref 274.212 274.223} {manref 274.246 274.255} {tt 274.257 274.262} {tt 274.417 274.434} {tt 274.442 274.449} {h3 279.0 279.8} {b 281.27 281.35} {tt 281.48 281.56} {tt 284.0 284.15} {tt 285.186 285.200} {tt 288.0 288.16} {i 288.16 288.45} {tt 289.4 289.20} {i 289.20 289.49} {tt 290.4 290.20} {i 290.20 290.49} {i 290.57 290.68} {tt 291.4 291.20} {i 291.20 291.49} {i 291.56 291.67} {tt 295.0 295.12} {i 295.12 295.21} {i 295.22 295.29} {i 295.30 295.47} {tt 296.0 296.12} {i 296.12 296.21} {i 296.22 296.29} {i 296.30 296.47} {tt 297.0 297.14} {i 297.14 297.23} {i 297.24 297.41} {tt 298.0 298.11} {i 298.11 298.18} {i 298.19 298.27} {i 300.4 300.21} {sc 300.110 300.117} {tt 300.171 300.184} {tt 300.192 300.200} {sc 300.223 300.230} {tt 300.235 300.239} {i 300.266 300.275} {i 300.280 300.287} {tt 300.343 300.344} {tt 300.348 300.350} {tt 300.353 300.354} {tt 302.24 302.34} {tt 304.293 304.305} {tt 304.309 304.324} {tt 304.478 304.482} {tt 304.629 304.643} {tt 306.40 306.51} {h3 309.0 309.8} {tt 311.162 311.170} {tt 312.0 312.46} {tt 313.0 313.21} {tt 316.0 316.54} {tt 317.0 317.21} {tt 320.0 320.46} {tt 321.0 321.51} {tt 324.0 324.60} {tt 325.0 325.24} {tt 326.0 326.22} {tt 329.0 329.41} {tt 330.0 330.45} {tt 331.0 331.21} {tt 332.0 332.18} {tt 335.0 335.25} {tt 335.69 335.75} {tt 338.0 338.25} {h3 341.0 341.26} {tt 343.48 343.52} {tt 343.244 343.248} {tt 343.670 343.678} {tt 345.77 345.85} {tt 345.181 345.188} {tt 345.305 345.329} {h1 348.0 348.25} {i 350.215 350.220} {sc 352.40 352.47} {sc 352.337 352.341} {i 352.528 352.532} {i 352.533 352.547} {tt 362.86 362.92} {tt 372.46 372.61} {tt 375.5 375.21} {tt 380.5 380.20} {tt 380.24 380.43} {tt 385.34 385.36} {tt 386.5 386.18} {tt 393.33 393.44} {i 396.16 396.26} {sc 399.50 399.57} {sc 399.90 399.97} {tt 401.95 401.103} {sc 401.118 401.125} {tt 401.353 401.361} {sc 401.380 401.384} {sc 403.523 403.530} {sc 403.535 403.539} {sc 403.727 403.734} {sc 403.819 403.826} {sc 403.1032 403.1039} {sc 403.1225 403.1229} {h2 406.0 406.26} {sc 410.124 410.131} {sc 410.224 410.228} {sc 410.300 410.304} {tt 410.414 410.419} {tt 410.435 410.438} {tt 411.64 411.71} {sc 411.122 411.129} {tt 411.284 411.291} {h1 414.0 414.7} {sc 416.19 416.26} {tt 416.192 416.199} {tt 416.432 416.439} {h1 419.0 419.11} {i 421.11 421.22} {manref 421.96 421.102} {i 421.105 421.116} {manref 421.125 421.129} {i 421.415 421.426} {tt 421.843 421.903} {h1 424.0 424.26} {tt 426.647 426.673} {i 428.15 428.22} {i 428.76 428.80} {i 428.180 428.183} {i 433.107 433.126} {i 436.7 436.26} {manref 439.63 439.69} {i 439.370 439.389} {i 442.6 442.25} {tt 444.9 444.55} {h1 447.0 447.6} {h1 455.0 455.16} {i 457.65 457.75} {i 459.0 459.20} {i 459.286 459.296} {tt 459.402 459.438} } {
	eval $t tag add $qq
}

foreach qq {{abstract 15.0} {introduction1 20.0} {using1 50.0} {locating2 55.0} {working2 76.0} {other2 101.0} {texinfo2 114.0} {version2 129.0} {preferences2 146.0} {customizing1 179.0} {environment2 206.0} {command2 219.0} {key2 263.0} {tkmandesc2 268.0} {platspec1 348.0} {multios2 406.0} {retkman1 414.0} {polyglotman1 419.0} {other1 424.0} {author1 447.0} {more1 455.0} } {
	eval $t mark set $qq
}

