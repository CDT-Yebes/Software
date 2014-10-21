#--------------------------------------------------
#
# mandesc-like features
#
# mani(<single letter>) => name of full title main index
# mani(<letter>) => listing of full dir & list of names
# mani(<letter>,form) => formatted?
# mani(<letter>,cnt) => # of entries
# mani(<letter>,dirs) => paths x sections cross product, w/mandesc diddling
# --> everybody has a letter and letters aren't repeated
#
#--------------------------------------------------


# cross product of paths by sections
# if LANG environment variable is set, first try to read directories with that name

proc manDescDefaults {} {
	global man manx mani env

	# don't check manx(defaults) here
	manDescManiCheck return

	if {[info exists env(LANG)]} {set langs [split [string trim $env(LANG)] ":"]} else {set langs ""}
	foreach i $mani(manList) { set mani($i,dirs) {} }
	foreach i $manx(paths) { set mani($i,dirs) {} }
	set mani($man(glimpsestrays),dirs) {}
	set curdir [pwd]

	foreach i $manx(paths) {
		cd $i
		set alldirs [glob -nocomplain $manx(subdirs)]
		# is this how languages are handled?
		foreach l $langs {
			# match on $l* so pick up terrirory, character set, version
			set alldirs [concat [glob -nocomplain $l*/$manx(subdirs)] $alldirs]; # localized go first!
		}
#DEBUG {puts "    alldirs = $alldirs"}
#DEBUG {puts "    sorted alldirs = [lsort -command bytypenum $alldirs]"}
		foreach d [lsort -command bytypenum $alldirs] {
			if {[string match "*/*" $d]} {
				set lang "[file dirname $d]/"; set dir [file tail $d]
			} else {set lang ""; set dir $d }
			# keep both manN and manN.Z, with manN.Z preferred
#			set dir [file rootname $d]
#puts "*** building db: $dir"
			if {![regexp $manx(zdirsect) $dir all dirsig]} continue
			# purpose of following line?
			if {[string match "cat*" $dir]} {set dirsig [file rootname $dirsig]}
			set num [file rootname $dirsig]; set num1 [string index $num 0]

			# what section group does it belong to?
			if {[lsearch -exact $mani(manList) $num]!=-1} {set n $num} else {set n $num1}

			# check for conflicts with other abbreviations starting with same letter
			# i.e., if have <lang>/man1, disregard simple man1; if have man1, disregard cat1; but always keep sman
			set pat "^[stringregexpesc $i]/${lang}(man|sman|cat)[stringregexpesc $dirsig]\$"
			set dir $i/$d
#if {[string match "*sman*" $dir]} {puts "*** setting pat: $dir"}
#if {[string match "*sman*" $dir]} {puts "*** \[lsearch -regexp \$mani($i,dirs) $pat\]==[lsearch -regexp $mani($i,dirs) $pat]==-1 && [manPathCheckDir $dir] eq "" && ![regexp {@\d+$} $dir]"}
			if {(![string match "cat*" $d] || [lsearch -regexp $mani($i,dirs) $pat]==-1) && [manPathCheckDir $dir] eq "" && ![regexp {@\d+$} $dir]} {
#if {[string match "*sman*" $dir]} {puts "*** appended: $dir"}
				lappend mani($i,dirs) $dir
				lappend mani($n,dirs) $dir
			}
		}
#DEBUG {puts "mani($i,dirs) = $mani($i,dirs)"}
	}
#DEBUG {foreach i $mani(manList) { puts "mani($i,dirs) = $mani($i,dirs)" }}

	cd $curdir
	set manx(defaults) 1
}

proc bytypenum {a b} {
	if {[string match "*/*" $a]} {set al [file dirname $a]; set a [file tail $a] } else {set al ""}
	if {[string match "*.Z" $a]} {set as [file extension $a]; set a [file rootname $a] } else {set as ""}
	set at [string range $a 0 2]
	if {[string match "*/*" $b]} {set bl [file dirname $b]; set b [file tail $b] } else {set bl ""}
	if {[string match "*.Z" $b]} {set bs [file extension $b]; set b [file rootname $b] } else {set bs ""}
	set bt [string range $b 0 2]

	# priority: language, type (man or cat), number, .Z suffix
	if {$al ne $bl} {
		if {$al eq ""} {return 1} elseif {$bl eq ""} {return -1} elseif {$al<$bl} {return -1} else {return 1}
	} elseif {$at ne $bt} {
		if {$at eq "sma" || ($at eq "man" && $bt eq "cat")} {return -1} else {return 1}
	} elseif {$as ne $bs} {
		# prefer .Z
		if {$as eq ""} {return 1} else {return -1}
	} else {
		if {$a<$b} {return -1} else {return 1}
	}

	return 0
}


