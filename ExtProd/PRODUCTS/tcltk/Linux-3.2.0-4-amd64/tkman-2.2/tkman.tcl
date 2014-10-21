#
# Bird?  Plane?  TkMan!  (TkPerson?)
#
#   initial prototype written March 24-25, 1993
#
#   Copyright (c) 1994-2003  Thomas A. Phelps
#



set manx(startuptime) [clock seconds]
set manx(reading) 0; set manx(startreading) -1
wm withdraw .; update idletasks


# could check for existing TkMan, if found raise its window and kill self,
# but person may want to run on different OSes from same screen


#--------------------------------------------------
#
# Shortcuts
#
#--------------------------------------------------

proc manShortcuts {w cmd} {
	global man manx short

#	set me $manx(name$w)
 	set me $manx(typein$w)
#	if {![string match "<*" $me]} { append me ".$manx(cursect$w)" }
#puts "$manx(man$w) => $manx(name$w).$manx(cursect$w)"

	set modeok [lmatch {man txt texi} $manx(mode$w)]
	if {$cmd ne "init" && (!$modeok || $manx(man$w) eq "")} return

	set present [expr {[lsearch -exact $manx(shortcuts) $me]!=-1}]
	if {$cmd eq "add" && !$present} {lappend manx(shortcuts) $me; set short($me) [clock seconds]
	} elseif {$cmd eq "sub" && $present} {set manx(shortcuts) [lfilter $me $manx(shortcuts)]}

	# update menu
	set m .shortcuts
	$m delete 0 last
	set len [llength $manx(shortcuts)]
	# store list by time added, sort on demand
	set list $manx(shortcuts)
	if {$man(shortcuts-sort)} {set list [lsort $list]}
	if {$len} {
		foreach i $list {
#			if {![regexp {^[<|]} $i]} {
				#  usual man page
#				if {[lsearch $manx(mandot) $i]>-1} {set name $i} {set name [file rootname $i]}
#			} else {set name $i}
			$m add command -label $i -command "incr stat(man-shortcut); manShowMan [list $i] {} \$curwin"
		}
	}

	foreach win [lmatches ".man*" [winfo children .]] {manShortcutsStatus $win}
	manMenuFit $m
}


proc manShortcutsStatus {w} {
	global man manx
	global bmb

#	set me $manx(name$w)
 	set me $manx(typein$w)
#	if {![string match "<*" $me]} { append me ".$manx(cursect$w)" }

	set modeok [lmatch {man texi txt} $manx(mode$w)]
	set present [expr {[lsearch -exact $manx(shortcuts) $me]!=-1}]
	set b $w.stoggle
	if {$modeok} {
		if {$present} {set cmd "sub"; set text "-"
		} else {set cmd "add"; set text "+"
		}
		$b configure -text $text; set bmb($b) "incr stat(page-shortcut-$cmd); manShortcuts $w $cmd"
	} else {$b configure -text "x"; set bmb($b) ""}
}



# compensate for Tk's nonalphnum-bounded wordstart and wordend
# should have companions to word{start,end} that are bounded by whitespace, not nonalpha
# (in this case analysis too complex for an extended wordstart)

proc manHotSpot {cmd t xy} {
	global man manx curwin

	set manchars {[ a-z0-9_.~/$+()-:<]}
	set manx(hotman$t) ""

	# click again in hot spot without time considerations
#	if {!catch{$t index hot.first} && [$t compare hot.first <= $xy] && [$t compare $xy >= hot.last]} {
#		set cmd get
#	}

	# act on command
	if {$cmd eq "clear"} {
		$t tag remove hot 1.0 end
		return
	}


	scan [$t index $xy] "%d.%d" line char
	scan [$t index "$line.$char lineend"] "%d.%d" bozo lineend

	# else $cmd=="show"
	$t tag remove hot 1.0 end


	# command line options trump
# FLAT, RAISED, SUNKEN, GROOVE, SOLID, or RIDGE
	if {0 && $manx(mode$curwin) eq "man" && ([$t get [set cmdstart "$xy wordstart-1c"]] eq "-" || [$t get [set cmdstart "$xy wordstart"]] eq "-")} {
		set skipe "\[]\[\t .,;:\{\}?\]"
		scan [$t index $cmdstart] "%d.%d" line char
		for {set c0 $char} {$c0>0 && ![regexp $skipe [$t get $line.$c0]]} {incr c0 -1} {}
		incr c0;	# went one too far
		scan [$t index "$xy wordend"] "%d.%d" line char
		for {set cn $char} {$cn<$lineend && ![regexp $skipe [$t get $line.$cn]]} {incr cn} {}

		if {[lsearch [$t tag names $line.$c0] "cmd"]==-1} {set toggle "add"} else {set toggle "remove"}
		$t tag $toggle cmd $line.$c0 $line.$cn

		selection own $curwin.man

		return
	}


### 8.0: possible to take advantage of tcl_endOfWord?
	# special cases when clicking on parentheses
	set c [$t get $line.$char]
	if {$c eq "("} {
		if {$char>0 && [$t get $line.$char-1c]!=" "} {incr char -1} else {incr char}
	} elseif {$c eq ")"} {
		if {$char>0} {incr char -1}
	}


	set lparen 0; set rparen 0
	# single space between name and parenthesized volume ok (found mainly in apropos but some page too)
	set fspace 0

	# gobble characters forwards
	for {set cn $char} {$cn<=$lineend && [regexp -nocase $manchars [set c [$t get $line.$cn]]]} {incr cn} {
		if {$c eq "("} {
			if {!$lparen} {set lparen $cn} else break
		} elseif {$c eq ")"} {
			if {!$rparen} {set rparen $cn; incr cn}
			break
		} elseif {$c eq ":" && ([string is space [$t get $line.$cn+1c]] || [string is space [$t get $line.$cn-1c]])} {
			break
		} elseif {[string is space $c]} {
			if {!$lparen && !$fspace && $cn<$lineend && [$t get $line.$cn+1c] eq "("} {set fspace 1} else break
		}
	}
	incr cn -1

	# gobble characters backwards
	for {set c0 $char} {$c0>=0 && [regexp -nocase $manchars [set c [$t get $line.$c0]]]} {incr c0 -1} {
		if {$c eq "("} {
			if {!$lparen} {set lparen $c0} else break
		} elseif {$c eq ")"} {
			break
		} elseif {$c eq ":" && ([string is space [$t get $line.$c0+1c]] || [string is space [$t get $line.$c0-1c]])} {
			break
		} elseif {[string is space $c]} {
			if {$lparen==[expr {$c0+1}] && !$fspace} {set fspace 1} else break
		}
	}
	incr c0

	# adjust if parentheses unbalanced
	if {!$lparen^!$rparen} {
		if {$lparen} {
			if {$char>$lparen} {set c0 [expr {$lparen+1}]} else {set cn [expr {$lparen-1}]}
			set lparen 0
		} else {
			# trim off right paren
			incr cn -1
		}

	# check for valid section number
	} elseif {$lparen && [lsearch $man(manList) [$t get $line.$lparen+1c]]==-1} {
		if {$char>$lparen} {set c0 [expr {$lparen+1}]} else {set cn [expr {$lparen-1}]}
		set lparen 0

	# nothing between parentheses
	} elseif {$lparen==[expr {$rparen-1}] && $lparen>0} {
		set cn [expr {$lparen-1}]

	# if have good parens, can't start with a "/"
	} elseif {$lparen && $rparen && [$t get $line.$c0] eq "/"} {
		incr c0
	} 

	# clean up sides
	while {$c0>0 && [lsearch {" "} [$t get $line.$c0]]>=0} {incr c0}
	while {$cn>$c0 && [lsearch {. - , " "} [$t get $line.$cn]]>=0} {incr cn -1}


	$t tag add hot $line.$c0 $line.$cn+1c
	set hyper [string trim [$t get $line.$c0 $line.$cn+1c]]
	# if clicked on absolute name, it's probably not a man page -- it is if I generated it
	#if [string match "/*" $hyper] {set hyper "<$hyper"}

	set manx(hotman$t) $hyper
}


proc manInstantiate {} {
	global stat manx

	incr stat(instantiation)
	incr manx(uid)
	incr manx(outcnt)
	set w [TkMan]
	manOutput

	return $w
}


proc manOutput {} {
	global manx

	set wins [lmatches ".man*" [winfo children .]]

	# make list of output choices
	set titleList {}
	foreach i [lsort -dictionary $wins] {
		set title "#[string range $i 4 end]"
		# special case for main window
		if {$title eq "#"} {append title 1}
		lappend titleList $title $i
	}

	# update list on each instantiation
	set wincnt 0
	foreach w $wins {
		set mb $w.output; set m $mb.m
		$m delete 0 last
		set mcnt 0
		foreach {label val} $titleList {
			set newlabel [expr {$wincnt==$mcnt?"Output":"=>$label"}]
			$m add radiobutton -label $label -variable manx(out$w) -value $val \
				-command "$mb configure -text $newlabel"
			incr mcnt
		}
		manMenuFit $m
		# if pointing to a zapped instance, reset to self
		if {![winfo exists $manx(out$w)]} {set manx(out$w) $w; $w.output configure -text "Output"}

		incr wincnt
	}

	# if multiple choices, show menu
	if {$manx(outcnt)==1} {
		pack forget .man.output
	} else {
		foreach w $wins {pack $w.output -before $w.occ -padx 2 -side left -expand yes}
	}
}


#--------------------------------------------------
#
# file completion
#
#--------------------------------------------------

proc manFilecomplete {w} {
	global manx

	set t $w.show; set wi $w.info
	set line $manx(typein$w)
	set file [string trim [llast $line] "<"]
	set posn [string last $file $line]

	set ll [llength [set fc [filecomplete $file]]]
#puts stdout "$line, $file, $posn, $fc"

	# check for no matches or more than one match
	if {!$ll} {
		manWinstderr $w "no matches"
		return
	} elseif {$ll>=2} {
		set matches {}; foreach i $fc {lappend matches [file tail $i]}
		if {[string length $matches]<50} {
			manWinstderr $w [lrest $matches]
		} else {
			manTextOpen $w
			$t insert end [lrest $matches]
			manTextClose $w
		}
		set fc [lfirst $fc]
	}

	# show new file name
	set manx(typein$w) [string range $line 0 [expr {$posn-1}]]$fc

	$w.mantypein icursor end
	$w.mantypein xview moveto 1
}


#--------------------------------------------------
#
# manNewMode -- collect mode change inits in single place
#	 types of modes: section, man, txt, apropos, glimpse, help
#
#--------------------------------------------------

proc manNewMode {w mode {n {""}}} {
	global man manx stat item2posn

	catch {unset item2posn}
	$w.c delete all
	set manx(tryoutline$w) 0

	set t $w.show
	$t tag add area 1.0; $t tag configure area -elide 0

	# save old highlights --> done continuously
#	manHighlights $w
	$w.high configure -foreground $man(buttfg) -background $man(buttbg) -font gui

	# save old yview
#	if {[$t index @0,0]==1.0 || [catch {if {[$t index @0,0]!=1.0} {set manx(yview,$manx(hv$w)) [$t index $manx(cursect$t)]}}]} {set manx(yview,$manx(hv$w)) [$t index @0,0]}

	set y [$t index @0,0]
	if {[$t tag ranges lastposn]!=""} {
		set y [$t index lastposn.first]
	} elseif {[$t tag ranges spot]!="" && [$t bbox spot.first]!=""} {
		set y [$t index spot.first]
	} elseif {[info exists manx(cursect$t)] && [set csy area$manx(cursect$t).first]!="" && [$t tag ranges $csy]!="" && [$t compare $csy > $y]} {
		set y $csy
	}
	# set to first nonblank line
	while {[$t compare $y < end] && [$t get $y] eq "\n"} {append y "+1l"}
#puts "save y for $manx(hv$w)"
	set manx(yview,$manx(hv$w)) [manPosn2OutnOff $t $y]

	set manx(oldmode$w) $manx(mode$w)
	set manx(mode$w) $mode
	set manx(manfull$w) ""
	set manx(catfull$w) ""
	set manx(man$w) ""
	set manx(name$w) ""
	set manx(num$w) ""
	set manx(tryoutline$w) 0

	# don't have to explicitly remove tags: done when delete all text "underneath"

	# reset searching
#	set manx(search,string$w) ""
	set manx(search,oldstring$w) ""
	manLineCnt $w ""
	searchboxKeyNav "" Escape 0 $t $w.info 0
#	if {$mode eq "section"} {searchboxKeyNav C s 0 $t "" 1}
	after 5 selection clear $t

#	set sbx(lastkeys$w) ""
	set manx(vect) 1
	set manx(try) 0
	set m $w.sections.m; eval destroy [winfo children $m]; $m delete 0 last
	# removing tag doesn't fire a Leave event
	$t configure -cursor left_ptr


	# disable various ui buttons for different types
	#   (paths, volumes, shortcuts, history always available)
	#
	#               man help txt info texi section apropos glimpse
	# yview          x   x    x   x    x     ?
	# sections       x   x        x    x
	# highlights     x   x    x        x
	# shortcuts +/-  x        x        x
	# print          x

	set high(0) disabled; set high(1) normal

	set h $high([lmatch {man help info texi rfc} $mode]); $w.sections configure -state $h
	set h $high([lmatch {man txt texi rfc help} $mode])
		# $w.high state controlled by highlighting code
		foreach i {high} {$w.$i configure -state $h}
#	if {![lmatch {man txt help} $mode]} {
##		foreach i {high hsub} {$w.$i configure -state disabled}
#	}
#	if {![lmatch {man txt rfc texi} $mode]} {
#		foreach i {stoggle} {$w.$i configure -state disabled}
#	}
	if {$man(print)!=""} {set h $high([lmatch man $mode]); .occ entryconfigure "Kill Trees" -state $h}

	manHyper $w $n
}


