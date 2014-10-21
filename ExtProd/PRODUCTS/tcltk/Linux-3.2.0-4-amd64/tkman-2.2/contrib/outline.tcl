#!/private/share/bin/wish
#
# demonstration of elided text patch
#
# Tom Phelps (phelps@acm.org)
# 9 January 1997
#

# txt, tags
set demotxt {
		"Elided Text Demo\n" title
		"Tom Phelps\n" {}
		"9 January 1997\n" {}


		"Click Me" h1
		"And Me" h2
		"Now click Click Me twice more.\n\n" {}

		 
		"What is This?" h1
		"This is a demonstration of the " {} "elided (hidden) text" i " patch to Tk's Text widget.  This is " {} "not " i "drawing text with identical foreground and background colors, but rather removing the text, embedded images, and embedded windows from contributing to the display, while retaining the text within the text widget for insertion/deletions and all other purposes.  One could simulate this by bypassing and restoring all the elements from the text widget--characters, images, window, tags, marks--but even to write a simple editor with outlining that collapses and expands sections across edit would involve quite a bit of bookkeeping.  And inefficient too, what with all the string deleting and reinsertions.\n\n" {}

		"This demo could expanded to let the user add new topics to the outline and promote/demote topics.  An outliner interface could be interesting in an HTML browser or for multipart MIME messages.  Conditional text is trivial to implement.\n" {}

		"What is Demonstrated?" h1
		"Nested outlines - click on the title of an outline section to expand/collapse it.  " {} "Wherever" i " button 3 is clicked, it toggles the state of that section.\n\n" {}
		"User-constructed elided text - select some text, click " {} "mark" tt " and select hide.  Then select " {} "always show" tt " and collapse that outline section.\n\n" {}
		"Automatic expansion - when jumping to a line in a collapsed portion of the outline, the surrounding context is expanded so that the line is shown on the screen.  Try making some highlights (by selecting some text and clicking the yellow plus button), closing up that section and then choosing that hightlight from the menu.\n\n" {}
		"Editing - type text, select text and click a button to make it bold, italic, highlighted, ....  These features are easy with Tk's text widget, and the elided text preserves these text tags.\n\n" {}


		"Status" h1
		"This feature is it is broadly useful, thoroughly tested both across platforms and over time, small, high performance, memory leak free, 100% compatible with existing scripts, and hard to replicate its effects in existing Tcl/Tk.  It was incorporated into Tcl/Tk 8.3.\n\n" {}

		"Changes to the text widget\n" h1
		"TAGS\n" b
		"\t-elide " {} "boolean\n" i
		"\tSpecifies whether or not to elide (hide) the text, images and embedded windows covered by this tag.  Elided text is just like other text except that is not formatted or displayed.  That is, it occupies line and character numbers, can be tagged and untagged, and moves about properly as the buffer is edited.  But during formatting, this text is ignored (except on one point: due to a technical consideration, if the elided region contains one or more newlines, a linebreak is forced).  This feature is useful for implementing outliners, speakers notes, Notemarks (see TkMan), and other applications.\n" {}
		"\n...\n\n" {}
		"pathName " i "search " b "?switches? pattern index ?stopIndex?\n" i
		"\t-elide\n" b
		"\tSearch ignores elided text unless given this switch.\n" {}


		"Performance" h1
		"The implementation efficiently skips elided areas within a (newline-terminated) line, making fast enough for 1000s of lines (at least on my UltraSPARC).  Tk's text widget expects to have a display structure (a \"DLine\") for each newline-terminated line in the displayed range, so without reworking that, we still have to examine each line and generate at least one DLine per line on layout and to traverse it on screen paint, which consumes CPU cycles.  Elided text is different from Tk's other tags in that other tags just have to operate on a window-sized chunk of text at a time, whereas with elided tags, we may need to cross vast contiguous spans of text to find enough to fill the window.\n" {}
}

image create bitmap opened -data {
#define open_width 16
#define open_height 16
static char open_bits[] = {
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x7f,0xfc,0x7f,0x1c,
 0x70,0x38,0x38,0x70,0x1c,0xe0,0x0e,0xc0,0x07,0x80,0x03,0x00,0x01,0x00,0x00,
 0x00,0x00};
}

image create bitmap closed -data {
#define closed_width 16
#define closed_height 16
static char closed_bits[] = {
 0x00,0x00,0xe0,0x00,0xe0,0x01,0xe0,0x03,0x60,0x07,0x60,0x0e,0x60,0x1c,0x60,
 0x38,0x60,0x1c,0x60,0x0e,0x60,0x07,0xe0,0x03,0xe0,0x01,0xe0,0x00,0x00,0x00,
 0x00,0x00};
}


