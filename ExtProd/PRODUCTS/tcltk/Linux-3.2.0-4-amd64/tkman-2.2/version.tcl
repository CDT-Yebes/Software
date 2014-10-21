set man(versiondiff) 1; set manx(versiondiff-v) {1 0}; set manx(versiondiff-t) {"yes" "no"}
set manx(edrx) {^(\d+),?(\d*)([adc])(\d+),?(\d*)$}

set manx(vdiff) $man(vdiff)

proc manVersionDiff {f w} {
	global man manx

	if {[string match "*/RCS/*,v" $f]} {
		set rcsf $f
		set dir [file dirname [file dirname $f]]
		set tail [file tail $f]; set tail [string range $tail 0 [expr {[string length $tail]-3}]]
		set f $dir/$tail
	} elseif {[regexp {(.*)/(([^/]+)\.([^\.]+))} $f all dir tail rootname suffix]} {
		set rcsf "$dir/RCS/$tail,v"
	} else return
	if {![file readable $rcsf]} {return ""}

#	if {$manx(effcols) ne ""}  {
		set fid [open $manx(longtmp) "w"]; puts $fid ".ll $man(columns)\n.hym 20"; close $fid
#	}

	set cachedir $dir
	if {[regsub {/man([^/]+)$} $dir {/cat\1} d2]} {set cachedir $d2}
	append cachedir $manx(effcols)
	if {![file writable $cachedir] && ![file writable [file dirname $cachedir]]} {
		if {[regexp {^(/usr)?/(.*)man/man(.*)$} $dir all junk prefix suffix]} {
			set cachedir "$man(fsstnddir)/${prefix}cat$suffix$manx(effcols)"
		}
	}
	append cachedir "/RCSdiff"

	set cachefile "$cachedir/$tail"
	set existingcachefile [lfirst [glob -nocomplain "$cachefile$manx(zoptglob)"]]
	if {[file readable $existingcachefile] && [file mtime $existingcachefile]>[file mtime $f] && [file mtime $existingcachefile]>[file mtime $rcsf] && [file mtime $existingcachefile]>$manx(mtime)} {
		# use cache
		# slightly different than manManPipe
		if {[regexp $manx(zregexp) $existingcachefile]} {set pipe "|$man(zcat) "} else {set pipe ""}
		set fid [open "$pipe$existingcachefile"]; set diffs [read $fid]; close $fid
#puts "using cached"

	} else {
		cursorBusy
		cd $dir
		manWinstdout $w "Computing diffs for $tail $manx(effcols) ..." 1

		### find first version with changes (if any)
		set search 1
		set insym 0
		set fid [open "|$man(rlog) $tail"]
		while {$search && [gets $fid line]!=-1} {
			if {!$insym} {
				# look for "<ws>checkpoint: <rev>"
				if {[regexp "^\[ \t\]+" $line]} {
					if {[regexp "^\[ \t\]+checkpoint: (\[0-9\\.\]+)\$" $line all vnum]} {
						set search 0
					}
					continue

				} else {set insym 0}
				# and fall through
			}
			if {[regexp {^revision ([\d\.]+)$} $line all vnum]} {
#puts "testing $vnum"
				# gotta collect the stderr, ugh
				catch {exec $man(rcsdiff) -r$vnum $tail} info
#puts "checking\n$info"
				foreach line [split $info "\n"] {
					if {[regexp $manx(edrx) $line]} {
#puts "match on $vnum"
						set search 0; break
					}
				}
			}
		}
		catch {close $fid}

#		if !$isdiff {return ""} => even if no diff, cache this knowledge so faster next time


		### collect diffs
		# diff needs at least one of them to be a real file.  want text of previous version around anyhow
		set tmpf /tmp/tkman[pid]
# $man(changeleft) $man(zaphy) -- obsolete options
		set format "$man(format) | $manx(rman) -f ASCII -N"
#puts "creating $tmpf (old)"
#puts "exec $man(co) -p$vnum $tail | $format > $tmpf"
		catch {eval exec $man(co) -p$vnum $tail | $format > $tmpf} info

#puts "creating diffs vs v$vnum"
#puts $manx(vdiff)
# use "|open..." and read line at a time
		catch {set diffs [eval exec [manManPipe $tail] | $format | $manx(vdiff) $tmpf -]} diffs
#puts $diffs
		file delete -force $tmpf
#		if {$manx(effcols) ne ""} {
			file delete -force $manx(longtmp)
#		}

		# just save lines from old RCS file, as already have new lines!
		# this works especially well as documents tend to grow
		set newdiffs {}

		set skip 0; set keep 0
		set lines [split $diffs "\n"]
		for {set linenum 0} {$linenum<[llength $lines]} {incr linenum} {
			set line [lindex $lines $linenum]
			if {$keep} {incr keep -1; append newdiffs [string range $line 2 end] "\n"; continue
			} elseif {$skip} {incr skip -1; continue}
			if {![regexp $manx(edrx) $line all n1 n2 cmd n3 n4]} break
			if {$n2 eq ""} {set n2 $n1}; if {$n4 eq ""} {set n4 $n3}
			set lcntold [expr {$n2-$n1+1}]; set lcntnew [expr {$n4-$n3+1}]
			if {$cmd eq "a"} {
				# already have added lines, throw them all out
				set skip $lcntnew
				append newdiffs "0a$lcntnew@$n3\n"
			} elseif {$cmd eq "c"} {
				# changed: keep old, skip separator and new

				# first verify that changes aren't just formatting changes
				# (not the same as diff's -B as formatting change may span lines)
				set nrx "\[ \t\n|\]+"
				set cold ""; set cnew ""
				set i 0
				for {set i 0} {$i<$lcntold} {incr i} {append cold [string range [lindex $lines [expr {$linenum+1+$i}]] 2 end] "\n"}
				for {set i 0} {$i<$lcntnew} {incr i} {append cnew [string range [lindex $lines [expr {$linenum+1+$lcntold+1+$i}]] 2 end] "\n"}
				regsub -all $nrx [string trim $cold] " " ncold
				regsub -all $nrx [string trim $cnew] " " ncnew

				if {$ncold ne $ncnew} {
#puts "diff: $ncold\n   => $ncnew"
					set keep $lcntold
					set skip [expr {1+$lcntnew}]
					append newdiffs "${lcntold}c$lcntnew@$n3\n"
				} else {
#puts "bogus diff: $ncold"
					incr linenum [expr {$lcntold+1+$lcntnew}]
				}

			} else { # d
				# deleted from old, bring them along
				set keep $lcntold
				append newdiffs "${lcntold}c0@$n3\n"
			}
		}

		set diffs $newdiffs
#puts $f\n$newdiffs
#puts $diffs
#exit 0

		# cache diffs if possible
		set writedir $cachedir
		set mkdirs {}
		while {![file exists $writedir]} {
			lappend mkdirs $writedir
			set writedir [file dirname $writedir]
		}
		if {[file writable $writedir]} {
			foreach mkdir [lreverse $mkdirs] {file mkdir $mkdir}
		}
#puts "$cachedir"


		if {[file writable $cachedir]} {
			if {[file writable $cachedir]} {
				if {$existingcachefile ne ""} {file delete $existingcachefile}
				#manWinstdout $w "Cacheing diffs ..." 1
				set fid [open $cachefile "w"]; puts $fid $diffs; close $fid
				catch {eval file delete [glob $cachefile.$manx(zglob)]}
				eval exec $man(compress) $cachefile
			} else {manTextPlug $w.show 1.0 "Couldn't cache version differences: $cachedir not writable" b}
		}
		cursorUnset
	}

	return $diffs
}


