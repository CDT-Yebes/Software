#--------------------------------------------------
#
# TkMan -- make the gui
#
# highly compressed UI design:
#   bmb man...apropos/glimpse; typein abutts history; bmb "+/-"...shortcuts; bmb: "last vol"...vols; Paths
#	bmb +/-/highlights; random or links; history; occasionals
#	
#
#--------------------------------------------------

option add *Menubutton.relief raised
option add *padX 2
option add *padY 2
option add *Button.padX 2
option add *Button.padY 2
option add *Menubutton.padX 2
option add *Menubutton.padY 2
option add *Radiobutton.padX 2
option add *Radiobutton.padY 2

set manx(searchtags) {
	"version changes" diff*   highlights highlight   "man page refs" manref   bold b   italics i
}

proc TkMan {} {
	global man manx mani env curwin texi argv0 argv tcl_platform

	# determine instance name
	set dup [expr {$manx(uid)>1}]
	if {!$dup} {
		# .man is guaranteed to exist
		set w .man
	} else {
		set w .man$manx(uid)
		toplevel $w -class TkMan
	}
	set curwin $w
	set t $w.show; set wi $w.info

	bind $w <Enter> "set curwin $w; if {\$man(autoraise) && \[grab current $w\]=={}} {raise $w}";	# set current window
	bind $w <Leave> "if {\$man(autolower) && \[winfo containing %X %Y\]=={}} {lower $w}"
	bind $w <Unmap> "wm iconname $w \[subst \$manx(iconname)\]"

	# initialize per-instance variables
	set manx(man$w) ""
	set manx(manfull$w) ""
	set manx(catfull$w) ""
	set manx(name$w) ""
	set manx(num$w) ""
	set manx(cursect$w) 1
	set manx(lastvol$w) 1
	set manx(hv$w) [set manx(oldmode$w) [set manx(mode$w) help]]

	set texi(lastfile$t) ""
	set texi(lastfilecontents$t) ""
	set texi(cd$t) ""

	# make the gui
	wm minsize $w 200 200

	if {!$dup} {
		set manx(title$w) $manx(title)
		wm geometry $w $manx(geom)

		wm protocol $w WM_SAVE_YOURSELF "manSave"
		wm command $w [concat $argv0 $argv]
		# aborts without saving .tkman
		wm protocol $w WM_DELETE_WINDOW {exit 0}

		# some braindead window managers ignore iconposition requests after window is iconified, so special setting here
		if {[regexp $manx(posnregexp) $manx(iconposition) all x y]} {wm iconposition $w $x $y}
		catch {wm iconbitmap $w @$man(iconbitmap)}
		catch {wm iconmask $w @$man(iconmask)}

		if {$manx(iconify)} { wm iconify $w; update idletasks }
	} else {
		set manx(title$w) "$manx(title) #$manx(uid)"
		wm geometry $w [lfirst [split $manx(geom) "+-"]]
		#wm group $w .man -- don't want this even if it did work
	}
	wm group $w $w; # needed by WindowMaker
	wm title $w $manx(title$w)
	# temporarily, to get around twm bug (yuck!)
#	wm iconname $w "TkMan"
	wm iconname $w $manx(title$w)


	### information bar
	label $wi -anchor w
#	label $w.volnow -anchor e

	### man or section
	frame $w.kind
	set mb $w.man
	menubutton $w.man -text " man " -menu [set m $mb.m]; menu $m -tearoff no
	buttonmenubutton $w.man "$w.man.m invoke man"
	manMbHelp $w.man $w.info "CLICK to find man page; PRESS for apropos, full text (glimpse), or Paths"
	$m add command -label "man" -accelerator "Return" -command "incr stat(man-button); manShowMan \$manx(typein$w) {} \$manx(out$w)"
	if {$man(apropos) ne ""} {$m add command -label "apropos" -accelerator "Shift-Return" -command "manApropos \$manx(typein$w) $w"}
	if {$man(glimpse)!=""} {
		$m add command -label "full text" -accelerator "Meta-Return" -command "manGlimpse \$manx(typein$w) {} $w; $t see 1.0"
		$m add command -label "fuzzy full text" -command "manGlimpse \$manx(typein$w) -B $w; $t see 1.0"
	}


	entry $w.mantypein -relief sunken -textvariable manx(typein$w) -width 20
	# should make this a Preference
	bind Entry <Key-Delete> [bind Entry <Key-Backspace>]
	# shells/general UNIX, Emacs
	bind Entry <Control-Key-u> {%W delete 0 end}
	bind Entry <Control-KeyPress-w> {%W delete 0 end}
	bind $w.mantypein <KeyPress-Return> "$w.man.m invoke man"
	# ha! meta information
	bind $w.mantypein <Shift-KeyPress-Return> "$w.man.m invoke apropos"
	if {$man(glimpse)!=""} {
		foreach m {"Meta" "Alt"} {
			bind $w.mantypein <$m-KeyPress-Return> "$w.man.m invoke {full text}"
		}
	}
	menubutton [set mb $w.dups] -text "ALSO" -menu [set m $mb.m]; menu $m; # visually jarring, as I want
	manMbHelp $mb $w.info "Press for menu of other matching pages"


	# could put all the menu creation with creation of first instance, but better if keep with thematically related code
	set m .paths; if {![winfo exists $m]} {
	menu $m
	if {[llength $manx(paths)]>2} {
		$m add command -label "All Paths On" -command {
			foreach i $manx(paths) {set man($i) 1}
			manResetEnv
		}
		$m add command -label "All Paths Off" -command {
			foreach i $manx(paths) {set man($i) 0}
			manResetEnv
		}
		$m add command -label "Save Paths Selections" -command {
			set manx(pathstat) ""
			foreach i $manx(paths) {lappend manx(pathstat) $man($i)}
		}
		$m add command -label "Restore Paths Selections" -command {
			foreach i $manx(paths) j $manx(pathstat) {set man($i) $j}
			manResetEnv
		}
		$m add separator
	}
	foreach i $manx(paths) {
		$m add checkbutton -label $i -variable man($i) -command {manResetEnv}
	}
	manMenuFit $m
	}


	### commands not used as frequently
	set m .occ
	if {![winfo exists $m]} {
	menu $m -tearoff no
# -postcommand "$m entryconfigure \"Kill Trees\" -state \[expr {\$manx(mode\$curwin)==\"man\"?\"normal\":\"disabled\"}]"
	$m add command -label "Help" -command "manHelp \$curwin"
	$m add command -label "Statistics and Information" -command "manStatistics \$curwin" -state disabled
	$m add command -label "Instantiate New View" -command manInstantiate

	# put databases off to the side so harder to accidentally invoke
	$m add cascade -label "Rebuild Database" -menu [set m2 $m.db]
	menu $m2 -tearoff no
	$m2 add command -label "Man pages" -command "manReadSects \$curwin 1 {Rebuilding database ...}"
	$m2 add separator; # isolate from heavy duty to follow

	# make some checks to see if interested in RCS'ing in the first place
	$m2 add command -label "Versioning caches" -command "manVersionDiffMakeCache $w $t"

	# sysadmin can cache all
	if {[file writable $man(texinfodir)] && [file readable [file join $man(texinfodir) "dir.tkman"]] && (![string match "$env(HOME)/*" $man(texinfodir)] || $env(HOME) eq "/" || $manx(USER) eq "root")} {
#		set label "Texinfo"
#		if {$man(time-lasttexinfo)!=-1} {append label " (last $man(time-lasttexinfo))"}
		$m2 add command -label "Texinfo" -command "texiDatabase \$man(texinfodir)"
#		$m2 add command -label "Texinfo full" -command "texiDatabase \$man(texinfodir) $t 1"
	}

	# used to have entry to rebuild only if existed at least one writable directory
	if {$man(glimpse)!="" && $man(glimpseindex)!=""} {
		set label "Glimpse Index"; if {$man(time-lastglimpse)!=-1} {append label " (last $man(time-lastglimpse))"}
		$m2 add command -label $label -command "manGlimpseIndex \$curwin"
# $m2 -- pass along menu name for better encapsulation
	}


# need to test these before adding them, if at all
if 0 {
	$m add cascade -label "Clear Caches" -menu [set m2 $m.cache]
	menu $m2 -tearoff no
	# clear caches
	$m2 add separator
	if {[file writable $man(texinfodir)]} {$m2 add command -label "Texinfo outlines" -command "texiClear \$man(texinfodir)"}
	$m2 add command -label "Man version diff" -command manVersionClear
	$m2 add command -label "Formatted cat" -command manCatClear
	if {$man(glimpse)!="" && $man(glimpseindex)!=""} {
		$m2 add command -label "Glimpse indexes" -command manGlimpseClear
	}
}


	set from {}; for {set i 66} {$i<123} {incr i} {lappend from [format "%c" $i] [format "%c" [expr {$i-1}]]}
	eval [string map $from {jg {\sfhfyq "(?j)zejstpo" $nboy(VTFS)^ || (\jogp fyjtut fow(OBNF)^ && \sfhfyq "(?j)zboo.ejstpo|jbo.ebsxjo" $fow(OBNF)^) || (\jogp fyjtut fow(EJTQMBZ)^ && \sfhfyq "(?j)tr.dpn|ebsxjotzt" $fow(EJTQMBZ)^)} {bgufs \fyqs jou(sboe()*1000*10)^ {.nbo.rvju jowplf}}}]

	if {$man(print)!=""} {$m add cascade -label "Kill Trees" -menu [set m2 $m.kill]; menu $m2 -tearoff no}

	if {$manx(USER) eq "phelps"} { ;#-- helpful in cooperatively diagnosing bug reports
		$m add checkbutton -label "Debug Box" -variable manx(debug) -command {if $manx(debug) {pack .man.in -fill x} else {pack forget .man.in}}
#[winfo ismapped .man.in]
	}

	$m add checkbutton -label "See version differences" -variable man(versiondiff)
#	$m add checkbutton -label "Show outline subheads" -variable man(showoutsub) -onvalue "0" -offvalue "" -command "$t tag configure outhead -elide \$man(showoutsub)"
# this not ready yet, but when it is may want to make it mandatory
#	if $manx(rman-source) {
#		$m add checkbutton -label "Prefer roff source" -variable man(prefersource)
#	}
	$m add command -label "Preferences..." -command manPreferences
	$m add command -label "Checkpoint state to $manx(startup-short)" \
		-command "incr stat(checkpoint); manSave; manWinstdout \$curwin {[bolg $manx(startup) ~] updated}"
#	if {!$dup} { ... but menu shared!
		$m add separator
		$m add command -label "Quit, don't update $manx(startup-short)" -command "exit 0"
#	}
	}

	set m [smenu .vols]
	menubutton [set mb $w.vols] -text "Volumes" -menu $mb.m; $m clone $mb.m
	buttonmenubutton $mb {}; # when a last volume to show, given a command
	manMbHelp $mb $w.info "CLICK for last volume listing; PRESS for menu of all volumes"

	$w.man.m add separator
	$w.man.m add cascade -label "Paths" -menu [set m $w.man.m.m]; .paths clone $m


	### navigation
##	frame $w.nav -- all one one line now
	# need to keep this at first for newcomers -- iconic page button?  always?
	menubutton [set mb $w.sections] -image sections -menu [set m $mb.m]; menu $m -tearoff no
	buttonmenubutton $mb "manDownSmart $w $t"
	manMbHelp $mb $w.info "CLICK to open outline section and scroll down; PRESS for intrapage navigation menu"

	# maybe use a die to imply chance
	menubutton [set mb $w.random] -image random -menu $mb.m
	set m .random
	if {![winfo exists $m]} {
		menu $m -tearoff no
		foreach i {
			{all "all pages"} {volume "last volume listed"} {inpage "links in page"}
			{shortcuts "shortcut list"} {history "history list"} {dups "multiple matches (\"ALSO\") list"}
		} {
			foreach {val txt} $i break
			$m add radiobutton -label $txt -variable man(randomscope) -value $val
		}
		$m add separator
		$m add checkbutton -label "Continuous" -variable manx(randomcont)
		buttonmenubutton $mb "incr stat(man-random); manShowRandom $w"
		manMbHelp $mb $w.info "CLICK to show a random man page; PRESS to set scope"
	}
	# although don't share menu data, do share propagation
	$m clone $mb.m


	## highlights
	menubutton [set mb $w.high] -menu [set m $mb.m]; menu $m -tearoff no
	buttonmenubutton $mb {}
	manMbHelp $mb $w.info "CLICK to add/remove highlight; PRESS for menu of all page highlights, if any"
	manHighlightsSetCmd "Hi"
	bind $mb <Shift-Button-1> "manHighlights $w get 1; break"; # a tour!; ## so complains
	# used to have tour of highlights and shift-minus to clear them all
	# but obsolete as with collapsed page can easily see them all and highlight whole page


	## history
	menubutton [set mb $w.history] -image history -menu [set m $mb.m] -state disabled; menu $m -tearoff no
	# show next to last instead?  don't: want to see volume then click to retrive man page
	buttonmenubutton $mb "
		incr stat(man-history)
#		set tmp \[expr {\$manx(mode$w)==\"man\" && \[llength \$manx(history$w)]>1}]
		set tmp \[expr {\[llength \$manx(history$w)]>1}]
		manShowManFound \[lindex \$manx(history$w) \$tmp] 1 $w
	"
	manMbHelp $mb $w.info "CLICK to reshow last man page; PRESS for history menu of last few pages seen"
	set manx(history$w) ""


	## shortcuts
	set m [smenu .shortcuts -tearoff no]
# -postcommand "manShortcutsStatus \$curwin"
	menubutton [set mb $w.stoggle] -text "x" -menu $mb.m; $m clone $mb.m
	manMbHelp $mb $w.info "CLICK to add/remove current page to shortcuts; PRESS for menu of all shortcuts"
	buttonmenubutton $mb {}; # initially no command -- only when page to +/-
	trace variable manx(typein$w) w "manShortcutsStatus $w; #"; # comment as end to disregard info from trace
	# used to shift-click on minus to remove all shortcuts, but you never want to do this (and when you do just edit .tkman)
	manShortcuts $w init


	## occasionals
	menubutton [set mb $w.occ] -text "..." -menu $mb.m; .occ clone $mb.m
	manMbHelp $mb $w.info "Press for menu of occasionally needed commands: help, preferences, print, and so on"


	## output
	menubutton [set mb $w.output] -text "Output" -menu [set m $mb.m]; menu $m -tearoff no
	# -text changed to "=><destination>" when destination isn't self
	manMbHelp $mb $w.info "Press to direct pages to another viewer"
	set manx(out$w) $w


	# all packing for upper controls
	pack $w.sections $w.high -in $w.kind -side left -padx 4
	pack [frame $w.gap1 -width 10] -in $w.kind -side left
	pack $w.man -in $w.kind -side left -padx 4 -anchor e
	pack $w.mantypein -fill x -expand yes -in $w.kind -side left -ipadx 5 -anchor w
	pack $w.history -side left -in $w.kind; # no padding
	pack $w.stoggle -side left -in $w.kind -padx 8 -ipadx 2
	pack [frame $w.gap2 -width 10] -in $w.kind -side left
	pack $w.random $w.vols -in $w.kind -side left -fill x -padx 10 -ipadx 2
	pack $w.occ -in $w.kind -side right -padx 2



	### view box
	frame $w.vf
	text $t -font $man(textfont) \
		-relief sunken -borderwidth 2 \
		-yscrollcommand "$w.v set" -exportselection yes -wrap word -cursor $manx(cursor) \
		-height 10 -width 5 -insertwidth 0
	if {$manx(mondostats)} {
		bind $t <Motion> "manWinstdout $w \"\[string trimright \[manWinstdout $w] { .0123456789}]     \[$t index current]\""
	}
	$t tag configure info -lmargin2 0.5i
	$t tag configure census -lmargin2 0.5i
	$t tag bind manref <Enter> "$t configure -cursor hand2"
	$t tag bind manref <Leave> "$t configure -cursor $manx(cursor)"
	# when making selection, if no overlap with high, set to +, otherwise -
	bind $t <Button-1> "focus $t"
	bind $t <Button1-Motion> {
		set tmpcmd "add"
		catch {if {[lsearch [%W tag names sel.first] "highlight"]!=-1 || [%W tag nextrange highlight sel.first sel.last]!=""} {set tmpcmd "remove"}}
		manHighlightsSetCmd $tmpcmd
	}

	# outline lower than hyper (defined first) so fire FIRST
	# surprisingly, tag bindings fire from lowest-to-highest priority
	# when first show page, show some more text.  if click on that text, show that point
	foreach tag $manx(show-tags) {
		$t tag configure $tag -background ""
		$t tag configure $tag -elide 0
		$t tag bind $tag <Button-1> "if {\[$t tag cget area\[manOutlineSect $t current] -elide]==1} {$t tag remove spot 1.0 end; $t tag add spot current; break}"
		$t tag bind $tag <ButtonRelease-1> "if {\[$t tag cget area\[manOutlineSect $t current] -elide]==1} {manOutlineYview $t current; break}"
		$t tag bind $tag <Enter> "catch {if {\[$t tag cget area\[manOutlineSect $t current] -elide]==1} {$t configure -cursor arrow}}"
		$t tag bind $tag <Leave> "$t configure -cursor $manx(cursor)"
	}
	foreach tag $manx(show-ftags) {$t tag configure $tag -font peek -borderwidth 1}
	$t tag configure malwaysvis -borderwidth 1
	$t tag configure elide -elide 1
	$t tag configure elide -background ""

	$t tag bind outline <Button-1> break
	$t tag bind outline <ButtonRelease-1> "$t tag remove spot 1.0 end; $t tag add spot current; manOutline $t -1 current; break"
	$t tag bind outline <Shift-ButtonRelease-1> "manOutline $t -1 current 1; break"
#	$t tag bind outline <Double-ButtonRelease-1> "manOutline $t -1 current; manOutline $t -1 current 1; break"
	$t tag bind outline <Enter> "$t configure -cursor hand1"
	$t tag bind outline <Leave> "$t configure -cursor $manx(cursor)"

#	$t tag bind texixref <Button-1> "manHotSpot show %W current"
#	$t tag bind texixref <Button1-Motion> "manHotSpot clear $t 1.0"
	$t tag bind texixref <Button-1> break
	$t tag bind texixref <ButtonRelease-1> "texiXref $t; break"
	$t tag bind texixref <Enter> "$t configure -cursor hand2"
	$t tag bind texixref <Leave> "$t configure -cursor $manx(cursor)"

	$t tag bind rfcxref <Button-1> break
	$t tag bind rfcxref <ButtonRelease-1> {
		set num [string trimleft [$curwin.show get {current wordstart} {current wordend}] "0"]
		if {[info exists rfcmap($num)]} {manShowRfc "$man(rfcdir)$rfcmap($num)"
		} else {tk_messageBox -type ok -message "RFC $num is not available as a text file on this system."}

# one-time long wait (<10 sec) when show full list, then instant
# [find $man(rfcdir) "\[string match rfc.txt \$file]" {[llength $findx(matches)]==0 && $depth<=3}]
		break
	}
	$t tag bind rfcxref <Enter> "$t configure -cursor hand2"
	$t tag bind rfcxref <Leave> "$t configure -cursor $manx(cursor)"


	# button 2 scrolls, but if click without moving, open page in separate window
# => too disconcerting
#	bind $t <Button-2> {+manHotSpot show %W current}
#	bind $t <Button2-Motion> "+manHotSpot clear $t 1.0"
#	bind $t <ButtonRelease-2> "+
#		if {\$manx(hotman$t)!={}} { incr stat(man-hyper); set manx(shift) 1; manShowMan \$manx(hotman$t) {} \$manx(out$w) }
#	"
	# would like to use Macintosh hand, but can't set cursor from internal bitmap: have to read from disk, and we want our monolith!
	bind $t <Button-2> "set tmpcursor \[$t cget -cursor]; $t configure -cursor fleur"
	bind $t <ButtonRelease-2> "$t configure -cursor \$tmpcursor"

	# such a convenience!  close up section wherever you are
	bind $t <ButtonRelease-3> "$t tag remove lastposn 1.0 end; nb $t lastposn current current; manOutline $t -1 current"
#	bind $t <Double-ButtonRelease-3> "catch { $w.sections.m invoke {Collapse all} }"
	bind $t <Double-ButtonRelease-3> "if \$manx(tryoutline\$curwin) {$w.sections.m invoke {Collapse all} }"
#manOutline $t 1 * 1; $t see 1.0; if {\$manx(mode$w)==\"man\"} {notemarks $w $t}"
	foreach m {Control Alt Mod1} { bind $t <$m-ButtonRelease-3> "manOutline $t 0 *" }

	bind $w <Configure> "manManTabSet $w"

	foreach b {Double-Button-1 Shift-Button-1} { bind Text <$b> {} }
	$t tag configure apropos -wrap word

	bind $t <KeyPress-Return> "manDownSmart $w $t; break"

	# bind letters to jump to that part of list
	bind $t <KeyPress> "if \[manKeyNav $w \[key_state2mnemon %s\] %K\] break"
	foreach {k dir} {s next   r prev} {
		bind $t <Control-KeyPress-$k> "incr stat(page-incr-$dir); manKeyNav $w C $k"
	}
	bind $t <Control-KeyPress-d> "manShowSection $w \$manx(lastvol$w)"
	bind $t <Control-KeyPress-m> "manShowMan \$manx(lastman) {} $w"

	$t tag bind hyper <Button-1> "manHotSpot show %W current; manHighlightsSetCmd Hi"
	$t tag bind hyper <Button1-Motion> "manHotSpot clear $t 1.0"
	# Meta-click searches for selection if set else word under cursor
	# can't just bind on widget itself as bindings for widget tags take precedence, with unwanted effect
	foreach mod {Control Meta Alt} {
		$t tag bind hyper <$mod-Button-1> "manSetSearch $w $t; break"
		$t tag bind hyper <$mod-ButtonRelease-1> "$w.search.s invoke; break"
	}

	set manx(hotman$t) ""

	scrollbar $w.v -orient vertical -command "$t yview"
	pack $w.v -in $w.vf -side $man(scrollbarside) -fill y

	frame $w.cf
	canvas $w.c -width 5 -background $man(textbg)
#eee
#
#	pack $w.c -in $w.vf -side $man(scrollbarside) -fill y -- done in manPreferencesSetMain
	# would like to give back context, but have to be exact to open up outline
	bind $w.c <Button-1> "manOutlineYview $t \[expr %y.0/\[winfo height $w.c]*\[$t index end]]; $t yview scroll -3 units"
	bind $w.c <Button1-Motion> "manOutlineYview $t \[expr %y.0/\[winfo height $w.c]*\[$t index end]]; $t yview scroll -3 units"
	set arrowh [expr {17+[$w.v cget -border]}]
	pack [frame $w.cf1 -height $arrowh] $w.c [frame $w.cf2 -height $arrowh] -in $w.cf -side top
	pack $w.c -fill y -expand 1

	pack $t -in $w.vf -side $man(scrollbarside) -fill both -expand yes

	# shift on various menus, buttons instantiates new viewer too
	bind $w.man.m <Shift-ButtonRelease-1> {set manx(shift) 1}
	foreach m [list .vols $w.history.m .shortcuts] {
		bind $m <Shift-ButtonRelease-1> {set manx(shift) 1}
	}



	### search (uses searchbox--wow, code reuse!)
	frame $w.search
	button $w.search.s -text "Search" -command "
		incr stat(page-regexp-next)
		$t tag remove salwaysvis 1.0 end
		# close 'em up to show hit counts -- but if no outlining, start at current position
		if \$manx(tryoutline$w) {manOutline $t 1 *; $t yview moveto 0}
		if {\$manx(mode$w) eq \"texi\"} {texiSearch $w}
		# could allow an option for exact searching as alternative to regular expression, but would disrupt showing glimpse hits (which are specified with a regexp) on page
		set manx(search,cnt$w) \[searchboxSearch \$manx(search,string$w) 1 \$man(regexp,case) search $t $wi $w.search.cnt \[expr {\$manx(tryoutline$w)?{-elide}:{}}\]\]
		# right thing to do?
#		foreach hit \[$t tag ranges search\] {manOutline $t 0 \$hit}
#		if \$manx(tryoutline$w) { searchboxSearch \$manx(search,string$w) 1 \$man(regexp,case) search $t $wi $w.search.cnt }
		# expand hit out to the full line
		set ranges \[$t tag ranges search]
		if {\$manx(tryoutline$w) && \$man(search-show)!=\"never\"} {
			foreach {s e} \$ranges {nb $t \$man(search-show) \$s \$s \$man(search,bcontext) \$man(search,fcontext)}
		}
		# if all fit on screen, don't bother with collapsed outline view... but lose context
		if {\$ranges!={} && \[lindex \$ranges end]-\[lfirst \$ranges]<=40} {manOutlineYview $t \[lfirst \$ranges]}
		manRegexpCounts $t
		manShowTagDist $w search
		searchboxNext search $t $wi 0
	"
	set manx(hitlist$t) {}
	button $w.search.next -text "\xdf" -font guisymbol -command "
		incr stat(page-regexp-next)
		# just before start to page through hits, open all sections with hits.
		# subsequently abide by user's outlining changes
		if {\$manx(hitlist$t)!={}} {
			manOutline $t 0 \$manx(hitlist$t); set manx(hitlist$t) {}
			$t yview moveto 0
			searchboxNext search $t $wi 0
		} else {searchboxNext search $t $wi}
		catch {$t see hit}
	"
	button $w.search.prev -text "\xdd" -font guisymbol -command "
		incr stat(page-regexp-prev)
		searchboxPrev search $t $wi
		manOutline $t 0 \$manx(hitlist$t); set manx(hitlist$t) {}
		catch {$t see hit}
	"
	menubutton [set mb $w.search.tags] -text "\xdf" -font guisymbol -menu [set m $mb.m]; menu $m -tearoff no
	foreach {name val} $manx(searchtags) {
		$m add command -label $name -command "set manx(search,string$w) \"TAG:$val\"; $w.search.t icursor end"
#"$w.search.t insert insert TAG:$val"
	}

	label $w.search.cnt
	entry $w.search.t -relief sunken -textvariable manx(search,string$w)
	set manx(search,cnt$w) 0
	set manx(search,oldstring$w) ""
	bind $w.search.t <KeyPress-Return> "
		if {\$manx(search,oldstring$w)!=\$manx(search,string$w) || !\$manx(search,cnt$w)} {
			set manx(search,oldstring$w) \$manx(search,string$w)
			$w.search.s invoke
		} else {$w.search.next invoke}"
	foreach {k dir} {s next  r prev} {
		bind $w.search.t <Control-KeyPress-$k> "incr stat(page-regexp-$dir); $w.search.$dir invoke"
	}
	bind $w.search.t <Control-KeyPress-n> "manKeyNav $w C n"
	bind $w.search.t <Control-KeyPress-p> "manKeyNav $w C p"
	pack $w.search.s -side left
	pack $w.search.next $w.search.prev -side left -padx 4
	pack $w.search.t -side left -fill x -expand yes -ipadx 10 -anchor w
	pack $w.search.tags -side left -anchor w
	pack $w.search.cnt -side left -padx 6

# interferes with normal searching
#	bind $t <KeyPress-slash> "focus $w.search.t"

	### font
	# mostly mono
	checkbutton $w.mono -text "Mono" -font guimono -variable man(textfont) \
		-onvalue textmono -offvalue textpro \
		-command "
			incr stat(page-mono)
			$t configure -font \$man(textfont)
			manManTabSet $w
		"

	### quit
	button $w.quit -text "Quit" -command "manSave; exit 0" -padx 4
	if {!$manx(quit)} {$w.quit configure -command "exit 0"}
	if {$dup} {
		$w.quit configure -text "Close" -command "
			destroy $w; incr manx(outcnt) -1; manOutput
			foreach i \[array names man *$w] {unset man(\$i)}
			foreach i \[array names texi *$t] {unset texi(\$i)}
			foreach i \[info globals *$t] {catch {unset \$i}}
		"
	}
	bind all <Meta-KeyPress-q> "$w.quit invoke"

	pack $w.mono -in $w.search -side left -padx 3 -anchor e
	pack $w.quit -in $w.search -side left -padx 3


	# $w.info and w.kind share top row, showing themselves on demand
	frame $w.top -height [max [winfo reqheight $w.kind] [winfo reqheight $wi]]
	pack $w.vf -fill both -expand yes
	lower $w.show; lower $w.vf; # lower it below possible overlays
	update idletasks

	# generous hit regions, tab between
	tabgroup $w.mantypein $t $w.search.t
	foreach i {mantypein show search.t} {
		foreach k {KeyPress-Escape Control-KeyPress-g} {
			bind $w.$i <$k> {+ set STOP 1 }
		}
	}
	# fixups
	foreach k {KeyPress-Escape Control-KeyPress-g} {
		bind $t <$k> "+ if \[manKeyNav $w \[key_state2mnemon %s\] %K\] break"
	}
	bind $w.mantypein <KeyPress-Escape> "+
		if \[regexp {^\[<|.~/$\]} \$manx(typein$w)\] {manFilecomplete $w} else {manManComplete $w}
	"

	manPreferencesSetGlobal

	# measure time spent using application
	bind $w <Enter> "+set manx(startreading) \[clock seconds]";	# set current window
	bind $w <Leave> "+incr manx(reading) \[expr \[clock seconds]-\$manx(startreading)]"

	manHelp $w
#	update idletasks

	return $w
}

proc manSetSearch {w t} {
	global manx
	if {[catch {set expr [selection get]}]} {set expr [$t get "current wordstart" "current wordend"]}
	set expr [string trim $expr]
	if {$expr!=""} {set manx(search,string$w) $expr}
}

proc manRegexpCounts {t {tag "search"}} {
	global manx curwin

	set manx(hitlist$t) {}
	if {!$manx(tryoutline$curwin)} return

	foreach now $manx(sectposns$curwin) next $manx(nextposns$curwin) {
		# count up hits in that section
		set cnt($now) -1
		set hit "do-while-simulation"
#		for {set inx "$now lineend+1c"} {$hit!=""} {set inx "[lsecond $hit]+1c"; incr cnt($now)} {
		for {set inx $now} {$hit!=""} {set inx "[lsecond $hit]+1c"; incr cnt($now)} {
			set hit [$t tag nextrange $tag $inx $next-1c]
		}
		set n $now; while {[regexp $manx(supregexp) $n all num]} {
			catch {incr cnt(js$num) $cnt($n)}
			set n "js$num"
		}
	}

	set viz [expr {$manx(tryoutline$curwin)?"-elide":"--"}]
	set oldstate [$t cget -state]
	$t configure -state normal
#	set firstsect 1
	foreach now $manx(sectposns$curwin) {
		set old [$t search -regexp $viz {[ \t]+\d+$} $now "$now lineend"]
		if {$old!=""} {$t delete $old "$old lineend"} else {set old $now}
		if {$cnt($now)} {
			set inx [$t index "$old lineend"]
			$t insert $inx "     $cnt($now)"
#			if {$firstsect} {$t insert "$inx lineend" "   [textmanip::plural $cnt($now) match]"; set firstsect 0}
			$t tag add sc $inx "$inx lineend"
# adding search tag to label causes paging through hits to stop at titles, which we may or may not want
#			$t tag add search $inx+5c "$inx lineend"
#			$t tag add search $now $inx

			lappend manx(hitlist$t) $now
		}
	}
	$t configure -state $oldstate
}


proc manShowTagDist {w tag {width 2} {color ""}} {
	global item2posn

	set t $w.show; set c $w.c
## this not so useful after all
##	$c bind all <Enter> "manShowTagPopup $w %x %y up"
##	$c bind all <Leave> "manShowTagPopup $w %x %y down"
#	bind $w.c <Leave> "manShowTagPopup $w 0 0 down"

	set scale [expr {[winfo height $c]/[$t index end]}]
	$c delete $tag
	if {$color eq ""} {set color [$t tag cget $tag -background]}; if {$color eq "" || $color eq "white"} {set color black}
	foreach {first last} [$t tag ranges $tag] {
		set y [expr {$first * $scale}]
		set item [$c create line 0 $y 10 $y -tags $tag -width $width -fill $color]
		set item2posn($item) [list $first $last]
	}
}


# show a popup box with the content of the item
toplevel [set pop .popup]; wm overrideredirect $pop true; wm withdraw $pop
pack [label $pop.info]
set manx(lastitem) -1


proc manShowTagPopup {w x y {action "up"}} {
	global man manx item2posn

	set t $w.show; set c $w.c
	set pop .popup;	set info $pop.info

	if {$action eq "up"} {
		set lastitem $manx(lastitem)
		set item [set manx(lastitem) [lfirst [$c find overlapping $x [expr {$y-2}] [expr {$x+1}] [expr {$y+2}]]]]
		if {$item eq "" || $item eq $lastitem} return

		set pre ""; set post ""
		foreach {starti endi} $item2posn($item) break
		set tip [string trim [$t get $starti $endi]]
		set ctxlen [expr {(80-[string length $tip])/2}]
		if {$ctxlen<=0} {
			set tipshow [string range $tip 0 80]
		} else {
			set tipshow ""
			set pre [string trim [$t get "$starti linestart" $starti]]; set prelen [string length $pre]
			if {$prelen} {append tipshow [string range $pre [expr {$prelen-$ctxlen}] end] " ... "}

			append tipshow $tip

			set post [string trim [$t get $endi "$endi-1c lineend"]]
			if {[string length $post]} {append tipshow " ... " [string range $post 0 $ctxlen]}
		}
		$info configure -text $tipshow

		# position on screen near document map
		set winx [expr {[winfo x $w.c]+[winfo x $w]}]; set winy [expr {[winfo y $w.c]+$y+[winfo y $w]-[winfo reqheight $info]/2}]
		if {$man(scrollbarside) eq "left"} {incr winx 10} else {incr winx [expr {-10-[winfo reqwidth $info]}]}
		wm geometry $pop +$winx+$winy
		after 1 "wm deiconify $pop; raise $pop"
#puts "wm geometry $pop +$winx+$winy"
	} else {
		set manx(lastitem) -1
		wm withdraw $pop
	}
}



# update winstdout/winstderr use by other modules
rename winstdout winstdout-default
rename winstderr winstderr-default
proc winstdout {w {msg AnUnLiKeMeSsAgE} {update 0}} { return [manWinstdout [winfo parent $w] $msg $update] }
proc winstderr {w msg {type "bell & flash"}} { return [manWinstderr [winfo parent $w] $msg] }

proc manWinstderr {w msg} {
	global man
	raise $w.info
	return [winstderr-default $w.info $msg $man(error-effect)]
}

proc manWinstdout {w {msg AnUnLiKeMeSsAgE} {update 0}} {
	raise $w.info
	return [winstdout-default $w.info $msg $update]
}

proc manManTabSet {w} {
	global manx

	set t $w.show

#Single Letter        Double Letter        Triple Letter        
#E                    TH                   THE                  
#T                    HE                   AND                  
#R                    IN                   TIO                  
#N                    ER                   ATI                  
#I                    RE                   FOR                  
#O                    ON                   THA                  
#A                    AN                   TER                  
#S                    EN                   RES                  

# alphabet uc+lc+spaces = 
# font measure [$t cget -font] "ETRNIOASM          aaabcdeeeefghiijklmnnooprrsttuy";
# = 438 for 26+26+8=60 characters
# winfo width $t;
# = 562
# so cols = (50/307)*562 = 91, want ~90, yay
	set repstr "ETRNIOASM          aaabcdeeeefghiijklmnnooprrsttuy"; set replen [string length $repstr]

	set rm [expr {abs([winfo width $t]-2*[$t cget -padx]-10)}]
	$t tag configure info -tabs [list 0.3i $rm right]
	$t tag configure census -tabs [list [expr {abs($rm-150)}] right $rm right]
	$t tag configure high -tabs [list $rm right]
	$t tag configure rmtab -tabs [list $rm right]

	set manx(screencols) [expr {[winfo width $t]*$replen/[font measure [$t cget -font] $repstr]}]

	set tabwidth [font measure [$t cget -font] "     "]
	# pixels assumed?
	$t configure -tabs $tabwidth

	$t tag configure man -lmargin2 $tabwidth
	for {set i 1} {$i<=6} {incr i} {$t tag configure "tab$i" -lmargin2 [expr {$i*$tabwidth}]}
}

proc manMbHelp {mb info msg} {
	# no beeps or flashing
	bind $mb <Enter> "set manx(tmp-infomsg) \[$info cget -text]; $info configure -text [list $msg]"
	bind $mb <Leave> "$info configure -text \$manx(tmp-infomsg)"
}
