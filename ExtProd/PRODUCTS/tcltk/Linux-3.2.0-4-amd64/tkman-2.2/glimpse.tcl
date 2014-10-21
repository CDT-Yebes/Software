#--------------------------------------------------
#
# manGlimpse -- full text search
#
#--------------------------------------------------

proc manGlimpse {name {opts ""} {w .man}} {
	global man manx

	# index over currently selected paths, and (always) stray cats
	set dirs $man(glimpsestrays)

	set len [llength $name]
	if {$len>=2} {
		if {[string match "-*" $name]} {
			set name [lindex $name end]; set opts [concat $opts [lrange $name 0 [expr {$len-1-1}]]]
		} else {
#			set name [tr $name " \t\n" ";"]
			set name [tr $name {\s} ";"]
		}
	}
	if {$man(indexglimpse) eq "distributed"} {
		set texindexdir [file join $man(texinfodir) glimpse]
		if {$man(texinfodir) ne "" && [file readable $texindexdir]} {lappend dirs $texindexdir}

		if {$man(rfcdir) ne "" && [file readable $man(rfcdir)]} {lappend dirs $man(rfcdir)}
		foreach dir $man(indexalso) { if {[file readable $dir]} {lappend dirs $dir} }

		foreach d $manx(paths) {
			if {$man($d)} {	lappend dirs $d }
		}
	} else {
# can't restrict unified glimpse searches to directories in Paths
# because list of directories can exceed a buffer in agrep
#		set first "-F "
#		foreach d $manx(paths) {
#			append auxopts $first [stringregexpesc $d]
#			set first ","
#		}
	}

	manGlimpse2 $name $dirs $opts $w
}