# commands: move, copy, delete
# from, to *list* of source, target dirs
# list is list of directory *patterns*

proc manDescMove {from to dirs} {manDesc move $from $to $dirs}
proc manDescDelete {from dirs} {manDesc delete $from "" $dirs}
proc manDescCopy {from to dirs} {manDesc copy $from $to $dirs}
set manx(mandesc-warnings) ""
proc manDescAdd {to dirs} {
	global mani manx man

	set manx(mandesc-warnings) ""
	set warnings ""

	manDescManiCheck
	foreach d $dirs {
		if {[set warnmsg [manPathCheckDir $d]] ne ""} {
			append warnings $warnmsg
		} else {
			foreach t $to {lappend mani($t,dirs) $d}

			# try to attach these oddball directories to some MANPATH
			# in order to make them available for Glimpse indexing
DEBUG {puts "MANPATH for $d?"}
			set mp $d
			while {[string match "/*" $mp] && $mp ne "/"} {
				if {[lsearch -exact $manx(paths) $mp]>=0} {
DEBUG {puts "\tyes, in $mp"}
					lappend mani($mp,dirs) $d; break
				} else {set mp [file dirname $mp]}
			}
			if {$mp eq "/"} { lappend mani($man(glimpsestrays),dirs) $d
DEBUG {puts "\tno, added to strays\n\t\tnow mani($man(glimpsestrays),dirs) =  $mani($man(glimpsestrays),dirs)"}
			}
		}
	}


	if {$warnings ne ""} {
		if {![string match *manDescAdd* $manx(mandesc-warnings)]} {
			append manx(mandesc-warnings) "Problems with manDescAdd's...\n"
		}
		append manx(mandesc-warnings) $warnings
	}
}


proc manDesc {cmd from to dirs} {
	global man manx mani

	manDescManiCheck
	if {$from eq "*"} {set from $mani(manList)}
	if {$to eq "*"} {set to $mani(manList)}
	foreach n [concat $from $to] {
		if {[lsearch $mani(manList) $n]==-1} {
			puts stderr "$cmd: Section letter `$n' doesn't exist."
			exit 1
		}
	}

DEBUG {puts stdout "$cmd {$from} {$to} {$dirs}"}
	foreach d $dirs {
		foreach f $from {
			set newdir {}
			foreach fi $mani($f,dirs) {
				if {[string match $d $fi]} {
					if {$cmd eq "copy"} {lappend newdir $fi}
					if {[regexp "copy|move" $cmd]} {
						foreach t $to {if {$f ne $t} {lappend mani($t,dirs) $fi} else {lappend newdir $fi}}
					}
				} else {lappend newdir $fi}
			}
			set mani($f,dirs) $newdir
DEBUG {puts stdout $f:$mani($f,dirs)}
		}
	}
}

proc manDescAddSects {l {posn "end"} {what "n"}} {
	global man mani

	manDescManiCheck
	if {[regexp "before|after" $posn]} {set l [lreverse $l]}
	foreach i $l {
		foreach {n tit} $i break
		if {[lsearch $mani(manList) $n]!=-1} {
			puts stderr "Section letter `$n' already in use; request ignored."
			continue
		}

		if {$posn eq "end"} {
			lappend mani(manList) $n
			lappend mani(manTitleList) $tit

		} elseif {$posn eq "before" || $posn eq "after"} {
			if {[set ndx [lsearch $mani(manList) $what]]==-1} {
				puts stderr "Requested $posn $what, but $what doesn't exist; request ignored"
				continue
			}
			if {$posn eq "after"} {incr ndx}
			set mani(manList) [linsert $mani(manList) $ndx $n]
			set mani(manTitleList) [linsert $mani(manTitleList) $ndx $tit]

		} elseif {$posn eq "sort"} {
			lappend mani(manList) $n
			set mani(manList) [lsort $mani(manList)]
			set ndx [lsearch $mani(manList) $n]
			set mani(manTitleList) [linsert $mani(manTitleList) $ndx $tit]
		}

		set mani($n,dirs) {}
	}
}


# if mani array, matrix not already created, do it now

proc manDescManiCheck {{action "exit"}} {
	global man mani manx env

	# check for missing call to manDot
	if {!$manx(manDot)} manDot

	if {![info exists mani(manList)]} {
		set mani(manList) $man(manList)
		set mani(manTitleList) $man(manTitleList)

		if {![info exists env(MANPATH)] || [string trim $env(MANPATH)] eq ""} {
			puts stderr "You must set a MANPATH environment variable,\nwhich is a colon-separated list of directories in which\nto find man pages, for example /usr/man:/usr/share/man.\n(See the help page for an explanation of why\nalternatives to the MANPATH are a bad thing.)"
			exit 1
		}
		set manx(MANPATH0) $env(MANPATH)

		manManpathCheck

		if {$action eq "return"} return
		manDescDefaults
	}
}