# returns outlinesect/lineoff.charoff
proc manPosn2OutnOff {t posn} {
	global manx

	if {[catch {scan [$t index $posn] "%d.%d" line char}]} return
	for {set s $posn+2c} {$s!="" && ![string match "js*" $s]} {set s [$t mark previous $s]} {}
	if {$s eq ""} {return "1/0.0"}

	scan [$t index $s] "%d" basestartline
	regexp {js(.*)} $s all basenum

	return "$basenum/[expr {$line-$basestartline}].$char"
#puts "*** $first => $baserel"
}


# set mouse clicks for hyperlinking
proc manHyper {w {n ""}} {
	global man manx

	set t $w.show

	# clear old settings
	foreach i {"Double-" ""} {
		foreach j {"" "Alt-" "Shift-"} {
			$t tag bind hyper <${j}${i}ButtonRelease-1> "format nothing"
		}
	}

	if {$man(hyperclick) eq "double"} {set mod "Double-"} else {set mod ""}
	$t tag bind hyper <ButtonRelease-1> "
		if {\$manx(hotman$t)!={}} { set manx(typein$w) \$manx(hotman$t) }
	"
	$t tag bind hyper <${mod}ButtonRelease-1> "+
		if {\$manx(hotman$t)!={}} { incr stat(man-hyper); manShowMan \$manx(hotman$t) $n \$manx(out$w) }
	"
	$t tag bind hyper <Shift-${mod}ButtonRelease-1> "
		if {\$manx(hotman$t)!={}} { incr stat(man-hyper); set manx(shift) 1; manShowMan \$manx(hotman$t) $n \$manx(out$w) }
	"
	$t tag bind hyper <Alt-${mod}ButtonRelease-1> "
		if {\$manx(hotman$t)!={}} { set manx(typein$w) \$manx(hotman$t); manShowMan <\$manx(hotman$t) \$manx(out$w) }
	"

	# (<Button-1> and <Button1-Motion> don't change)
}



#--------------------------------------------------
#
# manXXX - miscellaneous medium-level commands
#
#--------------------------------------------------

# just jab some text into the widget regardless of state
proc manTextPlug {t posn args} {
	set state [$t cget -state]; $t configure -state normal
	eval $t insert $posn $args
	$t configure -state $state
}

proc manTextOpen {w} {
	global man manx

	#raise $w
	cursorBusy
	set t $w.show
	$t configure -state normal
	$t delete 1.0 end
	# delete all marks and tags
	set manx(sectposns$w) ""
	set manx(cursect$t) js1
	foreach i [$t mark names] {if {$i!="insert"&&$i!="current"} {$t mark unset $i}}
	foreach i [$t tag names] {if {[regexp {(area)?js\d*} $i]} {$t tag delete $i}}
	$t mark set js1 1.0; $t mark gravity js1 left
}

proc manTextClose {w} {
	set t $w.show

	# zap final newline so last line is flush with bottom
	if {[$t get "end -2c"] eq "\n"} {$t delete "end -2c"}

	$t tag add hyper 1.0 end

	if {[lsearch [$t mark names] "endcontent"]==-1} {$t insert end " "; $t mark set endcontent end-1c}
	$t configure -state disabled
	cursorUnset
	$t mark set xmark 1.0
#	if {[lsearch [$t mark names] "endcontent"]==-1} {$t mark set endcontent end}
}

proc manResetEnv {} {
	global env man manx mani

	set manpath {}
	foreach i $manx(paths) {if {$man($i)} {append manpath :$i}}
	set env(MANPATH) [string range $manpath 1 end]

	# also updates contents of volume listings
	foreach i $manx(manList) {
		if {[lsearch $manx(specialvols) $i]==-1 || $i eq "all"} {set mani($i,form) ""}
	}
}

proc manSetSect {w n} {
	global manx mani

	set manx(cursect$w) *

	# passed full pathname, search for volume
	if {[regexp {^([A-Z]:)?/} $n]} {
		set dir [file dirname $n]
		# try to find (possibly remapped) volume
		foreach vol $mani(manList) {
			if {[lsearch -exact $mani($vol,dirs) $dir]!=-1} {
				set manx(cursect$w) $vol
#				set f [lsearch -exact $mani(manList) $vol]
				return $vol
			}
		}

		# else if has .<char>, take that
		if {[regexp {\.(.)[^/\.]*$} $n all letter]} {
			set manx(cursect$w) $letter
			return $letter
		}

	# passed alphanum, use if valid
	} elseif {[set f [lsearch $manx(manList) $n]]!=-1} {
		set manx(cursect$w) $n
	}
#		$w.volnow configure -text "([lindex $manx(manList) $f]) [lindex $manx(manTitleList) $f]"
#$w.volnow configure -text ""
	return $n
}

# put entire pulldown menu on screen, using progressively smaller fonts as necessary
proc manMenuFit {m} {
	global man manx

	if {[winfo class $m]!="Menu"} {puts stderr "$m not of Menu class"; exit 1}
	if {[$m index last] eq "none"} return

	set sh [winfo screenheight $m]

	# starting with current gui font size, pick smaller font as needed
	# until all entries fit on screen or out of smaller fonts
	set ok 0
	for {set i [expr {[lsearch $manx(sizes) $man(gui-points)]+1}]} {$i>=0} {incr i -1} {
		set p [lindex $manx(pts) $i]
		set f [spec2font $man(gui-family) $man(gui-style) $p]
		$m configure -font $f; update idletasks
		set mh [winfo reqheight $m]
#DEBUG {puts stderr "manMenuFit $m: $f, $mh, $sh"}
		if {$mh<$sh} {set ok 1; break}
	}

	# if menu still too big for screen, clip entries from bottom until it is
	if {!$ok} {
		set ctr 0
		# kind of heavyweight but don't need to do this often
		while {[winfo reqheight $m]>=$sh} {
			$m delete last; incr ctr; update idletasks
		}
		# make space for "too many" at bottom
		$m delete last; incr ctr
		$m add command -label "($ctr too many to show)" -state disabled
	}
}


#--------------------------------------------------
#
# manInit -- determine which sections exist,
#
#--------------------------------------------------

proc manInit {} {
	global man manx mani

	if {$manx(init)} return

	manReadSects
	# MANPATH may have shifted during startup
	manResetEnv
	set manx(init) 1
}



# max levels = 2 for man (section, subsection), 4 for Texinfo (chapter, section, subsection, subsubsection), help = 3 (h1, h2, h3)
set manx(MAXLEVELS) 4


# man page, Texinfo, Help
# THIS IS A BOTTLENECK
proc manShowManFoundSetText {w t key} {
	global man manx


	set alljs [lmatches "js*" [$t mark names]]
	if {[llength $alljs]==0} {set alljs 1.0}
	set manx(sectposns$w) [lsort -dictionary $alljs]
	set manx(nextposns$w) [concat [lrange $manx(sectposns$w) 1 end] endcontent]
	set manx(cursect$t) [lfirst $manx(sectposns$w)]


	# fix up sections: remove hyper tag and reformat short sections -- always
	# if short enough and no subsections, de-section-ify it.  don't see diffs, though
	# count lines in each section (not shown for short sections)
	set manx(sectname$t) {}
	# can speed up processing of Texinfo by processing in bulk, which is good because they have many header lines
	if {$manx(mode$w) eq "texi"} {
		if {$man(showsectmenu)} {set manx(sectname$t) [split [$t get [lfirst $manx(sectposns$w)] "[llast $manx(sectposns$w)] lineend"] "\n"]} else {set manx(sectname$t) ""}
		foreach now $manx(sectposns$w) {set manx(lcnt$now) [set manx(lcnt0$now) 0]}
		$t tag remove hyper 1.0 end
	} else {
		scan [$t index [lfirst $manx(sectposns$w)]] "%d" linenow
		foreach now $manx(sectposns$w) next $manx(nextposns$w) {
			lappend manx(sectname$t) [$t get $now "$now lineend"]
			scan [$t index $next] "%d" linenext
			set manx(lcnt$now) [set manx(lcnt0$now) [expr {$linenext-$linenow-1}]]
			set linenow $linenext
		}
		$t tag remove hyper $now "$now lineend"
	}

	set manx(sectlevels$t) {}
	$t configure -state normal
	foreach now $manx(sectposns$w) next $manx(nextposns$w) secttxt $manx(sectname$t) {
		lappend manx(sectlevels$t) [regsub -all {\.} $now {\.} junk]

		for {set sup $now} {[regexp $manx(supregexp) $sup all supnum]} {set sup "js$supnum"} {
			catch {incr manx(lcntjs$supnum) [expr {$manx(lcnt$now)+1}]}
		}

		set skip($now) 0

		# crunch short man sections, unless man(outline) off 
		if {$manx(mode$w) eq "man" && $man(outline) ne "off" && ($manx(lcnt$now)<=2 || ($manx(lcnt$now)<=5 && $secttxt ne "Synopsis" && $secttxt ne "Files")) && [lsearch -glob $manx(sectposns$w) $now.*]==-1} {
			set ss "$now linestart+1l"; set se "$now linestart+1l+$manx(lcnt$now)l"
			set fNAME [string equal $secttxt "Name"]; # normalized by RosettaMan
#			set fSYNOPSIS [string equal $secttxt "Synopsis"]; # only used once, not in loop

			# quick feasiblity check
			if {[$t compare "$ss+[expr {$manx(screencols)*2}]c" > $se]} {
			set utxt [$t get $ss $se]; regsub -all " +" $utxt "" txt; set txtlen [string length $txt]
#			if {$txtlen<60 || ($txtlen<80 && $fNAME)} {
#			if {$txtlen<$man(columns)-10 || ($txtlen<$man(columns)*1.1 && $fNAME)} {
			if {$txtlen<$manx(screencols) || ($txtlen<$manx(screencols)*1.1 && $fNAME)} {
				set skip($now) 1
				set manx(lcnt$now) [set manx(lcnt0$now) 1]

				# append lines onto header, replacing with \n
				# have to zap text in buffer rather than insert new text so as to preserve tags
				$t insert "$now lineend" "  "
#				$t insert "$now lineend" "  " {} $txt [expr {$fNAME?"sc":""}]
				for {scan [$t index $se-1l] "%d" i} {[$t compare $i.0 > $now]} {incr i -1} {
					while {[regexp "\[ \t\]" [$t get $i.0]]} {$t delete $i.0}
					# RosettaMan strips trailing spaces
					# make internals elided but keep \n's around for diff line numbers
#					if $fSYNOPSIS {$t insert $i.0 " //"}
					$t insert $i.0 " "; $t delete $i.0-1c; $t insert $i.0 "\n" elide
				}

				# strip out multiple spaces
				foreach {junk s} [$t tag nextrange h2 1.0] {}; append s "+3c"
				while {[set x [$t search "  " $s 2.0]]!=""} {$t delete $x}

#				set zapend [expr int([$t index $se])]
#				for {set i [expr int([$t index $ss])]} {$i<$zapend} {incr i} {$t delete $i.0 "$i.0 lineend"}

				# since accept more characters to put NAME on single line, make them small
				if {$fNAME} {$t tag add sc "$now linestart+7c" "$now lineend"}
			}
			}
		}
	}
	$t configure -state disabled



	set manx(tryoutline$w) [expr {$manx(mode$w) eq "texi" || ($man(outline) ne "off"
						  # exceptions: help page, full page fits on screen
						  && $manx(manfull$w) ne "_help" && [$t bbox endcontent] eq "")}]


	### after reading in text, build sections menu, count lines, show highlights
	# highlights
#	if {$manx(catfull$w)!=""} {set manx(hv$w) $manx(catfull$w)} {set manx(hv$w) $manx(manfull$w)}
	# always key highlights to name of source
	set manx(hv$w) $key


	if {$manx(tryoutline$w)} {
		for {set i 0} {$i<$manx(MAXLEVELS)} {incr i} {set last($i) ""}

		$t configure -state normal
		foreach now $manx(sectposns$w) level $manx(sectlevels$t) secttxt $manx(sectname$t) {
#if {![regexp {[[:lower:]]} $txt] && [string length $txt]>3} { set txt [string tolower $txt] } -- casified by RosettaMan

			# expand/collapse section and subsections by clicking on title
			if {!$skip($now)} {
				set closed 1; set imagename "closed"
				if {$manx(mode$w) eq "man" && ($man(outline) eq "allexp" || ([string match "allbut*" $man(outline)] && [regexp -nocase $man(outlinebut) $secttxt$manx(lcnt$now)]))} {set closed ""; set imagename "opened"}

				set tags [$t tag names "$now linestart"]
				$t image create "$now linestart" -image $imagename
				foreach tag $tags {$t tag add $tag "$now linestart"}

				# number of lines within each section (# subsections in Texinfo)
				if {$manx(lcnt$now)>0} {$t insert "$now lineend" "     $manx(lcnt$now)" sc}
				#if {$firstsect} {$t insert "$eol lineend" "  lines"; set firstsect 0}

				$t tag configure area$now -elide $closed
				$t tag add outline "$now linestart" "$now lineend"; # if +1l can click to area off the right
				# maybe indent heading only, not body
				set lmar [expr {0.3*(1+$level)}]c; $t tag configure area$now -lmargin1 $lmar -lmargin2 $lmar
			}

			# man page subsections always visible
			if {$level>0 && $manx(mode$w) eq "man"} {$t tag add alwaysvis "$now linestart" "$now lineend+1c"}

			# at start of new entity at that level, close up everything at that level and below (== higher #)
			for {set j $level} {$j<$manx(MAXLEVELS)} {incr j} {
				if {$last($j)!=""} {$t tag add area$last($j) "$last($j) lineend" "$now linestart"; set last($j) ""} else break
			}
			set last($level) $now
		}

		for {set j $level} {$j<$manx(MAXLEVELS)} {incr j} {
			if {$last($j)!=""} {$t tag add area$last($j) "$last($j) lineend" "endcontent"} else break
		}
		$t configure -state disabled
	}


	# adjust priorities after flurry of tag creation
	foreach tag [concat $manx(show-tags) hyper elide] {$t tag raise $tag}


#	manHighlights $w get --> man pages want to attach highlights after diffs so offsets in menu accurate
#	manYview $w	--> let Texinfo fault in corresponding section

	if {$man(showsectmenu)} {after 1000 manMakeSectMenuAfter $w $t}

	# crucial "after" to prevent whole system from locking up!
	# maybe works ok with Tcl 8.0 final; have to try that some time
	after 100 focus $t
#	focus $t
}