proc setup {} {
	global demotxt sectlist showtxt

	text [set t .inv] -font {Times 12 {}} -wrap word -borderwidth 3 -padx 5 -pady 5 -yscrollcommand "[set v .v] set"
	set finv [expr 1-[catch {$t tag configure invis -elide 1}]]
	if !$finv { puts "you must apply the elided text patches first"; exit 0 }

	scrollbar $v -orient vertical -command "$t yview"

	frame [set f .butts]
	button $f.b -text "b" -font {Times 12 bold} -command "tagsel $t b"
	button $f.i -text "i" -font {Times 12 italic} -command "tagsel $t i"
	button $f.tt -text "tt" -font {Courier 12 {}} -command "tagsel $t tt"
	button $f.p -text "p" -font {Times 12 {}} -command "tagsel $t {}"
	frame $f.gap1 -width 20
	button $f.marki -text "mark" -command "tagsel $t v"
	button $f.unmarki -text "unmark" -command "tagsel $t ~v"
#	checkbutton $f.show -text "show" -command "$t tag configure v -elide \[expr {\$show?\"\":1}\]" -variable show
	set showtxt "show"
	tk_optionMenu $f.show showtxt "show" "hide" "always show"
	trace variable showtxt w setMarkElide


	frame $f.gap2 -width 20
	menubutton $f.high -relief raised -text "highlights" -menu [set m $f.high.m] -state disabled
	menu $m -tearoff no
	button $f.add -text "+" -background yellow -command "tagsel $t +"
	button $f.sub -text "-" -command "tagsel $t -"

	pack $f.p $f.b $f.i $f.tt $f.gap1 $f.marki $f.unmarki $f.show $f.gap2 $f.high $f.add $f.sub -side left
	pack $f.gap1 $f.gap2 -expand yes -fill x

	entry [set d .debug]
	bind $d <Return> "puts \[eval \[$d get\]\]"

	pack $f -side top -fill x
	pack $d -side bottom -fill x
	pack $v -side right -fill y
	pack $t -expand yes -fill both


	bind $t <ButtonRelease-3> "outline $t -1 current"
	$t tag configure title -font {Times 24 bold}
	$t tag configure h1 -font {Times 18 bold}
	$t tag configure h1 -font {Times 14 bold}
	$t tag configure b -font {Times 12 bold}
	$t tag configure i -font {Times 12 italic}
	$t tag configure tt -font {Courier 12 {}}
	$t tag configure high -background yellow
	$t tag configure v -overstrike yes


	set sectcnt 0; set subsectcnt 0
	set lastsect ""; set lastsubsect ""
	foreach {txt tag} $demotxt {
		set h1 [string equal $tag "h1"]; set h2 [string equal $tag "h2"]
		if {$h1||$h2} {
			$t insert end "\n\n"
			append txt "\n"
			if {$h1} {
				tagarea $t $lastsect; tagarea $t $lastsubsect; set lastsubsect ""

				set tag "sect[incr sectcnt]"; set subsectcnt 0
				set finv 1
#				set finv ""
				set lastsect $tag
			} else {
				tagarea $t $lastsubsect

				set tag sect$sectcnt.[incr subsectcnt]
				set finv 1
				set lastsubsect $tag
			}
			$t image create end -image [expr {$finv==1?"closed":"opened"}]
			$t tag bind $tag <ButtonRelease-1> "outline $t -1 $tag"
			$t tag bind $tag <Enter> "$t configure -cursor hand1"
			$t tag bind $tag <Leave> "$t configure -cursor left_ptr"
			$t tag configure A$tag -elide $finv
			lappend sectlist $tag
		}

		$t insert end $txt $tag
	}
	tagarea $t $lastsect; tagarea $t $lastsubsect

	$t tag raise v

	# special case for 15-second demo
	$t tag configure sect1 -font {Times 18 {bold italic}}
	$t delete sect1.last+1c sect1.last+2c
	$t insert sect2.first-1c "\n\n\n"
#	outline $t 1 sect1
}


array set showtxt2val {"show" {} "hide" 1 "always show" 0}
proc setMarkElide {var junk op} {
	global showtxt showtxt2val
	set t .inv
	$t tag configure v -elide $showtxt2val($showtxt)
}

proc dumptags {} {
	set t .inv
	foreach i [$t tag names] {
		foreach {start end} [$t tag ranges $i] {
			puts "$i\t$start .. $end, \"[$t get $start $end]\""
		}
	}
}

proc tagarea {t tag} {
	if {[string equal $tag ""]} return

#	puts "$t tag add A$tag [$t index $tag.first] [$t index {end linestart}]"
	$t tag add A$tag "$tag.first lineend+1c" "end linestart-1c"
}


proc tagsel {t tag} {
	if {[string equal [set range [$t tag ranges sel]] ""]} {
		tk_messageBox -default ok -message "You must select a range of characters first!" -type ok
		return
	}

	if {[string equal $tag ""]} {
		foreach i {i b tt} {eval $t tag remove $i $range}
	} elseif {[string equal $tag "+"] || [string equal $tag "-"]} {
		if {[string equal $tag "+"]} {eval $t tag add "high" $range} {eval $t tag remove "high" $range}
		set m [set mb .butts.high].m
		$m delete 0 last
		foreach {first last} [$t tag ranges high] {
			$m add command -label "[$t get $first $last]" -command "outline $t 0 $first; $t yview $first"
		}
		$mb configure -state [expr {[$m index last]!="none"?"normal":"disabled"}]
	} elseif {[string equal $tag ~v"]} {
		eval $t tag remove v $range
	} else {eval $t tag add $tag $range}
	selection clear
}


proc outline {t finv sect} {
	global sectlist

	# if not passed an outline tag, search for nearest previous one
	if ![string match "sect*" $sect] {
		set now [$t index $sect]
		set new [lindex $sectlist 0]
		foreach try $sectlist {
			if {[$t compare $try.first > $now]} break
			set new $try
		}
		set sect $new
	}

	set oldfinv [$t tag cget A$sect -elide]
	if {$finv==-1} {
		set finv [expr {$oldfinv==""?1:""}]
	} elseif {$finv==0} {set finv ""}

	if {$finv!=$oldfinv} {
		$t tag configure A$sect -elide $finv
		set txtstate [$t cget -state]
		$t configure -state normal
		set inx "$sect.first linestart"
		$t delete $inx
		$t image create $inx -image [expr {$finv==1?"closed":"opened"}]
		$t configure -state $txtstate
	}

	# if showing, show parent too
	if {[string equal $finv ""] && [regexp {sect([0-9]+)\.[0-9]+} $sect all num]} {outline $t $finv "sect$num"}
}


setup
