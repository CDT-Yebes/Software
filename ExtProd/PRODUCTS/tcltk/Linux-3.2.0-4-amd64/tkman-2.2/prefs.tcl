#--------------------------------------------------
#
# manPreferences -- graphical interface to many values stored in startup file
#
#--------------------------------------------------

proc manPreferencesMake {{w0 ""}} {
	global prefedit manx man bozo
# don't do global man here

	set w .prefs
	if {[winfo exists $w] || $w0 eq ""} {return $w}

	toplevel $w; wm resizable $w 0 0
	wm geometry $w $prefedit(geom-prefs)
	wm title $w "Preferences"
	wm withdraw $w

	set f [frame $w.pages]
	foreach i {"Fonts" "Colors" "See" "Outline" "Database" "Window" "Misc"} {
		set il [string tolower $i]
		radiobutton $f.$il -text $i -command manPreferences -variable manx(prefscreen) -value $il
		pack $f.$il -side left -fill x -padx 4
	}
	frame $w.sep1 -height 2 -background $prefedit(guifg)



	### fonts
	set g [frame $w.[set group "fonts"]]

	# fonts: gui, file, errors -- family, size
	foreach {var txt} {gui Interface   text "Text display"   vol "Volume listings"  
			diffd "Text deleted from last version"  diffc "Text changed from last version"  diffa "Text added since last version"} {
		lappend manx(vars-$group) $var-style

		if {[info exists $var-family]} {lappend manx(vars-$group) $var-family}
		lappend manx(vars-$group) $var-style
		# $var-points -- diff[dca] don't have points
		if {[info exists $var-points]} {lappend manx(vars-$group) $var-points}
		set f [frame $g.font$var]
		label $f.l -text $txt
		[eval tk_optionMenu $f.style prefedit($var-style) $manx(styles)] configure -tearoff no
		pack $f.l -side left -fill x
		pack $f.style -side right -padx 2
		if {![string match diff* $var]} {
			[eval tk_optionMenu $f.family prefedit($var-family) $manx(fontfamilies)] configure -tearoff no
			[eval tk_optionMenu $f.points prefedit($var-points) $manx(sizes)] configure -tearoff no
			pack $f.points $f.family -after $f.style -side right -padx 2

			lappend manx(vars-$group) $var-family $var-points
		}
	}

#	set var fontpixels; set txt "Specify font as (see font(n))"
#	lappend manx(vars-$group) $var-style
#	set f [frame $g.$var]
#	label $f.l -text $txt
#	[eval tk_optionMenu $f.choice prefedit($var-t) $manx($var-t)] configure -tearoff no
#	pack $f.l -side left -fill x
#	pack $f.choice -side right -padx 2

	pack $g.fontgui $g.fonttext $g.fontvol $g.fontdiffa $g.fontdiffc $g.fontdiffd -fill x -pady 3 -padx 4



	### colors
	set g [frame $w.[set group "colors"]]

	foreach {var txt} {gui "Interface"   butt "Buttons"   active "Active Regions"   text "Text"   selection "Selection"} {
		lappend manx(vars-$group) ${var}fg ${var}bg

		set f [frame $g.$var]
		label $f.l -text $txt
		foreach j {{fg "foreground"} {bg "background"}} {
			foreach {jvar jtxt} $j break
			if {$jvar eq "fg"} {set jopp "bg"} else {set jopp "fg"}
			set mb $f.$var$jvar
			[set m [eval tk_optionMenu $mb prefedit($var$jvar) $man(colors)]] configure -tearoff no
			# when monochrome, keep foreground and background colors opposites!
			if {$manx(mono)} {
				foreach k $man(colors) {
					set copp [lindex $prefedit(colors) [expr {1-[lsearch $prefedit(colors) $k]}]]
					$m entryconfigure $k -command "set prefedit($var$jopp) $copp; set prefedit($var$jvar) $k"
				}
			}
		}
		pack $f.l -side left -fill x
		pack $f.${var}bg [label $f.${var}on -text "on"] $f.${var}fg -side right -padx 4
	}

	foreach {var fb txt} {
			synopsisargs b "Name and Synopsis arguments"
			manref f "Man page references"   isearch b "Incremental search hits"
			search b "Regexp search hits"   highlight b "Highlights"
			autokey f "Keywords"
		} {
		lappend manx(vars-$group) $var
		set f [frame $g.$var]
		label $f.l -text $txt

		[set m [eval tk_optionMenu [set mb $f.$var] prefedit($var) $manx(highs)]] configure -tearoff no
			foreach k $manx(highs) {
				if {[lsearch $man(colors) $k]==-1} {set val $k} \
				else {if {$fb eq "f"} { set val "-foreground [list $k]"} else { set val "-background [list $k]" } }
				$m entryconfigure $k -command "set prefedit($var) [list $val]"
			}
		pack $f.l -side left -fill x
		pack $mb -side right -padx 4
	}

	pack $g.text $g.highlight $g.gui $g.butt $g.active $g.selection $g.synopsisargs $g.manref $g.isearch $g.search $g.autokey \
		-fill x -expand yes -pady 3 -padx 4



	### See
	set g [frame $w.[set group "see"]]

	foreach {var txt} {
			wordfreq "Page summary as word freqency counts"
			headfoot "Header, footer, date at bottom"
			maxpage "Page content only, except when menus active by Tab or mouse into region"
			documentmap "Document map (adjacent to scrollbar)"
			scrollbarside "Scrollbar side"
			textboxmargin "Text box internal margin (in pixels)"
			volcol "Width of columns in Volumes list"
			high,vcontext "Back context for Highlights jump (lines)"
			error-effect "Status line error/warning effect"
			subvols "Subvolumes as submenus in Volumes"
			apropostab "Tab stop in apropos list"
			rebus "Rebus (icons instead of words) for: file, TeX, ..."
			lengthchunk "Page length (estimated) reported in"
#			diffbar "Generate change bars"
		} {
		lappend manx(vars-$group) $var
		set f [frame $g.$var]
		label $f.l -text $txt
		[set m [eval tk_optionMenu $f.high bozo($var) $manx(${var}-t)]] configure -tearoff no
			set j 0
			foreach mv $manx(${var}-v) {
				$m entryconfigure $j -command "set prefedit($var) [list $mv]"
				incr j
			}
			trace variable prefedit($var) w manPrefBozo
		pack $f.l -side left -fill x
		pack $f.high -side right
	}

# $g.diffbar
	pack $g.wordfreq $g.headfoot $g.lengthchunk $g.maxpage $g.subvols $g.documentmap $g.high,vcontext $g.volcol $g.apropostab $g.rebus $g.scrollbarside $g.textboxmargin $g.error-effect \
		-fill x -pady 3 -padx 4



	### Outline
	set g [frame $w.[set group "outline"]]

	foreach {var txt} {
			outline "Outlining state at page load"
			tidyout "With outline \"smart scroll down\", collapse previous section"
			manfill "Excerpt "
			manfill-show ""
			highlight-show "Highlights in collapsed outline visible"
#			subsect-show "Subsection heads in collapsed visible"
			options-show "Command line options in collapsed visible"
			manref-show "Manual page references in collapsed visible"
			search-show "Search hits in collapsed visible"
#			outline-show "Texinfo outline headers visible down to"
			search,bcontext "lines before,   "
			search,fcontext "after"
			showsectmenu "Show Sections menu (obsolete with outlining)"
			} {
		lappend manx(vars-$group) $var
		set f [frame $g.$var]
		label $f.l -text $txt
		[set m [eval tk_optionMenu $f.high bozo($var) $manx(${var}-t)]] configure -tearoff no
			set j 0
			foreach mv $manx(${var}-v) {
				$m entryconfigure $j -command "set prefedit($var) [list $mv]"
				incr j
			}
			trace variable prefedit($var) w manPrefBozo
		pack $f.l -side left -fill x
		pack $f.high -side right
	}
	pack $g.manfill-show -in $g.manfill -side right -padx 4
	entry $g.manfill.e -width 40 -textvariable prefedit(manfill-sects) -relief sunken
	pack $g.manfill.e -after $g.manfill.l -side left

	foreach {var txt} {
		outlinebut "In outline \"all but collapsed\", show"   autokeywords "Keywords"
		autosearchnb "Auto search regexp as Notemarks"   autosearch "Auto search regexp NOT as Notemarks"
	} {
		lappend manx(vars-$group) $var
		set f [frame $g.$var]
		label $f.l -text $txt
		entry $f.e -width 40 -textvariable prefedit($var) -relief sunken
		pack $f.l -side left -fill x
		pack $f.e -side right
	}
	# maybe add to autosearch: off, first letter, whole word

	# package search hits back and forward context together
	set f [frame $g.searchcontext]
	pack [label $f.l -text "Search hits context"] -side left -fill x; lower $f
	foreach var {search,fcontext search,bcontext} {
		pack $g.$var.l -side right; pack $g.$var.high -side left
		pack $g.$var -side right -fill none -in $f
	}

	pack $g.outline $g.outlinebut $g.tidyout $g.manfill $g.highlight-show $g.options-show $g.manref-show $g.search-show $g.searchcontext $g.autosearchnb $g.autosearch $g.autokeywords $g.showsectmenu \
# $g.outline-show
		-fill x -pady 3 -padx 4



	### window-related
	set g [frame $w.[set group "window"]]

	foreach {var txt} {autoraise "Auto raise window when mouse enters"  autolower "Auto lower window when mouse leaves"  iconify "Iconify on startup"  focus "Text entry focus set by"} {
		lappend manx(vars-$group) $var
		set f [frame $g.$var]
		label $f.l -text $txt
		[set m [eval tk_optionMenu $f.high bozo($var) $manx(${var}-t)]] configure -tearoff no
			set j 0
			foreach mv $manx(${var}-v) {
				$m entryconfigure $j -command "set prefedit($var) [list $mv]"
				incr j
			}
			trace variable prefedit($var) w manPrefBozo
		pack $f.l -side left -fill x
		pack $f.high -side right
	}

	foreach {var txt} {iconname "Name when iconified"
			iconbitmap "Path name of icon bitmap"   iconmask "Path name of icon mask"
			iconposition "Icon position (+|-)x(+|-)y"} {
		lappend manx(vars-$group) $var
		set f [frame $g.$var]
		label $f.l -text $txt
		entry $f.e -width 40 -textvariable prefedit($var) -relief sunken

		pack $f.l -side left -fill x
		pack $f.e -side right
	}
	set ring {iconname iconbitmap iconmask iconposition}; set ringl [llength $ring]
	for {set i 0} {$i<$ringl} {incr i} {
		set wig $g.[lindex $ring $i].e
		foreach k {Tab Return} { bind $wig <KeyPress-$k> "focus $g.[lindex $ring [expr {($i+1)%$ringl}]].e"; break }
		bind $wig <Shift-KeyPress-Tab> "focus $g.[lindex $ring [expr {($i-1)%$ringl}]].e; break"
	}

	# file completion for bitmap names
	foreach wig {iconbitmap iconposition} {
		set e $g.$wig.e
		bind $e <KeyPress-Escape> "manFilecompleteLocal $e"
	}

	pack $g.autoraise $g.autolower $g.iconify $g.iconname $g.iconbitmap $g.iconmask $g.iconposition $g.focus \
		-fill x -pady 3 -padx 4



	### Miscellaneous
	set g [frame $w.[set group "misc"]]

	foreach {var txt} {
			hyperclick "Mouse click to activate hyperlink"
			incr,case "Incremental Search Case Sensitive"
			regexp,case "Regexp and Glimpse Case Sensitive"
			subsect "Parse man page subsections"
			strictmotif "Strict Motif behavior"
#			tables "Aggressive table parsing"
			maxhistory "Maximum length of history list"
			shortcuts-sort "Shortcuts list order"
#			zaphy "Prevent hyphenation (good for searches)"
			showrandom "Show \"random man page\" button"
	} {
		lappend manx(vars-$group) $var
		set f [frame $g.$var]
		label $f.l -text $txt
		[set m [eval tk_optionMenu $f.high bozo($var) $manx(${var}-t)]] configure -tearoff no
			set j 0
			foreach mv $manx(${var}-v) {
				$m entryconfigure $j -command "set prefedit($var) [list $mv]"
				incr j
			}
			trace variable prefedit($var) w manPrefBozo
		pack $f.l -side left -fill x
		pack $f.high -side right
	}


	if {$man(print) ne ""} {
		foreach {var txt} {printers "Printer list (space separated)"} {
			lappend manx(vars-$group) $var

			set f [frame $g.$var]
			label $f.l -text $txt
			entry $f.e -width 40 -textvariable prefedit($var) -relief sunken

			pack $f.l -side left -fill x
			pack $f.e -side right
		}
		pack $g.printers -fill x -pady 3 -padx 4
	}

	pack $g.hyperclick $g.incr,case $g.regexp,case $g.subsect $g.maxhistory $g.shortcuts-sort $g.showrandom $g.strictmotif \
# $g.zaphy
		-fill x -pady 3 -padx 4


	### Database
	set g [frame $w.[set group "database"]]

	foreach {var txt} {
			nroffsave "Cache formatted (nroff'ed) pages"
#			fastman "Don't cache man if formatting takes less than (sec)"
#			fasttex "Don't cache Texinfo if formatting takes less than (sec)"
			fsstnd-always "Cache directory"
			columns "Width of man pages, in columns"
			recentdays {"Recent" volume age, in days}
			preferGNU "Prefer GNU versions of pages (e.g., od => god)"
			preferTexinfo "Prefer Texinfo to man"
			tryfuzzy "Try fuzzy match if exact fails"
			indexglimpse "Glimpse indexing"
			maxglimpse "Maximum Glimpse hits (per man hierarchy)"
			maxglimpseexcerpt "Excerpt Glimpse hits if number of pages with hits less than"} {
		lappend manx(vars-$group) $var
		set f [frame $g.$var]
		label $f.l -text $txt
		[set m [eval tk_optionMenu $f.high bozo($var) $manx(${var}-t)]] configure -tearoff no
			set j 0
			foreach mv $manx(${var}-v) {
				$m entryconfigure $j -command "set prefedit($var) [list $mv]"
				incr j
			}
			trace variable prefedit($var) w manPrefBozo
		pack $f.l -side left -fill x
		pack $f.high -side right
	}
	entry $g.fsstnd-always.e -width 30 -textvariable prefedit(fsstnddir) -relief sunken
	pack $g.fsstnd-always.e -side right
	lappend manx(vars-$group) fsstnddir


	foreach {var txt} {glimpsestrays "Distributed stray cats / unified index"
			indexalso "Additional directories for full text"
#			fsstnddir "Cache directory if .../catN unwritable"
# (useful if long lines)
			texinfodir "Texinfo dir/cache directory"
#			rfcdir "rfc-index.txt index directory"
		} {
		lappend manx(vars-$group) $var

		set f [frame $g.$var]
		label $f.l -text $txt
		entry $f.e -width 40 -textvariable prefedit($var) -relief sunken

		pack $f.l -side left -fill x
		pack $f.e -side right
	}

	pack $g.nroffsave $g.columns $g.fsstnd-always $g.texinfodir $g.recentdays $g.preferTexinfo $g.tryfuzzy $g.preferGNU \
		$g.maxglimpse $g.maxglimpseexcerpt $g.indexglimpse $g.glimpsestrays $g.indexalso \
		-fill x -pady 3 -padx 4
	if {![string match "*groff*/tmp/ll -*" $man(format)]} {pack forget $g.columns}



	# buttons
	frame $w.bsep -relief sunken -height 2 -background $prefedit(guifg)
	set f [frame $w.butts]
	button $f.ok -text "OK" -padx 6 -command "grab release $w; wm withdraw $w; manPreferencesSet"
	button $f.apply -text "Apply" -command "manPreferencesSet"
	button $f.cancel -text "Cancel" -command "
		grab release $w; wm withdraw $w
		manPreferencesGet cancel; manPreferencesSet
	"
	button $f.default -text "Defaults" -command "manPreferencesGet default"
	pack $f.ok $f.apply $f.default $f.cancel -side right -padx 4


	pack $w.pages $w.sep1 $w.bsep $w.butts \
		-side top -fill x -pady 3 -padx 4

	return $w
}