# place SGI's magically-appearing catman subdirectories into volumes

proc manDescSGI {patterns} {
	global man manx mani

	# start up checks for patterns
	# (=> maybe go with (vol name pats) tuples)

	set paterrs 0
	foreach pat $patterns {
		foreach {mapto patlist} $pat {}

		# make sure each mapping exists as a volume that's been added
		if {[lsearch -regexp $mani(manList) ".?$mapto"]==-1} {
			puts stderr "no volume corresponding to $mapto mapping (patterns: $patlist)"
			incr paterrs
		}

		# make sure patterns don't overlap
		#    can't have identical patterns (ftn =>! 2f and 3ftn.)
		#    either: 2/ftn=>2f and 3/ftn=>3ftn)  *or*  merge with ftn => 2ftn and 3ftn
		foreach p $patlist {
			foreach pat2 $patterns {
				if {$pat eq $pat2} break
				set mapto2 [lfirst $pat2]; set patlist2 [lsecond $pat2]
				foreach p2 $patlist2 {
					if {[string match $p2 $p]} {
						puts stderr "pattern $p never reached -- $mapto2's $p2 precludes it"
						incr paterrs
					}
				}
			}
		}
	}

	# add a guaranteed match, that's placed in single-letter volume
	lappend patterns {"" {""}}
	DEBUG {puts "mani(manList) => $mani(manList)"}

	# collect .../catman directories (know they're readable by this point)
	set catmen {}
	foreach d $manx(paths) {
#[split $manx(MANPATH0) ":"] {
		if {[string match "*/catman" $d]} {lappend catmen $d}
	}
	if {![llength $catmen]} {
		puts stderr "No sneaky catman directories found in MANPATH:\n\t$manx(MANPATH0)"
		return
		#exit 1
	}


	# make sure end of list test is deferred because possibly adding to list each time
	set rcats $catmen; set catmandirs {}
	for {set i 0} {$i<[llength $rcats]} {incr i} {
###	foreach dir $rcats ???
		foreach f [glob -nocomplain [file join [lindex $rcats $i] "*"]] {
			# relying on shortcircuiting behavior of &&
			# Tcl's file isdirectory dereferences symbolic links
			# SGI's xman relies upon directories not ending in .z,
			# don't use ![regexp $manx(zregexp) $f] as manx(zregexp) not set when this is called
		    	# can't rely on pack .z compression: seen .gz, seen uncompressed -- checking for "." in filename tail (.z/.gz/.3X/...)
# was:			if {![string match "*.z" $f]...
			if {![regexp {/[^/]+\.[^/]+$} $f] && [file tail $f] ne "RCS" && [file tail $f] ne "RCSdiff" && [lsearch -exact $rcats $f]==-1 && [file isdirectory $f]} {
				lappend rcats $f; lappend catmandirs $f
			}
		}
	}

	foreach dir $catmandirs {
		if {[regexp {(catman|_man)$} $dir]} continue
		set tail [file tail $dir]
		set vol [file tail [file dirname $dir]]
		if {![regexp "^(man|cat)" $vol]} {set vol $tail; set tail ""}

		set volnum [string index $vol 3]

		DEBUG {puts -nonewline "$dir ($vol:$tail ($volnum)) => "}
		set matched 0
		foreach pat $patterns {
			foreach {mapto patlist} $pat break
			foreach dp $patlist {
				if {[string match "*$dp" $dir]} {
					DEBUG {puts -nonewline "match on $dp => "}
					set matched 1
					# first try to place in mapto name in current volume
					if {[lsearch -exact $mani(manList) "$volnum$mapto"]!=-1} {
						DEBUG {puts $volnum$mapto}
						manDescAdd "$volnum$mapto" $dir

					# then try mapto name in any volume
					} elseif {[lsearch -exact $mani(manList) $mapto]!=-1} {
						DEBUG {puts $mapto}
						manDescAdd $mapto $dir

			 		# else place in a parent volume
					} elseif {[lsearch -exact $mani(manList) $volnum]!=-1} {
						DEBUG {puts $volnum}
						manDescAdd $volnum $dir

					} else {
						DEBUG {puts "can't place"}
					}

					break
				}
			}
			if {$matched} break
		}
		DEBUG {if {!$matched} {puts "CAN'T MATCH\a\a"}}
	}
}



# for debugging
proc manDescShow {} {
	global man manx mani

	manDescManiCheck
	puts stdout "*** manDescShow"
	foreach i $mani(manList) {
		puts stdout $i:$mani($i,dirs)
	}
}