proc manMakeSectMenuAfter {w t} {
	global man manx

	# make sections menu
	set m [set mb $w.sections].m
	if {$manx(tryoutline$w)} {
# && [winfo manager $mb]
		$m add command -label "Expand next/scroll" -accelerator "Return" -command "manDownSmart $w $t"
# people can figure this out without help
		$m add command -label "Toggle current" -accelerator "Button 1 on header" -command "manOutline $t -1 \$manx(cursect$t)"
		$m add command -label "Current + hierarchy" -accelerator "Shift-Button 1 on header" -command "manOutline $t -1 \$manx(cursect$t) 1"
# believe me, you don't want this
#		if {$manx(mode$w) eq "man"} {$m add command -label "Expand All" -command "manOutline $t {} * 1; $t yview moveto 0"}
		# warning: on=0

		set manx(texishowsubs) ""
		if {$manx(mode$w) eq "texi"} {
			$m add checkbutton -label "Show All Subsection Heads" -variable manx(texishowsubs) -onvalue 0 -offvalue "" -command "foreach tag {section subsection subsubsection} {$t tag configure \$tag -elide \$manx(texishowsubs); $t tag raise \$tag}; $t yview moveto 0"
			if {[catch {$t index js2}] || [llength $manx(sectposns$w)]<40} {$w.sections.m invoke "last"}
		}
		$m add command -label "Collapse current" -accelerator "Button 3 anywhere" -command "manOutline $t 1 \$manx(cursect$t)"
		$m add command -label "Collapse all" -accelerator "Double-Button 3" -command "manOutline $t 1 *; $t yview moveto 0; if {\$manx(mode$w) eq \"man\"} {notemarks $w $t}"
		$m add separator
	}


	# compute number of levels to show in Sections (always build Sections in case put back in in medias res via Preferences)
	for {set i 0; set prefix ""} {$i<$manx(MAXLEVELS)} {incr i} {
		set clevel($i) 0
		set pfx($i) $prefix; append prefix "   "
	}

	foreach level $manx(sectlevels$t) {incr clevel($level)}

	set showlevel 0
	set scnt $clevel(0)
	for {set i 1} {$i<$manx(MAXLEVELS)} {incr i} {
		incr scnt $clevel($i)
		if {$scnt>50} break
		incr showlevel
	}

	set first 1
	foreach now $manx(sectposns$w) txt $manx(sectname$t) level $manx(sectlevels$t) {
		if {$level<=$showlevel} {
			$m add command -label "$pfx($level)$txt" -command "incr stat(page-section); manOutlineYview $t $now"
			# may have stuffed more text into top
			# (also have to special case 1.0 in manOutlineYview)
			if {$first} {$m entryconfigure last -command "incr stat(page-section); $t see 1.0"; set first 0}
		}
	}

#	if {![string match "_*" $key] && $man(headfoot)!=""} {
	if {$manx(mode$w) eq "man" && $man(headfoot) ne ""} {
		$m add separator
		$m add command -label "Header and Footer" -command "incr stat(page-section); $t yview endcontent"
#headfoot"
	}
	configurestate $mb
# [llength $ml]
#PROFILE "manMenuFit"
	after 500 manMenuFit $w.sections.m
#PROFILE "done manMenuFit" -- up to a quarter second for Emacs
}



proc manYview {w} {
	global manx man

	set t $w.show
	if {[catch {set y $manx(yview,$manx(hv$w))}]} {set y "1/1.0"
	} else {
		# with outlining, hard to determine last scroll position, so just highlight it
#$t tag remove lastposn 1.0 end; 
#puts -nonewline "\amanx(hv\$w)=$manx(hv$w).  nb $y => "
		regexp {(.*)/(.*)\.(.*)} $y all sect loff coff; set y "js$sect+${loff}l+${coff}c"
#puts $y
		if {[$t index $y]!=1.0} {
			if {$manx(tryoutline$w)} {nb $t lastposn $y $y} else {manOutlineYview $t $y}
		}
#		unset manx(yview,$manx(hv$w))
	}
	$t mark set xmark [$t index @0,0]
}


proc manOutlineYview {t line} {
	global man

	if {[catch {set line [$t index $line]}] || [$t compare $line < 2.0]} return; # don't open top section when first show page
	manOutline $t "" $line
	$t yview $line-$man(high,vcontext)l
	$t see $line
}

proc manOutlineSect {t sect} {
	global manx curwin

	if {[catch {set now [$t index $sect]}]} {return 0.0}
	regexp {(.*)/(.*)} [manPosn2OutnOff $t $sect] all new junk
#	set new [lfirst $manx(sectposns$curwin)]
#	foreach try $manx(sectposns$curwin) {
#		if {[$t compare "$try linestart" > $now]} break
#		set new $try
#	}
	return "js$new"
}



# smart scrolling: try to expand sections rather than scrolling
# if unexpanded section on sixth line or later, expand
proc manDownSmart {w t} {
	global man manx stat

	if {!$manx(tryoutline$w) || [lsearch {section apropos glimpse info} $manx(mode$w)]>-1 || [catch {$t index js1}]} {$t yview scroll 1 pages; return}
	incr stat(page-downsmart)

	set sect $manx(cursect$t)
	if {[$t bbox $sect] eq ""} {
		set sect [manOutlineSect $t @0,0]
		if {[$t bbox $sect] eq ""} {
			set sect [lindex $manx(sectposns$w) [expr {1+[lsearch $manx(sectposns$w) $sect]}]]
		}
	}

	set x [lsearch $manx(sectposns$w) $sect]
	while 1 {
		set openme [lindex $manx(sectposns$w) $x]
		if {$openme eq "" || [$t bbox $openme] eq ""} {
			$t yview scroll 1 pages
			break

		} elseif {[$t tag cget area$openme -elide]=="1"} {
			# optionally collapse previous at same level: 
			# high level structural context more important than last few lines of previous section

			if {$man(tidyout)} {
				set level [regsub -all {\.} $openme {\.} junk]; set curlevel 1000
				for {set i [expr {$x-1}]} {$i>=0} {incr i -1} {
					set cursect [lindex $manx(sectposns$w) $i]
					set curlevel [regsub -all {\.} $cursect {\.} junk]
					if {$curlevel<$level} {$t see $cursect; break}
					manOutline2 $t 1 $cursect
					#if {$curlevel==$level} break
				}
			}

			manOutline $t 0 [set manx(cursect$t) $openme]
			$t tag remove spot 1.0 end; $t tag add spot $openme

			break
		} else {incr x}
	}

	update idletasks
}



proc manOutline {t finv sect {prop 0}} {
	global manx curwin

	set time0 [clock clicks]

	if {!$manx(tryoutline$curwin) || [string trim $sect] eq ""} return

	# if explicitly playing with one section, don't subsequently open all of them
	set manx(hitlist$t) {}


	if {$sect eq "*"} {set sect $manx(sectposns$curwin)}

	if {[llength $sect]>1} {
		foreach s $sect {manOutline $t $finv $s $prop}
		return
	} elseif {![string match "js*" $sect]} {
		# if not passed an outline tag, search for nearest previous one
		if {[catch {set now [$t index $sect]}]} return
		set sect [manOutlineSect $t $sect]
	}

	set oldfinv [$t tag cget area$sect -elide]
	if {$finv==-1} {
		set finv [expr {$oldfinv==""?1:""}]
	} elseif {$finv==0} {set finv ""}

	# could be disconcerting, have to see how it wears
	if {$finv==""} { foreach tag $manx(show-ftags) {$t tag remove $tag 1.0 end} }

	set sects $sect
	if {$prop} {
		set su $sect
		# close up parents
		if {$finv=="1"} {
			while {[regexp $manx(supregexp) $su all sunum]} {lappend sects [set su "js$sunum"]}

		# open up all children
		} else {
			set lev [regsub -all {\.} $sect {\.} junk]
			foreach s [lrange $manx(sectposns$curwin) [expr {1+[lsearch $manx(sectposns$curwin) $sect]}] end] {
				if {[regsub -all {\.} $s {\.} junk] <= $lev} break
				lappend sects $s
			}
		}
	}
	foreach s $sects {manOutline2 $t $finv $s}

	# maintain context
	if {$finv!=1} {
		$t yview [set manx(cursect$t) $sect]
		if {[$t dlineinfo $sect-5l] eq ""} {$t yview scroll -5 units}
	}

# this is very fast now -- if $manx(mondostats) {manWinstdout $curwin "[lfirst [manWinstdout $curwin]]    time [expr ([clock clicks]-$time0)/1000000.0] sec"}
}


proc manOutline2 {t finv sect} {
	global man manx curwin texix$t stat
	upvar #0 texix$t texix

	# if showing, show parent too
	if {$finv!=1} {
		if {[regexp $manx(supregexp) $sect all num]} {manOutline2 $t $finv "js$num"}
	}
	if {[lsearch $manx(sectposns$curwin) $sect]==-1 || [lsearch -exact [$t tag names $sect] outline]==-1} return

	set oldfinv [$t tag cget area$sect -elide]
	if {$finv==$oldfinv} return

	$t tag configure area$sect -elide $finv
	set txtstate [$t cget -state]
	$t configure -state normal
	$t image configure "$sect linestart" -image [expr {$finv==1?"closed":"opened"}]
#$man(subsect-show)!="never"
#$man(subsect-show)
	$t configure -state $txtstate
	if {$finv==1} {incr stat(outline-collapse)} else {incr stat(outline-expand)}

	# generalize this
	# if Texinfo, may need to format (after expansion, otherwise have to search in nested elide)
	if {$finv!=1 && $manx(mode$curwin) eq "texi"} {
# && $texix($sect)!=""} {
		cursorBusy 0
		texiCallback $t $sect; # use anchored points to ease bookkeeping for texiMarkup
		cursorUnset
		scan [$t index end-1c] "%d" lastline 
		manLineCnt $curwin $lastline; # counts \n-terminated lines, sigh
	}
}


proc manLineCnt {w cnt {unit ""}} {
	global man manx

	if {$cnt==""} {$w.search.cnt configure -text ""; return}

	if {$unit==""} {
		if {$man(lengthchunk) eq ""} return;	# no report
		set unit [textmanip::plural $cnt $man(lengthchunk)]
		set cnt [expr {1+int($cnt/$manx($man(lengthchunk)-scale))}]
	}
	$w.search.cnt configure -text "$cnt $unit"
}


proc manManPipe {f} {
	global man manx

#	if {$man(gtar)!="" && [regexp "(.*\.tar($manx(zregexp)?))/(.+)" $f all tar z subf]} {
#		if {$z!=""} {set z "z"}
#		set pipe "$man(gtar) -xO${z}f $subf"
#		if {[regexp $manx(zregexp) $subf]} {append pipe " | $man(zcat)"}; # compress within tar
#
#	} else
	if {[regexp $manx(zregexp) $f] || [regexp $manx(zregexp) [file dirname $f]]} {
		set pipe $man(zcat)
	} else {set pipe "cat"}

	return "$pipe $f"
}

# (proper) man page and text file finishings
proc manShowManStatus {w} {
	global man manx pagecnt

	set t $w.show; set wi $w.info

	### update status information

	# show section
	manSetSect $w $manx(manfull$w)

	# typein field
	set manx(typein$w) $manx(name$w)
	$w.mantypein icursor end

	# history - save entire path, including any compression suffix
	set manx(history$w) \
		[lrange [setinsert $manx(history$w) 0 [list $manx(manfull$w)]] 0 [expr {$man(maxhistory)-1}]]
	# should do this as a postcommand, but that's too messy
	set m [set mb $w.history].m
	$m delete 0 last
	$m post 0 0; $m unpost; # needed to compensate for Tk menu bug
	foreach i $manx(history$w) {
		if {[llength [lfirst $i]]>=2} {set l [lfirst $i]} else {set l $i}
		if {![regexp {^[|<]} $l]} {set l [zapZ [file tail $l]]}
		$m add command -label $l -command "incr stat(man-history); manShowMan $i {} $w"
	}
	configurestate $mb
# [llength $manx(history$w)]
	manMenuFit $m


	# shortcuts
	manShortcutsStatus $w


	# line count
	scan [$t index end] "%d" linecnt 
	manLineCnt $w $linecnt

	# page count statistics
	set f [zapZ $manx(manfull$w)]
	if {![string match "<*" $f]} {set f [file tail $f]}
	if {![info exists pagecnt($f)]} {set pagecnt($f) [list 0 0 -1 0 [clock seconds]]}

	foreach {times lasttime cksum nlines firsttime} $pagecnt($f) break
	if {$firsttime==""} {set firsttime [clock seconds]}
	if {$cksum==""} {set cksum -1}
	set pagecnt($f) [list [expr {1+$times}] [clock seconds] $cksum $linecnt $firsttime]
}


proc zapZ! {f} {
	uplevel 1 set $f \[zapZ \[set $f\]\]
}
proc zapZ {f} {
	global manx
	return [expr {[regexp $manx(zregexp) $f]?[file rootname $f]:$f}]
}


#--------------------------------------------------
#
# manShowText -- use searching, etc. facilities for non-man page text
#	 to use via `send', pass full path name of text file to show
#
#--------------------------------------------------

