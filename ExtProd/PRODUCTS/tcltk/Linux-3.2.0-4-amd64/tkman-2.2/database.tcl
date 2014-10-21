proc manReadSects {{w .man} {force 0} {msg "Building database ..."}} {
	global man manx mani manc stat env hunk hunkcode

	set wi $w.info

	cursorBusy
	manWinstdout $w $msg 1

	# compute recent in the background
	catch {unset hunkcode hunk}
	set manx(newmen) {}
	set manx(hunkcnt) 0
	set hunkcode(0) manReadRecentDone
	# kill one in progress, if any
	if {$manx(hunkid) ne ""} {after cancel $manx(hunkid)}

	set manx(manList) ""; set manx(manTitleList) ""; set manx(mandot) ""
	set lastv ""
	set total 0
	catch {unset manc}
	set manx(stray-warnings) ""

	set buildtime [time {
	foreach i $mani(manList) j $mani(manTitleList) {
		set nowv [string index $i 0]
		if {$nowv eq $lastv} {set more [string range $i 1 end]} else {set more " $i"}
		set lastv $nowv
		manWinstdout $w "[manWinstdout $w]$more" 1
		if {[set cnt [manReadSection $i]]} {
			lappend manx(manList) $i; lappend manx(manTitleList) $j
			incr total $cnt
		}
	}
	manReadSection MASTER
	}]

	cursorUnset
	manWinstdout $w "Read $total pages"
	set manx(db-pagecnt) $total

	if {![llength $manx(manList)]} {
		puts stderr "Can't find any man pages!"
		puts stderr "MANPATH = $env(MANPATH)"
		exit 1
	}

	set maxdir ""; set maxdirtime 0
	foreach i $mani(manList) {
		scan [manLatest $mani($i,dirs)] "%d %s" mstime msdir
		set mani($i,update) $mstime
		if {$maxdirtime<$mstime} {set maxdirtime $mstime; set maxdir $msdir}
	}
	set manx($man(glimpsestrays),latest) $maxdirtime


	# dynamically formatted
	foreach i $manx(manList) {set mani($i,form) ""}

	# add standard pseudo-volumes
	foreach i $manx(extravols) {
		foreach {letter title msg} $i break
		lappend manx(manList) $letter; lappend manx(manTitleList) $title
		set mani($letter,form) $msg; set mani($letter,cnt) 0; set mani($letter,update) ""
	}

	### also need to rebuild section pulldown here
	manMakeVolList

	# kick off hunk chain
#puts "kick off @ $hunkcode(0)"
#puts "hunk 0 = $hunkcode(0)"
#for {set i 0} {$i<$manx(hunkcnt)} {incr i} {puts "hunk #$i: [string range $hunkcode($i) 0 50]..."}
	set manx(hunkid) [after 1000 $hunkcode(0)]
}




proc manLatestMan {root} {
	# compare index date against dates of SUBDIRECTORES
	# SGI sub-subdirectories lose out here... but these mostly just the preinstalled ones anyway
	#	if [catch {set men [exec $man(find) $root -type d -name 'man?*' -print]} info] { set men $info }

	set men [glob -nocomplain "$root/man?*"]
	# in cat-only situation?
	if {$men eq ""} {
		set men [glob -nocomplain "$root/*"]
		#if [catch {set men [exec $man(find) $root -type d -print]} info] { set men $info }
	}

	return [manLatest $men]
}

proc manLatest {dirs} {
	global mani

	set max 0; set maxdir ""
	foreach sub $dirs {
		if {[file isdirectory $sub]} {
			set mtime [file mtime $sub]
			set mani($sub,update) $mtime
			if {$mtime>$max} { set max $mtime; set maxdir $sub }
		}
	}

	return [list $max $maxdir]
}



#--------------------------------------------------
#
# manReadRecent -- takes lotsa time to mtime every file in a large directory, so do it in background
#
#--------------------------------------------------