set manx(glimpse-pattern) ""; # shouldn't need to set it here, but just to be safe
proc manGlimpse2 {name dirs {auxopts ""} {w .man}} {
	global man manx mani sbx env stat STOP texi

	if {$manx(shift)} {set manx(shift) 0; set w [manInstantiate]}
	set t $w.show; set wi $w.info

	# set name to search for and name to show
	if {$name eq ""} {set name $manx(man$w)}
	if {$name eq ""} {
		manWinstderr $w "Type in regular expression for full text search"
		return
	}
	set showname $name

	# set options
	#set opts "-ly"
	set opts "-y"
	if {$man(regexp,case)!=-1 || [string is lower $name]} {append opts "i"}
	if {$man(maxglimpse) ne "none"} {append opts " -L $man(maxglimpse):0:5"}

	# kill -w for everybody -- use at your own risk: gotta keep for "perl" and others
	set g1 "$man(glimpse) $auxopts $opts"
#	regsub -- {-([^ /]*)w} "$man(glimpse) $auxopts $opts" {-Z\1} g1
	# kill -N for excerpts search
	regsub -- {-([^ /]*)N} $g1 {-Z\1} g2


	set foundList ""
	set errorList ""

	# FIRST SEARCH index only to estimate number of matches

	foreach d $dirs {
		# this error reported at startup, so silently skip over missing .glimpse_* here
		if {![file readable [file join $d ".glimpse_index"]]} continue
DEBUG {puts "index search: $g1 -H $d $name"}

		# would be considerably(?) more efficient if Glimpse could handle a list of directories
		# to search for matches, rather than multiple exec's
		# HACK: -N spits out block matches to stderr, which is an error to Tcl, so 2>/dev/null
		# protect name with braces as may include semicolon (glimpse AND operator)
		if {![catch {set matches [eval exec "$g1 -N -H $d {$name} 2>/dev/null"]} info]} {
			set foundList [concat $foundList [lsort [split $matches "\n"]]]
		} else {set errorList [concat $errorList [list "error with glimpsing $d:"] [split $info "\n"]]}
	}
	set fIndexonly [expr {[llength $foundList]>$man(maxglimpseexcerpt)}]


	# SECOND SEARCH extracts those matches, if < $man(maxglimpseexcerpt), 

	if {!$fIndexonly} {
		set foundList ""; # replace existing hit list with one with excerpts
		set errorList ""

		# -w and -z together gives stderr message -- probably a bug in glimpse
		# => but we always kill -w anyhow, so nothing to worry about here
		#set redirect "" -- and don't have to redirect anymore, in absence of -N and (-w and -z)

		set STOP 0
		cursorBusy

		foreach d $dirs {
			if {![file readable [file join $d ".glimpse_index"]]} continue
			set glz ""; if {[file readable [file join $d ".glimpse_filters"]] && [file size [file join $d ".glimpse_filters"]]>1} {set glz "-z"}
			manWinstdout $w "Glimpsing for \"$showname\" in $d ..."; update; # not "update idletasks" because want to accept stop requests from keyboard (should change "man" to "STOP" and reprogram so can stop with a click too)
DEBUG {puts "$g2 -H $d $name"}
			if {$STOP} {set STOP 0; break}
			if {![catch {set matches [eval exec "$g2 $glz -O -H $d {$name} 2>/dev/null"]} info]} {
# || [string match "There are matches to *" $info] || [string match "*-d or -w option is not supported for this pattern*" $info]
				set foundList [concat $foundList [split $matches "\n"]]
			} else {set errorList [concat $errorList [list "error with glimpsing $d:"] [split $info "\n"]]}
		}
	}


	## format the result

	set foundform ""
	set found 0

	foreach errmsg $errorList {lappend foundform "$errmsg\n" i}
	if {[llength $errorList]} {lappend errmsg "\n\n" {}}

	# Texinfo
	set texindexdir [file join $man(texinfodir) glimpse]
	if {$man(texinfodir) eq "" || ![file readable $texindexdir]} {set texindexdir ""}
	if {$texindexdir ne ""} {
#		if ![info exists texi(texinfo,paths)] { -- always compute as may have changed
#			set texi(texinfo,paths) {}
			texiDatabase $man(texinfodir)
#		}
		set texifound {}
	}


	# reformat results: link on file, spaces on hit text, canonicalize Texinfo paths
	foreach page $foundList {
		set page [string trimright $page ":"]

		# The following not true?
		# If there are more subMatchVar's than parenthesized subexpressions within exp, or if a
		# particular subexpression in exp doesn't match the string (e.g. because it was in a
		# portion of the expression that wasn't matched), then the corresponding subMatchVar
		# will be set to ``-1 -1'' if -indices has been specified or to an empty string otherwise.

		if {$texindexdir ne "" && [string match [file join $texindexdir "*"] $page]} {
#puts "considering $page"
			set mapped ""

			# if exact match on file (including compression suffix, if any), it's a keeper...
			set mapto [zapZ [file tail $page]]
#puts "\t$mapto"
			foreach canon $texi(texinfo,paths) {
				if {[string match /*/$mapto [zapZ $canon]]} {set mapped $canon; break}
			}
			# ... else try to match on dir
			if {$mapped eq ""} {
				set mapto [file rootname [file tail [file dirname $page]]]
#puts "\t$mapto"
				foreach canon $texi(texinfo,paths) {
					if {[string match /*/$mapto [file dirname $canon]]} {set mapped $canon; break}
				}
			}
			# you'd better have found it by now
			if {$mapped ne "" && [lsearch $texifound $mapped]==-1} {lappend texifound [set page $mapped]} else {set page ""}; # ... else continue
#puts "=> $mapped / $page"
		}


		if {$page eq ""} {
			# nothing
		} elseif {[string match "/*" $page]} {
			lappend foundform "[bolg $page ~]\n" manref
			incr found
		} else {
			lappend foundform "     $page\n" sc
		}
	}
	manWinstdout $w ""
	cursorUnset


	set error [string length $errorList]
	if {!$found && !$error} {
		manWinstderr $w "$name not found in full text search"
		# don't destroy old list
	} else {
		manNewMode $w glimpse; incr stat(glimpse)
		set mani(glimpse,update) [clock seconds]
		set form {}
		lappend form " Glimpse full text search for \"$name\"\n\n" {}

		if {$error} {
			lappend form "Errors while Glimpsing:\n\n" {}
		}

#		set cnt [expr {$error?"errors":$found]}]

		set mani(glimpse,form) [concat $form $foundform]
		set mani(glimpse,cnt) $found
		set mani(glimpse,shortvolname) "glimpse"

		# seed regexp and isearch strings
#		set manx(search,string$w) [tr [tr [llast $name] ";" ".*"] "," "|"]
		set manx(search,string$w) [set manx(glimpse-pattern) [tr [tr [llast $name] ";" "|"] "," "|"]]
		set sbx(lastkeys-old$t) [llast $name]

		.vols entryconfigure "*glimpse*" -state normal
# -label "glimpse hit list ($cnt for \"$name\")"
		manShowSection $w glimpse

		if {!$fIndexonly} "
			after 1000 {
				searchboxSearch \$manx(search,string$w) 1 \$man(regexp,case) search $t
				foreach {s e} \[$t tag ranges search] {$t tag remove search \$s+1c \$e}
			}
		"
	}
}