proc manShowText {f0 {w .man} {keep 0}} {
	global man manx stat

	set wi $w.info

# maybe want to use `file' to check for ASCII files
#	if {![file readable $f] || [file isdirectory $f]} {
#		manWinstdout $w "Can't read $f"
#		return
#	}

	set t $w.show

	if {[string match <* $f0]} {
		set f [fileexp [string range $f0 1 end]]
		if {[string length $f]==0} return
		if {[regexp $manx(zregexp) $f]} {set f "|$man(zcat) $f"}
# {set f "|cat $f"}
	} else {set f [pipeexp $f0]}

	# strain out control characters and show nroff files
#	append f " | rman"

	manNewMode $w txt; incr stat(txt)

	manTextOpen $w
	if {[catch {
		set fid [open $f]
		$t insert end [read $fid]
		close $fid
	}]} {manTextClose $w; manWinstderr $w "Trouble reading $f0"; return}
	manTextClose $w
	if {!$keep} {pack forget $w.dups}

	if {[file isfile $f]} {cd [file dirname [glob $f]]}


	### update status information

	# could always save full path here, but that occupies too much screen real estate
	set manx(man$w) $f0
	set manx(num$w) X
	set manx(hv$w) [bolg [zapZ $f] ~]
	set manx(manfull$w) $f0
	set manx(catfull$w) $f
	set manx(name$w) $f0
	manShowManStatus $w

	manWinstdout $w $manx(manfull$w)
	manHighlights $w get; manYview $w
	focus $t

	return $f
}



#--------------------------------------------------
#
# manShowTexi -- use searching, etc. facilities for non-man page text
#	 to use via `send', pass full path name of text file to show
#
#--------------------------------------------------

proc manShowTexi {f0 {w .man} {keep 0}} {
	global man manx stat

	set t $w.show
	set wi $w.info

	set f $f0
#	if {[regexp $manx(zregexp) $f]} {set f "|$man(zcat) $f"}

	manNewMode $w texi; incr stat(texi)
#	manNewMode $w section; incr stat(texi)

#	set loading [clock clicks]
	manTextOpen $w
	texiShow $t $f $man(texinfodir)
#	$t insert js2 "$f dated [textmanip::recently [file mtime $realf]]\n\n" sc
	manTextClose $w
#	puts "loaded in [expr ([clock clicks]-$loading)/1000000.0] sec"

	if {!$keep} {pack forget $w.dups}


	# if all marks under chapter 1 (or 0), raise everyone up a level => just be robust to missing hierarchy

	### update status information

	# could always save full path here, but that occupies too much screen real estate
	set manx(man$w) $f0
	set manx(num$w) X
	set manx(hv$w) [bolg [zapZ $f] ~]
	set manx(manfull$w) $f0
	set manx(catfull$w) $f
	set manx(name$w) [file tail $f0]

	# Texinfo outline shows number of subsections (more useful than number of lines)
#	set outline [clock clicks]
	manShowManFoundSetText $w $t $manx(hv$w)
	manShowManStatus $w

#	foreach tag [lrange $manx(outline-show-v) 1 end] {$t tag raise $tag}
	# if only have one toplevel section, open it (otherwise just see single line of text)
#	if [catch {$t index js2}] {manOutline $t 0 js1} => good but superceded by showing header lines (higher level)

#	puts "outlining in [expr ([clock clicks]-$outline)/1000000.0] sec"

	manWinstdout $w $manx(manfull$w)
	manHighlights $w get
	if {[info exists manx(yview,$manx(hv$w))]} {
#puts "\amanx(yview,$f0)? => $manx(yview,$f0)"
		regexp {(.*)/(.*)} $manx(yview,$manx(hv$w)) all sect junk
		texiFault $t js$sect
#puts "\afaulting in js$sect [lindex $manx(sectname$t) [lsearch $manx(sectposns$w) $sect]]"
	}
#	focus $t	-- done by manShowManFoundSetText
	manYview $w

	return $f
}



#--------------------------------------------------
#
# manShowRfc -- use searching, etc. facilities for non-man page text
#	 to use via `send', pass full path name of text file to show
#
#--------------------------------------------------

proc manShowRfc {f0 {w .man} {keep 0}} {
	global rfcmap stat

 	manNewMode $w rfc; incr stat(rfc)

	manShowText $f0 $w $keep
#	manShowMan "$man(rfcdir)$rfcmap($num)/rfc$num.txt"
# one-time long wait (<10 sec) when show full list, then instant
# [find $man(rfcdir) "\[string match rfc.txt \$file]" {[llength $findx(matches)]==0 && $depth<=3}]
	# strip out page headers/footers
	set t $w.show
	set state [$t cget -state]
	$t configure -state normal
	while {[$t get 1.0] eq "\n"} {$t delete 1.0}
	set index 1.0
	while {[set index [$t search -forwards -regexp "^\f" $index end]]!=""} {
#puts "back @ $index"
		scan [$t index "$index linestart -1l"] "%d" back
		while {[$t get $back.0] ne "\n"} {incr back -1}
		while {[$t get $back.0] eq "\n"} {incr back -1}
		incr back
#puts "forward @ $index"
		scan [$t index "$index linestart +1l"] "%d" forward
		while {[$t compare $forward.0 < end] && [$t get $forward.0] ne "\n"} {incr forward}
		while {[$t compare $forward.0 < end] && [$t get $forward.0] eq "\n"} {incr forward}
		incr forward -1
		$t delete $back.0 "$forward.0 lineend"; # keep a \n separation (sometimes right, sometimes wrong)
	}

	# outline -- can't parse reliably
#puts "outline"
	if 0 {
	set index 1.0
	set js 1
	while {[$t get $index]!=" "} {set index [$t index $index+1l]}
	while {[set index [$t search -forwards -regexp {^[^ ]} $index+1l end]]!=""} {
#puts "outline js$js @ $index"
		$t mark set js$js $index; incr js
#		$t tag add search $index
	}
#puts "done"
	manShowManFoundSetText $w $t $f0
	}
	$t configure -state $state

	return $f0
}


#--------------------------------------------------
#
# manApropos -- show `apropos' (`man -k') information, w/dups filtered out, reformatted
#
#--------------------------------------------------