# rewrite this with threads library
proc manReadRecent {sect files recentdef hunknext} {
	global manx hunk hunkcode

#DEBUG { puts -nonewline stderr "!" }
#DEBUG { puts stderr "![file dirname [lfirst $files]]" }
#puts "length of manReadRecent list = [llength $files]"
	foreach f $files {
		catch {
			# also [file readable $f]?
			if {![regexp "$manx(bkupregexp)\$" $f] && [file mtime $f]>$recentdef && [file isfile $f]} {
#puts "adding $f"
				lappend hunk($sect) [zapZ [file tail $f]]
			}
		}
	}

#DEBUG {puts "next hunk: $hunkcode($hunknext)"}
#DEBUG {puts "invoking hunk #$hunknext"}
	# have to use time, not idle, in order for code to have a chance to abort
	set manx(hunkid) [after 100 $hunkcode($hunknext)]
}

proc manReadRecentDone {} {
	global manx hunk

DEBUG {puts "RECENT DONE, hunk array: [array names hunk]"}
	foreach n [array names hunk] {
		if {$hunk($n) ne ""} {lappend manx(newmen) [list $n [lsort $hunk($n)]]}
	}

	.vols entryconfigure "Recently*" -state normal -label "Recently added/changed"
	set manx(hunkid) ""
}


#--------------------------------------------------
#
# manReadSection -- time consuming proc, so carefully optimize it
#
#--------------------------------------------------