set mani(glimpseindex,update) 0
proc manGlimpseIndexShow {} {
	global man manx mani curwin

	set gi [file join $man(glimpsestrays) ".glimpse_index"]
	if {$man(indexglimpse) ne "unified" || ![file readable $gi] || $mani(glimpseindex,update)>[file mtime $gi]} return

	set fid [open $gi]; set indexglimpse [read $fid]; close $fid
	regsub -all "\002\[^\n\]+" $indexglimpse "" indexglimpse; # offset into partitions -- also \002.... notrail -- 
	regsub -all "\[\001-\011\013-\037\]+" $indexglimpse "" indexglimpse; # noctrl
	# need while [regsub ...] or skip every word following a match
	while {[regsub -all "\n\[_-\]+\n" $indexglimpse "\n" indexglimpse]} {}; # nobox
	while {[regsub -all "\n\[^\n\]\[^\n\]?\[^\n\]?\n" $indexglimpse "\n" indexglimpse]} {}; # misses some?  -- no123
	while {[regsub -all "\n\[^_a-z\]\[^\n\]*\n" $indexglimpse "\n" indexglimpse]} {}; # no noise

	set index {}; set sub {}; set och2 "__"
	foreach i [lsort $indexglimpse] {
		set ch2 [string range $i 0 1]
		if {$ch2 ne $och2} {lappend index [join $sub "\t"] manref "\n\n" {}; set sub {}; set och2 $ch2}
		lappend sub $i
	}
	if {$sub ne ""} {lappend index [join $sub "\t"] manref}

	set mani(glimpseindex,update) [clock seconds]
	set mani(glimpseindex,form) $index
	set mani(glimpseindex,cnt) [llength $indexglimpse]
}


set mani(glimpsefreq,update) 0
proc manGlimpseFreqShow {} {
	global man manx mani curwin

	set gi [file join $man(glimpsestrays) ".glimpse_index"]
	set gp [file join $man(glimpsestrays) ".glimpse_partitions"]
	if {$man(indexglimpse) ne "unified" || ![file readable $gi] || ![file readable $gp] || $mani(glimpseindex,update)>[file mtime $gi]} return

	set mani(glimpsefreq,form) 0
	set fid [open $gi]
	while {![eof $fid]} {
		# assume -b or -o (otherwise file offsets stored in _index)
		if {![regexp "(\[^\002]+)\002(....)" [gets $fid] all name bo]} continue
		binary scan $bo I offset
puts "$name $offset"
	}
	close $fid
	return
	regsub -all "\002\[^\n\]+" $indexglimpse "" indexglimpse; # offset into partitions -- also \002.... notrail -- 
	regsub -all "\[\001-\011\013-\037\]+" $indexglimpse "" indexglimpse; # noctrl
	# need while [regsub ...] or skip every word following a match
	while {[regsub -all "\n\[_-\]+\n" $indexglimpse "\n" indexglimpse]} {}; # nobox
	while {[regsub -all "\n\[^\n\]\[^\n\]?\[^\n\]?\n" $indexglimpse "\n" indexglimpse]} {}; # misses some?  -- no123
	while {[regsub -all "\n\[^_a-z\]\[^\n\]*\n" $indexglimpse "\n" indexglimpse]} {}; # no noise

	set index {}; set sub {}; set och2 "__"
	foreach i [lsort $indexglimpse] {
		set ch2 [string range $i 0 1]
		if {$ch2 ne $och2} {lappend index [join $sub "\t"] manref "\n\n" {}; set sub {}; set och2 $ch2}
		lappend sub $i
	}
	if {$sub ne ""} {lappend index [join $sub "\t"] manref}

	set mani(glimpseindex,update) [clock seconds]
	set mani(glimpseindex,form) $index
	set mani(glimpseindex,cnt) [llength $indexglimpse]
}