proc manPrefBozo {array var op} {
	global prefedit manx bozo
	set bozo($var) [lindex $manx($var-t) [lsearch $manx($var-v) $prefedit($var)]]
}


proc manFilecompleteLocal {t} {
	set line [$t get]
	set fc [filecomplete $line]
	set ll [llength $fc]

	# no matches returns
	if {!$ll} {
		bell
		return
	}

	# otherwise show longest valid name (longest common prefix determined by filecomplete)
	$t delete 0 end
	$t insert 0 [lfirst $fc]
	$t icursor end
	$t xview moveto 1
}


proc manPreferencesGet {{cmd "fill"}} {
	global man manx default prefedit cancel curedit

	# conflict of command name and special case of switch command
	if {$cmd=="default"} {set cmd "prefdefault"}

	switch -exact $cmd {
	fill {foreach i [array names default] {set prefedit($i) [set curedit($i) [set cancel($i) $man($i)]]}}
	prefdefault {foreach i $manx(vars-$manx(prefscreen)) {set prefedit($i) $default($i)}}
	cancel {foreach i [array names default] {set prefedit($i) $cancel($i)}}
	man {foreach i [array names default] {set man($i) $prefedit($i)}}
	curedit {foreach i [array names default] {set curedit($i) $prefedit($i)}}
	}
}