proc manApropos {name {w .man}} {
	global man manx mani stat

	if {$manx(shift)} { set manx(shift) 0; set w [manInstantiate] }
	set wi $w.info; set t $w.show

	if {$name eq ""} {set name $manx(man$w)}
	if {$name eq ""} {
		manWinstderr $w "Type in keywords to search for"
		return
	}

	set form {}
	lappend form " Apropos search for \"$name\"\n\n" {}
	manWinstdout $w "Apropos search for \"$name\" ..." 1

DEBUG {puts "manApropos: exec $man(apropos) $name $man(aproposfilter) 2>/dev/null"}
	if {[catch {set tmp [eval exec "$man(apropos) $name $man(aproposfilter) 2>/dev/null"]} info] || [string trim $tmp] eq ""} {
		if {$info ne ""} {
			lappend form $info i
		} else {
			lappend form "Nothing related found.\n" i
		}
		if {$man(glimpse)!=""} { lappend form "Try a full text search with Glimpse.\n" {}}
		set mani(apropos,cnt) 0
	} else {
		manNewMode $w aprops; incr stat(apropos)
		set mani(apropos,update) [clock seconds]
		set cnt 0
		foreach line [split $tmp "\n"] {
			# zap formatting codes if erroneously given roff source
			regsub "^\\.\[^ \t\]+" $line "" line
			# normalize tabs
			regsub -all "\[\t \]+" $line " " line
			# normalize spacing between names and descriptions to single tab
			regsub " - " $line "\t - " line
			# some idiot apropos index maker puts in "}}} {{{" before text excerpt
			regsub -all {[][{}"]} $line "" line
			# Solaris gives name of file, name of function within page
			if {[lfirst $line] eq [lsecond $line]} { regsub {^[ ]*[^ ]+[ ]*} $line "" line }

			if {[regexp "(\[^\t]+)\t+(.*)" $line all cmds desc]} {
			} elseif {[regexp "(.+)  +(.*)" $line all cmds desc]} {
			} else {set cmds [lindex $line 0]; set desc [lrange $line 1 end]}
#			foreach {cmds desc} [split $line "\t"] {} -- some apropos binaries don't write spaces?
			lappend form $cmds manref "\t$desc\n" {}
#$line "\n"
			incr cnt
		}
		.vols entryconfigure "apropos*" -state normal
# -label "apropos hit list ($cnt for \"$name\")"

		set mani(apropos,cnt) $cnt
		set manx(yview,apropos) 1/1.0
	}
	set mani(apropos,form) $form
	set mani(apropos,shortvolname) "apropos"

	manShowSection $w apropos
}



#--------------------------------------------------
#
# manHelp -- dump help text that's "compiled" offline
#
#--------------------------------------------------

proc manHelp {w} {
	global man manx stat tk_library

	set t $w.show; set wi $w.info

	manNewMode $w help; incr stat(help)
	wm title $w "$manx(title$w) v$manx(version)"
	set manx(manfull$w) "_help"
	set manx(name$w) "_help"

	manTextOpen $w
	# put in help first so marks set correctly (they stay correct subsequently as they float)
	manHelpDump $t
	# fixups
	$t tag remove h1 1.0 "1.0 lineend"; $t tag add title 1.0 "1.0 lineend"
	$t delete 2.0
#	set copyright [$t search "(c)" 1.0]
#	$t delete $copyright $copyright+3c; $t insert $copyright "\251"; $t tag add symbol $copyright
	$t image create 2.0 -image icon -padx 8 -pady 8
	$t mark set insert "author1+2lines lineend"
	$t insert insert "\t"
	$t image create insert -image face -align bottom -padx 8 -pady 8

	set demo [file join $tk_library demos widget]
	if {[file executable $demo]} {
		button $t.demo -text "run Tcl/Tk demo" -foreground $man(textfg) -background $man(textbg) -font $man(textfont) \
			-command "exec \[info nameofexecutable\] $demo &"
		$t window create [list [$t search "Tcl/Tk" 1.0]  lineend] -window $t.demo -align bottom -padx 8
	}

	# now add to opening screen
	# update warnings
	manManpathCheck
	set fWarn 0
	foreach warn {stray manpath mandesc} {
		if {$manx($warn-warnings)!=""} {
			$t insert 1.0 $manx($warn-warnings)\n\n
			set fWarn 1
		}
	}
	if {$fWarn} {$t insert 1.0 "Warnings\n\n" b}

	$t insert 1.0 $manx(updateinfo)

	manTextClose $w


	# translate SGML names to Tk marks
	set sectcnt 0; set subsectcnt 0
	foreach i [lsort -command "bytextposn $t " [$t mark names]] {
# can't ever do this because need numbers in, names out:  foreach i [lsort -dictionary [$t mark names]] {
		if {[string match "*1" $i]} { $t mark set js[incr sectcnt] $i; set subsectcnt 0; $t mark unset $i }
		if {[string match "*2" $i]} { $t mark set js$sectcnt.[incr subsectcnt] $i; $t mark unset $i }
	}

	manShowManFoundSetText $w $t "_help"
	manShowTagDist $w h2
	manHighlights $w get


	# use update and after for good interaction with rebuilding database
	update idletasks
	after 1 "manWinstdout $w \"TkMan v$manx(version) of $manx(date)\""
}

proc bytextposn {t a b} {
	return [expr {[$t compare $a < $b]?-1:[$t compare $a > $b]}]
}


#--------------------------------------------------
#
# manKeyNav -- keyboard-based navigation and searching
#    calls out to searchbox module
#
#--------------------------------------------------

proc manKeyNav {w m k} {
	global man manx

	set t $w.show; set wi $w.info
	if {[catch {set isearch [$t index isearch.first]}]} {set isearch -1}

	set firstmode [regexp "section|apropos" $manx(mode$w)]
	set casesen [expr {$firstmode?1:$man(incr,case)}]

	set fFound [searchboxKeyNav $m $k $casesen $t $wi $firstmode [expr {$manx(tryoutline$w)?"-elide":""}]]
#	if {!$fFound && $firstmode} {set fFound [searchboxKeyNav $m $k 0 $t $wi $firstmode]}
	if {[catch {set isearch2 [$t index isearch.first]}]} {set isearch2 -1}
	if {$isearch2!=-1 && $isearch!=$isearch2} {manOutlineYview $t isearch.first}

	return $fFound
}



#--------------------------------------------------
#
# manSave -- manage merging with old config file
# if passed name of save file, could put this into utils
#
#--------------------------------------------------

proc manSave {} {
	global man manx env

	if {[file dirname $manx(startup)] eq "/"} return; # no save file for root
	if {$manx(savegeom)} {set man(geom) [wm geometry .man]}
	set w [manPreferencesMake]
	if {[winfo exists $w]} {set man(geom-prefs) [geom2posn [wm geometry $w]]}

	set nfn $manx(startup)
	set ofn $manx(startup).bak

	if {![file exists $nfn] || [file writable $nfn]} {
		# thought about making backup only if current backup is more than a day old, so don't quickly propagate error to backup copy, but need backup in order to copy user code
		if {[file exists $nfn]} {file copy -force $nfn $ofn}
		if {[catch {set fid [open $nfn w]}]} {
			manWinstderr .man "$nfn is probably on a read-only filesystem"
			return
		}
		foreach p [info procs *SaveConfig] {eval $p $fid}
		puts $fid "manDot\n"
		puts $fid $manx(userconfig)

		# copy user code from old version
		if {[file exists $ofn]} {
			set ofid [open $ofn]
			set p 0
			while {[gets $ofid line]!=-1} {
				if {$p} {puts $fid $line} \
				elseif {$manx(userconfig) eq $line} {set p 1}
			}
			close $ofid
		}
		close $fid
	}

	# don't delete ~/.oldtkman
}



#--------------------------------------------------
#
# manSaveConfig -- dump persistent variables into passed file id
#
#--------------------------------------------------

proc manSaveConfig {fid} {
	global man manx high default tcl_platform tk_patchLevel

# if only persistent stuff in man array,
# could have general SaveConfig in utils.tcl

	# write out preamble
	puts $fid "#\n# TkMan v$manx(version)"
# insert $env(USER)?
	puts $fid "# configuration saved on [clock format [clock seconds]]"
	puts $fid "#"
	puts $fid "# Tcl [info patchleve]/Tk $tk_patchLevel   [winfo interps]"
	puts $fid "# $tcl_platform(os) $tcl_platform(osVersion) / $tcl_platform(machine), [winfo server .]"
	puts $fid "# screen [winfo vrootwidth .]x[winfo vrootheight .], [winfo visual .] [winfo screendepth .] / [winfo visualsavailable .]"
	puts $fid "#\n"

	set preamble {
		Elements of the man array control many aspects of operation.
		Most, but not all, user-controllable parameters are available
		in the Preferences panel.  All parameters are listed below.
		Those that are identical to their default values are commented
		out (preceded by \"#\") so that changes in the defaults will propagate nicely.
		If you want to override the default, uncomment it and change the value
		to its new, persistent setting.
	}
	foreach line [split [textmanip::linebreak $preamble] "\n"] {puts $fid "# $line"}
	puts $fid ""


	# save miscellaneous variables

	manStatsSet; # update its value
	# write out man(), commenting out if same as corresponding default()
	# maybe iterate through default array ==> no!  won't pick up man(/<directory>)'s
	foreach i [lsort [array names man]] {
		if {[info exists default($i)]} {
			set co [expr {$default($i) eq $man($i)? "#" : ""}]
			puts $fid "${co}set [list man($i)] [tr [list $man($i)] \n \n$co]"
		} elseif {[string match "/*" $i]} {puts $fid "set man($i) $man($i)"}
	}

	puts $fid "\n\n#\n# Highlights\n#\n"
#	puts $fid "# format: time, start/end pairs for use by text widget" -- too complicated to write by hand
	foreach i [lsort [array names high]] {
		puts $fid "set [list high($i)] [list $high($i)]"
	}

	puts $fid "\n"
}



#--------------------------------------------------
#
# manStats* -- cumulative statistics
#
#--------------------------------------------------

# write out new stats line
proc manStatsSaveFile {} {
	global man manx

DEBUG {puts -nonewline "manStatsSaveFile"}
	# if flag not set, don't bother
	if {$manx(statsdirty) && [file readable $manx(startup)] && [file writable $manx(startup)]} {

		# read in file
		set fid [open $manx(startup)]; set startup [read $fid]; close $fid

		manStatsSet
		foreach var {stats pagecnt} {
			set stats "set man($var) [list $man($var)]\n"

			# rewrite variable or instantiate new variable before userconfig, if such a line exists
			if {[regsub "set man\\($var\\)\[^\}\]+\}\n" $startup $stats nstartup]} {
#			if {[regsub "set man\\($var\\).*\n\}\n" $startup $stats nstartup]} -- eats too much!
				# problem copying from and into same variable, though seems to work in other cases
				set startup $nstartup
#puts "\n$startup\n"
DEBUG {puts -nonewline "\tfound existing variable"}
			} elseif {[regsub "\n\n$manx(userconfig)\n" $startup "\n\n$stats\n$manx(userconfig)\n" nstartup]} {
				set startup $nstartup
DEBUG {puts -nonewline "\tinserted before userconfig"}
			} else {
				append startup $stats
DEBUG {puts -nonewline "\tappended"}
			}
		}

		# write it out
		set fid [open $manx(startup) "w"]; puts -nonewline $fid $startup; close $fid
DEBUG {puts -nonewline "\tsaved to file"}
	}
DEBUG {puts ""}

	after [expr 5*60*1000] manStatsSaveFile
}


# save as name-value pairs so can extend list without positional dependencies leading to madness
set man(prof) {}
proc manStatsSet {} {
	global man manx stat pagecnt short prof

DEBUG {puts "manStatsSet"}
	trace vdelete stat w manStatsDirty
	trace vdelete pagecnt w manStatsDirty
	scan $man(stats) "%d" stat(cum-time)
	set newstats $stat(cum-time)

	# simple profile statistics
	set tmp {}
	foreach p [array names prof cnt-*] {
		set name [string range $p 4 end]
		lappend tmp [list $name $prof(cnt-$name) $prof(totaltime-$name)]
	}
	set man(prof) ""
	set cnt 0
	foreach p [lsort -decreasing -real -index 2 $tmp] {
		set name [lfirst $p]
		append man(prof) "\n\t" $name " \"$prof(cnt-$name) $prof(totaltime-$name)\""
		incr cnt
	}
	append man(prof) "\n"


	# bump up monolithic cumulative
	foreach i $manx(all-stats) {
		# get cumulative value
		if {[set index [lsearch $man(stats) $i]]>=0} {
			set stat(cum-$i) [lindex $man(stats) [expr {$index+1}]]
		} else {
			set stat(cum-$i) $stat($i)
		}

		# bump up cumulative totals
		incr stat(cum-$i) [expr {$stat($i)-$stat(cur-$i)}]
		set stat(cur-$i) $stat($i)

		lappend newstats $i $stat(cum-$i)
	}
	set man(stats) $newstats

	# shortcuts
	set man(shortcuts) {}
	foreach i $manx(shortcuts) {lappend man(shortcuts) [list $i $short($i)]}

	# page counts
	set man(pagecnt) ""
	set cnt 0
	# store in frequency order, so someone can easily delete entries with low counts to save space
	# create list
	set tmp {}
	foreach name [array names pagecnt] {lappend tmp [concat $name $pagecnt($name)]}; # want a destructive concat
	foreach i [lsort -index 1 -integer -decreasing $tmp] {
		set name [lfirst $i]
		# can't have sublists (sneaky stats regexp), but ok to put numbers in quotes
		append man(pagecnt) [expr {$cnt%2==0? "\n\t": " "}] $name " \"$pagecnt($name)\""
		# aw, all real editors can handle long lines
		#lappend man(pagecnt) $name [lfirst $pagecnt($name)] [lsecond $pagecnt($name)]
		incr cnt
	}
	append man(pagecnt) "\n"

	# for counts of browses, update last element
	set newchrono [lreplace $man(chronobrowse) end end "$manx(startuptime)/[expr {[clock seconds]-$manx(startuptime)}]/$manx(reading):$stat(man)/$stat(texi)/$stat(rfc)"]
	set man(chronobrowse) "\n\t"
	set cnt 0
	foreach tuple $newchrono {
		incr cnt
		append man(chronobrowse) $tuple [expr {$cnt%4==0? "\n\t": " "}]
	}
	append man(chronobrowse) "\n"


	trace variable stat w manStatsDirty
	trace variable pagecnt w manStatsDirty
	set manx(statsdirty) 0
}

# set trigger of writes to stat array to set flag
proc manStatsDirty {name1 name2 op} {
	global manx mani
DEBUG {puts "manStatsDirty: $name2"}
	set manx(statsdirty) 1
#	set mani(census,form) "" -- cleared before shown, but keep for random
}


#--------------------------------------------------
#
# Startup initialization and validity checks
#
#--------------------------------------------------


# after reading .tkman variables but before executing code

proc manDot {} {
	global manx

	manManManx

	# configuring a font should create it if necessary, as with text tags, but it doesn't
	foreach font {textpro gui guisymbol guimono peek textmono} {font create $font}
	manPrefDefaultsSet

	# make window here so ~/.tkman commands can manipulate it without `after'
	toplevel .man -class TkMan
	manPreferencesGet fill

	set manx(manDot) 1
}

proc manManManx {} {
	global man manx
	# these get set to man counterparts, unless overwritten by command line options
	foreach i {
			iconify iconname iconbitmap iconmask iconposition
			geom 
#glimpsestrays
		} {
		if {![info exists manx($i)]} {set manx($i) $man($i)}
	}
}


#
# check for existence of supporting executables, with right versions
# this information usually fine, usually just taxing startup time,
# so defer to a thread.  So have to wait a little for Statistics, who cares?
#

proc manBinCheck {{inx 0} {err 0}} {
	global man manx env stat

#	set homebin $env(HOME)/bin
#	set needmybin [expr {[file readable $homebin] && [llength [glob -nocomplain $homebin]]>0}]
# if person dosn't have ~/bin in PATH, he should know about it already (as compared to ~/man)

	# binaries checks for rman, sed, ...
	set var [lindex $manx(binvars) $inx]
	set val [string trim [set $var]]
	if {$val!=""} {
DEBUG {puts "manBinCheck on $var"}

		# first check for existence and executability...
		foreach pipe [split $val "|"] {
			set bin [lfirst $pipe]
			if {$manx(doze)} {append bin ".exe"}
			# likely check for some binaries more than once, as with gzip/gzip for compress/uncompress, but just a couple so don't mind duplicating a little work
			set found 0
#; set exe 0

#puts stderr "checking $var's $bin"
			if {[string match "/*" $bin]} {set pathlist [file dirname $bin]; set tail [file tail $bin]
			} else {set pathlist $manx(bin-paths); set tail $bin}

			foreach dir $pathlist {
				if {$dir eq "."} continue
				set fullpath $dir/$tail
				# ignore file if not executable, just like shells do
				if {[file isfile $fullpath] && [file executable $fullpath]} {
					set found 1
#					if {[file executable $fullpath]} {set exe 1}
#puts stderr "\tfound @ $dir"
					set stat(bin-$bin) $fullpath
DEBUG { puts "$bin => $fullpath" }
					break
				}
			}

			if {!$found} {
				puts stderr "$bin not found in your PATH--check the $var variable in $manx(startup) or the Makefile."
				incr err
#			} elseif {!$exe} {
#				puts stderr "$bin found but not executable--check permissions."
#				incr err
			} else {
				# ... then check for proper versions of selected executables
				if {[set info [lassoc $manx(bin-versioned) $tail]]!=""} {
#					lset $info flag minvers
					foreach {flag minvers} $info {}
					# use 2> /dev/null because glimpseindex triggers error message on FreeBSD
					set execerr [catch {set lines [exec $fullpath $flag < /dev/null 2> /dev/null]} info]
				} elseif {[string match "g*" $tail]} {
					# could be a GNU -- maybe take this out since it lengthens startup for all in exchange for small benefit for few
					set minvers 0.0
					#foreach flag {"--version" "-V" "-v"} -- takes to long to start up
					# GNU programs print version information to stderr; should be stdout
					set execerr [catch {set lines [exec $fullpath $flag < /dev/null]} info]
					set execerr 0; set lines $info
				} else continue

				if {$execerr && $minvers==0.0} {
					# nothing
				} elseif {$execerr} {
					puts "ERROR executing \"$fullpath $flag\": $info\a"
					incr err
				} else {
					set line ""; foreach line [split $lines "\n"] { if {$line!=""} break }
					# grok version number
					set vers unknown
					if {$line eq "" || ![regexp $manx(bin-versregexp) $line vers] || [package vcompare $minvers $vers]==1} {
						if {$minvers!=0.0} {
							puts stderr "$bin is version $vers--must be at least $minvers."
							incr err
						}
					} else { set stat(bin-$bin-vers) $vers }
				}
			}
		}
	}

	# chain to next one
	incr inx
	if {$inx<[llength $manx(binvars)]} {
		after 1000 manBinCheck $inx $err
	} else {
		if {$err} {exit 1}
		.occ entryconfigure "Statistics*" -state normal
	}

#	if [string match "3*" $stat(bin-rman-vers)] {set manx(rman-source) 1}
}

proc manParseCommandline {} {
	global manx argv argv0 env geometry

	for {set i 0} {$i<[llength $argv]} {incr i} {
		set arg [lindex $argv $i]; set val [lindex $argv [expr {$i+1}]]
		switch -glob -- $arg {
			-help -
			-h* -
			--help {
				set helptxt {
					[-M <MANPATH>] [-M+ <paths to append to MANPATH>] [-+M <paths to prepend to MANPATH>]
					[-[!]iconify] [-version]
					[-title <string>] [-startup <file>] [-[!]debug] [<man page>[(<section>)]]
				}
				puts -nonewline "tkman"
				foreach line [split [textmanip::linebreak $helptxt 70] "\n"] { puts "\t$line" }
				exit 0
			}
			-M {set env(MANPATH) $val; incr i}
			-M+ {append env(MANPATH) ":$val"; incr i}
			-+M {set env(MANPATH) "$val:$env(MANPATH)"; incr i}
			-dpi {set manx(dpi) $val; lappend manx(dpis) $val; incr i}
			-profile {set manx(profile) 1}
			-iconname {set manx(iconname) $val; incr i}
			-iconmask {set manx(iconmask) $val; incr i}
			-iconposition {set manx(iconposition) $val; incr i}
			-iconbitmap {set manx(iconbitmap) $val; incr i}
			-icon* {set manx(iconify) 1}
			-noicon* {set manx(iconify) 0}
			-quit {if {[string match no* $val]} {set manx(quit) 0}; incr i}
			# put the more permissive option name patterns down below
			-start* {set manx(startup) $val; incr i}
			-data* {puts stderr "-database option obsolete: database kept in memory"; incr i}
			--v* -
			-v* {puts stdout "TkMan v$manx(version) of $manx(date)"; exit 0}
			-t* {set manx(title) $val; incr i}
			-d* {set manx(debug) 1; set manx(quit) 0; set manx(iconify) 0}
			-nod* {set manx(debug) 0}
			-* {puts stdout "[file tail $argv0]: unrecognized option: $arg"; exit 1}
			default {
				after 2000 manShowMan $arg {{}} .man
				# permit several???  add extras to History?
				break
			}
		}
	}
	# grr, special case
	if {[info exists geometry]} {set manx(geom) $geometry}
}


proc ASSERT {args} {
	if {![uplevel 1 eval $args]} {
		puts "ASSERTION VIOLATED: $args"
		exit 1
	}
}

proc DEBUG {args} {
	global manx
	if {$manx(debug)} {uplevel 1 eval $args}
}

set manx(lastclick) 0
proc PROFILE {msg} {
	global manx
	set clicknow [clock clicks]
# @ [clock clicks]
	if {$manx(profile)} {puts "$msg, delta=[expr {$clicknow-$manx(lastclick)}]"}
	set manx(lastclick) $clicknow
}




##################################################
###
### start up
###
##################################################

### environment checks
if {[package vcompare [info tclversion] $manx(mintcl)]==-1 || [package vcompare $tk_version $manx(mintk)]==-1} {
	puts -nonewline stderr "Tcl $manx(mintcl)/Tk $manx(mintk) minimum versions required.  "
	puts stderr "You have Tcl [info tclversion]/Tk $tk_version"
	exit 1
} elseif {int([info tclversion])-int($manx(mintcl))>=1 || int($tk_version)-int($manx(mintk))>=1} {
	puts stderr "New major versions of Tcl and/or Tk may have introduced\nincompatibilies in TkMan.\nCheck the TkMan home site for a possible new version.\n"
}
set manx(doze) [string equal "windows" $tcl_platform(platform)]


#--------------------------------------------------
#
# set defaults for shared global variables
#
#--------------------------------------------------

# # # # # # # # # # # # # # # # # # # # # # # # # #
# DON'T EDIT THE DEFAULTS HERE--DO IT IN ~/.tkman #
# # # # # # # # # # # # # # # # # # # # # # # # # #

# man() = persistent variables
# manx() = x-pire, system use, command line overrides

set curwin [set w .man]

#
# man
#

set man(manList) {1 2 3 4 5 6 7 8 9 l o n p D}
set man(manTitleList) {
	"User Commands" "System Calls" Subroutines
	Devices "File Formats"
	Games "Miscellaneous" "System Administration" "*** check contrib/*_bindings ***"
	Local Old New Public "*** check contrib/*_bindings ***"
}
set man(stats) [clock seconds]
set man(time-lastglimpse) -1
set manx(styles) {normal bold italics bold-italics}
set manx(pts) {8 9 10 12 14 18 24 36}
set manx(sizes) {tiny small medium large larger huge}
set man(gui-family) "Times"
set man(gui-style) "bold"
set man(gui-points) "small"
set man(text-family) "New Century Schoolbook"
set man(text-style) "normal"
set man(text-points) "small"
set man(vol-family) "Times"
set man(vol-style) "normal"
set man(vol-points) "small"
#foreach f {diffa diffc diffd} {set man($f-family) $man(text-family)}
set man(diffd-style) "normal"
set man(diffc-style) "bold-italics"
set man(diffa-style) "italics"
set man(textfont) textpro

set manx(fontfamilies) [lsort [string tolower [font families]]]


### general tags
set man(isearch) {-background gray}
#set man(search) reverse
set man(search) {-background orange}; # eye-catching but not overbearing on long stretches
set man(lastposn) {-background gray90}
#set man(cmd) {-background green}
set man(autokey) {-foreground red}
set man(synopsisargs) {-background green}
set man(spot) {-background red}
set man(manref) {sanserif -foreground blue}
#set man(manrefseen) {sanserif -foreground #00C} -- not useful
# -underline yes}
set man(hot) {-foreground red}
# -underline yes}
set man(highlight) {-background #ffd8ffffb332}; # a pale yellow
set man(indent) {-lmargin1 5m -lmargin2 10m}
set man(indent2) {-lmargin1 10m -lmargin2 15m}


### Texinfo tags
# don't need to have named fonts for tags
set manx(tags) {diffa diffd diffc title h1 h2 h3 tt t sc y b bi i highlight highlight-meta search autosearchtag autokey isearch manref hot indent indent2 spot synopsisargs lastposn
r asis example smallexample display table list subscript superscript lisp smalllisp code kbd key file var emph author strong dfn chapter section subsection subsubsection majorheading titlefont heading subheading subsubheading w deffn defun defmac defspec quotation index cite subtitle author flushleft flushright center cartouche nowrap texixref rfcxref
}
#set man(diffa) {-font diffa}
#set man(diffc) {-font diffc}
#set man(diffd) {-font diffd -overstrike yes}
#set man(diffa) {"$man(diffa-family)" "$man(diffa-style)"}
#set man(diffc) {"$man(diffc-family)" "$man(diffc-style)"}
#set man(diffd) {"$man(diffd-family)" "$man(diffd-style)" -overstrike yes}
set man(diffa) {"$man(diffa-style)"}
set man(diffc) {"$man(diffc-style)"}
set man(diffd) {"$man(diffd-style)" -overstrike yes -foreground "$man(difffg)" s}
#set man(diffbar) "yes"; set manx(diffbar-v) {1 0}; set manx(diffbar-t) {"yes" "no"}
set man(strike) {-overstrike yes}
set man(tt) [set man(t) mono]
set man(sc) s
set man(y) symbol
set man(b) bold
set man(bi) bold-italics
set man(i) italics
set man(title) {bold large l}
set man(h1) {bold l}
set man(h2) {bold m}
# -spacing3 3}
set man(h3) {bold s}
set man(h4) {s}
# h1,h2,h3,h4 <=> chapter,section,subsection,subsubsection
#italics
# Texinfo -- should give these to texi.tcl
set man(r) {}
# set man(format) {} -- NO! conflicts with nroff formatting pipe!
set man(asis) {}
set man(example) {mono small s -wrap none -tabs 0.3i}
set man(lisp) {mono small -wrap none}
set man(smalllisp) {mono small s -wrap none}
set man(smallexample) $man(smalllisp)
set man(display) {-lmargin1 0.3i -lmargin2 0.3i -rmargin 0.3i}
set man(table) {-tabs 1.0i -lmargin2 1.0i}
set man(list) {-tabs 0.3i -lmargin2 0.3i}
set man(subscript) {-offset -3}
set man(superscript) {-offset 3}
set man(code) {mono small}
set man(kbd) {mono}; set man(key) $man(sc)
set man(url) {mono}
set man(file) {italics}
set man(var) {italics}
set man(emph) {italics}
set man(strong) {bold}
set man(deffn) {italics}
set man(defun) {italics}
set man(defmac) {italics}
set man(defspec) {italics}
set man(author) {bold}
set man(dfn) {bold}
set man(chapter) [set man(majorheading) [set man(titlefont) {bold m}]]
set man(section) [set man(heading) {bold s}]
set man(subsection) [set man(subheading) {italics}]
set man(subsubsection) [set man(subsubheading) {}]
set man(cite) {italics}
set man(cartouche) {-borderwidth 2}
set man(subtitle) {italics}
set man(author) {bold}
set man(center) {center}
set man(flushleft) {left}
set man(flushright) {right}
set man(w) {}
set man(nowrap) {-wrap none}
#-wrap none} -- affects whole line or nothing
set man(quotation) {-lmargin1 0.5i -lmargin2 0.5i -rmargin 0.5i}
set man(index) {s -tabs 3i}
set man(texixref) $man(manref)
set man(rfcxref) $man(manref)
set man(maxhistory) 15; set manx(maxhistory-v) [set manx(maxhistory-t) {5 10 15 20 30 40 50}]
set man(recentdays) 14; set manx(recentdays-v) [set manx(recentdays-t) {1 2 7 14 30 60 90 180}]
set man(pagecnt) {}
set man(chronobrowse) {}
# seed shortcuts with set for the beginner?  then have to remove... if they exist!
set man(shortcuts) {}
set man(shortcuts-sort) 0; set manx(shortcuts-sort-v) {1 0}; set manx(shortcuts-sort-t) {"alphabetical" "chronological"}
#set man(indexglimpse) "distributed";  -- now set in Makefile
set manx(indexglimpse-v) [set manx(indexglimpse-t) {"distributed" "unified"}]
set man(incr,case) -1; set manx(incr,case-v) {1 0 -1}; set manx(incr,case-t) {"yes" "no" "iff upper"}
set man(regexp,case) -1; set manx(regexp,case-v) {1 0 -1}; set manx(regexp,case-t) {"yes" "no" "iff upper"}
set man(maxglimpse) 200; set manx(maxglimpse-v) [set manx(maxglimpse-t) {25 50 100 200 500 1000 "none"}]
set man(maxglimpseexcerpt) 50; set manx(maxglimpseexcerpt-v) [set manx(maxglimpseexcerpt-t) {25 50 100 200 500 1000}]
# some window managers can't handle autoraise/autolower well, so default to off
set man(autoraise) 0; set manx(autoraise-v) {1 0}; set manx(autoraise-t) {"yes" "no"}
set man(autolower) 0; set manx(autolower-v) {1 0}; set manx(autolower-t) {"yes" "no"}
set man(iconify) 0; set manx(iconify-v) {1 0}; set manx(iconify-t) {"yes" "no"}
set man(focus) 1; set manx(focus-v) {1 0}; set manx(focus-t) {"window entry" "click-to-type"}
set man(subsect) ""; set manx(subsect-v) {"-b" ""}; set manx(subsect-t) {"yes" "no"}
set man(nroffsave) "off"; set manx(nroffsave-v) [set manx(nroffsave-t) {"on" "on & compress" "off" "off & ignore cache"}]
# roff so pokey never too fast to cache, though could put it in can wait for hardware to catch up
#set man(toofasttocache) "1.5"; set manx(toofasttocache-v) [set manx(toofasttocache-t) {"on" "on & compress" "off" "off & ignore cache"}]
set man(headfoot) "-k"; set manx(headfoot-v) {"-k" ""}; set manx(headfoot-t) {"yes" "no"}
set man(hyperclick) "single"; set manx(hyperclick-v) [set manx(hyperclick-t) {"double" "single"}]
set man(fsstnddir) /var/catman
set man(fsstnd-always) 0; set manx(fsstnd-always-v) {1 0}; set manx(fsstnd-always-t) {"always" "iff .../canN unwritable"}
set man(versions) {}
set man(aproposfilter) {| sort | uniq}
set man(scrollbarside) right; set manx(scrollbarside-v) [set manx(scrollbarside-t) {"left" "right"}]
set man(documentmap) 1; set manx(documentmap-v) {1 0}; set manx(documentmap-t) {"yes" "no"}
set man(strictmotif) 0; set manx(strictmotif-v) {1 0}; set manx(strictmotif-t) {"yes" "no"}
set man(subvols) 1; set manx(subvols-v) {1 0}; set manx(subvols-t) {"yes" "no"}
#set man(checkstraycats) 1; set manx(checkstraycats-v) {1 0}; set manx(checkstraycats-t) {"yes" "no"} -- doesn't matter so much as startup really fast, and better to be safe than sorry
set man(preferGNU) ""; set manx(preferGNU-v) {"g?" ""}; set manx(preferGNU-t) {"yes" "no"}
set man(preferTexinfo) 1; set manx(preferTexinfo-v) {1 0}; set manx(preferTexinfo-t) {"yes" "no"}
set man(wordfreq) 0; set manx(wordfreq-v) {1 0}; set manx(wordfreq-t) {"yes" "no"}
set man(search,fcontext) 0; set manx(search,fcontext-v) [set manx(search,fcontext-t) {0 1 2 3 4 5}]
set man(search,bcontext) 0; set manx(search,bcontext-v) [set manx(search,bcontext-t) {0 1 2 3 4 5}]
set man(textboxmargin) 5; set manx(textboxmargin-v) [set manx(textboxmargin-t) {0 1 2 3 4 5 7 10}]
set man(lengthchunk) "line"; set manx(lengthchunk-v) {line screen page ""}; set manx(lengthchunk-t) {"lines" "screenfuls" "printed pages" "no report"}; # "line/screen"
set manx(line-scale) 1; set manx(screen-scale) 45; set manx(page-scale) [expr int(60*1.5)]
set man(error-effect) "bell & flash"; set manx(error-effect-v) [set manx(error-effect-t) {"bell & flash" "bell" "flash" "none"}]
set man(columns) 65; set manx(columns-v) {65 90 130 5000}; set manx(columns-t) {"65 (most compatible)" 90 130 "wrap to screen width"}; # no one would want shorter lines
set manx(longtmp) /tmp/ll
set man(volcol) 4.0c; set manx(volcol-v) {0 1.5c 2.0c 2.5c 3.0c 3.5c 4.0c 4.5c 5.0c 7.5c 10.0c}; set manx(volcol-t) {"no columns" "1.5 cm" "2 cm" "2.5 cm/~1 inch" "3 cm" "3.5 cm" "4 cm" "4.5 cm" "5.0 cm/~2 inches" "7.5 cm" "10 cm"}
set man(apropostab) "4.5c"; set manx(apropostab-v) {0 3.0c 4.0c 4.5c 5.0c 5.5c 6.0c 7.5c 10.0c}; set manx(apropostab-t) {"none" "3 cm" "4 cm" "4.5 cm" "5 cm" "5.5 cm" "6 cm" "7.5 cm" "10 cm"}
#set man(showoutsub) ""
set man(high,hcontext) 50
set man(high,vcontext) 5; set manx(high,vcontext-v) [set manx(high,vcontext-t) {0 2 5 7 10 15 20}]
set man(outline) "allbut"; set manx(outline-v) {"allexp" "allcol" "allbut" "off"}; set manx(outline-t) {"all expanded" "all collapsed" "all collapsed but" "none"}
# long Name, short Description, short Synopsis, short See Also
set man(outlinebut) {^name\d+$|(syntax|synopsis)[1-2]?\d$|description\d$|(author|identification|credits)\D*[1-9]$|(see also|related information)\d$}
set man(autosearchnb) {unsafe|warning|danger|obsolete|international|english|posix|web|performance|privacy|security|authoritative|deadlock|berkeley|solaris|version \d+}
# nonnb - if you're in the area, show me, but not of global importance
# me -posix, +annotation, +texinfo=>superceded by authoratative
# for others
#	+multithread
# too frequent to show as Notemarks -- but good to see if you happen to be in the area
#	@ - either no email or million in list of contributors + many false hits + meta character for Texinfo and Perl
set man(autosearch) {fail|ignore|explicit|difficult|tricky|postscript|html|priority|wait|block}
# maybe +octal
set man(autokeywords) {default|return|null|empty|inclusive|exclusive|sensitive|insensitive|ascii|octal|hex|dec |decimal|symbolic}; # not dec=>december
# highlights and searches change, but subsections and options are stable
foreach i {highlight options search manfill manref} {
# subsect
	set manx($i-show-v) {"alwaysvis" "firstvis" "never"}
	set manx($i-show-t) {"always" "at first" "never"}
}
set manx(openFilePWD) [pwd]
set manx(pathsep) [expr {$manx(doze)?";": ":"}]; # Tcl seems not to have addressed this
set man(randomscope) all
set manx(manhits) {}
set man(tidyout) 1; set manx(tidyout-v) {1 0}; set manx(tidyout-t) {"yes" "no"}
set manx(highlight-show-v) {"halwaysvis" "firstvis" "never"}
set manx(search-show-v) {"salwaysvis" "sfirstvis" "never"}; # is "never" never a good choice?
set manx(manfill-show-v) {"malwaysvis" "mfirstvis" "never"}
set manx(show-atags) {alwaysvis halwaysvis salwaysvis malwaysvis}
set manx(show-ftags) {firstvis mfirstvis sfirstvis lastposn}
set manx(show-tags) [concat lastposn $manx(show-atags) $manx(show-ftags)]
set man(highlight-show) halwaysvis; #firstvis
#set man(subsect-show) never
set man(options-show) firstvis
set man(manref-show) never
set man(search-show) salwaysvis
set man(manfill-show) mfirstvis
set man(manfill-sects) {description introduction command usage operators}
#set man(outline-show) section; set manx(outline-show-v) [set manx(outline-show-t) {"chapter" "section" "subsection" "subsubsection"}]
# DON'T ADD THESE TO man(manfill-sects)
#	environment - you consult to set once, then ignore
set man(manfill) "in entirety"; set manx(manfill-v) [set manx(manfill-t) {"in entirety" "as space"}]
set man(showsectmenu) 1; set manx(showsectmenu-v) {1 0}; set manx(showsectmenu-t) {"yes" "no"}
set man(rebus) 0; set manx(rebus-v) {1 0}; set manx(rebus-t) {"yes" "no"}
set man(tryfuzzy) 1; set manx(tryfuzzy-v) {1 0}; set manx(tryfuzzy-t) {"yes" "no"}
set man(showrandom) 0; set manx(showrandom-v) {1 0}; set manx(showrandom-t) {"yes" "no"}
set man(maxpage) 0; set manx(maxpage-v) {1 0}; set manx(maxpage-t) {"yes" "no"}
##always show highlights as combo +/-/menu
set man(geom) [min 570 [expr {[winfo screenwidth .]-100}]]x[min 800 [expr {[winfo screenheight .]-50}]]+100+10
set man(geom-prefs) +300+300
set man(iconname) {TkMan: $manx(name$curwin)}
set man(iconbitmap) "(default)"
set man(iconmask) ""
set man(iconposition) ""
set man(startup) $env(HOME)/.tkman

# colors
set man(colors) {black white red "light yellow" yellow orange green blue beige SlateGray4 gray75 gray90}

# set preferred colors
set man(textfg) "black"
set man(textbg) "white"
set man(difffg) "gray60"
#set man(buttfg) [set man(activefg) [set man(guifg) "gray"]]
#set man(buttbg) [set man(guibg) "beige"]
#set man(activebg) #eed5b7

# colors are Tk's defaults, except for black-on-white text
checkbutton .a
#set man(textfg) []
set man(buttfg) [set man(guifg)  [.a cget -foreground]]
set man(guibg) [set man(buttbg) [.a cget -background]]
#set man(textbg) "white"; if {$man(textfg) eq "white"} {set man(textbg) "black"}
# default textbg is ugly grey
set man(activefg) [.a cget -activeforeground]
set man(activebg) [.a cget -activebackground]
destroy .a
set man(selectionfg) black
set man(selectionbg) gray90

#set man(fontpixels) "X"
#set manx(fontpixels-v) {"-" "+"}; set manx(fontpixels-t) {"pixels" "points"}
set manx(dpi) [expr {int([winfo screenwidth .]/([winfo screenmmwidth .]/25.4))}]
## for intial setting, assume 75 and 100 dpi fonts available
##set man(fontpixels) [expr {($manx(dpi)==75 || $manx(dpi)==100)? "": "-"}]
# set interactively if no startup file
# find closest font dpi
if {[catch {set bestdpi $env(DISPLAY_DPI)}]} {
	set bestdpi 75; set mindpidiff 1000
	foreach dpi $manx(dpis) {
		set dpidiff [expr {abs($dpi-$manx(dpi))}]
		if {$dpidiff<$mindpidiff} {set mindipdiff $dpidiff; set bestdpi $dpi}
	}
}
tk scaling [expr {$bestdpi/72.0}]
# can't rescale
# tk scaling can be overridden in ~/.tkman free essay portion
# if you want to use pixels, use "tk scaling 1"


set manx(mono) [expr {[winfo depth .]==1}]
if {$manx(mono)} {
	set man(foreground) "black"
	set man(background) "white"
	set man(colors) {black white}
	#set man(textfg) []
	set man(activebg) [set man(buttfg) [set man(guifg) "black"]]
	#set man(textbg) []
	set man(difffg) [set man(activefg) [set man(buttbg) [set man(guibg) "white"]]]
	set man(selectionfg) $man(textbg); set man(selectionbg) $man(textfg); # gotta reverse on b&w

	set man(search) [set man(isearch) "reverse"]
#	set man(cmd) underline
	set man(highlight) "bold-italics"
	set man(manref) "mono underline"
#	set man(manrefseen) "mono"
	set man(spot) reverse

	# any more modifications for monochrome?
}
set man(highlight-meta) $man(highlight)


### collect all man's to this point as the defaults
# used for Defaults button in Preferences
# and to "comment out" unchanged parameters, so that subsequent
# changes (corrections), usually in the Makefile, propagate as expected
# (i.e., should make for fewer cases of "delete ~/.tkman")
# CAREFUL!  Only man()'s recorded here in defaults are saved to ~/.tkman
# ok to put man() with modules, 'cause all modules loaded by this time
set man(print) [string trim $man(print)]
foreach i [array names man] {set default($i) $man($i)}


#
# man()-independent manx()
#

set manx(title) "TkMan"
regexp {(\d\d\d\d)/(\d\d)/(\d\d)} {$Date: 2003/04/01 23:02:52 $} manx(date) y m d
set manx(mtime) [clock scan "$m/$d/$y"]
set manx(stray-warnings) ""
if {[catch {set default(manList) 0}]} {puts "\aBLT conflicts with TkMan."; exit 1}
set manx(manList) $man(manList)
set manx(manTitleList) $man(manTitleList)
set manx(userconfig) "### your additions go below"
set manx(posnregexp) {([-+]?\d+)([-+]\d+)}
set manx(bkupregexp) {(~|\.bak|\.old)}; # exclude old?  may want to refer to it => make it an option?
set manx(init) 0
set manx(texishowsubs) ""
set manx(manDot) 0
set manx(cursor) left_ptr
set manx(yview,help) 1/1.0
set manx(paths) ""
set manx(pathstat) ""
set manx(uid) 1
set manx(hunkid) ""
set manx(outcnt) 1
set manx(debug) 0
set manx(profile) 0
set manx(defaults) 0
set manx(startup) $man(startup)
set manx(savegeom) 1
# can't be sure volume 1 exists(!)
#set manx(lastvol$w) 1
set manx(lastman) TkMan
set manx(censussortby) 1
set manx(highsortby) 0
set manx(normalize) "-N"
set manx(quit) 1
set manx(mandot) ""
set manx(db-manpath) ""
set manx(db-signature) ""
set manx(mondostats) 0
set manx(newmen) ""
set manx(highdontask) {}
#set manx(xmono) {courier|helvetica}
set manx(subdirs) "{sman,man,cat}?*"
set manx(shift) 0
set manx(searchtime) 0
if {[file executable /usr/ucb/whoami]} {set manx(USER) [exec /usr/ucb/whoami]
} elseif {[file executable /usr/bin/whoami]} {set manx(USER) [exec /usr/bin/whoami]
} elseif {[info exists manx(USER)]} {set manx(USER) $env(USER)
} else {set manx(USER) "luser"}
append man(autosearchnb) "|$manx(USER)"; # vanity
# default printer
if {[info exists env(PRINTER)]} {set manx(printer) $env(PRINTER)} \
elseif {[info exists env(LPDEST)]} {set manx(printer) $env(LPDEST)} \
else {set manx(printer) ""}

# versions of supporting binaries, if those binaries happen to be used
set manx(bin-versregexp) {(\d+\.\d+(\.\d+)*)}; # followed by ([^,;:\s]*)
# Glimpse min version of 4.0 so know what index looks like for index pseudovolume
# morons maintaining glimpse exit with non-zero for version information
#set manx(bin-versioned) {{rman "-v" 3.0.5} {glimpse "-V" 4.0} {glimpseindex "-V" 4.0}}
set manx(bin-versioned) {{rman "-v" 3.1}}
set manx(modes) {man texi rfc help section txt apropos glimpse info}
set manx(mode-desc) {"manual pages seen" "Texinfo files read" "RFC documents read" "references to help page" "volume listings invoked" "text files seen" "apropos listings" "Glimpse full-text searches" "ganders at this page"}
DEBUG { assert [llength $manx(modes)]!=[llength $manx(mode-desc)] "mismatched modes lists" 1 }
set manx(stats) {man-hyper man-dups man-button man-history man-shortcut man-random page-section page-highlight-go page-highlight-add page-highlight-sub page-shortcut-add page-shortcut-sub page-regexp-next page-regexp-prev page-incr-next page-incr-prev page-downsmart page-mono high-exact high-move high-lose high-carry print glimpse-builds outline-expand outline-collapse instantiation checkpoint}
set manx(stats-desc) {"via hyperlink" "via multiple matches pulldown" "via man button or typein box" "via history menu" "via shortcut menu" "via random page" "jumps to section header" "jump to highlight" "highlight additions" "highlight deletions" "shortcut additions" "shortcut deletions" "regular expression searches forward" "regular expression searches backward" "incremental searches forward" "incremental searches backward" "scrolls with smart outline expansion/collapse" "swaps between proportional font and monospaced" "exact" "repositioned" "lost" "pages printed" "Glimpse builds" "expanded outline" "collapsed outline" "additional instantiations" "checkpoints to save file"}
DEBUG { assert [llength $manx(stats)]!=[llength $manx(stats-desc)] "mismatched stats lists" 1 }
set stat(man-no) 0
set manx(all-stats) [concat $manx(modes) $manx(stats) "man-no" "executions"]
foreach i $manx(all-stats) {set stat(cur-$i) [set stat($i) 0]}
set manx(zdirsect) {(?:man|sman|cat)\.?(.*)}



# TKMAN environment variable gives standard options
# env(TKMAN) goes first so options given on command-line override
if {[info exists env(TKMAN)]} {set argv "$env(TKMAN) $argv"}
if {![info exists env(PATH)] || $env(PATH) eq ""} { set env(PATH) "/usr/local/bin:/usr/bin" }
# don't pick up changes to env(PATH) in startup file (just so you know)
set manx(bin-paths) [split [string trim $env(PATH) $manx(pathsep)] $manx(pathsep)]

#puts "*** manParseCommandline"
# usually want to do this after startup file, but need to get -M here, before manx(startup) (?)
manParseCommandline
set manx(startup-short) [file tail $manx(startup)]

# execute some arbitrary Tcl code for new users (it may create a startup file)
if {![file exists $manx(startup)]} {eval $manx(newuser)}

# read in startup file after proc/vars/ui, so can modify them
set manx(savefilevers) "1.0"
set manx(updateinfo) ""
#puts "*** before startup"

# if on special case OS and don't have startup file, instantiate right startup code
# uname -s -r: SunOS 5.5 on ecstasy, IRIX 5.2 on bohr, SCO_SV on SCO OpenServer Release 5
# (for future references: OSF1 V3.2 on tumtum, HP-UX A.09.05 on euca)
# Put this code after eval newuser.

if {$manx(startup) ne "" && ![file exists $manx(startup)] && [file writable [file dirname $manx(startup)]]} {
	catch {
	set os [string tolower $tcl_platform(os)]; set osvers $tcl_platform(osVersion)
	set setup ""; # most OSes work without configuration file

	# three trouble makers
	if {$os eq "sunos" && $osvers>=5.0} {
		set setup solaris
		if {$osvers>=5.7} {append setup "28"
		} elseif {$osvers>=5.6} {append setup "26"
		} elseif {$osvers>=5.5} {append setup "25"}
	} elseif {[string match "irix*" $os]} {
		set setup irix
	} elseif {$os eq "sco_sv"} {
		set setup $os
	}
#puts stderr "\afound $setup"

	if {$setup!="" && [info exists manx($setup-bindings)]} {
		set fid [open $manx(startup) "w"]
		puts $fid $manx($setup-bindings)
		close $fid
	}
   }
}



if {$manx(startup)!="" && [file readable $manx(startup)]} {
	set fid [open $manx(startup)]

	# I don't know how this happens, but it has, apparently
	if {[string match "#!*" [gets $fid line]]} {
		puts stderr "$manx(startup) looks like an executable."
		puts stderr "You should delete it, probably."
		exit 1
	}

	while {![eof $fid]} {
		# manx(savefilevers) discards alpha/beta designation
		if {[regexp {^# TkMan v(\d+(\.\d+)+)} $line all savefilevers]} {
			set manx(savefilevers) $savefilevers
			break
		}
		gets $fid line
	}
	catch {close $fid}
DEBUG {puts "*** savefilevers = $manx(savefilevers)"}

	source $manx(startup)

#puts "*** read $manx(startup)"
# later use array {get,set} => no, hard for user to edit

	# update several variables from old save files

	set fixup 0
	if {[package vcompare $manx(savefilevers) 1.6]==-1} {
		set manx(updateinfo) "Startup file information updated from version $manx(savefilevers) to version $manx(version).\n"

		### changes for < 1.6
		# update these variables
		foreach var {catsig compress zcat} {
#	 detailed list of changes more information than user wants
#			append manx(updateinfo) "    Changed man($var) from $man($var) to $default($var)\n"
			set man($var) $default($var)
		}

		# zap problem shifted sb keys
		foreach k {greater less question} {
			set var "sb(key,MS-$k)"
			if {[info exists $var]} {unset $var}
#			append manx(updateinfo) "    Deleted $k keybinding (use M-$k)\n"
		}

		# call manDot before user code
		append manx(updatedinfo) "    Added call to manDot\n"
		# (if no problem before, no problem now)

		# zap old man() variables ==> done every time save file updated
#		foreach v [array names man] {
#			if {![info exists default($v)] && ![string match "/*" $v]} {
#				append manx(updateinfo) "    Deleted obsolete variable man($v) (was set to $man($v))\n"; 
#				unset man($v)
#			}
#		}

		append manx(updateinfo) "Save updates via the Quit button or Occasionals/Checkpoint, or cancel updates via \"Occasionals / Quit, don't update\".\n"
		# backup old startup file
		if {![catch "file copy -force $manx(startup) [set ofn $manx(startup)-$manx(savefilevers)]"]} {
			append manx(updateinfo) "Old startup file saved as $ofn\n"
		}
		append manx(updateinfo) "\n\n"
		set fixup 1

	}

	if {[package vcompare $manx(savefilevers) 1.8.1]==-1} {
		if {[info exists man(stats)] && [llength [lsecond $man(stats)]]==2} {
			# construct and save new version soon
			set newstyle [lfirst $man(stats)]
			foreach s [lrange $man(stats) 1 end] { lappend newstyle [lfirst $s] [lsecond $s] }
			set man(stats) $newstyle

			# use of glimpse has changed: -W, no -w for glimpse; -f for glimpseindex
			set man(glimpse) $default(glimpse)
			set man(glimpseindex) $default(glimpseindex)
			# likewise, reset manformat so assured of picking up long lines
			set man(format) $default(format)

			set fixup 1
		}
	}

	if {[package vcompare $manx(savefilevers) 2.0]==-1} {
		foreach db [glob -nocomplain ~/.tkmandatabase*] {file delete -force -- $db}
	}

	if {[package vcompare $manx(savefilevers) 2.1]==-1} {
		set man(high,vcontext) 5
		# lose existing setting, but how else to split into nb and non-nb?
		set man(autosearch) $default(autosearch); # autosearchnb and autokeywords are new in 2.1
	}

	# convert shortcuts to name+time added, the time for use later
	if {[llength [lfirst $man(shortcuts)]]==1} {
		set tmp {}
		foreach i $man(shortcuts) {lappend tmp [list $i [clock seconds]]}
		set man(shortcuts) $tmp
	}
	if {[info exists man(pagecnt)] && [llength [lsecond $man(pagecnt)]]==1} {
		set tmp {}
		foreach {name cnt lastread} $man(pagecnt) {lappend tmp $name [list $cnt $lastread]}
		set man(pagecnt) $tmp
	}
	array set pagecnt $man(pagecnt)

	if {!$manx(manDot)} {
		#puts stderr "no mandot" -- clean this up silently
		manDot
		set fixup 1
	}

	if {$fixup} {after 500 manSave}
} else {
# if no startup file
}

#if {$man(fontpixels)=="X"} {
#	set man(fontpixels) "+"
#	after 100 {.__tk__messagebox.msg configure -font {Times 24}}
#	if {[tkMessageBox -message "Is this font jagged?" -type yesno -icon question]=="yes"} {
#		set man(fontpixels) "-"
#	}
#}

if {$man(glimpse) eq "" || $man(glimpseindex) eq ""} {set man(glimpse) ""; set man(glimpseindex) ""}

#if {[lsearch $man(versions) $manx(version)]==-1} {lappend man(versions) $manx(version)} -- track backtracks too
if {[lindex $man(versions) end]!=$manx(version)} {lappend man(versions) $manx(version)}

set manx(shortcuts) {}
foreach i $man(shortcuts) {
	foreach {name time} $i {lappend manx(shortcuts) $name; set short($name) $time}
}

catch {unset high(*)}


foreach {name info} $man(prof) {
	set prof(cnt-$name) [lfirst $info]; set prof(totaltime-$name) [lsecond $info]
}


# manx(highs) needs to get latest list of colors
set manx(highs) [concat $manx(styles) reverse underline mono $man(colors)]

set manx(extravols) {}
if {$man(apropos) ne ""} {
	lappend manx(extravols) [list apropos "apropos hit list" [list "No apropos list" b]]
}
if {$man(glimpse) ne ""} {
	lappend manx(extravols) [list glimpse "glimpse hit list" [list "No glimpse list" b]]
	if {$man(indexglimpse)=="unified" && [file readable [file join $man(glimpsestrays) ".glimpse_index"]]} {
		lappend manx(extravols) [list "glimpseindex" "glimpse word index" {}]
	}
}
lappend manx(extravols) {recent "Recently added/changed" {}} {high "All with Highlights" {}} {census "All pages seen" {}} {all "All Enabled Volumes" {}}
foreach i $manx(extravols) { lappend manx(specialvols) [lfirst $i] }

set manx(subregexp) {js(\.?(\d+))+}
set manx(supregexp) {js(\d+(\.\d+)*)\.\d+}
# calculate compression comparison expressions
set manx(zregexp) "\\.("; set manx(zregexpopt) "(\\.("
set manx(zglob) "{"; set manx(zoptglob) "{,"
foreach z $man(zlist) {
	append manx(zregexp) "$z|"
	append manx(zregexpopt) "$z|"
	append manx(zglob) "$z,"
	append manx(zoptglob) ".$z,"
}
foreach z {zregexp zglob zoptglob} { set manx($z) [string trimright $manx($z) ",|"] }
set manx(zregexp0) "[string trimright $manx(zregexp) |])"
set manx(zregexpl) "(\\.\[^\\. \]+)$manx(zregexp0) "
set manx(zregexp) "$manx(zregexp0)\$"
set manx(zregexpopt) "[string trimright $manx(zregexpopt) |]))?"
append manx(zglob) "}"; append manx(zoptglob) "}"
set manx(filetypes) [list [list "Manual Pages" ".{\\\[1-9olnpD],man}*$manx(zoptglob)"] [list "Texinfo" ".texi$manx(zoptglob) .texinfo$manx(zoptglob)"] [list "Text file" ".txt$manx(zoptglob)"] {"Any file" *}]


# make master lists of man, bin dirs
set mani(MASTER,dirs) {}
foreach i $manx(mastermen) {
	if {![file readable $i] || [lsearch $manx(paths) $i]!=-1} continue
#puts "master $i"; flush stdout
	foreach j [glob -nocomplain $i/man*] {
		if {[file readable $j] && [file isdirectory $j]} {lappend mani(MASTER,dirs) $j}
	}
}
set manx(aux-binpaths) {}
foreach i $manx(masterbin) {
	if {[lsearch $manx(bin-paths) $i]==-1 && [file readable $i] && [file isdirectory $i]} {
		lappend manx(aux-binpaths)
	}
}




# do this after source of ~/.tkman has chance to change some of these
set manx(binvars) {
	manx(rman) man(glimpse) man(glimpseindex) man(cksum) man(gzgrep)
# man(co) man(rlog) man(rcsdiff) man(vdiff) -- don't check for these
	man(format) man(print) man(catprint) man(apropos) man(zcat) man(compress) 
}

set manx(canformat) [expr {$man(format) ne ""}]
if {$manx(doze)} {
    # Windoze doesn't have groff/nroff/tbl/neqn/col), glimpse, lpr, ...
    # so can't format pages, no full-text search, can't print, ...
    foreach var {format glimpse glimpseindex print catprint apropos} {
	set man($var) ""
    }

    # convert PATH and MANPATH
    # cygwin bash uses "//C/bin://C/jdk1.2.2/bin",
    # whereas Tcl wants "C:/bin;C:/jdk1.2.2/bin"
    foreach var {MANPATH PATH} {
	if {[info exists env($var)] && [string match "*//*" $env($var)]} {
	    set newvar $env($var)
	    regsub -all ":" $newvar "\;" newvar
	    regsub -all {//([A-Z])/} $newvar {\1:/} newvar
	    set env($var) $newvar
	}
    }
}

after 1500 manBinCheck

# assertions

if {[llength $man(manList)]!=[llength $man(manTitleList)]} {
	puts stderr "Length of section abbreviations differs from length of section titles:\n\nlength [llength $man(manList)]:\t$man(manList)\n\nlength [llength $man(manTitleList)]:\t$man(manTitleList)"
	exit 1
}

# no sense to tease glimpseindex if can't write anything
set manx(glimpseindex) ""
if {$man(glimpse)!="" && $man(glimpseindex)!=""} {
	foreach p $manx(paths) {
		if {![file writable $p]} {set manx(glimpseindex) $man(glimpseindex); break}
	}
}


# almost always you'll want to make the cross product
#	 if you don't, be tricky and `set manx(defaults) 1'
if {!$manx(defaults)} manDescDefaults

# set up cumulative statistics watchdog
lappend man(chronobrowse) "X"
set manx(statsdirty) 0
manStatsSet
# added this statistic after the others
#if {[package vcompare $manx(savefilevers) 2.0.3]==-1} {set stat(cum-executions) [expr $stat(cum-executions)/$stat(cum-help)]; set man(stats) "executions $stat(cum-executions) $man(stats)"}
if {[package vcompare $manx(savefilevers) 2.0.3]==-1} {set stat(cum-executions) $stat(cum-help); set man(stats) "executions $stat(cum-executions) $man(stats)"}
#if {$stat(cum-executions)==0 && $stat(cum-help)>0} {set stat(cum-executions) $stat(cum-help)}
manStatsSaveFile;	# should just set timer this time through, not save to a file

# if no stray dirs for glimpse, don't glimpse there
#if {$man(indexglimpse)=="distributed" && [llength $mani($manx(glimpsestrays),dirs)]==0} {set manx(glimpsestrays) ""}


if 0 {
foreach proc [info procs man*] {
	puts -nonewline "rewriting $proc"
	set vals ""; foreach aargh [info args $proc] {append vals " \$$aargh"}
	set aarghs {}
	foreach aargh [info args $proc] { if {[info default $proc $aargh def]} {lappend aarghs [list $aargh $def]} else {lappend aarghs $aargh}}
puts "   $aarghs"
	proc $proc $aarghs "puts \"entering $proc $vals\"; flush stdout\n[info body $proc]\nputs {exiting $proc}; flush stdout"
}
}

set STOP 0


TkMan
#image create bitmap wmicon -data [icon cget -data]

set starttime [time manInit]
manHelp $w; # show newly available stray cat warnings


# debug box always available
# convenience variables
#	set w .man
set t $w.show

# debug box
entry $w.in -relief sunken -textvariable manx(debugcmd)
# maybe automatically decide destination based on length
bind $w.in <KeyPress-Return> {manWinstdout .man "[eval $manx(debugcmd)]"}
bind $w.in <Meta-KeyPress-Return> {manTextOpen .man; $t insert end $manx(debugcmd) b "   =>   " tt "\n\n" {} [eval $manx(debugcmd)]; manTextClose .man}

DEBUG {
	puts stdout "init takes $starttime"
	pack $w.in -fill x
	proc manStatsSaveFile args {}
}


set stat(executions) 1

# no profiling on non-TkMan procs
#rename proc {}
#rename proc_builtin proc

if {$stat(cum-executions)==100 
	|| ($stat(cum-executions)>0 && int($stat(cum-executions)/1000)*1000==$stat(cum-executions))} {
	set txt "This is the $stat(cum-executions)th time you've run TkMan.  Please help improve future versions of TkMan by emailing the file ~/.tkman with its collected statistics to phelps@ACM.org.  (This must be done manually; no action is taken automatically.)  Thanks!"
	manTextPlug $w.show 1.0 "$txt\n\n" b
	tk_messageBox -icon info -parent $w -title "Please Help" -type ok -message $txt
}

# report first run and every month or so
if {$stat(cum-executions)%27==0} {
	set txt ""
	if {$man(texinfodir)==""} {append txt "+ In addition to showing manual pages, TkMan supports Texinfo (GNU documentation) with high quality text display, intra-document and full text search, highlight annotations, and an outlining interface that preserves navigation context to combat (solve?) the \"lost in info-space\" problem.  (To install, see the Makefile.)\n"}
	if {$man(glimpse) eq ""} {append txt "+ You can do full text search on all man pages, Texinfo, and other text files by installing Glimpse.  (It's is conviently available as binaries.  To install, see the Makefile.)\n"}
	if {$man(outline) eq "off"} {append txt "+ Now that you're comfortable with TkMan, try the outlining display (set Preferences/Outline/Outlining state at page load, to all collapsed but).  Rather than scolling screen after screen in a man page to find the information, outlining and Notemarks give a high density display that's likely to show the information you want on the first or second screenful.\n"}
	if {$stat(cum-executions)>10 && $stat(cum-page-highlight-add)<10} {append txt "+ You can make yellow highlighter annotations.  If the page content changes or the page moves, highlights are automatically repositioned.\n"}
	if {$stat(cum-executions)>10 && $man(outline)!="off" && $stat(cum-page-downsmart)<$stat(cum-man)/2} {append txt "+ Try using <Return> for smart scrolling through outlines, opening up closed sections as they are encountered and closing up sections as they are read.\n"}
	if {!$man(wordfreq)} {append txt "+ You can get a kind of summary of man pages via word frequency counts (turn on at Preferences/See/Page summary).\n"}
	if {$man(columns)!=5000} {
		append txt "+ You can man page lines to wrap at whatever your screen width is (set Preferences/Database/Width of man pages)."
		if {![string match "*groff*" $man(format)]} {append txt "  (But first you need to use groff, set in the Makefile or your ~/.tkman file)."}
  		append txt "\n"
	}
	if {$txt!=""} {
		tk_messageBox -icon info -parent $w -title "Presents for you" -type ok -message "TkMan:  There are a couple great features you're not taking advantage of.  Click OK to read more."
		manTextPlug $w.show 1.0 "$txt\n\n" b
		wm deiconify $w
	}
}