proc manGlimpseIndex {{w .man}} {
	global man manx mani stat texi

	# may have changed glimpse strays dir since startup
	set var "manx($man(glimpsestrays),latest)"
	if {![info exists $var]} {set $var 0}

	# index over all paths, whether currently on or not
	set texinfodir $man(texinfodir)
	if {$texinfodir ne "" && [file writable $texinfodir]} {set texindexdir [file join $texinfodir glimpse]} else {set texinfodir ""}
#puts "cd $texindexdir"

	set rfcdir $man(rfcdir)
	if {$rfcdir eq "" || ![file readable $rfcdir]} {set rfcdir ""}

	# pairs of (dest-dir-of-index list-of-dirs-to-index)
	if {$man(indexglimpse) eq "distributed"} {
		set dirpairs {}
		if {[llength $mani($man(glimpsestrays),dirs)]} {
			lappend dirpairs [list $man(glimpsestrays) $mani($man(glimpsestrays),dirs)]
		}
		foreach dir $manx(paths) {
			lappend dirpairs [list $dir $mani($dir,dirs)]
		}
		if {$texinfodir ne ""} {lappend dirpairs [list $texindexdir $texindexdir]}
		if {$rfcdir ne "" && [file writable $rfcdir]} {lappend dirpairs [list $rfcdir $rfcdir]}
		foreach dir $man(indexalso) { if {[file writable $dir]} {lappend dirpairs [$dir $dir]} }
	} else {
		set dirs $mani($man(glimpsestrays),dirs)
		foreach dir $manx(paths) {
			set dirs [concat $dirs $mani($dir,dirs)]
		}
		if {$texinfodir ne ""} {lappend dirs $texindexdir}
		if {$rfcdir ne ""} {lappend dirs $rfcdir}
		foreach dir $man(indexalso) { if {[file readable $dir]} {lappend dirs $dir} }
		set dirpairs [list [list $man(glimpsestrays) $dirs]]
	}

	# Texinfo files
	if {$texinfodir ne ""} {
#		if ![info exists texi(texinfo,paths)] { -- always compute as may have changed
#			set texi(texinfo,paths) {}
			texiDatabase $man(texinfodir)
#		}

		# so many links unaesthetic, would prefer to add directories to -H, but that would pick up too mcuh extraneous junk(?) (in man page directories, just have man pages).  could postprocess .glimpse_filenames and rebuild .glimpse_filename_index with glimpseindex switch and make texindexdir temporary
		catch {file mkdir $texindexdir}
		cd $texindexdir
		catch { eval file delete [glob *] }; # clean up everybody in case deleted some from dir.tkman...
		# ... and create new links
		set texlns {}; set manx($texindexdir,latest) [file mtime [file join $texinfodir "dir.tkman"]]
		foreach tex $texi(texinfo,paths) {
			set texdir [file dirname $tex]
			if {![file readable $texdir]} continue
			set texlist [glob [file join $texdir "*.texi*"]]
			set cnt [llength $texlist]
			foreach texexcept {version gpl} {if {[lsearch -glob $texlist */$texexcept.texi*]!=-1} {incr cnt -1}}
#puts "$texlist => $cnt"
			if {$cnt==1} {set makeme $tex; set nameme [file tail $tex]} else {set makeme $texdir; set nameme [file tail $texdir].dir}; # XXX.dir so included in *.*
			set ln [file tail $makeme];	# file w/ or w/o .gz (keep .gz so .glimpse_filters works), or directory
#puts "ln -s $makeme $nameme"
			if {[lsearch $texlns $ln]==-1} {
				exec ln -s $makeme $nameme; lappend texlns $ln
				set manx($texindexdir,latest) [max $manx($texindexdir,latest) [file mtime [file join $texinfodir "dir.tkman"]]]
				if {$man(indexglimpse) eq "unified"} {set $var [max [set $var] $manx($texindexdir,latest)]}
			}
		}
	}
#puts $dirpairs; exit 0


	set buildsec [expr {[lfirst [time {manGlimpseIndex2 $dirpairs $w}]]/1000000}]

	if {$buildsec<[expr 60*60]} {set buildfmt "%M:%S"} else {set buildfmt "%T"}
	if {$buildsec>30 || $man(time-lastglimpse)==-1} {
		set man(time-lastglimpse) [clock format $buildsec -format $buildfmt]
	}
	incr stat(glimpse-builds)

	.occ.db entryconfigure "*Glimpse*" -label "Glimpse Index (last $man(time-lastglimpse))"

	# now update Glimpse warnings -- done at every Help
	#manManpathCheck
}