set manx(prefscreen) "fonts"
set manx(oldprefscreen) ""
proc manPreferences {{screen ""}} {
	global manx

	# show right grouping
	set w [manPreferencesMake bozo]
	raise $w
	if {$screen eq ""} {set screen $manx(prefscreen)} else {set manx(prefscreen) $screen}
	set prev $manx(oldprefscreen)

	if {$screen ne $prev} {
		if {$prev ne ""} {
			pack forget $w.$prev
#			$w.pages.$prev configure -relief raised
		}

		pack $w.$screen -after $w.sep1 -fill x
#		$w.pages.$screen configure -relief sunken

		set manx(oldprefscreen) $screen
	}

	if {![winfo ismapped $w]} {
		manPreferencesGet fill
		wm deiconify $w; grab set $w
	}
}

proc manPrefDefaultsSet {} {
	global man

	# fonts & colors
	foreach {var txt} {gui ""   butt "Button."   butt "Menubutton."   butt "Radiobutton." 
			butt "Checkbutton."   text "Text."} {
# {gui "Scrollbar."}} {
		option add Tkman*${txt}Foreground $man(${var}fg) 61
		option add Tkman*${txt}Background $man(${var}bg) 61
#puts "option add ...$txt... $man(${var}fg) on $man(${var}bg)"
	}

	option add Tkman*activeForeground $man(activefg) 61
	option add Tkman*activeBackground $man(activebg) 61
	option add Tkman*highlightBackground $man(activebg) 61

	option add Tkman*selectColor $man(buttfg) 61
	option add Tkman*font gui 61


	eval font configure textpro [spec2font $man(text-family) $man(text-style) $man(text-points)]
#puts "set textpro to [font actual textpro]"
	eval font configure gui [spec2font $man(gui-family) $man(gui-style) $man(gui-points)]
#puts "set gui to [font actual gui]"
	eval font configure guisymbol [spec2font "symbol" $man(gui-style) $man(gui-points)]
	eval font configure guimono [spec2font "courier" $man(gui-style) $man(gui-points)]
	eval font configure textmono [spec2font "Courier" $man(text-style) $man(text-points)]
	eval font configure peek [spec2font $man(text-family) "italics" $man(text-points) "s"]
#	foreach f {diffa diffc diffd} {
#		eval font configure $f [spec2font $man($f-family) $man($f-style) $man(text-points)]
#	}

	# bitmaps
	foreach bitmap [image names] {
		if {[regexp "face|icon" $bitmap]} {
			# face and icon always black on white
		} elseif {[regexp "sections|history|random" $bitmap]} {
			$bitmap configure -foreground $man(buttfg) -background $man(buttbg)			
		} else {
			$bitmap configure -foreground $man(textfg) -background {}
		}
	}
}