proc manReadSection {n} {
	global man manx mani manc hunk hunkcode env

	# follow all paths here, even if search presently turned off for that dir
	if {![llength $mani($n,dirs)]} {return 0}
	# regexps common to man and cat
	set zbkup " \[^ \]+$manx(bkupregexp) "
	set znodot { [^ \.]+ } 
	set zsect {\.[^\. ]* }
	set ztclmeta {([][{}"])}


DEBUG { puts -nonewline stderr $n }
	set first 1

	# collect recent additions/changes
	# need -maxdepth *0* on find for SGI's nested directories, but only gfind has it so homebrew
	set recentdef [expr {[clock seconds]-$man(recentdays)*24*60*60}]
	# make this an after idle event.  recent section not available for ~10 seconds--who'll notice?

	# chop up files to mtime into hunks that aren't noticable to user interaction
	# would like to have threads for this
	# => just do this on demand when choose that section?
	set hunksize 25
	foreach i $mani($n,dirs) {
		set dirtime [file mtime $i]
		# not foolproof test: could just change pages
		if {$dirtime>$recentdef} {
			set mtimeme [glob -nocomplain $i/*]
#puts "$i"
			set hunk($n) {}
			for {set j 0} {$j<[llength $mtimeme]} {incr j $hunksize} {
				set hunknow $manx(hunkcnt); set hunknext [incr manx(hunkcnt)]
				# push last guy down
				set hunkcode($hunknext) $hunkcode($hunknow)

#puts "\tmaking hunk #$manx(hunkcnt) @ $j"
				set hunkcode($hunknow) "manReadRecent $n [list [lrange $mtimeme $j [expr {$j+$hunksize-1}]]] $recentdef $hunknext"
			}
		}
	}

	# collect names from directory
	set cnt 0
	foreach i $mani($n,dirs) {
		if {$manx(canformat)} {
			# all names start and end with space for regexp patterns
			cd $i; set men " [glob -nocomplain *] "
		} else {
			# preformatted pages only (SGI, Windoze)
			set men ""
		}

		# normalize names by stripping volume and compression suffixes
		# (leave dumb SGI .z suffixes to be stripped by general page normalization -- now I find that SGI uses .Z too in installing freeware, just to top their previous peak of stupidity)
		# (need while loop in case hits on consecutive names)
		regsub -all $manx(zregexpl) $men {\1 } men
		# no Emacs backup files "~" or ".bak", or no "." in name
		while {[regsub -all $zbkup $men " " men]} {}
		while {[regsub -all $znodot $men " " men]} {}

		# would like to normalize section number in name (as for .../man/.../<name>.man), but it's too variable -- ???
		regsub -all $zsect $men " " men

		# one last pass to escape Tcl meta characters -- I should think these are rare
		regsub -all $ztclmeta $men {\\\1} men


		# suck up corresponding cat dir too, in case have stray cats
		set cat ""
		if {[regsub {/man([^/]+)$} $i {/cat\1} d2] && [file isdirectory $d2] && [file readable $d2]} {
			cd $d2; set cat " [glob -nocomplain *] "
			regsub -all $manx(zregexpl) $cat {\1 } cat
			while {[regsub -all $zbkup $cat " " cat]} {}
			while {[regsub -all $znodot $cat " " cat]} {}
			regsub -all $zsect $cat " " cat
			regsub -all $ztclmeta $cat {\\\1} cat
			set cat [lsort $cat]
		}


		set unique {}
		set lastman ""
		set cati 0; set catl [llength $cat]
		set strays {}

		if {!$manx(canformat)} {
		    foreach k $cat {if {[regexp {\.} $k]} {lappend manx(mandot) $k}}
		    set unique $cat
		} else {
		    # can't use lsort -unique on concat-enated lists as want to glean stray cats
		    foreach k [lsort $men] {
			# check for stray cats
			while {$cati<$catl && [string compare [set kt [lindex $cat $cati]] $k]==-1} {
				lappend strays $kt
				lappend unique $kt
				if {[regexp {\.} $kt]} {lappend manx(mandot) $kt}
				incr cati
			}
			while {[lindex $cat $cati] eq $k} {incr cati}

			# elsewhere handle multiple pages in same man-cat pair with same name but different suffixes, e.g., printf.3s and printf.3v
			if {$k eq $lastman} continue
			lappend unique $k
			if {[regexp {\.} $k]} {lappend manx(mandot) $k}
			set lastman $k
		    }
		}

		set manc($n,$i) $unique
		if {[llength $strays]} {
			if {$manx(stray-warnings) eq ""} {set manx(stray-warnings) "Stray cats (formatted pages in .../man/catN without corresponding source in .../man/manN)\n"}
			append manx(stray-warnings) "$d2\n\t$strays\n"
		}

		incr cnt [llength $unique]
	}

	return $cnt
}



#--------------------------------------------------
#
# manShowSection -- show listing
#
#--------------------------------------------------

proc manShowSection {w n} {
	global man manx mani high stat
	global bmb

	if {[lsearch $manx(manList) $n]==-1} { manWinstderr $w "Volume $n not found"; return }
	if {$manx(shift)} { set manx(shift) 0; set w [manInstantiate] }
	set t $w.show; set wi $w.info

	manNewMode $w section $n; incr stat(section)
#	wm title $w "$manx(title$w): Volume $n"
	set manx(lastvol$w) $n
	set manx(hv$w) $n
	manShortcutsStatus $w

	set head [lindex $manx(manTitleList) [lsearch $manx(manList) $n]]

	if {$mani($n,form) eq ""} {
		cursorBusy
		manWinstdout $w "Formatting $head ..." 1
		set mani($n,shortvolname) [manFormatSect $n]
		cursorUnset
	}

	set info $head
#	if {$mani($n,update) ne ""} { append info "   (last update [textmanip::recently $mani($n,update)])" }
	manWinstdout $w $info
	manSetSect $w $n

	manTextOpen $w
#	eval $t insert end $mani($n,form) -- sometimes blows up with glimpse word index, grumble
	foreach {txt tag} $mani($n,form) {$t insert end $txt $tag}
	manLineCnt $w $mani($n,cnt) "entries"
	manTextClose $w

	manYview $w
#	focus $t
	# apropos needs special formatting tags
	if {[lsearch {apropos high census} $n]!=-1} { set tag $n } else { set tag volume }
	$t tag add $tag 1.0 end

	# rewrite Volumes label to show what volume that will be
	$w.vols configure -text $mani($n,shortvolname); set bmb($w.vols) "manShowSection $w $n"
	set manx(name$w) $head

#	if {$man(hyperclick) eq "double"} {set mod "Double-" } else {set mod ""}
	set mod [expr {$man(hyperclick) eq "double"? "Double-" : ""}]
	set ev "<${mod}ButtonRelease-1>"
#	$t tag bind hyper $ev {}
#	manHyper $w
	if {$n eq "glimpse"} {
		$t tag bind hyper $ev "+if {\$manx(glimpse-pattern) eq \$manx(search,string$w)} {$w.search.s invoke}"
#; catch {$w.sections.m invoke {Collapse all}}"
	} elseif {$n eq "glimpseindex"} {
		$t tag bind hyper $ev "+
			if {\$manx(hotman$t)!={}} { incr stat(man-hyper); manGlimpse \$manx(hotman$t) -w \$manx(out$w) }
		"
	}
}


proc manFormatSect {n} {
	global man manx mani manc high pagecnt

	set form {}; set cnt 0

	if {$n eq "high"} {
		lappend form "\tTime of last annotation\n" {}
		set lastletter ""; set lastday ""
		set sortedlist {}
		if {$manx(highsortby)==0} {
			foreach name [lsort -command manSortByTail [array names high]] {
				set sec [lindex $high($name) 0]; if {[llength $sec]>1} {set time 0}
				lappend sortedlist [list $name $sec]
			}
		} else {
			set tuples {}
			foreach name [array names high] {
				set sec [lindex $high($name) 0]; if {[llength $sec]>1} {set time 0}
				lappend tuples [list $name $sec]
			}
			set sortedlist [lsort -integer -index 1 -decreasing $tuples]
		}
		foreach k $sortedlist {
# || $k eq "*"
			foreach {name sec} $k break

			# name
			if {$manx(highsortby)==0} {
				set letter [string tolower [string index [file tail $name] 0]]
				if {$letter ne $lastletter} {lappend form "$letter  " h2; set lastletter $letter}
			}
			lappend form $name manref

			# time
			regexp {(\d+:[\d:]+)*(.*)} [textmanip::recently $sec] all time day
			if {$manx(highsortby)==1} {
				if {$day eq $lastday} {set day ""} else {set lastday $day}
			}
			if {$sec>0} { lappend form "\t$time$day" i }
			lappend form "\n" {}
			incr cnt
		}
		set mani(high,cnt) $cnt
		if {$mani(high,cnt)==0} {set form [list "No manual pages have been annotated.\n" b]}

		set mani(high,form) $form
		return "Highlighted"

	} elseif {$n eq "recent"} {
		set first 1
		foreach i $manx(newmen) {
			foreach {vol names} $i {}
			if {$first} {set first 0} else {lappend form "\n\n\n" {}}
			if {[set index [lsearch $mani(manList) $vol]]!=-1} {
				lappend form " Volume $vol, \"[lindex $mani(manTitleList) $index]\", updated at " {} [textmanip::recently $mani($vol,update)] i "\n\n" {}
			} else { lappend form $vol {} "\n\n" {}}
			# yay, tabs not underlined!
			lappend form [join $names "\t"] manref
			incr cnt [llength $names]
		}
		set mani(recent,cnt) $cnt
		if {$mani(recent,cnt)==0} {
			lappend form "There are no manual pages less than $man(recentdays) [textmanip::plural $man(recentdays) day] old.\n" {}
			lappend form "You can change the definition of `recent' in Preferences/Misc.\n"
		}
		set mani(recent,form) $form
		return "Recent"

	} elseif {$n eq "census"} {
		lappend form "\tTimes read\tTime last read\n" {}

		# can't use array get because it makes value into sublist
		set cntlist {}
		foreach name [array names pagecnt] {lappend cntlist [concat $name $pagecnt($name)]}
		if {![set cnt [llength $cntlist]]} {
			lappend form "You haven't seen any pages yet!\n"
		} else {
			set lastday ""
			set type "-integer"; set sortdir "-decreasing"
			if {$manx(censussortby)==0} {set type "-ascii"; set sortdir "-increasing"}
			foreach tuple [lsort $sortdir $type -index $manx(censussortby) $cntlist] {
				foreach {name seencnt lastread} $tuple break
				regexp {(\d+:[\d:]+)*(.*)} [textmanip::recently $lastread] all time day
				if {$manx(censussortby)==2} {
					if {$day eq $lastday} {set day ""} else {set lastday $day}
				}
				lappend form $name manref "\t$seencnt\t" {} "$time$day" i "\n" {}
			}
		}
		set mani($n,form) $form; set mani($n,cnt) $cnt
		return [lindex {Alpha Frequency Chrono} $manx(censussortby)]

#	} elseif {$n eq "glimpsefreq"} {
	} elseif {$n eq "glimpseindex"} {
		manGlimpseIndexShow
		return "Index"
	}

	if {$n eq "all"} {set sect $man(manList)} else {set sect $n}
	set ltmp {}
	foreach subvar [manSearchArray $sect] {
		# can't use lappend, at least directly
		append ltmp $manc($subvar) " "
	}

	if {$man(volcol) eq "0"} {set sep "   "} else {set sep "\t"}
	set cnt 0

	# specialized version of uniqlist
	set pr ""; set pl ""
	set sub {}
	foreach ir [lsort $ltmp] {
		# no extensions anymore, just the name root
		set il [string tolower [string index $ir 0]]

		if {$pl ne $il && [llength $sub]} {
# && ($n==3 || ![string match {[A-Z]} [string index $i 0]])} 
			lappend form [join $sub "\t"] manref "\n\n" {}
			set sub {}
			set pl $il
		}
		# within same section $pr!=$ir always, but in (all) can have duplicates
		if {$pr ne $ir} {lappend sub $ir}
		set pr $ir
		incr cnt
	}
	lappend form [join $sub "\t"] manref

	if {!$cnt} {lappend form "No man pages" b " in currently enabled paths.\nTry turning on some under the Paths pulldown menu." {}}
	set mani($n,form) $form
	set mani($n,cnt) $cnt

	return "($n)"
}

proc manSortByTail {a b} {
	return [string compare -nocase [file tail $a] [file tail $b]]
}



# would like to show size of page (# lines, maybe only estimated),
# but it would take forever to stat every file,
# and not cacheing database on disk anymore
proc manMakeVolList {{recentok 0}} {
	global man manx bmb

	set m .vols
	destroy $m; menu $m -tearoff no -font gui

	if {$man(texinfodir) ne ""} {
		$m add command -label "Texinfo" -command "manTextOpen \$curwin; texiTop \$man(texinfodir) \$curwin.show; \$curwin.show tag add volume 1.0 end; manTextClose \$curwin; \$curwin.vols configure -text Texinfo; set bmb(\$curwin.vols) {$m invoke Texinfo}"
		#"manShowSection \$curwin texi"
	}

	if {$man(rfcdir) ne "" && [file exists [file join $man(rfcdir) "rfc-index.txt"]]} {
		$m add command -label "Request for Comments (RFC)" -command {
			manShowText $man(rfcdir)/rfc-index.txt
			searchboxSearch {^\d\d\d\d} 1 1 rfcxref $curwin.show $curwin
			if {![info exists rfcmap]} {
				manWinstdout $curwin "Finding RFC directories (required first time only)..."
				cursorBusy
				foreach rfc [find $man(rfcdir) {[string match "rfc*.txt" $file]} {$depth<=2}] {
					if [regexp "$man(rfcdir)(.*/rfc0*(\\d+).txt)" $rfc all dir rfcnum] {
						set rfcmap($rfcnum) $dir
					}
				}
				cursorUnset
				manWinstdout $curwin "Request for Comment"
			}
			$curwin.vols configure -text "RFC"; set bmb($curwin.vols) "$curwin.vols.m invoke *RFC*"
		}
	}

	set iapropos [lsearch -exact $manx(manList) "apropos"]; # this is disgusting

	set ctr 0
	foreach i $manx(manList) j $manx(manTitleList) {
		set menu $m; set label "($i) $j"
		if {[llength [lassoc $manx(extravols) $i]]} {set label $j} \
		elseif {$man(subvols)} {
			set l1 [string index $i 0]
			set p [lsearch -exact $manx(manList) $l1]
			set c [lsearch -glob $manx(manList) "$l1?*"]; if {$c>=$iapropos} {set c -1}

			if {$p!=-1 && $c!=-1} {
				# part of a group => add entry to cascade menu
				set menu $m.$p
				if {$ctr==$p} {set label "general"}
#				if $manx(mondostats) { append label "   $mani($l1,cnt)" }

				# if that cascade menu doesn't exist yet, create it now
				# (so submenus need not precede their root)
				if {![winfo exists $menu]} {
					menu $menu -tearoff no
					$m add cascade -label "($i) [lindex $manx(manTitleList) $p]" -menu $menu
				}
			}
		}

		# everybody gets added somewhere, under some name
		if {$i eq "census"} {
			$menu add cascade -label $label -menu [set m2 .vols.seensortby]; menu $m2 -tearoff no
			foreach {label index} {
				"sort by frequency" 1   "sort chronologically" 2  "sort alphabetically" 0
			} {
				$m2 add command -label $label -command "set mani(census,form) {}; set manx(censussortby) $index; manShowSection \$curwin census; \$curwin.show see 1.0"
			}
		} elseif {$i eq "high"} {
			$menu add cascade -label $label -menu [set m2 .vols.highsortby]; menu $m2 -tearoff no
			foreach {label index} {
				"sort chronologically" 1  "sort alphabetically" 0
			} {
				$m2 add command -label $label -command "set mani(high,form) {}; set manx(highsortby) $index; manShowSection \$curwin high; \$curwin.show see 1.0"
			}
		} else {
			$menu add command -label $label -command "manShowSection \$curwin $i"
		}
		incr ctr
	}
	if {!$recentok} {$m entryconfigure "Recently*" -state disabled -label "Recently -- Available momentarily"}

	catch {$m entryconfigure "*apropos*" -state disabled}
	catch {$m entryconfigure "*glimpse*" -state disabled}

	foreach win [lmatches ".man*" [winfo children .]] {
		.vols clone $win.vols.m
		set mb $win.vols; $mb configure -text "Volumes"; set bmb($mb) {}
	}
	manMenuFit $m
}

proc manCatClear {} {
	global man manx
#mani
#	foreach l $mani(manList) {
#		foreach dir $mani($l,dirs) {

	# doesn't respects settings in Paths menu
	foreach dir $manx(paths) {
		# if catman, may be only copy of page (SGI only has formatted)
		if {[string match "*/catman*" $dir]} continue

		# don't complain if can't write
		# maybe wipes out RCSdiff's too
		catch {eval file delete -force [glob $dir/cat*/*]}
	}
	# plus recursive on FSSTND (necessarily retains the dir at the top of the hierarchy--this is a clean up, not an uninstall--I'm mean nobody would ever want to uninstall)
	manCatClearRecursive $man(fsstnddir)
}

proc manCatClearRecursive {dir} {
	foreach f [glob -nocomplain $dir] {
		if {[file isdirectory $f]} {manCatClearRecursive $f}
	}
	catch {eval file delete -force [glob $dir/*]}
}