proc manVersionDiffMakeCache {w t} {
	global mani manx man

	manTextOpen $w
	foreach sect $mani(manList) {
		foreach dir $mani($sect,dirs) {
			# dump this information info main window so can report "no RCS", "not writable", et cetera
			$t insert end $dir b "     "
			set rcsdir "$dir/RCS"

			set cachedir $dir
			if {[regsub {/man([^/]+)$} [file dirname $dir] {/cat\1} d2]} {set cachedir $d2}
			append cachedir $manx(effcols)
			if {![file writable $cachedir] && ![file writable [file dirname $cachedir]]} {
				if {[regexp {^(/usr)?/(.*)man/man(.*)$} $dir all junk prefix suffix]} {
					set cachedir "$man(fsstnddir)/${prefix}cat$suffix$manx(effcols)"
				}
			}
			append cachedir "/RCSdiff"
			set writedir $cachedir
			while {![file exists $writedir]} {set writedir [file dirname $writedir]}

			set errmsg ""
			if {![file exists $rcsdir]} {set errmsg "no versioning information (RCS directory)"
			} elseif {![file readable $rcsdir]} {set errmsg "$rcsdir not readable"
			} elseif {![file writable $writedir]} {set errmsg "$cachedir not writable/creatable (need perissions on $writedir)"
			}

			$t insert end "[expr {$errmsg==""?"CACHEING":$errmsg}]\n"
			update idletasks; $t see end
			if {$errmsg ne ""} continue

			foreach rcsfile [lsort -dictionary [glob -nocomplain "$rcsdir/*,v"]] {
				foreach cols $manx(columns-v) {
					set tmp $manx(effcols); set manx(effcols) [expr {$cols==65?"":"@$cols"}]
					manVersionDiff $rcsfile $w
					set manx(effcols) $tmp
				}
			}
		}
	}
	manTextClose $w
}