# reconfigure screen based on new preferences information
proc manPreferencesSet {} {
	global man manx mani prefedit curedit default

	set change 0
	foreach i [array names default] {
		if {$curedit($i) ne $prefedit($i)} {
			set change 1
			break
		}
	}
#puts "* manPreferencesSet, change=$change"
	if {!$change} return

	# random updates
	set mani($prefedit(glimpsestrays),dirs) $mani($man(glimpsestrays),dirs)

	# make temporary permanent
	manPreferencesGet man
#	manGeometry get -- done just before quit

	# # # set keybindings--later

	# fonts -- text, gui (main and preferences windows)
	manPrefDefaultsSet

	resetcolors

	foreach i [list .occ .paths] {$i configure -selectcolor $man(guifg)}

	manPreferencesSetGlobal

#	manGeometry set
	manPreferencesGet curedit
}

proc manPreferencesSetGlobal {} {
	global man manx curedit tk_strictMotif

	set tk_strictMotif $man(strictmotif)

	# icon-related
	# ... need to reference man() to get new values, but manx() has command line options
	foreach i {iconname iconposition iconbitmap iconmask} {
		if {$man($i) ne $curedit($i)} {set manx($i) $man($i)}
	}

	manShortcuts .man init

	set manx(effcols) ""
	if {[string match "*groff*$manx(longtmp) -*" $man(format)] && $man(columns)!=65} {set manx(effcols) "@$man(columns)"}

	if {$man(print) ne "" && ([[set m2 .occ.kill] index end] eq "none" || $curedit(printers) ne $man(printers)) } {
		set plist [string trim $man(printers)]
		# always put default printer in list
		if {[lsearch $plist $manx(printer)]==-1} {set plist [concat $manx(printer) $plist]}

		#if {[llength $plist]==1} => always want level of indirection for printing
		$m2 delete 0 end
		foreach p $plist { $m2 add command -label $p -command "manPrint \$curwin $p" }
		if {![llength $plist]} {$m2 add command -label "(default)" -command "manPrint \$curwin"}
	}

	if {$curedit(subvols) ne $man(subvols)} {manMakeVolList 1}

	# update text tags and other .man* bits
	foreach w [lmatches ".man*" [winfo children .]] {manPreferencesSetMain $w}

	foreach w [lmatches ".man*" [winfo children .]] {
		foreach i {info kind mantypein} {bind $w.$i <Enter> [expr {$man(focus)?"focus $w.mantypein":""}]}
		foreach i {vf show v} {bind $w.$i <Enter> [expr {$man(focus)?"focus $w.show":""}]}
		bind $w.search <Enter> [expr {$man(focus)?"focus $w.search.t":""}]
	}


	# compute scaling factors
	set cols $man(columns)
	# screens based on font, window size, line length
	set t .man.show
	set fh [font metrics [$t cget -font] -linespace]
	if {$cols>=200} {set fh [expr {$fh*2.2}]}; # say 6 lines per paragraph, but lotsa blank lines, lotsa single lines
	set wh [winfo height $t]
	set manx(screen-scale) [expr {$wh/$fh}]
	# pages based on line length
	set lpp 60; set scale $lpp
	if {$cols<80} {set scale [expr {$scale*1.5}]} elseif {$cols>=200} {set scale [expr {$scale/2.2}]}
	set manx(page-scale) $scale
	set manx(page-fhscale) $fh
}


