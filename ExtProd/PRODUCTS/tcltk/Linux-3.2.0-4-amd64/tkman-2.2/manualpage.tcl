#--------------------------------------------------
#
# manShowMan -- given various formats of names,
#	 search for that man page.  if successful, call manShowManFound
#
# don't use `man' to show because may want to *always*
#	 format with my own macros
#
#--------------------------------------------------

set manx(outlinesearch) ""
set manx(subsearch) ""

proc manShowMan {fname {goodnum ""} {w .man}} {
	global man manx mani env stat
DEBUG {puts stdout "manShowMan: $fname $goodnum $w"}

	if {$manx(shift)} {set manx(shift) 0; set w [manInstantiate]}

	set wi $w.info; set t $w.show

	# establish valid variable values
	if {[string trim $fname] eq ""} return

	# dispatch to pipe, straight text, Texinfo
	# `|command' for shell command, whose text is sucked into search box,
	#    to use with lman, say
	# `< file' syntax for file to suck up raw text
	# for more sophisticated file reading, use NBT

	if {[llength [set filelist [glob -nocomplain -- $fname]]]>1} {
		# show list to choose from => dups!
		manNewMode $w picklist
		manTextOpen $w
		# bolg?
		$w.show insert end [join $filelist "\n"] manref
		manTextClose $w
		return
	} elseif {[string match /* $fname]} {manShowManFound $fname 0 $w; return}
	# else search for man/Texinfo

	# given full path?  if so, don't need to search
	if {[regexp {^(\.\./|\./|[a-zA-Z]:|[~/$])} $fname]} {
#puts "full path match on $fname"
		return [manShowManFound [fileexp [lfirst $fname]] 0 $w]
	}

	# split out <name>/<subsection> or <name>?<searchstring>
	regexp {^([^/]+)\?([^/]+)$} $fname all fname manx(subsearch)
	regexp {^([^/]+)/([^/]+)$} $fname all fname manx(outlinesearch)


	### need to search for name

	# protect backslashes
	regsub "\\\\" $fname "\a" fname

	# goodnum comes from double clicks from sections or previously parsed section number
	if {[lsearch $manx(specialvols) $goodnum]!=-1} {set goodnum ""}

	# construct stem, section, extension
	set oname [string trimright [string trim [lfirst $fname] { ,?!;"'-}] .]
	if {$goodnum ne ""} {set tmp "($goodnum)"} else {set tmp ""}
	manWinstdout $w "Searching for \"$oname$tmp\" ..." 1
	set fname [string tolower $oname]; # lc w/  () for regexp
	set sname [string trim $fname ()]; # lc w/o ()
	set oname [string trim $oname ()]; # original case w/o ()

	set name $sname; set num ""; set ext ""
# set sect {\..};

	# extract section number in `man(sect)' format
	if {[regexp {([\w.+-:]+)\s*\(([^)]?)(.*)\)} $fname \
		 all pname pnum pext]} {
		set name $pname; set num $pnum; set ext $pext
#		set sect "\\\..$ext"
DEBUG {puts "(num) = $num"}

	# if you have a dot, assume it's the section number
	} elseif {[regexp {(.+)\.(.)([^.]*)$} $oname all namex sectx extx]
# bad sections fixed up later--just check for mandots here
		&& [lsearch -exact $manx(manList) $sectx]!=-1
		&& [lsearch -exact $manx(mandot) $oname]==-1} {
#		set sect {\.}
		set name $namex; set num $sectx; set ext $extx
#		set num [string trimleft [file extension $oname] .]
#		set name [file rootname $oname]
DEBUG {puts ".num = $num"}

	# given section number
	} elseif {$goodnum ne ""} {
#		set sect "\\\.$goodnum"
#		set sect {\.}
		set num $goodnum
	}

	# check for multicharacter section "letters"
	if {[lsearch -exact $manx(manList) "$num$ext"]!=-1} {
		set num "$num$ext"; set ext ""
	}

# get section number in `man.sect' format
# no .z's here

	set ext [string tolower $ext]
	if {$man(shortnames)} {set name [string range $name 0 10].*}
	if {[catch {regexp $name validregexpcheck}]} {set name [stringregexpesc $name]}
	# restore backslashes
	foreach v {fname sname oname name} {regsub "\a" [set $v] "\\" $v}

	# special case
	if {$name eq "tkman"} {manHelp $w; return}

	# search!
	cursorBusy
DEBUG {puts stdout "$name : $num : $ext"}
	set manx(searchtime) [lfirst [time {
	set foundList [manShowManSearch $name $num $ext]
	}]]
	cursorUnset
DEBUG {puts stdout "search time: $manx(searchtime)"}

	# if no matches with extension, look for one without
	set found [llength $foundList]
	if {!$found} {
DEBUG {puts stdout "$name not found: $ext, $num, [file rootname $name], [stringregexpesc $name]"}
		if {$ext ne ""} {
			manShowMan $name $num $w; return
		} elseif {$num ne "" || [file rootname $name] ne $name} {
			manShowMan [file rootname $name] {} $w
			return
		} elseif {$name ne [stringregexpesc $name] && ![string match {*\\*} $name]} {
			# case when name has embedded regexp meta characters which are part of valid regexp
			manShowMan [stringregexpesc $name] {} $w
			return
		}
	}

	# act on results of search
	if {!$found} {
		# assume got first letter right, but then be leinient
		# letter insert, delete, quasi-transpose, new all ok; later sort by length
#		regsub -all {(.)} [string range $name 1 end] {(|\1.?)} fuzzyname
#		set fuzzyname "[string index $name 0]$fuzzyname"
		# transpose, insert, delete, replace => want min edit distance
		set fuzzyname ""
		for {set i 0; set imax [expr {[string length $name]-1}]; set odd 0} {$i<$imax} {incr i; set odd [expr {1-$odd}]} {
			append fuzzyname {[} [string range $name $i [expr {$i+1}]]
#			append fuzzyname {[} [string index $name $i]
			append fuzzyname {]}
			if {$odd} {append fuzzyname "?"} elseif {$i>0} {append fuzzyname ".?"}
		}
		append fuzzyname {[} [string index $name end] {.]?}
#puts "*** FUZZY SEARCH for $name / $fuzzyname"

		# see if match in disabled Paths
		if {[llength [set hiddenList [manShowManSearch $name "" "" 1]]]} {
#puts "\t$hiddenList"
			manNewMode $w picklist
			manTextOpen $w
			$t insert end "However, found in [textmanip::plural [llength $hiddenList] {disabled path}]:\n\n"
			foreach path $hiddenList {$t insert end "[file dirname [file dirname $path]]" b "/[file tail [file dirname $path]]/[file tail $path]\n"}
			$t insert end "\nPaths can be enabled with the Paths menu, under the man menu."
			manTextClose $w
			#after 2000 $w.paths flash -- can't flash menubuttons, alas
			after 500 $w.man configure -foreground $man(buttbg) -background $man(buttfg)
			after 2500 $w.man configure -foreground $man(buttfg) -background $man(buttbg)

		# see if can find it in master list of man hierarchies
		} elseif {[llength [set masterList [manShowManSearch $name MASTER]]]} {
			manNewMode $w picklist
			manTextOpen $w
			$t insert end "However, it was found in the master list of manual page directory hierarchies.  You use the [textmanip::plural [llength $masterList] hyperlink] now, but to find this page and others clustered with it in the usual search, add the corresponding directory (named ..." "" "/man" tt ", not ..." "" "/man" tt "n" i ") to your " "" "MANPATH" sc " in a shell.\n\n"
			# don't show the following if can somehow tell user is an expert... but how?
			#set hyper [lfirst $masterList] -- use as example below... but always get weird ones
			$t insert end "For instance, if the page hyperlink shows " "" "/opt/SUNWrtvc/man/man1/mpeg_rc.1" tt " and your " "" "MANPATH" sc " is " "" "/usr/man:/usr/local/man" tt ", add " "" "/opt/SUNWrtvc/man" tt " to make it " "" "/usr/man:/usr/local/man:/opt/SUNWrtvc/man" tt ".  Then restart TkMan by typing " ""  "retkman" tt ".\n\n"
			foreach path $masterList {$t insert end "$path\n" manref}
			manTextClose $w

		# try a fuzzy match
		} elseif {$man(tryfuzzy) && [llength [set fuzzyList [manShowManSearch $fuzzyname]]]} {
			set minlen [max 4 [expr {[string length $name]-1}]]
			set priorityList {}; foreach page $fuzzyList {set fuzlen [string length [file rootname [file tail $page]]]; if {$fuzlen>=$minlen} {lappend priorityList [list $page $fuzlen]}}
			if {[llength $priorityList]} {
				set foundList {}; foreach pagepri [lsort -decreasing -integer -index 1 $priorityList] {lappend foundList [lfirst $pagepri]}
				return [manShowManFound $foundList 0 $w]
			}
		}

		manWinstderr $w "$sname not found"; incr stat(man-no)

	} else {
		set orname [file rootname $oname]
#puts "sorting $foundList"
		set priorityList {}; foreach page $foundList {lappend priorityList [list $page [manShowManPriority $page $num $ext $orname $manx(cursect$w)]]}
		set foundList {}; foreach pagepri [lsort -decreasing -integer -index 1 $priorityList] {lappend foundList [lfirst $pagepri]}
		return [manShowManFound $foundList 0 $w]
	}
}


proc manShowManPriority {m num ext orname onum} {
	global man manx mani

	# locals: d=directory, t=tail, n=number, e=extention
	set d [file dirname $m]; set t [file tail $m]
	set r [file rootname $t]; set x [file extension $t]
	set n [string index $x 1]; set e [string range $x 2 end]
	set gr $r; if {[string index $r 0] eq "g"} {set gr [string range $r 1 end]}

	# determine priority value
	# levels: name, lc names, num, ext, num==onum
	set pri 0
#	if {$man(preferTexinfo) ^ ![string match "*.texi*" $x]} {incr pri 256}; # name might be different due to matching within Texinfo's description -- but this could be confusing as not immediately apparent that Texinfo is even related!
	if {$gr eq $orname} {incr pri 128} elseif {[string equal -nocase $gr $orname]} {incr pri 32}
# I think $n==$num is true for all or none
	if {$n ne "" && $n==$num} {incr pri 64} elseif {$n==$onum} {incr pri 1}
	if {$e ne "" && $e eq $ext} {incr pri 32}
	if {$man(preferTexinfo) ^ ![string match "*.texi*" $x]} {incr pri 16}
	if {[string equal $man(preferGNU) ""] ^ ([string index $r 0] eq "g" || [regexp -nocase {/gnu} $d])} {incr pri 8}
	# stray cat can by chance override man unless prefer man
	if {[string match "*/man/man*" $d]} {incr pri 4}
DEBUG {puts "$m => $pri .. $n==$num/$n==$onum/$r==$orname/$e==$ext/*.texi*==$e"}
	set pri [expr {$pri<<8}]; # move out of tie breaker space

	# tie breaker #1: MANPATH order
	set p -1; set l [llength $manx(paths)]
	while {$d ne "/" && [set p [lsearch -glob $manx(paths) $d*]]==-1} {
		set d [file dirname $d]
	}

	# should manDescAdd directories be first or last?
	if {$p==-1} {set p $l}
	incr pri [expr {$l-$p}]
	set pri [expr {$pri<<7}]

	# tie breaker #2: section number order
	set l [llength $mani(manList)]
	set p [lsearch -exact $mani(manList) $n]; if {$p==-1} {set p $l}
	incr pri [expr {$l-$p}]

	### use time last seen as another tie breaker (later the better)?

	return $pri
}


# given name, number and extension of manual page,
# return a list of matches as full pathnames
# (should do some memoizing here)
proc manSearchArray {{sectpat ""} {inactive 0}} {
	global man manx mani
# manc

	if {[string match "*MASTER*" $sectpat]} {
		set sects "MASTER"
	} else {
		if {[string match $sectpat ""] || [lsearch $manx(manList) $sectpat]==-1} {set sectpat "*"}
		set sects $manx(manList)
	}

	set vars {}
	foreach s $sects {
		if {![string match $sectpat $s] || ![info exists mani($s,dirs)]} continue
		foreach d $mani($s,dirs) {
			set sup [file dirname $d]
			if {([info exists man($sup)] && !$man($sup)) ^ $inactive} continue
			lappend vars "$s,$d"
		}
	}
	return $vars
}


proc manManComplete {w} {
	global manx

	set t $w.show; set wi $w.info
	
	set typelen [string length $manx(typein$w)]
	if {$typelen<=1} return

	set candidates {}
	foreach c [string tolower [manShowManSearch "$manx(typein$w).*"]] {
		lappend candidates [file tail $c]
	}
	set cnt [llength $candidates]
	if {!$cnt} {
		manWinstderr $w "no matches"
		return
	} elseif {$cnt>=2} {
		if {[string length $candidates]<50} {
			manWinstderr $w $candidates
		} else {
			manTextOpen $w
			$t insert end $candidates
			manTextClose $w
		}
	}

	# compute longest common prefix
	set typeend [expr {$typelen-1}]
	set pfx [lfirst $candidates]; set end [expr {[string length $pfx]-1}]
	foreach c $candidates {
		set cend [expr {[string length $c]-1}]
		if {$end>$cend} {set end $cend; set pfx [string range $pfx 0 $end]}
		while {[string range $c 0 $end] ne $pfx} {incr end -1; set pfx [string range $pfx 0 $end]}
		if {$end==$typeend} break
	}

	set manx(typein$w) $pfx
	$w.mantypein icursor end
}


proc manShowManSearch {name {sect ""} {ext ""} {inactive 0}} {
	global man manx mani manc texi

	set foundList {}
#	set e "^$man(preferGNU)$name\$"
#	set e "^(g|n)?"; # include GNU and "new" too, whether preferred or not
#	if {[string length $name]>=5} {append e ".[string range $name 1 end]"} else {append e $name}
#	append e "\$"
	set e "(?i)\\m(g|n)?$name\\M"; # include GNU and "new" too, whether preferred or not
	set closee "(?i)^(g|n)?$name\$"; # with \m can match after "::" (which C++ and Perl use)

	# treat Texinfo as just another section
	texiDatabase $man(texinfodir)
	if {[info exists texi(texinfo,names)]} {
		set inx [lsearch -regexp $texi(texinfo,names) $e]
		if {$inx==-1} {set inx [lsearch -regexp $texi(texinfo,desc) $e]}
		if {$inx>=0} {lappend foundList [lindex $texi(texinfo,paths) $inx]}
#puts "found $e @ $inx in $texi(texinfo,names) => [lindex $texi(texinfo,paths) $inx]"
	}

#puts "manSearchArray $sect$ext* $inactive => [llength [manSearchArray $sect$ext* $inactive]]"
	foreach subvar [manSearchArray "$sect$ext*" $inactive] {
		set d [lsecond [split $subvar ","]]
		set var manc($subvar)
#puts "$var for $sect"

		# need an lsearch that can return all matches or at least search from a starting index
		# lsearch about twice as fast as foreach, so quick pass with lsearch to see if any, then complete pass with foreach (skipping first $match)
		if {[info exists manc($subvar)] && [set match [lsearch -regexp $manc($subvar) $e]]!=-1} {
			# if at least one match, find them all
			foreach p [lrange $manc($subvar) $match end] {
				if {[regexp $closee $p]} {

					set f "$d/$p"
#					puts "found $f"

					if {![llength [set actual [glob -nocomplain "$f.?*"]]]} {
						# could have been stray cat that was normalized
						if {[regsub {/man([^/]+)$} [file dirname $f] {/cat\1} d2]} {
							set actual [glob -nocomplain [file join $d2 "[file tail $f].?*"]]
						}
					}
#puts "actual = $actual"
					foreach i $actual {
						zapZ! i
						if {[regexp "$manx(bkupregexp)\$" $i]} continue
						if {[lsearch $foundList $i]==-1} {lappend foundList $i}
					}
				}
			}
		}
	}
	return $foundList
}



#--------------------------------------------------
#
# manShowManFound -- display man page and update gui with parse info
#
# invariants:
#	 manx(catfull$w)!="" iff loaded from .../cat. directory
#--------------------------------------------------

proc manShowManFound {f {keep 0} {w .man}} {
	global man manx stat pagecnt stoplist

	set t $w.show; set wi $w.info

	if {$man(maxpage)} {pack forget $w.kind $w.search}

#	if {$manx(effcols)!=""} { -- can have long lines enabled but set to 65 columns
	if {[set trylong [string match "*$manx(longtmp)*" $man(format)]]} {
		set fid [open $manx(longtmp) "w"]
		puts $fid ".ll $man(columns)\n.hym 20"
# XX augmented with architecture-specific macros not in groff's set: C for HP => too many, just prepend system's macro set to GROFF_TMAC_PATH... but that's no good either since HP's macros don't have the space between .de and macro name required by groff
#		puts $fid ".de C\n\\f3\\\\\$1 \\\\\$2 \\\\\$3 \\\\\$4 \\\\\$5 \\\\\$6 \\fR\n.."
		close $fid
# doesn't work, macros are overridden	set fid [open $manx(longtmp) "w"]; puts $fid ".ll $man(columns)\n.de VS\n..\n.de VE\n"; close $fid
	}

	# update dups arrow
	set flen [llength $f]
	if {$flen>1} {
		set manx(manhits) $f

		# multiple matches
		pack $w.dups -after $w.mantypein -side left -anchor e -padx 10; $w.dups configure -state active
		after 2000 raise $w.dups
		set m $w.dups.m
		$m delete 0 last
		foreach i [lrange $f 0 100] {$m add command -label $i -command "incr stat(man-dups); manShowManFound $i 1 \$manx(out$w)"}
		manMenuFit $m

		set f [lfirst $f]
		set keep 1
	} elseif {!$keep} {pack forget $w.dups; set manx(manhits) {}}

	# usually get name from database which doesn't have .z's, but just in case (and for transition time)
	set f [zapZ [string trim $f]]

###	if {[set manf [manManCache $w $f]]!=""} {return $manf}

# need protocol for adding suffix handlers.  generalize manShowXXX
	if {[string match "*/rfc*.txt" $f]} {
		# just like text file except credit to different account
		incr stat(rfc); incr stat(txt) -1
		manShowRfc $f $w $keep; return
	} elseif {[regexp {^[|<]} $f] || [string match "*.txt" $f]} {manShowText $f $w $keep; return
	} elseif {[regexp ".*\.texi(nfo)?$manx(zregexpopt)\$" $f]} {manShowTexi $f $w $keep; return
	}


	manNewMode $w man; incr stat(man)


	# only redirect text of man pages
#puts "show me $f$manx(zoptglob)"
	# passed filename may or may not have (i.e., need) compression suffix
#	if {[set fg [lfirst [glob -nocomplain $f*$manx(zoptglob)]]]!=""} {

	set frcs "[file dirname $f]/[zapZ [file tail $f]]"
	set isrcs 0
	if {[regexp {([^/]+):([\d\.]+)$} $f all rcstail rcsrev] 
		&& [file readable [set frcs "[file dirname $frcs]/$rcstail"]]} {

#puts "rcstail=$rcstail, frcs=$frcs, rcsrev=$rcsrev"
		set isrcs 1
#		set f [file dirname $frcs]/$rcstail
#		set f $frcs
		set fid [open "|$man(co) -p$rcsrev"]

	} elseif {[set fg [lfirst [glob -nocomplain $f$manx(zoptglob)]]] ne ""} {
		set f $fg

		if {[file isdirectory $f]} {
			manWinstderr $w "$f is a directory"
			return
		} elseif {![file readable $f]} {
			manWinstderr $w "$f not readable"
			return
		}


		# if coming from an odd place, see if looks like man; if not dump as txt
		if {![string match "*/man/*" $f] && ![string match "*/catman/*" $f]} {
#DEBUG {puts "\aman from odd place"}
			set fid [open "|[manManPipe $f]"]; set hunk [read $fid 1024]; catch {close $fid}
			if {![regexp "(^|\n)(\\.|'\\\")" $hunk]} {
#DEBUG {puts "\a=> reclassifying as txt"}
				# no roff command in first 1K => it's txt
				manShowText $f $w $keep
				return				
			}
		}

		set fid [open "|[manManPipe $f]"]

	} else {manWinstderr $w "$f doesn't exist"; return}

	set f0 $f

	# for relative names w/. and ..
	set tmpdir [file dirname $f]
#	set f [stringesc $f $manx(regexpmetachars)]
#puts "$f => $f"

	# on first line, check for single-line .so file pointing to a compressed destination
	# on second line, check for "  Purpose" as sign of IBM AIX manual page
	set so 0
#	catch {
	set line1 [set line2 [set line3 ""]]
#	if {[file readable $f]} {
#		set fid [open "|[manManPipe $f]"] -- moved up
		while {([string trim $line1] eq "" || [regexp {^[.']\\"} $line1]) && ![eof $fid]} {gets $fid line1}
		while {[string trim $line2] eq "" && ![eof $fid]} {gets $fid line2}
		while {[string trim $line3] eq "" && ![eof $fid]} {gets $fid line3}
		catch {close $fid}
#puts stderr "***$line1***\n***$line2***"
		# don't be fooled by simple inclusion of macro file
		if {[regexp {^\.so (man.+/.+)} $line1 all newman]} {
DEBUG {puts stderr "*** single-line .so => $manx(manfull$w): $line1"}
			# glob here as redirected file may be compressed
			# (catch in case destination of .so doesn't exist)
			if {[catch {set f [lfirst [glob [file join [file dirname $tmpdir] "$newman*$manx(zoptglob)"]]]}]} return
			set tmpdir [file dirname $f]
			set so 1
DEBUG {puts stderr "*** new f => $f"}
		# e.g,  <!ENTITY zcat-1 SYSTEM "./compress.1">
		# e.g., <!ENTITY uc-nisplus-1 SYSTEM "nis+.1">
		} elseif {[regexp "SHADOW_PAGE" $line2]} {
			regexp {SYSTEM "(?:./)?(.*)">} $line3 all f
			set so 1
		}
#	}
#	}

	# set up variables
	set manx(manfull$w) $f
	set manx(man$w) [zapZ [file tail $f]]
	# used to rootname so can do easy apropos or glimpse if don't find a match
	if {$isrcs} {set manx(name$w) $f} else {set manx(name$w) [string trimright [file rootname $manx(man$w)] "\\"].[manSetSect $w $f]}
#	set manx(name$w) [string trimright $manx(man$w) "\\"]

	set fdir [zapZ [file dirname $manx(manfull$w)]]
	set topdir [file dirname $fdir]
	# strip trailing Zs
	regexp $manx(zdirsect) [file tail $fdir] all manx(num$w)
	if {[lsearch $man(manList) $manx(num$w)]==-1} {set manx(num$w) [string index $manx(num$w) 0]}
#puts "manx(num\$w) = $manx(num$w)"
#	set manx(num$w) [string index [file extension $manx(man$w)] 1]
#	if {[file extension $manx(man$w)] eq ".man"} {set manx(num$w) [string index [file dirname $f] 1]}
	set cat "$topdir/cat$manx(num$w)$manx(effcols)"


	# set FSSTND for finding and saving
	# Linux FSSTND: /usr/<blah/>man/manN/<name> => /var/catman/<blah>/catN/<name>
	set fsstnd ""
# can have fsstnd set but not cache page there if directory doesn't match pattern
	if {[regexp {^(/usr)?/(.*)man/(?:s?)man(.*)$} [file dirname $manx(manfull$w)] all junk prefix suffix]} {
		# FHS 2.0 (PostScript page 26) says to strip a trailing /share... but this lead to conflicts so I'm ignoring this stupidity
		#if {[file tail $prefix] eq "share"} {set prefix [file dirname $prefix]}
		set fsstnd "$man(fsstnddir)/${prefix}cat$suffix$manx(effcols)/$manx(man$w)$manx(zoptglob)"
DEBUG {puts "*** fsstnd = $fsstnd"}
	} else {set fsstnd "$man(fsstnddir)/cat@$manx(effcols)/[file dirname $manx(manfull$w)]"}

# if get good translation from [tn]roff source, use it
#	if {$manx(rman-source) && $man(prefersource)} {
#		set manx(catfull$w) $manx(manfull$w)
#		set pipe [manManPipe $manx(catfull$w)]

	set gotcat 0
	# if cat-only, then manfull is cat already
	if {$isrcs || [string match "*ignore*" $man(nroffsave)]} {
# || $flonglines))} {
		# ignoring cache -- keep gotcat==0
	} elseif {[regexp $man(catsig) $fdir]} {
#[string match */cat?*/* $f]} {
# $tmpdir] || [string match */cat?* [file dirname $tmpdir]]} {
		set manx(catfull$w) $manx(manfull$w)

		if {$line2 eq "  Purpose"} {
			manShowText $f $w 1
			set manx(typein$w) [set manx(name$w) [file rootname [set manx(man$w) [file tail $f]]]]
			return
		}
		set gotcat 1
	} else {
DEBUG {puts "regexp on $topdir"}
		# bizarro cases:
		# Linux FSSTND set above
		# BSDI suffixes formatted pages with .0 rather than .<section>
		set bsdi "$cat/[file rootname $manx(man$w)].0$manx(zoptglob)"
#puts "bsdi = $bsdi"
		# stupid, stupid IRIX
		set irix "$cat/[file rootname $manx(man$w)].z"
#puts "irix = $irix"
#		set manx(catfull$w) "$cat*/$manx(man$w)$manx(zoptglob)"
		set manx(catfull$w) "$cat{,.Z}/$manx(man$w)$manx(zoptglob)"
DEBUG {puts "manx(man\$w) = $manx(man$w), catfull = $manx(catfull$w)"}


		# check for already-formatted man page that's up to date vis-a-vis source code
	    # for case of source a link to nowhere but formatted version OK (yeesh)
		if {[catch {set manfullmtime [file mtime $manx(manfull$w)]}]} {set manfullmtime 0}

#puts "list is  [list $manx(catfull$w) $fsstnd $bsdi $irix]"
		foreach catme [list $manx(catfull$w) $fsstnd $bsdi $irix] {
			if {$catme eq ""} continue
#puts "trying $catme"
			if {[set path [lfirst [lsort [glob -nocomplain $catme]]]] ne ""
				&& [file readable $path] && ([file mtime $path]>=$manfullmtime || !$manx(canformat))} {
					set manx(catfull$w) $path
					set gotcat 1
#puts "got it: $path"
					break
			}
#puts "catme now $catme"
		}
	}


	# need to format from roff source
	if {$isrcs} {
		# man(format) until/if source interpretation
		set pipe "$man(co) -p$rcsrev $frcs | $man(format)"
	} elseif {$gotcat} {
		set pipe [manManPipe $manx(catfull$w)]
	} elseif {[file exists $manx(manfull$w)]} {
		# cd into top of man hierarchy in case get .so's
		if {[string match */man?* $tmpdir]} {
			set topdir [file dirname $tmpdir]
		} else {set topdir $tmpdir}
		if {[catch {cd $topdir}]} {
			manWinstderr $w "Can't cd into $topdir.  This is bad.  Change permissions."
			return
		}
#puts stdout "\n\n\tcurrend dir [pwd]"
#puts stdout "manShowManFound\n\tcatfull = $cat, manfull = $manx(manfull$w)"
		# try to save a nroff-formatted version?
		# check for H-P save directory
		if {[string match "*compress" $man(nroffsave)] && [file writable "$cat.Z"]} {
			append cat ".Z"
		}
		if {[string match "*/man/sman*/*" $f]} {set format0 "/usr/lib/sgml/sgml2roff $manx(manfull$w)"} else {set format0 "[manManPipe $manx(manfull$w)]"}; append format0 " | $man(format)"

		if {[string match "on*" $man(nroffsave)]
# && [file size $manx(manfull$w)]<10*1024 -- startup for nroff/groff too much by itself
		} {
			set saveerr ""

			# if .../catN unavailable, check Linux /var/catman alternative
#puts "$man(fsstnd-always), [file writable $man(fsstnddir)], $fsstnd"
			if {($man(fsstnd-always) || ([file exists $cat]? ![file writable $cat] : ![file writable [file dirname $cat]]))
				&& [file writable $man(fsstnddir)] && $fsstnd ne ""} {
				set cat [file dirname $fsstnd]
			}

			# may need to create intermediate directories
			set idir ""
DEBUG {puts "cat = $cat"}
			foreach dir [file split [string range $cat 1 end]] {
DEBUG {puts "idir = $idir, dir = $dir"}
				if {![file exists [file join $idir $dir]]} {
DEBUG {puts "\tmaking $idir/$dir"}
#					if {![file writable $idir]} {
#						manWinstderr $w "$idir not writable when trying to mkdir $dir"
#						break
#					}
					if {[catch "file mkdir $idir/$dir" info]} {
DEBUG {puts "\t  ERROR: $info"}
#						manWinstderr $w $info 1
						set saveerr $info
						break
					} else {
						# permissions: if dir=.../catN and exists .../manN, make same as .../manN
						# otherwise make same a parent directory (assume never have to create /)
						catch {
							if {"$idir/$dir" ne $cat || ![string match cat* $dir] ||
							![file isdirectory [set permme "$idir/man[string range $dir 3 end]"]]} {
								set permme $idir
							}
							file stat $permme dirstat
							set perm [format "0%o" [expr {$dirstat(mode)&0777}]]
DEBUG { puts "\tsetting permission of directory $idir/$dir to $perm, from $permme" }
							file attributes [file join $idir $dir] -permissions $perm
						}
					}
				}
				append idir "/$dir"
			}

			if {$saveerr ne ""} {
				# nothing
			} elseif {![file writable $cat]} {
				set saveerr "CAN'T SAVE: $cat not writable"
			} else {
				# same name as source file, different directory
				set path [set manx(catfull$w) [file join $cat $manx(man$w)]]
				if {$manx(fBSDI)} {[set path [set manx(catfull$w) [file join $cat "[file rootname $manx(man$w)].0"]]]}

				manWinstdout $w "Saving copy formatted by nroff ..." 1
				# zap any existing out of date or compressed
				foreach zapme [glob -nocomplain $path$manx(zoptglob)] {file delete -force $zapme}
DEBUG { puts "[manManPipe $manx(manfull$w)] | $man(format) > $path" }
				set pipe "$format0 > $path"
				if {[catch "exec $pipe" info]} {
					set saveerr $info
				} else {
					catch {
						file stat [file dirname $manx(manfull$w)] dirstat
						set perm [format "0%o" [expr {$dirstat(mode)&0666}]]
DEBUG { puts "\tsetting permission of $path to $perm, from $manx(manfull$w)" }
						file attributes $path -permissions $perm
 					}

					# if successfully saved formatted version, check on compressing it
					if {[string match "*compress" $man(nroffsave)]} {
						manWinstdout $w "Compressing ..." 1
						set pipe "$man(compress) $manx(catfull$w)"
						if {[catch "exec $pipe" info]} {
							set saveerr "CAN'T COMPRESS:  $info"
							# set path -- keep same path
							# return -- ok to fall through
						} elseif {[file extension $cat] eq ".Z"} {	# H-P
							file rename [glob $manx(catfull$w).$manx(zglob)] $manx(catfull$w)
							set path $manx(catfull$w)
						} else {
							set path [set manx(catfull$w) [lfirst [glob $manx(catfull$w).$manx(zglob)]]]
						}
					}
					set pipe [manManPipe $path]
				}
			}

			# if problem making nroff version, fall back
			if {$saveerr ne ""} {
#				after 20 manWinstderr $w "{$saveerr}"
DEBUG {puts "FORMATTING ERROR: $saveerr"}
				after 20 manFormatError $w "{$pipe}" "{FORMATTING ERROR}" "{$saveerr}"
				#manFormatError $w $pipe "FORMATTING ERROR" $saveerr
				#return
				# probably mostly formatted, with just a couple of minor problems
				set path $manx(manfull$w)
				set manx(catfull$w) ""
				set pipe $format0
			}

		# don't save formatted version
		} else {
			set path $manx(manfull$w)
			set manx(catfull$w) ""
			set pipe $format0
		}

	} elseif {[catch {[file readlink $manx(manfull$w)]}]} {
		manWinstderr $w "$manx(manfull$w) is a symbolic link that points nowhere"
		return
	} else {
		manWinstderr $w "$manx(manfull$w) not found"
		return
	}


	# got full file name, now show it
	set errflag 0
	set msg [expr {[string match "*/*roff*" $pipe]?"Formatting and filtering":"Filtering"}]
	manWinstdout $w "$msg $manx(name$w) ..." 1


# can't really have -p here
	append pipe " | $manx(rman) -f TkMan $manx(normalize) $man(subsect) $man(headfoot)"
	if {$man(rebus)} {append pipe " -R $manx(rebus)"}
# $man(zaphy)
DEBUG {puts stderr "pipe = $pipe"}
PROFILE "opening pipe"

	# source should take a pipe argument: "source |$pipe"
	if {[catch {set fid [open "|$pipe"]} info]} {
#		manWinstderr $w "Deep weirdness with $path.  Tell your sys admin."
#		manWinstderr $w "ERROR: $info"
		after 20 manFormatError $w "{$pipe}" "ERROR" "{$info}"
DEBUG {puts "can't open pipe: $info"}
		return
	}

	manTextOpen $w


 	#while {![eof $fid]} {eval [gets $fid]}
	# don't know exact size needed because reading through pipe
	# default buffer size should be bigger (though not necessarily this big--on the other hand, what's 100K these days?)
	fconfigure $fid -buffersize 102400
	eval [read $fid]

	if {[$t compare end < 3.0]} {
		$t insert end "\nThis is a pretty short page.  Perhaps something's wrong with the formatting commands.\nType the following from a shell:\n\t$pipe\n\nIt should show man page text intermingled with Tcl/Tk commands.  (You can drop the '| rman ...' part to supress the Tcl/Tk commands.)  If not, change it so that it does--perhaps by tweaking an option in groff--and put the fix in the Makefile and/or the ~/.tkman startup file.\n"
	}

	while {[$t get 1.0] eq "\n"} {$t delete 1.0}
PROFILE "starting clo/pra/reb tags"
	# add tags from "raw" RosettaMan, before start zapping text
	$t tag add man 1.0 end-1c; # handles single tab lines and leftovers
	set cnt 1
	foreach tabcnt $manx(tabcnts) {
		if {$tabcnt>=2 && $tabcnt<=6} {$t tag add tab$tabcnt $cnt.0 "$cnt.0 lineend"}
		incr cnt
	}
	foreach clo $manx(clo) {$t tag add clo $clo.0}
	foreach para $manx(para) {$t tag add para1 $para.0}
	foreach reb $manx(reb) {$t tag add reb $reb.0}

	# do this as soon as possible to avoid future jump
	if {$man(wordfreq)} {$t insert 1.0 "\n"}

#	$t mark set endcontent end
#	$t mark gravity endcontent left

	# pseudo-section for Revision History
	set rcsfile "[file dirname $frcs]/RCS/[file tail $frcs],v"
	set rcscache "[file dirname $frcs]/RCSdiff/[file tail $frcs]"
	if {$man(versiondiff) && [file readable $rcsfile]} {
		catch {
		set rlog [exec $man(rlog) $frcs]
		set index [expr {$man(headfoot) eq ""? "end-1l" : "[lindex [$t tag ranges h2] end] linestart-1l"}]
		$t insert $index "\n" "" "Revision History\n" h2 "\n[string trim $rlog]" "" "\n\n"
		# hyperlinks of revision x.y
		set rx {^revision ([0-9\.]+)}
		while {[set index [$t search -regexp $rx $index+1l end]] ne ""} {
			regexp $rx [$t get $index "$index lineend"] all rev
			$t insert "$index lineend" "\t$frcs:$rev" {manref hyper}
		}
		}
	}

PROFILE "finding bin"
	if {!$isrcs && $man(headfoot) ne ""} {
		set f $manx(manfull$w)

		if {[catch {set og "[file attributes $f -owner]/[file attributes $f -group]"}]} {set og "(unknown)"}

		$t insert end "[bolg $f ~], installed [textmanip::recently [file mtime $f]] by $og\n"
		# report corresponding executables, if any, automatically listing first one that would be executed
		set binpre "executable: "; set binpost ""; set bincnt 0
		set bin [file rootname $manx(name$w)]; # strip suffix
		foreach bindir $manx(bin-paths) {
			foreach path [glob -nocomplain $bindir/$bin $bindir/$bin-*] {
				if {![file readable $path]} continue; # symbolic link to nowhere
				if {[catch {set binog "[file attributes $path -owner]/[file attributes $path -group]"}]} {set binog "(unknown)"}

				if {!$bincnt} {
					# if binary install more than a 2 days after man page, not mismatch
					if {[file mtime $manx(manfull$w)]+2*24*60*60 < [file mtime $path]} {
						$t insert end "May be out of date with respect to executable\n" bi
					}
				}

				set binvers ""
# too dangerous
#				foreach flag {"--version" "-V" "-v"} {
#					if {[catch {set versdump [exec $path $flag < /dev/null]} errinfo]} {set versdump $errinfo}
#					if {[regexp $manx(bin-versregexp) $versdump vers]} {
#						set binvers " (v$vers)"
#						break
#					}
#				}
				$t insert end "$binpre[bolg $path ~]$binvers, installed [textmanip::recently [file mtime $path]]"
				if {$binog ne $og} {$t insert end " by $binog"}
				$t insert end "$binpost\n"; incr bincnt

				# break -- to prevent alternatives
				set binpre "   also:  "; set binpost ""
			}
		}
		set actvol [string index [file extension [zapZ $f]] 1]
		if {$bincnt==0 && ($actvol==1 || $actvol==6 || $actvol==8)
			&& ![string match "Intro*" $f] && ![string match "List*" $f]} {
			$t insert end "No corresponding executable in PATH!" bi
			set binalts ""
			foreach bindir [concat $manx(aux-binpaths) "[file dirname [file dirname $f]]/bin" "[file dirname [file dirname [file dirname $f]]]/bin"] {
				if {[llength [glob -nocomplain $bindir/$bin $bindir/$bin-*]]} {
					append binalts ":$bindir"
				}
			}
			if {$binalts eq ""} {
				$t insert end "  This may be fine, but it is unusual for volume $actvol"
				catch {$t insert end ", [lindex $manx(manTitleList) [lsearch $manx(manList) $actvol]]"}
			} else {
				$t insert end "  However, try appending \"" "" $binalts tt "\" to your " "" "PATH" sc
			}
			$t insert end ".\n"
		}
		$t insert end "\n"

PROFILE "end bin / meta data report"
		# canonical name.  can have name conflicts, but rare
		# continue to verify any conflict would be harmless for read cnt, last read time, cksum
		set fc [zapZ [file tail $f]]
		set fpagecnt [info exists pagecnt($fc)]
		if {!$fpagecnt} {set pagecnt($fc) [list 0 [clock seconds] 0 0 [clock seconds]]}
		foreach {times lasttime cksum nlines firsttime} $pagecnt($fc) break
		set fnewdate [expr {[file mtime $f]>$lasttime}]
PROFILE "checksum"
		if {!$fpagecnt || [llength $pagecnt($fc)]<=2 || $fnewdate} {
			set curcksum 0
			catch {set curcksum [lfirst [eval exec [manManPipe $manx(manfull$w)] | $man(cksum)]]}
#puts "set curcksum \[lfirst \[exec [manManPipe $manx(manfull$w)] | $man(cksum)]] => $curcksum"
		} else {set curcksum $cksum}
PROFILE "end checksum"
		if {!$fpagecnt} {
			$t insert end "Reading $fc for " "" "first time" b "\n"
		} else {
#			foreach {times lasttime cksum nlines} $pagecnt($fc) {}
			$t insert end "Read $fc  " "" $times b " [textmanip::plural $times time], last time " "" [textmanip::recently $lasttime] b "\n"

			if {$fnewdate} {
				if {$cksum ne $curcksum && (![file readable $rcscache] || [file size $rcscache]>1)} {
					# highlights are robust enough to handle the following insertion at 1.0
					set txt "This manual page has changed since you last looked at it.  "
					# if versioning files, can see exactly how it's changed
					if {![file readable $rcsfile]} {
						append txt "If you had an old version in RCS, I could SHOW you exactly how it has changed."
					} elseif {!$man(versiondiff)} {
						append txt "If you turn on Occasionals/Show version differences, version difference information will be incorporated into the page so you can see exactly what changed."
					} else {
						append txt "You can see exactly how by scrolling through the page or by choosing \"version changes\" from the arrow next to \"n lines\" at the bottom of the screen and clicking Search."
					}
					after 1000 manTextPlug $t js1 [list "$txt\n\n"] b
				}
			}
		}
		# could use destructive list mutation operator
		set pagecnt($fc) [concat [lrange $pagecnt($fc) 0 1] $curcksum [lrange $pagecnt($fc) 3 end]]

		if {$manx(mondostats)} {after 2000 manMondostatsAfter $t $loadtime}
	}

	manTextClose $w
PROFILE "close text widget"
	manWinstdout $w ""

	catch {close $fid}
	# co -p spits to stderr and co -q dumps core
#	if {[catch {close $fid} info] && !$isrcs} {
#		manWinstderr $w "Man page not installed properly, probably."
#		manWinstderr $w "ERROR: $info"
#DEBUG {puts "can't close pipe: $info"}
#		return
#	}

#	if $manx(mondostats) {
#		# flash stats for 2 seconds
#		$t yview end; update idletasks; after 2000
#	}

	# if followed a .so link, restore initial man page name for history and shortcuts, but not highlights
	# (is this the right policy decision?)
	if {$so} {
		set manx(manfull$w) $f0
		set manx(man$w) [zapZ [file tail $f0]]
		set manx(name$w) [file rootname $manx(man$w)]
#puts stderr "new status: $manx(manfull$w), $manx(man$w), $manx(name$w)"
	}

PROFILE "collecting js*.* from h2,h3"
	# collect js*.* from tags: h2=>jsX, h3=>jsX.Y
	set sect 1
	foreach {s e} [$t tag ranges h2] {$t mark set js$sect $s; incr sect}
	if {$man(headfoot) ne ""} {
		$t mark set endcontent js[incr sect -1]-1l; $t mark unset js$sect
		$t tag add sc "endcontent+3l" "end"
	}
	set maxsect [expr {$sect-1}]
	set lastsect 1; set subsect 0
	foreach {s e} [$t tag ranges h3] {
		# find corresponding section.  since iterating in order, search from last matched section
		set sect $lastsect; while {$sect<=$maxsect && [$t compare js$sect < $s]} {incr sect}
		incr sect -1
		if {$sect ne $lastsect} {set subsect 1} else {incr subsect}; set lastsect $sect
		$t mark set js$sect.$subsect $s
	}
PROFILE "end collect / start manShowManFoundSetText"

	manShowManFoundSetText $w $t [bolg [zapZ $manx(manfull$w)] ~]
	manYview $w

	# man page refs as Notemarks -- superceding Links menu.  (still worthless though)
if {$manx(tryoutline$w) && [set tag $man(manref-show)] ne "never"} {
		foreach {s e} [$t tag ranges manref] {nb $t $tag $s $e}
	}


	# do this before go adding and deleting lines!
	# but after figure out Notemarks, 'cause don't want any show version info unless specifically requested
	$t configure -state normal
	if {$man(versiondiff) && $manx(normalize) eq "-N"} {
		scan [time {set diffcnt [manVersion $w $t $f]}] "%d" msec
#		if $manx(mondostats) {$t insert end "\n\ndiff: $diffcnt in [format %.5f [expr $msec/1000000.0]] sec" sc}
	}

PROFILE "begin rebus"
	# do rebus before highlights
	# Rebus - lines found by RosettaMan
	set rx " ($manx(rebus))"
	foreach {ls lsplus1} [$t tag ranges reb] {
		set s $ls
		set le "$ls lineend"
		# within line don't know which or how many matches
		while {[set s [$t search -elide -regexp -nocase -count e $rx $s $le]] ne ""} {
			set s "$s+1c"; incr e -1
			if {[lsearch [$t tag names $s] manref]==-1} {
				set name "[string tolower [$t get $s $s+${e}c]]Rebus"
				$t delete $s $s+${e}c
				$t image create $s -image $name
			}
		}
	}
PROFILE "end rebus"

PROFILE "highlights"
	manHighlights $w get
PROFILE "end highlights"

PROFILE "Notemarks"
	set manx(nb-cache) {}
	notemarks $w $t
PROFILE "end Notemarks"

	manAutosearch $w $t 1.0; # no delay for first hunk (maybe show first page's, eliminating future jump)

	after idle manSynargs $w $t
	after idle manAutokey $t
###	after idle manManCachePut $w $f; # has to be after the above... but needs to happen before next page

	# do word freq last (schedule furthest in future) as big time hog
	if {$man(wordfreq)} "after 100 manWordfreqAfter $w $t"

PROFILE "tagDist"
	$t configure -state disabled
	manShowTagDist $w h2 3
	manShowTagDist $w manref 1 [$t tag cget manref -foreground]
PROFILE "end tagDist"


	# whatis information -- find by scanning text => obsolete with NAME section crunching

	manWinstdout $w ""
	manWinstdout $w $manx(hv$w)

	cd $tmpdir
#	if {$manx(effcols) ne ""} {
	if {$trylong} {file delete -force $manx(longtmp)}
#}
	manShowManStatus $w
#	wm title $w "$manx(title$w): $manx(man$w)"
	set manx(lastman) $manx(manfull$w)

	if {$manx(outlinesearch) ne ""} {
		set hit ""; set js 1
		# lsearch doesn't have -nocase option
		foreach sectname $manx(sectname$t) {
			if {[regexp -nocase $manx(outlinesearch) $sectname]} {
				if {[regexp -nocase ^$manx(outlinesearch) $sectname]} {
					set hit $js; break
				} elseif {$hit eq ""} {set hit $js}
			}
			incr js
		}
		if {$hit ne ""} {manOutlineYview $t js$hit}
		set manx(outlinesearch) ""
	} elseif {$manx(subsearch) ne ""} {
		set manx(search,string$w) $manx(subsearch)
		$w.search.s invoke
		set manx(subsearch) ""
	}


	# for remote calls(?)
	return $manx(manfull$w)
}

proc manMondostatsAfter {t loadtime} {
	global manx

PROFILE "start mondo stats"
	set state [$t cget -state]; $t configure -state normal

	$t insert end "\n\n"
	scan [$t index end] "%d" numlines

	$t insert end "search time: "
	$t insert end [format %.2f [expr {$manx(searchtime)/1000000.0}]] [expr {$manx(searchtime)>600000? "b":""}]
	$t insert end " sec in $manx(db-pagecnt) pages, load time: "
	$t insert end [format %.2f [expr {$loadtime/1000000.0}]] [expr {$loadtime>1000000? "b":""}]
#	$t insert end " sec for $numlines lines\n"
	$t insert end " sec for [string length [$t get 1.0 end]] chars\n"
#[file size $f] -- file may be compressed

	set manx(searchtime) 0; # in case load from dups or history

	set sum 0; set csum 0
#	foreach tag [lsort [$t tag names]] {; # may just want b i bi tt sc symbol h2 h3 manref
	foreach tag {b i bi tt sc symbol h2 h3 manref} {
		set ranges [$t tag ranges $tag]
		set eol [llength $ranges]
		if {$eol==0} continue
		if {$tag eq "h2"} {incr eol -2} elseif {$tag eq "sc"} {incr eol -2}
		set ranges [lrange $ranges 0 [expr {$eol-1}]]
		# doesn't take that long to compute this, on an UltraSPARC anyhow
		foreach {start end} [$t tag ranges $tag] {
			# ok to diff chars as RosettaMan never crosses lines with tags
			scan $start "%d.%d" junk s; scan $end "%d.%d" junk e
			incr csum [expr {$e-$s}]
		}
		set cnt [expr {$eol/2}]; incr sum $cnt
		$t insert end "$cnt $tag, "
	}
	$t delete end-3c end-1c
	$t insert end ".   total=$sum tags, covering $csum characters\n"
	$t insert end "averages: [format %.2f [expr {$csum/($sum+0.0)}]] characters/tag, "
set tpl [expr {$sum/($numlines+0.0)}]
	$t insert end [format %.2f $tpl] [expr {$tpl>1.0? "b":""}]
	$t insert end " tags/line"

	$t configure -state $state
PROFILE "done mondo"
}



proc manWordfreqAfter {w t} {
	global manx

	set key "wordfreq,$manx(manfull$w)"
	# could truncate to n characters rather than nowrap (which affects scrolling), but don't know size to which to truncate
	if {![info exists manx($key)]} {
PROFILE "wordfreq"
		set manx($key) [join [lrange [textmanip::wordfreq [$t get 1.0 end]] 0 6] "    "]
PROFILE "end wordfreq"
	}

# doesn't work so well
#puts [textmanip::summarize $t 5]
#	foreach tuple [textmanip::summarize $t 2] {
#		foreach {s e} $tuple break
#		$t tag add bi $s $e
#		$t tag add alwaysvis $s $e
#	}

	manTextPlug $t 1.0 $manx($key) {sc nowrap}
}


proc manAutokey {t {s 1.0} {e end}} {
	global man

	if {[string trim $man(autokeywords)] eq ""} return
	set rx "(^|\[ \t(:-\])($man(autokeywords))"
#s?( |\$)"
	for {} {[set s [$t search -elide -nocase -regexp -- $rx $s $e]] ne ""} {append s "+1c"} {
		$t tag add autokey "$s+1c wordstart" "$s+1c wordend"
		# would like to make these Notemarks, but too often too many hits
	}	
}


proc manSynargs {w t} {
	global manx

PROFILE "start synopsis args in green"
	# show name and synopsis arguments in green -- would like to draw lines
	set multiple [regexp "," [lfirst [split [$t get js1 js2] "-"]]]
	set searchfor [file rootname $manx(name$w)]; set len [string length $searchfor]
	if {[set inx [lsearch $manx(sectname$t) "Synopsis"]]!=-1} {
		set now [lindex $manx(sectposns$w) $inx]; set next [lindex $manx(nextposns$w) $inx]

		set syntrim "*\[\]()&.,\;: \t"
		set syncnt 0
		for {set s $now} 1 {set s $e} {
			if {[set nextrange [$t tag nextrange i $s $next]] eq ""} break
			foreach {s e} $nextrange break
			set argname [string trim [$t get $s $e] $syntrim]
			if {![info exists synargs($argname)]} {
				set synargs($argname) ""
				$t tag add synopsisargs $s $e; # first occurance only
				incr syncnt
			}
		}
		set s $now
		for {set s $next} {$syncnt && [set nextrange [$t tag nextrange i $s end]] ne ""} {set s $e+1c} {
			foreach {s e} $nextrange break
			set name [string trim [$t get $s $e] $syntrim]
			if {[info exists synargs($name)]} {
				$t tag add synopsisargs $s $e; nb $t malwaysvis $s $e
				unset synargs($name)
				incr syncnt -1
			}
		}

		# name in synopsis
		if {$multiple && [set s [$t search -elide -- $searchfor $now $next]] ne ""} {
			$t tag add synopsisargs $s [set e $s+${len}c]; nb $t malwaysvis $s $e
		}
	}
	# name throughout rest of document, but limit to first 5 occurances for cases such as zip.1
	set cnt 0
	set rx "\t$searchfor"
	for {set s 1.0} {$cnt<5 && $multiple && [set s [$t search -elide -- $rx $s end]] ne ""} {set s $e} {
		$t tag add synopsisargs $s [set e $s+1c+${len}c]
		nb $t malwaysvis $s+1c $e
		incr cnt
	}
	update idletasks
PROFILE "end synopsis args in green"
}


proc manFormatError {w pipe errmsg errinfo} {
	set t $w.show
	# use manWinstdout instead of manWinstderr so can be aware of errors when they happen... but not too aware
	manWinstdout $w "$errmsg -- see bottom of page"
	set state [$t cget -state]
	$t configure -state normal
	#manTextOpen $w
	# insert at end so don't screw up highlights
	$t insert end "\n\n========== $errmsg ==========\n\n" b $errinfo b
	$t insert end "\n\nThis error was caused by the pipe below.  To prevent this from happening in the future, debug the pipe in a shell, outside of TkMan, and update the " "" "manformat" tt " specification in TkMan's " "" "Makefile" tt " or the " "" "man(format)" tt " variable in " "" "~/.tkman" tt " , or even  the man page itself.  If the error message refers to non-ASCII characters or unbreakable lines, the problem is with with the page itself or " "" "nroff" tt ".\n\n" "" $pipe tt
	#manTextClose $w
	$t configure -state $state
	#$t see end
}



# can't insert/delete text, just change tags
# maybe have RosettaMan make the time-consuming counts =>
#    but autosearch dominates and it's not so amenable (pass regexp, et cetera)
set manx(nb-cache) {}
proc notemarks {w t} {
	global man manx stat

	if {$manx(mode$w) ne "man"} return

	# cached?
	if {$manx(nb-cache) ne ""} {
		foreach {tag ranges} $manx(nb-cache) {
			if {$ranges ne ""} {eval $t tag add $tag $ranges}
		}
		return
	}


	set fll [expr {$man(columns)>2*$manx(screencols)}]

#puts "*** in [set ccnow [clock clicks]]"; set cclast $ccnow

	# compile list of diffd lines so can quickly skip these lines
	foreach {s e} [$t tag ranges diffd] {
		for {set i [expr {int($s)}]; set e [expr {int($e)}]} {$i<$e} {incr i} {
			set diffd($i) 1
		}
	}
#puts "diffd lines [set ccnow [clock clicks]], [expr $cclast-$ccnow]"; set cclast $ccnow

	# command line options as Notemarks
	if {$manx(tryoutline$w) && $man(options-show) ne "never"} {
		# add them all
		# the ...+5c could spill into next line, which would be desired as would have option too short to be meaningful
		foreach {clos cloe} [$t tag ranges clo] {nb $t $man(options-show) $clos "$clos+5c"}
		# if firstvis, remove ones in already opened sections -- though at this point no sections opened!
		if {$man(options-show) eq "firstvis"} {
			foreach now $manx(sectposns$w) next $manx(nextposns$w) {
				if {[$t tag cget "area$now" -elide]!="1"} {$t tag remove $man(options-show) $now $next}
			}
		}
	}
#puts "command line options [set ccnow [clock clicks]], [expr $cclast-$ccnow]"; set cclast $ccnow

	# if wasting vertical space and haven't shown Description, excerpt a few lines
	set alwaysex [string equal $man(manfill) "in entirety"]
	set exsects {}
	if {$manx(tryoutline$w) && [set tag $man(manfill-show)] ne "never"} {
		foreach now $manx(sectposns$w) next $manx(nextposns$w) sect $manx(sectname$t) {
			if {[$t tag cget "area$now" -elide]=="1"} {
				# lsearch -regexp compares pattern to string in wrong order for this application
				foreach pat $man(manfill-sects) {if {[regexp -nocase $pat $sect]} {lappend exsects $now $next}}
			}
		}
	}
	set onlyonesect [expr {[llength $exsects]<=2}]

	set winfoheight [winfo height $t]
	foreach {now next} $exsects {
		set ybot [lsecond [$t bbox endcontent]]; # end-1l?
		if {$ybot eq "" && !$alwaysex} break

		# size of description section in lines
		set maxl $manx(lcnt0$now); # don't include subsections
#		set effmaxl $maxl; if {$fll} {set effmaxl [expr {int($effmaxl*2.5)}]}
		set effmaxl $maxl; if {$fll} {set effmaxl [expr {int($effmaxl*4)}]}
		# would like to cancel excerpts for very long sections, but expect has 1159-line Commands that works great... maybe limit, ah, density?

		if {$ybot eq ""} {
			set fit 0
		} else {
			set h [font metrics [expr {$tag eq "malwaysvis"? "textpro" : "peek"}] -linespace]
#			if {$man(columns)>$manx(screencols)*2} {set maxlscreen [expr {$maxlscreen/4}]}; # average # screen lines in paragraph is, say, 4... could calculate this with metaindex...
			set fit [min $effmaxl [expr {int(($winfoheight-$ybot)/$h)}]]
#puts "min $effmaxl, expr int(($winfoheight-$ybot)/$h)"
		}

#puts "fit=$fit, maxl=$maxl, ybot=|$ybot|, sects = $exsects"
#if {$ybot ne ""} {puts "expanded size = [expr int(([winfo height $t]-$ybot)/[font metrics $man(textfont) -linespace])]"}
		# if all lines fit with expanded section, do that
		if {$ybot ne "" && $onlyonesect && 
#			int(($winfoheight-$ybot)/[font metrics $man(textfont) -linespace]) >= $maxl} {
			int(($winfoheight-$ybot)/$manx(page-fhscale)) >= $effmaxl} {
			manOutline2 $t "" $now

		# all lines of section fit (or almost fit), so show them
		} elseif {$fit>=$effmaxl-1 && $onlyonesect} {
			if {$fll} {
# WRONG
				nb $t $man(manfill-show) "$now+1l linestart" "$now+1l linestart+[expr {$fit*$manx(screencols)}]c"
			} else {
				$t tag add $man(manfill-show) "$now+1l linestart" "$now+${fit}l linestart"
			}

		# large section, show first lines of each "paragraph", with integer remainder going to first
		# doesn't always use rest of free space, but good enough
		} else {
#puts "start to count paragraphs [set ccnow [clock clicks]], [expr $cclast-$ccnow]"; set cclast $ccnow
			# count "paragraphs"
			set inx $now
			set pcnt 0
			while {[set inx [$t tag nextrange para1 $inx $next]] ne ""} {
				set para($pcnt) [expr {int([lfirst $inx])}]
				incr pcnt; set inx [lsecond $inx]
			}
			set para($pcnt) [expr {int([$t index $next])}]


			# if enormous number of paragraphs, see if some seem more important
			# (you Perl guys better appreciate this)
#			if {$pcnt>30 && double($pcnt)/double($effmaxl)>0.1} {
#			if {$pcnt>=25} {
				set bcnt 0
				for {set i 0} {$i<$pcnt} {incr i} {
					if {[lsearch -regexp [$t tag names $para($i).1] {^(b|i|bi)$}]!=-1} {
						set bpara($bcnt) $para($i); incr bcnt
					}
				}
				set bpara($bcnt) $para($pcnt)
				if {$bcnt>=5} {unset para; array set para [array get bpara]; set pcnt $bcnt}
DEBUG {puts "bcnt=$bcnt"}
				catch {unset bpara}
#			}
#puts "Perl review [set ccnow [clock clicks]], [expr $cclast-$ccnow]"; set cclast $ccnow


			set lcnt 0
#puts "lpp = $fit/$pcnt = [expr $fit/$pcnt]"
			set lpp 1; #if {1 || $ybot eq "" || !$pcnt || !$onlyonesect} {set lpp 1} else {set lpp [max 1 [expr $fit/$pcnt]]}
			$t tag configure $tag -relief [expr {$lpp>1?"raised":"flat"}]
#puts "\a*** $pcnt paragraphs, show $lpp lines per"

			# show first lpp lines in each paragraph, not counting lines already visible
			# stay within $fit or keep on truckin'.  maybe truckin' for malwaysvis only
			for {set p 0} {$p<$pcnt && ($alwaysex || $lpp+$lcnt<=$fit)} {incr p} {
				set lc 0; set pn [expr {$para([expr {1+$p}])-1}]
				# iterate through lines in that paragraph
				for {set l $para($p)} {$l<$pn} {incr l} {
					if {[$t bbox $l.0] ne "" || [info exists diffd($l)]} continue

					if {!$fll} {
						$t tag add $tag $l.0 $l.0+1l
						incr lc
					} else {
						# lines in terms of screencols
						scan [$t index "$l.0 lineend"] "%d.%d" junk scrnc
						set scrnl [min [expr {$lpp-$lc}] [max 1 [expr {($scrnc+$manx(screencols)-1)/$manx(screencols)}]]]
						$t tag add $tag $l.0 $l.[expr {$scrnl*$manx(screencols)}]
						incr lc $scrnl
					}

					if {$lc==$lpp} break
				}
			}
#puts "show first $lpp [set ccnow [clock clicks]], [expr $cclast-$ccnow]"; set cclast $ccnow
			# give integer remainder to first paragraph, maybe leaking into next section
#puts "extra [expr $fit-$lcnt]"
#			if {$lcnt<$fit && $onlyonesect} {$t tag add $tag "$now lineend+1c" "$now lineend+1c+[expr $fit-$lcnt+$lpp]l"}
#			if {$lcnt<$fit && $onlyonesect} {$t tag add $tag "$now lineend+1c" "$now lineend+1c" 0 [expr $fit-$lcnt+$lpp]}
		}
	}


	# if STILL have space, start opening up sections
	if {$manx(tryoutline$w)} {
		foreach now $manx(sectposns$w) {
			# break when see first no go, as would be weird to open random sections just because they're small
			if {[set ybot [lsecond [$t bbox endcontent]]] eq ""} break
#			if {[set ybot [lsecond [$t bbox endcontent]]] eq ""} continue; # if so, check super
			if {[$t tag cget "area$now" -elide]!="1"} continue

			if {[expr {$winfoheight-$ybot}]<[expr {$manx(lcnt0$now)*$manx(page-fhscale)}]} break
			manOutline2 $t "" $now
		}
	}

	# cache -- just for current page, but that's useful for collapsing outline and reattaching Notemarks
	# all at first viz
	# not search -- just catch the eye at first, not useful in subsequent navigation
	set cache {}; foreach tag $manx(show-ftags) {lappend cache $tag [$t tag ranges $tag]}
	set manx(nb-cache) $cache
# NO	$t tag lower hyper; # "one binding is invoked for each tag, in order from lowest-priority to highest priority"
}

proc manAutosearch {w t startinx {endinx ""}} {
	global man manx

	foreach var {autosearchnb autosearch} {set $var [string trim $man($var)]}
	if {$autosearch eq "" && $autosearchnb eq ""} return

	# autosearch string
	if {$autosearchnb ne ""} {
	set inx $startinx; if {$endinx eq ""} {set next [$t index $inx+200l]} else {set next $endinx}
	set rx "\\m($autosearchnb)"
	while {[set inx [$t search -regexp -nocase -forwards -count e -elide $rx $inx+1c $next]] ne ""} {
		# just first character?  catches eye but doesn't overwhelm
		$t tag add autosearchtag "$inx+1c wordstart"; # wordstart puts mark on section head triangle, which it vanishes when opened, but that's ok
		if {$manx(mode$w) ne "texi" && $manx(tryoutline$w) && $man(search-show) ne "never"} {
			nb $t $man(search-show) $inx+1c $inx+1c+${e}c; # no lines of context for autosearch
		}
	}
	}

	
	if {$autosearch ne ""} {
	set rx "\\m($autosearch)"
	for {set inx $startinx} {[set inx [$t search -regexp -nocase -forwards -count e -elide $rx $inx+1c $next]] ne ""} {set inx "$inx+1c"} {
		$t tag add autosearchtag "$inx+1c wordstart"
	}
	}

	if {$endinx eq "" && [$t compare $next < end]} {after idle manAutosearch $w $t $next} else {manShowTagDist $w search}
}



# centralized show of region around Notemark
# (used to be linestart .. lineend, but with lines as paragraphs that's too much)
proc nb {t tag start end {bcon 0} {fcon ""}} {
	global man manx

	if {$fcon eq ""} {set fcon $bcon}

	# widget lines == screen lines
	if {$man(columns)<2*$manx(screencols)} {$t tag add $tag "$start linestart-${bcon}l" "$end lineend+1c+${fcon}l"; return}

	if {$bcon==0} {set bcon 0.5}; if {$fcon==0} {set fcon 0.5}
	set s "$start-[expr {int($manx(screencols)*$bcon)}]c"; set smin "$start linestart"; if {[$t compare $s < $smin]} {set s $smin}
	set e "$end+[expr {int($manx(screencols)*$fcon)}]c"; set emax "$end lineend"
	if {[$t compare "$s+$manx(screencols)c" > $e]} {set e "$s+$manx(screencols)c"}
	if {[$t compare $e > $emax]} {set e $emax}
#	$t tag add $tag "$s wordstart" "$e wordend"
	$t tag add $tag $s $e; # cut into middle of words to emphasize it's an excerpt
#	$t tag add $tag "$s lineend"; # linebreaks between disparate marks
}


# pick a random manual page and show it
proc manShowRandom {w} {
	global man manx mani manc high

	expr {srand([clock clicks])}

	set sect ""
	set page TkMan

	switch -exact $man(randomscope) {
		all {
			# choose section
			while 1 {
				set sect [lindex $manx(manList) [expr {int(rand()*[llength $manx(manList)])}]]
				if {[lsearch $manx(specialvols) $sect]==-1} break
			}
			# choose page from that section
			while 1 {
				set dir [lindex $mani($sect,dirs) [expr {int(rand()*[llength $mani($sect,dirs)])}]]
				set page [lindex $manc($sect,$dir) [expr {int(rand()*[llength $manc($sect,$dir)])}]]
				if {[llength $manc($sect,$dir)]<=3 || ![regexp -nocase {list|intro} $page]} break
			}
		}
		shortcuts {
			if {[llength $man(shortcuts)]==0} {manWinstderr $w "The shortcuts list is empty"; return}
			set sect ""; # take from name
			set page [lindex $man(shortcuts) [expr {int(rand()*[llength $man(shortcuts)])}]]
		}
		history {
			if {[llength $manx(history$w)]==0} {manWinstderr $w "No pages seen: history empty"; return}
			set sect ""; # have the full path
			set page [lindex $manx(history$w) [expr {int(rand()*[llength $manx(history$w)])}]]
		}
		dups {
			set len [llength $manx(manhits)]
			if {$len<2} {manWinstderr $w "No pages in multiple matches list"; return}
			set sect ""; # have the full path
			set page [lindex $manx(manhits) [expr {int(rand()*$len)}]]
			manShowManFound $page 1 $w
			return
		}
		inpage {
			set t $w.show
			set manrefs [$t tag ranges manref]
			#$manx(mode$w)!="man" || 
			if {[llength $manrefs]==0} {
				# if no selection, choose random one from all pages
				set man(randomscope) all; manShowRandom $w; set man(randomscope) inpage
				return
			}
			set sect ""; # take from name
			set i [expr {int(rand()*[llength $manrefs]/2)*2}]
			set page [$t get [lindex $manrefs $i] [lindex $manrefs [expr {1+$i}]]]
		}
		volume {
			set sect $manx(lastvol$w)
			if {[catch {set textlist $mani($sect,form)}] || [llength $textlist]<2} {manWinstderr $w "No last volume"; return}
			set cnt 0
			while 1 {
				set i [expr {int(rand()*[llength $textlist]/2)*2}]
				set page [lindex $textlist $i]; set tag [lindex $textlist [expr {1+$i}]]
				if {$tag eq "manref"} break
				if {$cnt<50} {incr cnt} else return
			}
			if {[llength $page]>1} {set page [lindex $page [expr {int(rand()*[llength $page])}]]}
		}
	}

	manShowMan $page $sect $w
	set manx(tmp-infomsg) [manWinstdout $w]

	if {$manx(randomcont)} {after 1000 manShowRandom $w}
}


#--------------------------------------------------
#
# manPrint -- kill trees
#
#--------------------------------------------------

proc manPrint {w {printer ""}} {
	global man manx stat env

	# this shouldn't be available via GUI if $man(print)=="", but just in case...
	if {[string trim $man(print)] eq ""} return

	set t $w.show; set wi $w.info
# can't get here unless man page
#	if {$manx(mode$w)!="man" && $manx(mode$w)!="txt"} {
#		manWinstderr $w "TkMan only prints man pages."
#		return
#	}

	set f [string trim $manx(manfull$w)]
	if {$f eq "" || ![file exists $f]} return
	set tail [zapZ [file tail $f]]; set name [file rootname $tail]; set sect [string range [file extension $tail] 1 end]
	if {$sect eq ""} {regexp $manx(zdirsect) [file tail [file dirname $f]] all sect}

	set tmp [manWinstdout $w]
	manWinstdout $w "Printing $f ..." 1
	# need to cd in case of trying to print .so pages
	set curdir [pwd]
	set topdir [file dirname $f]
	set printpipe "[manManPipe $f] | $man(print)"
	if {[string match "*/man/sman*/*" $f]} {
		set printpipe "/usr/lib/sgml/sgml2roff $f | $man(print)"
	} elseif {[regexp -- $man(catsig) $topdir]} {
		set printpipe [manManPipe $f]
		if {[tk_messageBox -title "NO GUARANTEES" -message "No troff source.  Try to reverse compile cat-only page?" -icon question -type yesno -default yes] eq "yes"} {
			set printpipe " | $manx(rman) -f roff -n $name -s $sect $man(subsect) | $man(print)"
		} else {append printpipe " " $man(catprint)}
	}
	if {[regexp $man(catsig) $topdir] || [string match */man?* $topdir]} {
		set topdir [file dirname $topdir]
	}

	# try to move into $topdir, but don't complain if can't because it may not be necessary
	catch {cd $topdir}
DEBUG {puts stderr "print pipe = $printpipe"}

	if {[string trim $printer] ne ""} {
		set env(PRINTER) $printer; set env(LPDEST) $printer
	}
	eval exec $printpipe
	manWinstdout $w $tmp
	cd $curdir
	incr stat(print)
}