proc manVersion {w t f} {
	global man manx

	set diffcnt 0
	if {[set diffs [manVersionDiff $f $w]] eq ""} {return $diffcnt}
	set cmdrx {(\d+)([acd])(\d+)@(\d+)}

	### apply diffs
	set cmd XXX
	set deltal 0; set atl 0
	set dell 0
	set tags ""
	# invariant: start with command
#	manOutline $t 0 *
	foreach line [split $diffs "\n"] {

		# if comparing paragraphs, try big chunk regions
		if {$cmd eq "c" && $dell==1 && $dell0==1 && $man(columns)==5000} {
			set dell 0
			set newline [$t get $ts $ts+1l]
			set startpre 0; if {[regexp -indices "^(\\|?\[ \t]+)" $newline indices]} {
				set startpre [expr {1+[lsecond $indices]}]
				set newline [string range $newline $startpre end]
			}
			$t delete "$ts linestart+${startpre}c" "$ts lineend"
			eval $t insert "{$ts linestart+${startpre}c}" [textmanip::wdiff $line $newline]
			foreach tag $tagshere {$t tag add $tag "$ts linestart" "$ts lineend"}
			continue
		}

#		$t yview [expr $atl+$deltal].0-5l; update idletasks; after 1000
#puts "inspecting $line"
		# lines deleted, which we recover (insert) now
		if {$dell} {
#			$t insert $ts "$line" $tags
#			if {$dell ne $dell0} {$t insert "$ts lineend" "\n" $tags; incr deltal} else {incr atl}
			$t insert $ts "|$line\n" $tags; incr deltal
			set ts "[expr {$atl+$deltal}].0"
			incr dell -1
			continue
		}

#puts "cmd?  $line"
DEBUG {		if {![regexp $cmdrx $line all dell cmd insl atl]} {puts "NO MATCH on\t$line"}}
		if {![regexp $cmdrx $line all dell cmd insl atl]} break
		set dell0 $dell
		incr diffcnt
DEBUG {puts "applying $dell *$cmd* $insl @ $atl"}
		set ts "[expr {$atl+$deltal}].0"

		if {[regexp "a|c" $cmd]} {
			# add tag to existing text
#			if {!$insl} {set te $ts} else {set te "[expr $atl+$deltal+$insl].0"}
			set te "[expr {$atl+$deltal+$insl}].0"
			$t tag add diff$cmd $ts $te
			for {set ci 0} {$ci<$insl} {incr ci} {
				set cbi "[expr {$atl+$deltal+$ci}].0"
				if {[$t get $cbi] eq ""} {append cbi "+1c"}; # skip over outline image
				if {[$t get $cbi] ne "|"} {$t insert $cbi "|"}
			}
#puts "$t tag add diff$cmd $ts $te"
		}
		if {[regexp "c|d" $cmd]} {
			# insert old stuff, bump delta
			# keep initial "<" as marker in left margin and as something for zapped newlines
			set tagshere [$t tag names $ts]
			set tags [concat [lmatches areajs* $tagshere] [lmatches elide $tagshere] diffd]
		}
	}

	return $diffcnt
}

# zap everything in RCSdiff directories
proc manVersionClear {} {
	global man manx

	# doesn't respects settings in Paths
	foreach dir $manx(paths) {
		# if catman, may be only copy of page (SGI only has formatted)
		if {[string match "*/catman*" $dir]} continue

		# don't complain if can't write
		catch {eval file delete -force [glob $dir/cat*/RCSdiff/*]}
		catch {eval file delete -force [glob $dir/cat*/RCSdiff]}
	}
	# what about $man(fsstnddir)?
}