proc manPreferencesSetMain {w} {
	global man manx curedit

	if {![string match ".man*" $w]} return

	if {[regexp $manx(posnregexp) $manx(iconposition) all x y]} {
		wm iconposition $w $x $y
	}
	foreach i {iconbitmap iconmask iconwindow} {wm $i $w ""}

	if {[regexp {\)?default\)?} $manx(iconbitmap)]} {
		set iw ".iconwindow[string range $w 4 end]"
		if {![winfo exists $iw]} {
			toplevel $iw; label $iw.l -image icon; pack $iw.l
			# bug in ctwm doesn't deiconify if using icon window
			# (default deiconify Button-1 in ctwm?)
			bind $iw <Button-1> "wm deiconify $w"
		}
		wm iconwindow $w $iw
		# iconwindows left hanging around whn close an instantiation, but no big deal
	} else {
		# everybody shares same icons
		# (null string for name means no icon)
		foreach i {iconbitmap iconmask} {
			if {$manx($i) ne ""} {
				if {[catch {wm $i $w @$manx($i)} info]} {
					puts stderr "Bad $i: $manx($i).  Fix in Preferences/Icon."
#					tk_dialog .dialog "BAD [string toupper $i]" "Bad $i: $manx($i).  Fix in Preferences/Icon." "" 0 " OK "
				}
			}
		}
	}


	# random bits
	set t $w.show

	pack $w.v -side $man(scrollbarside)
	if {$man(documentmap)} { pack $w.cf -after $w.v -side $man(scrollbarside) -fill y } else { pack forget $w.cf }

	if {$man(maxpage)} {
		pack forget $w.info; pack forget $w.kind; pack forget $w.search

		pack $w.top -before $w.vf -fill x
		place $w.info -in $w.top -x 0 -y 0 -relwidth 1
		place $w.kind -in $w.top -x 0 -y 0 -relwidth 1
		lower $w.top; raise $w.info
		bind $w.mantypein <FocusIn> "lower $w.info"
		bind $w.info <Motion> "lower $w.info"
		bind $t <Motion> "+if {%y > \[winfo height $t]-[winfo reqheight $w.search]} {place $w.search -x 0}"
		place $w.search -in $t -x -[winfo width $t] -rely 1 -y -[winfo reqheight $w.search] -relwidth 1
		bind $w.search.t <FocusIn> "place $w.search -in $t -x 0"
		bind $w.search.t <FocusOut> "place $w.search -x -\[winfo width $t]"
	} else {
		pack forget $w.top; place forget $w.info; place forget $w.kind; place forget $w.search

		bind $w.mantypein <FocusIn> {}; bind $w.search.t <FocusIn> {}; bind $w.search.t <FocusOut> {}
		bind $t <Motion> {}; bind $w.info <Motion> {}
		pack $w.info -before $w.vf -fill x
		pack $w.kind -after $w.info -fill x -pady 3
		pack $w.search -after $w.vf -fill x -pady 6
	}

	foreach f {diffa diffc diffd} {
		$t tag configure $f -font [spec2font $man(text-family) $man($f-style) $man(text-points)]
	}

	# the scrollbar is an oddball
	$w.v configure -troughcolor $man(guibg)
	$w.v configure -background [expr {$man(buttbg) ne $man(guibg)? $man(buttbg) : $man(guibg)}]

	# text widget fonts and tags
	$t configure -padx $man(textboxmargin) -pady $man(textboxmargin)
	manManTabSet $w
