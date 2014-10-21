#--------------------------------------------------
#
# manStatistics
#
#--------------------------------------------------

proc manStatistics {w} {
	global man manx mani high default stat env

	if {$manx(shift)} {set manx(shift) 0; set w [manInstantiate]}
	set t $w.show; set wi $w.info; set m $w.sections.m

	manNewMode $w info; incr stat(info)
	set manx(hv$w) info
	set head "Statistics and Information"
#	wm title $w $head
	manWinstdout $w $head
#	$w.search.cnt configure -text ""

	manTextOpen $w

	$m add command -label "Statistics" -command "incr stat(page-section); $t yview 1.0"
	$t insert end "Statistics  " h1
	manStatsSet

	$t insert end "since startup at [textmanip::recently $manx(startuptime)]"
	$t insert end "   \[total since [textmanip::recently $stat(cum-time)]\]\n" i
	$t insert end "   'Man is the measure of all things.\n\n" i

	$t insert end "TkMan version $manx(version)"
	if {$stat(cum-man)} {
		set nth [expr {$stat(cum-executions)%100}]
		if {$nth>=11 && $nth<=13} {set nth 0} else {set nth [expr {$nth%10}]}
		if {$nth>3} {set nth 0}; set th [lindex {th st nd rd} $nth]
		$t insert end "\n\t$stat(cum-executions)$th execution"

		set days [expr {(0.0+[clock seconds]-$stat(cum-time))/(60*60*24)}]
		set timesperday [expr {$stat(cum-executions)/$days}]
		if {$timesperday>0.0} {set txt [format "%.2f times per day/%.2f times per weekday" $timesperday [expr {$timesperday*7.0/5.0}]]} else {set txt [format "%.2f days per execution" [expr {1.0/$timesperday}]]}
		$t insert end " ($txt)"

		$t insert end ", browsing [format %.2f [expr {(0.0+$stat(cum-man))/$stat(cum-executions)}]] pages/execution\n"

		if {$manx(mondostats)} {
			set days {Mon Tue Wed Thu Fri Sat Sun}
			foreach day $days {set mondo($day) [list 0 0 0 0 0]}
			foreach point $man(chronobrowse) {
				foreach {time counts} [split $point ":"] break
				foreach {start duration reading} [split $time "/"] break
				if {$duration eq ""} {set duration 0}
				if {$reading eq ""} {set reading 0}
				foreach {mancnt texcnt rfccnt} [split $counts "/"] break

				set day [clock format $start -format "%a"]
				scan $mondo($day) "%d %d %d %d %d" instsub secsub mansub texsub rfcsub
				incr instsub; incr secsub $duration; 
				incr mansub $mancnt; incr texsub $texcnt; incr rfcsub $rfccnt
				set mondo($day) [list $instsub $secsub $mansub $texsub $rfcsub]

				set year [clock format $start -format "%Y"]
				if {![info exists mondoy($year)]} {set mondoy($year) [list 0 0 0 0 0]}
				scan $mondoy($year) "%d %d %d %d %d" instsub secsub mansub texsub rfcsub
				incr instsub; incr secsub $duration; 
				incr mansub $mancnt; incr texsub $texcnt; incr rfcsub $rfccnt
				set mondoy($year) [list $instsub $secsub $mansub $texsub $rfcsub]
			}
			set txt "\n\t"
			foreach year [lsort -integer [array names mondoy]] {
				scan $mondoy($year) "%d %d %d %d %d" insttot sectot mantot textot rfctot
				if {$mantot+$textot+$rfctot!=0} {append txt "$year  $insttot: $mantot/$textot/$rfctot    "}
			}
			$t insert end $txt sc "     (year/day executions: man/Texinfo/RFC)" i "\n"

			set txt "\t"
			foreach day $days {
				scan $mondo($day) "%d %d %d %d %d" insttot sectot mantot textot rfctot
				if {$mantot+$textot+$rfctot!=0} {append txt "[string range $day 0 0] $insttot:$mantot/$textot/$rfctot    "}
			}
			$t insert end $txt\n sc
		}
	}
	$t insert end "\n"

	foreach i $manx(modes) desc $manx(mode-desc) {
		$t insert end "$stat($i)\t$desc " "" "\[$stat(cum-$i)\]\n" i
		if {$i eq "man"} {
# && $stat(man)} {
#			if $stat(man-no) {
				$t delete end-1c
				$t insert end ", $stat(man-no) not found " "" "\[$stat(cum-man-no)\]\n" i
#			}
			$t insert end "\t"
			set first 1
			foreach j $manx(stats) desc $manx(stats-desc) {
				if {[string match "man-*" $j]} {
					#if {!$stat($j)} continue
					if {!$first} {$t insert end ",  "}
					$t insert end "$stat($j)  $desc " "" "\[$stat(cum-$j)\]" i
					set first 0
				}
			}
			$t insert end "\n"
		}
	}

	set pageops 0; set cpageops 0
	foreach i [array names stat page-*] {
		incr pageops $stat($i)
		incr cpageops $stat(cum-$i)
	}
	$t insert end "$pageops\tpage navigation operations " "" "\[$cpageops\]\n" i
#	if {$pageops>0} {
		$t insert end "\t"
		set first 1
		foreach j $manx(stats) desc $manx(stats-desc) {
			if {[string match "page-*" $j]} {
				#if {!$stat($j)} continue
				if {!$first} {$t insert end ",  "}
				$t insert end "$stat($j)  $desc " "" "\[$stat(cum-$j)\]" i
				set first 0
			}
		}
		$t insert end "\n"
#	}

	$t insert end "\tHighlights:  $stat(high-exact) reattached " "" "\[$stat(cum-high-exact)\]" i
	$t insert end ",  $stat(high-move) automatically repositioned on changed page  " "" "\[$stat(cum-high-move)\]" i
	$t insert end ",  $stat(high-carry) automatically carried to moved page  " "" "\[$stat(cum-high-carry)\]" i
	$t insert end ",  $stat(high-lose) unattachable  " "" "\[$stat(cum-high-lose)\]\n" i

	$t insert end "$stat(print)\tpages printed  " "" "\[$stat(cum-print)\]\n" i

	if {$man(glimpse) ne ""} {$t insert end "$stat(glimpse-builds)\tGlimpse index builds  " "" "\[$stat(cum-glimpse-builds)\]\n" i}


	global tk_patchLevel
	$t insert end "\nRunning under Tcl [info patchlevel]/Tk $tk_patchLevel\n"
	$t insert end "[info cmdcount] Tcl commands executed\n"
	catch { $t insert end "Hardware: [exec uname -a]\n" }

	$t tag add info 1.0 end; update idletasks


	if {[file readable $manx(startup)]} {
		$m add command -label "Variables" -command "incr stat(page-section); $t yview [$t index end]"
		$t insert end "\nVariables overridden in [bolg $manx(startup) ~]\n\n" h1
		set allold 1
		foreach i [lsort [array names default]] {
			set new [tr $man($i) \n " "]; if {$new eq ""} {set new "(null)"}
			set old [tr $default($i) \n " "]; if {$old eq ""} {set old "(null)"}
			if {$new ne $old} {
				$t insert end "man(" {} $i b ") = " {} $new tt ", " {} "formerly " i $old tt "\n"
				set allold 0
			}
		}
		if {$allold} { $t insert end "None\n" }
	}


	$m add command -label "Full Paths" -command "incr stat(page-section); $t yview [$t index end]"
	$t insert end "\nFull paths of supporting executables\n\n" h1
	set allfull 1
	foreach i $manx(binvars) {
		set val [set $i]
		$t insert end "$i = $val.   "
		foreach j [split $val "|"] {
			set bin [lfirst $j]
			if {![string match "/*" $bin]} {
				$t insert end "  $bin" b " => " "" $stat(bin-$bin) tt
				set allfull 0
			}
			if {[info exists stat(bin-$bin-vers)]} { $t insert end "  (v$stat(bin-$bin-vers))" }
		}
		$t insert end "\n"
	}
	if {!$allfull} {
		$t insert end "\n" "" "PATH" tt "  environment variable is " "" $env(PATH) tt "\n"
	}

	
	$m add command -label "Dates" -command "incr stat(page-section); $t yview [$t index end]"
	$t insert end "\nDates\n\n" h1
	if {[file readable $manx(startup)]} {
		$t insert end "Startup " b "file last save\n\t" {} $manx(startup) tt "\t" {} [textmanip::recently [file mtime $manx(startup)]] i "\n"
	}
	# iterate through all glimpse directories?
	if {$man(glimpse) ne ""} {
		if {$man(indexglimpse) eq "distributed"} {
			$t insert end "Distributed Glimpse " {} "indexes" b " latest updates\n"
			set paths $manx(paths)
		} else { 
			$t insert end "Unified Glimpse " {} "index" b " latest update\n"
			set paths $man(glimpsestrays)
		}

		foreach i $paths {
			set db $i/.glimpse_index
			$t insert end "\t" {} $i tt "\t"
			if {[file exists $db]} {
				$t insert end [textmanip::recently [file mtime $db]] i "\n"
			} else { $t insert end "no index" b "\n" }
		}
	}


	$m add command -label "Volume Mappings" -command "incr stat(page-section); $t yview [$t index end]"
	$t insert end "\nVolume-to-directory mappings\n\n" h1

	set manpath0 [join $manx(paths) ":"]
	$t insert end "MANPATH" sc ": " "" $manpath0 tt "\n"
	if {$manx(MANPATH0) ne $manpath0} {
		$t insert end "As cleaned up from original " "" "MANPATH" sc ": "
		foreach path [split $manx(MANPATH0) ":"] {
			$t insert end $path [expr {[lsearch -exact $manx(paths) $path]==-1?"i":"tt"}] ":" tt
		}
		$t delete end-2c; $t insert end "\n"
	}
	$t insert end "\n"

	foreach i $mani(manList) {
		if {![llength $mani($i,dirs)]} continue
		$t insert end "Volume $i, [lindex $mani(manTitleList) [lsearch $mani(manList) $i]]\n" b
		foreach j $mani($i,dirs) { 
			$t insert end "\t" {} [bolg $j ~] tt "\t" {} [textmanip::recently $mani($j,update)] i "\n"
		}
	}
	# also show stray cats, if any


	$m add command -label "Change Log" -command "incr stat(page-section); $t yview [$t index end]"
	$t insert end "\nLog of Some Less-trivial Changes\n" h1
	$t insert end $manx(changes)

	$t tag add info 1.0 end
	manTextClose $w

	scan [$t index end] %d eot
	manLineCnt $w $eot

	manYview $w
}