proc manGlimpseIndex2 {dirpairs {w .man}} {
	global man manx mani env

	manNewMode $w glimpse
	set t $w.show; set wi $w.info

	manWinstdout $w "Rebuilding Glimpse database ... "
	set mani(glimpse,shortvolname) "Glimpse"
	manShowSection $w glimpse
	.vols entryconfigure "*glimpse*" -state normal

	manTextOpen $w; update idletasks
	set cnt [llength $dirpairs]; set cur 1
	set foneup 0

	foreach pair $dirpairs {
		foreach {dir dirs} $pair break
		$t insert end "Working on $dir" b " ($cur of $cnt), "
		set dircnt [llength $dirs]; set dirtxt [expr {$dircnt==1?"directory":"directories"}]
		$t insert end "$dircnt $dirtxt"
		$t insert end "\n\n"
		$t see end; update idletasks

		if {!$dircnt} {
			$t insert end "Nothing to index.\n"
			incr cur; $t insert end "\n\n"
			continue
		}

		set gzt ".glimpse_filters"
		set gf [file join $dir ".glimpse_filenames"]
		set gz [file join $dir $gzt]
		set gfe [expr {[llength [glob -nocomplain [file join $dir ".glimpse_{filenames,index}"]]]==2}]


		# see if index is out of date
		set outofdate [expr {!$gfe || [file size $gf]==0 || ([file exists $gz] && [file mtime $gz]>[file mtime $gf]) || [file mtime $gf]<$manx($dir,latest)}]

		if {!$outofdate} {
			$t insert end "Glimpse index still current.\n" indent

			set foneup 1
			# could use perl-style continue expression here
			incr cur; $t insert end "\n\n"
			continue
		}


		# directory writable?
		if {![file writable $dir]} {
			$t insert end "Glimpse index out of date but directory not writable" indent
			if {$gfe} {
				$t insert end " ... but old Glimpse files found\n" indent
				$t insert end "Full text seaching available here using existing files.\n" indent
			} else {
				$t insert end " ... and Glimpse files not found\n" indent
				$t insert end "No full text searching available here.\n" {indent bi}
			}

			incr cur; $t insert end "\n\n"
			continue
		}


		# create .glimpse_exclude to ignore RCS, RCSdiff
		set gex [file join $dir ".glimpse_exclude"]
		if {![file exists $gex]} {
			set fid [open $gex "w"]
			puts $fid [join {.glimpse_exclude$ ~$ .bak$ /RCS$ /RCSdiff .info .c$ .cc$ .h$ .tex$ .dvi$ .ps$} "\n"]
			# not /RCSdiff$ => have RCSdiff@90, e.g., nowadays
			close $fid
		}
		# "If a file is in both .glimpse_exclude and .glimpse_include it will be excluded"
		# "Symbolic links are followed by glimpseindex only if they are specifically included here"
		set gin [file join $dir ".glimpse_include"]
		if {![file exists $gin]} {
			set fid [open $gin "w"]
			puts $fid "*.*"; # one or more dots in name.  same test for valid page names as elsewhere -- handles .texi too! -- too liberal in accepting dots in directories and .glimpse_filters suffixes, though, as that can count for the dot, but seems to work well enough in practice
			close $fid
		}


		# see if .glimpse_filters file needed, and if so make one
		# (but don't overwrite any existing .glimpse_filters)
		if {![file exists $gz]} {
			set fcat [expr {[lsearch -regexp $dirs {/cat[^/]*$}]!=-1}]
#|/catman/
			set fhp [expr {[lsearch -regexp $dirs {\.Z$}]!=-1}]
			set fz 0
			foreach d $dirs {
				# cd into directory so get the short file names (important for /usr/man!)
				cd $d
				if {[lsearch -regexp [glob -nocomplain *] $manx(zregexp)]!=-1} {set fz 1; break}
			}

#			$t insert end "* * * create $gzt file here: fcat=$fcat, fhp=$fhp, fz=$fz\n"
			set fid [open $gz "w"]
			# # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
			# create file according to man(compress) and manx(zglob)  #
			# # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
			if {$fhp} {puts $fid "*.Z/*\tzcat <"}
			if {$fz} {
				set zcat [file tail [lfirst $man(zcat)]]
#				switch -glob -- $zcat {
#					gz* {puts $fid "*.z\t$man(zcat)\n*.Z\t$man(zcat)\n*.gz\t$man(zcat)"}
# would like to do this
#					gz* {puts $fid "*.{z,Z,gz}\t$man(zcat)"}
#					bzip2 {puts $fid "*.bz2\tbzip2"}
#					default {
#						# works for zcat, pcat and (one hopes) anything else to come
#						# (string trimright because of HP "zcat < ")
#						puts $fid "*.$manx(zglob)\t[string trimright $man(zcat) { <}]"
#					}
#				}
				foreach z $man(zlist) {puts $fid "*.$z\t$man(zcat)"}
			}
			# strip AFTER decompression
			if {$fcat} {puts $fid "*/cat*/*\trman <"}
			close $fid
		}


		### try to index or re-index directory
		if {[catch {set fid [open "|$man(glimpseindex) -z -H $dir $dirs"]} info]} {
			# other problems ... like what?
DEBUG {puts "error on: $man(glimpseindex) -z -H $dir $dirs]: $info"}
			$t insert end "$info\n" bi
			catch {close $fid}; # fid not set?
		} else {
DEBUG {puts "$man(glimpseindex) -z -H $dir $dirs"}
			# could think about reporting $dir and $dirs in text buffer
			fconfigure $fid -buffering line; # doesn't seem to make any difference on a pipe(?)
			set blankok 0
			while {![eof $fid]} {
				gets $fid line
				if {![regexp {(^This is)} $line] && ($line ne "" || $blankok)} {
					$t insert end "$line\n" tt; $t see end; update idletasks
					set blankok 1
				}
				update idletasks
			}
			if {[catch {close $fid} info]} { $t insert end "ERRORS\n" {indent bi} $info indent2 "\n" }

			if {[file size $gf]==0} {
				$t insert end "No files could be indexed.  No full text searching available here.\n" {indent bi}
				if {[file exists $gz]} {
					$t insert end "Try checking your $gzt file in $dir.  If $gzt wasn't created by TkMan, try deleting it and letting TkMan create one of its own.\n" indent
				}
			} else {
				# give glimpse files same permissions as directory
				catch {
					file stat $dir dirstat
					set perm [format "0%o" [expr {$dirstat(mode)&0666}]]
					foreach setperm [glob [file join $dir ".glimpse_*"]] {file attributes $setperm -permissions $perm}
				}
			}
		}

		incr cur
		$t insert end "\n\n"
	}

	if {$foneup} {
		$t insert end "\nTo force re-indexing of directories that TkMan claims are current, remove all Glimpse index files in that directory, as with `rm <dir> .glimpse_*'.\n" i
	}

	$t see end
	manTextClose $w

	set mani(glimpse,form) [list [$t get 1.0 end]]

	manWinstdout $w ""
}

proc manGlimpseClear {} {
	global man manx
	foreach dir [concat $manx(paths) $man(fsstnddir)] {
		# zaps .glimpse_filters, which may have been carefully constructed manually
		catch {eval file delete -force [glob [file join $dir ".glimpse_*"]]}
	}
}