# -tabs 0.2i -- tabs set to 5 spaces in current font

	$t tag configure volume -font [spec2font $man(vol-family) $man(vol-style) $man(vol-points)] -tabs $man(volcol)
# -lmargin2 $man(volcol)
	$t tag configure apropos -font [spec2font $man(vol-family) $man(vol-style) $man(vol-points)] -tabs $man(apropostab) -lmargin2 $man(apropostab)

	$t tag configure sel -foreground $man(selectionfg) -background $man(selectionbg)

	set man(highlight-meta) $man(highlight)
	set man(autosearchtag) $man(search)
	foreach v $manx(tags) {
#puts "$t => [winfo class $t]"
		$t tag configure $v -font "" -foreground "" -background "" -underline no
		set change ""; set newfont 0; set pending 0
		set fam $man(text-family); set sty $man(text-style); set poi $man(text-points); set poi2 "m"
		foreach g [subst $man($v)] {
#DEBUG {puts $g}
			if {$pending} {append change " " [list $g]; set pending 0; continue}
			switch -glob -- $g {
				# normal should be plain
				normal {}
				underline {append change " -underline yes"}
				reverse {append change " -foreground {$man(textbg)} -background {$man(textfg)}"}
				italics { set sty $g; set newfont 1 }
				bold -
				bold-italics {
					# aesthetically, among other text bold looks better when scaled down, for some reason
					set sty $g; set poi2 "s"; set newfont 1
				}
				mono { set fam "Courier"; set newfont 1 }
				symbol { set fam "Symbol"; set sty "normal"; set newfont 1 }
				serif { set fam "Times"; set newfont 1 }
				sanserif { set fam "Helvetica"; set newfont 1 }
				small -
				medium -
				large {
					set poi $g; set newfont 1
				}
				s -
				m -
				l {
					set poi2 $g; set newfont 1
				}
				left -
				right -
				center {
					append change " -justify $g"
				}
				-* {append change " " [list $g]; set pending 1}
				default {
#puts "lsearch $g => [lsearch $manx(fontfamilies) [string tolower $g]]"
					if {[lsearch $manx(fontfamilies) [string tolower $g]]!=-1} {set fam $g; set newfont 1
					} else {append change " " [list $g]}
				}
			}
		}
		if {$newfont} {append change " -font \"[spec2font $fam $sty $poi $poi2]\""}
#puts "change $v = $change"
		if {$change ne ""} {
			eval $t tag configure $v $change
			if {$v eq "highlight"} {catch {eval $w.high configure $change}}
#			if {$v eq "search"} {catch {eval $w.search.s configure $change}}
		}
	}
	$t tag raise sel
	$t tag configure sfirstvis -relief [expr {$man(search,bcontext)+$man(search,bcontext)>1?"raised":"flat"}]

	if {$man(showsectmenu)} {pack $w.sections -before $w.high -side left -padx 4} else {pack forget $w.sections}