#--------------------------------------------------
#
# manBug -- maybe not: bugs happen before this is available, usually
#
#--------------------------------------------------

proc manBug {w} {
	global man manx mani high default stat env argv0

	if {$manx(shift)} { set manx(shift) 0; set w [manInstantiate] }
	set t $w.show; set wi $w.info

	manNewMode $w bug; incr stat(bug)
	set manx(hv$w) bug
	set head "Submit Bug Report"
#	wm title $w $head
	manWinstdout $w $head
	manLineCnt $w ""

	manTextOpen $w

	$t insert end "Select all the text below and paste into your e-mail program.\n"
	$t insert end "Before submitting a bug report, first check the home ftp site (ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk) to make sure it hasn't already been fixed in a later version." i "\n\n"


	# maybe link up with exmh
	$t insert end "To: phelps@ACM.org\n"
	$t insert end "Subject: TkMan bug report\n\n"

	$t insert end "Describe the problem:\n\n\n\n" h1


	$t insert end "System description information\n\n" h1

	$t insert end "X Windows version: _____\n"
	$t insert end "window manager: ______\n"

	global tk_patchLevel
	$t insert end "TkMan version $manx(version)\n"
	$t insert end "MANPATH = $manx(MANPATH0)\n"
	$t insert end "Tcl [info patchlevel]/Tk $tk_patchLevel\n"
	catch { $t insert end "Hardware: [exec uname -a]\n" }

	if {[file readable $manx(startup)]} {
		$t insert end "\n\nVariables overridden in [bolg $manx(startup) ~]\n\n" h1
		set allold 1
		foreach i [lsort [array names default]] {
			set new [tr $man($i) \n " "]; if {$new eq ""} {set new "(null)"}
			set old [tr $default($i) \n " "]; if {$old eq ""} {set old "(null)"}
			if {$new ne $old} {
				$t insert end "man(" {} $i b ") = " {} $new code ", " {} "formerly " i $old code "\n"
				set allold 0
			}
		}
		if {$allold} { $t insert end "None\n" }
		$t insert end "\n\n\n"
	}

	# executable and Makefile probably OK if got to this point
if 0 {
	# first few lines
	if {[file readable $argv0]} {
		$t insert end "First few lines of `tkman' executable\n\n" h1
		set fid [open $argv0]
		for {set i 0} {$i<6} {incr i} {$t insert end [gets $fid] {} "\n"}
		catch {close $fid}
	}

	# include 400+ line file here?
#	$t insert end $manx(Makefile)
}

	manTextClose $w
	manYview $w
}