#	set inx [lsearch $manx(outline-show-v) $man(outline-show)]
#	foreach tag [lrange $manx(outline-show-v) 1 $inx] {$t tag configure $tag -elide 0}
#	foreach tag [lrange $manx(outline-show-v) [expr $inx+1] end] {$t tag configure $tag -elide ""}


	if {$man(showrandom)} {pack $w.random -before $w.vols -side left -padx 10} else {pack forget $w.random}


	if {$curedit(hyperclick) ne $man(hyperclick)} {manHyper $w ""}
}


proc resetcolors {{w .}} {
	global man curedit

	set c [winfo class $w]
	set g "gui"; if {$c eq "Text"} {set g "text"} elseif {[string match "*utton" $c]} {set g "butt"}
#|| $c eq "Entry"
	set foreground [set selector [set insertbackground $man(${g}fg)]]
	set background $man(${g}bg)
	set ofg $curedit(${g}fg)
	set obg $curedit(${g}bg)

#puts "checking $w, class $c"
	foreach i {foreground background insertbackground selectcolor} {
		if {![catch {set color [$w cget -$i]}]} {
			 if {$color eq $ofg} {$w configure -$i $foreground} \
			 elseif {$color eq $obg} {$w configure -$i $background}
		}
	}

	set activeforeground $man(activefg)
	set activebackground $man(activebg)
	set highlightbackground $activebackground
	foreach i {activeforeground activebackground highlightbackground} {
		catch {$w configure -$i [set $i]}
	}

	# recurse
	foreach c [winfo children $w] {
		resetcolors $c
	}
}


proc spec2font {{family "times"} {style "normal"} {points "medium"} {size "m"}} {
	global man manx

#puts -nonewline "$family + $style + $points ( $size ) => "
	set slant "roman"; set weight "normal"
	switch -exact -- $style {
		normal {}
		bold {set weight "bold"}
		italics {set slant "italic"}
		bold-italics {set weight "bold"; set slant "italic"}
		default {puts stderr "nonexistent style: $style"; exit 1}
	}

	# specify s,m,l within small,medium,large; or set absolute point size
	if {[set pts [lsearch $manx(sizes) $points]]!=-1} {
		set p "[lindex [lrange $manx(pts) $pts end] [lsearch {s m l} $size]]"
	} else {set p $points}

#	set font "-family [list $family] -size $man(fontpixels)$p -weight $weight -slant $slant"
	set font "-family [list $family] -size $p -weight $weight -slant $slant"
#puts $font

	return $font
}
