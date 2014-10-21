#--------------------------------------------------
#
# Highlights
#
#--------------------------------------------------

# get old highlights and yview, if any

# highlighting commands: update (menu), get (all from database)

proc manHighlightsSetCmd {{incmd add}} {
	global manx curwin bmb
	set w $curwin; # or, upvar #0 curwin w
	set wh $w.high
	set txt "Hi"; if {$incmd eq "add"} {set txt "+"} elseif {$incmd eq "remove"} {set txt "-"}
	set cmd "add"; if {$incmd eq "remove"} {set cmd "remove"}
	$wh configure -text $txt; set bmb($wh) "manHighlights $w $cmd"
}

proc manHighlights {w {cmd update} {auto 0}} {
	global high man manx mani stat

	set t $w.show
	set status ""
	set res ""
	set rele {([\d.]+)/(\d+)\.(\d+)}

	# get/save tags
	set f $manx(manfull$w)
#	if [string match <* $f] {set f [string range $f 1 end]}
	# canonical file name
	if {![catch {set sf [file readlink $f]}]} {
		if {[string match /* $sf]} {
			set f $sf
		} else {
			set f [file dirname $f]
			set strip 1
			while {$strip} {
				switch -glob $f {
					../* {set f [file dirname $f]; set sf [string range $sf 3 end]}
					./* {set sf [string range $sf 2 end]}
					default {set strip 0}
				}
			}
			append f /$sf
		}
	}
	set normalf [zapZ [bolg $f ~]]

	set var high($normalf)

	# try to recover if page moved
	if {$normalf ne "" && ![info exists $var]} {
		set movelist {}
		set tail [file tail $normalf]
		foreach hi [array names high] {
			if {$tail eq [file tail $hi]} {lappend movelist $hi}
		}
		foreach hi $movelist {
			if {[lsearch $manx(highdontask) $hi]!=-1} continue
			if {[catch {glob $hi$manx(zglob)}]} {
				if {[tk_messageBox -title "Moved Highlight?" -message "It appears that the highlighted page formerly at\n   $hi\nhas moved to\n   $normalf\nMove highlights too?" -icon question -type okcancel] eq "ok"} {
					set $var $high($hi); unset high($hi)
					incr stat(high-carry)
				} else {lappend manx(highdontask) $hi}
				break
			}
		}
	}


	if {[regexp "add|remove" $cmd]} {
		if {![llength [$t tag nextrange sel 1.0]]} {
			set errmsg "Select a range of "
			if {$cmd eq "add"} {append errmsg "characters to highlight"} else {append errmsg "highlighted characters to unhighlight"}

			manWinstderr $w $errmsg
			return
		}
		$t tag $cmd highlight sel.first sel.last
		if {$cmd eq "add"} {incr stat(page-highlight-add)} else {incr stat(page-highlight-sub)}
		set mani(high,form) {}
		selection clear $t
		set cmd "update"
	}
# define highlights in presence of diffd a nonproblem:
#    not going to be switching between seeing and not seeing all the time,
#    and in the absence of switching, *want* default behavior!
#    when do switch or update page (an infrequent happening), natural robustness carries the day
# elseif {$cmd eq "save"} {
#		foreach {s e} [lreverse [$t tag ranges diffd] 2] {$t delete $s $e}
#		set cmd "update"
#	}


	set tags ""
	if {$cmd eq "update"} {
		# new style annotations store date (latest) annotation made
		set tags [clock seconds]
		# save some context with tag in hopes of reattaching if the man page changes 
		# (or just reinstalled)
		foreach {first last} [$t tag ranges highlight] {
			eval lappend tags [manHighCompose $t $first $last]
		}

		# clear volume list because updated time of last highlight
		set mani(high,form) {}
		DEBUG {puts "updating highlights to $tags"}
		if {[llength $tags]>1} {set $var $tags} else {catch {unset $var}}
		set status "updated"

	} elseif {[info exists $var]} {
		set tags [set $var]

		if {[llength [lsecond $tags]]>1} {
			set losertxt ""; set dicey 0
			set res "new style"

			# new style highlights -- reattach given initial position and context; date irrelevant
			set newtags [lfirst $tags]; # retain creation date
			foreach {ftuple ltuple} [lrange $tags 1 end] {
				# abuse foreach.  more clear if had "set <var-list> <val-list>"
				foreach {first firsttxt predelta fhooklen} $ftuple break
				foreach {ldelta lasttxt postdelta lhooklen} $ltuple break

				# starting position can be relative to section (end is relative to start already)
				if {[regexp $rele $first all basenum relline charoff secttitle]} {
#puts "*** decoding baserel $first = js$basenum + $relline l + $charoff c"
# should have section name as well, but fix this in Multivalent
					set basesect "js$basenum"
					if {[lsearch $manx(sectposns$w) $basesect]!=-1} {
						set first [$t index "$basesect linestart+${relline}l+${charoff}c"]
						if {$manx(mode$w) eq "texi"} {texiFault $t $basesect}
					}
				}

				set new [manHighlightAttach $t  $first $firsttxt $predelta $fhooklen   $ldelta $lasttxt $postdelta $lhooklen]
				foreach {status firstnew ldeltanew} $new break
				if {$status eq "LOSE"} {
					incr stat(high-lose)
					append losertxt "[string range $firsttxt 0 [expr {$predelta-1}]] / [string range $firsttxt $predelta end] ($first)   ...   [string range $lasttxt 0 [expr {[string length $lasttxt]-$postdelta}]] / [string range $lasttxt [expr {[string length $lasttxt]-$postdelta+1}] end] (+$ldelta)\n"
					append res ", lost one"
				} elseif {$firstnew!=$first || $ldeltanew!=$ldelta} {
					# had to move one, save repositioned information
					incr stat(high-move)
					eval lappend newtags [manHighCompose $t $firstnew "$firstnew+${ldeltanew}c"]
					# dicey move
					if {$status eq "DICEY"} { set dicey 1; append res ", dicey move" }
				} else {
					incr stat(high-exact)
					# old info is still good
					lappend newtags $ftuple $ltuple
					append res ", exact"
				}
			}

			set warningtxt ""

			# report losers at bottom
			if {$losertxt ne ""} {
				manTextPlug $t end "\n\n\nCouldn't attach these highlights:\n" b $losertxt {} "\n"
				append warningtxt "Some highlights could not be repositioned.  See the bottom of the page for a list.  They will be forgotten unless they are reapplied manually now.   "
			}
			if {$dicey} {
				append warningtxt "Some highlights have moved considerably and may not have been repositioned correctly.  You may want to verify them now.   "
			}
			if {$warningtxt ne "" && !$auto} {
				tk_messageBox -title "Warning" -message $warningtxt -icon warning -type ok
			}

			# update persistent info
			set $var $newtags
			set tags $newtags

		} else {
			# old style highlights -- up to date or die
			set res "old style"
			if {![file isfile $f] || [file mtime $f]<=[lfirst [set $var]]} {
				# man page hasn't been changed (according to mtime) -- assume everything OK
				append res ", OK"
			} else {
				# old style highlights lose
				if {!$auto && [tk_messageBox -title "Warning" -message "Highlights out of date for $f.  Delete them?" -icon question -type yesno] eq "no"} {
					set $var [set tags "[file mtime $f] [lrange [set $var] 1 end]"]
				}
				append res ", out of date"
			}

			# lazily convert from old style to new
			# use after because have to draw highlights below before making new style ones
			after 1 manHighlights $w update
		}
	}
#puts stdout "v = $var, f = $f"


	### always redraw highlights (good check)
	foreach tag {halwaysvis highlight highlight-meta} {$t tag remove $tag 1.0 end}

	# show likely relevant information

	# update highlighting in text, menu
	set m [set mb $w.high].m
	$m delete 0 last

	foreach {first last} [lrange $tags 1 end] {
		if {[llength $first]>1} {
			set first [lfirst $first]
			if {[regexp $rele $first all basenum relline charoff secttitle]} {set first [$t index "js$basenum linestart+${relline}l+${charoff}c"]}
			set last "$first+[lfirst $last]c"
		}
		$t tag add highlight $first $last

		# show likely relevant information
		if {$manx(tryoutline$w) && $man(highlight-show) ne "never"} {nb $t $man(highlight-show) $first $last}

		if {$auto} { $t yview -pickplace $last; update idletasks; after 1000 }
		set label \
			[string range [manHighNormalize [$t get $first $last]] 0 $man(high,hcontext)]
		$m add command -label $label \
			-command "incr stat(page-highlight-go); manOutlineYview $t $first; $t yview scroll \[expr 5-\$man(high,vcontext)] units"
	}
	manShowTagDist $w highlight 3

	# propagate highlight information to section headers, if highlights not always visible
	if {$manx(tryoutline$w) && $man(highlight-show) ne "halwaysvis"} {
#($manx(subsect-show) => always for man, never for Texinfo
		foreach now $manx(sectposns$w) next $manx(nextposns$w) {
			if {[$t tag nextrange highlight $now $next-1l]!=""} {
				for {set sup "$now.0"} {[regexp $manx(supregexp) $sup all supnum]} {set sup "js$supnum"} {
					foreach {ts te} [$t tag nextrange outline "js$supnum linestart"] break; append ts "+1c"
					# supersections may not exist
					catch {$t tag add highlight-meta $ts $te}
				}
			}
		}
	}


##	configurestate [list $mb $w.hsub] "[llength $tags]>1"
	if {[llength $tags]>1} {catch {eval $mb configure $man(highlight)}} else {$w.high configure -foreground $man(buttfg) -background $man(buttbg) -font gui}
	manHighlightsSetCmd "Hi"
	manMenuFit $m

	return $res
}



# compose highlight data record from region of text
# want excerpt of text 
# and hook of reasonable length to search for (so may need to augment excerpt on that line)
# record format :== first-tag last-tag
# first-tag :== index excerpt pre-augment-length hook-length
# last-tag :== unnormalize-highlight-length excerpt post-augment-length hook-length
# when/if search across lines, hook-length worthless

proc manHighCompose {t first last} {
	global manx

	set excerptmax 30; set hookmax 20

	scan [$t index $first] "%d.%d" fline fchar
	scan [$t index $last] "%d.%d" lline lchar
	set rlen [string length [$t get $first $last]]
	set elen [min $excerptmax $rlen]
DEBUG {puts "EXCERPTING first=$first, last=$last, rlen=$rlen, elen=$elen"}

	# compute start 
	set fsi "$first linestart"
#	scan [$t index [set fsi "$first linestart"]] "%d.%d" junk fstartchar
	scan [$t index [set fei "$first lineend"]] "%d.%d" junk fendchar
	set exhooklen [min $elen [expr {$fendchar-$fchar+1}]]
DEBUG {puts "first\tfstartchar=0, fendchar=$fendchar, exhooklen = $exhooklen"}
	if {$exhooklen>=$hookmax} {
		# excerpted characters form substantial enough hook
		set hooklen [string length [manHighNormalize [$t get $first $first+${exhooklen}c]]]
		set prelen 0
		set excerpttxt [manHighNormalize [$t get $first $first+${elen}c]]
	} else {
		# augment excerpt if possible, at start only (for now?)
#puts "augmented"
		# when/if search across lines, don't be limited by start of line, end of line
		set prei "$first-[expr {$hookmax-$exhooklen}]c"; if {[$t compare $prei < $fsi]} {set prei $fsi}
		set excerpttxt [manHighNormalize [$t get $prei $first+${elen}c]]
		set posti "$first+${elen}c"; if {[$t compare $posti > $fei]} {set posti $fei}
		set hooklen [string length [manHighNormalize [$t get $prei $posti]]]
		set prelen [expr {$hooklen-[string length [manHighNormalize [$t get $first $posti]]]}]
	}
DEBUG {puts "|$excerpttxt|, $prelen, $hooklen"}

	set firsttag [list [manPosn2OutnOff $t $first] $excerpttxt $prelen $hooklen]

	# in updating from old to new style, sometimes can get empty line
	if {!$hooklen} { return "" }


	# compute end
	scan [$t index [set esi "$last linestart"]] "%d.%d" junk lstartchar
	scan [$t index [set eei "$last lineend"]] "%d.%d" junk lendchar
	set exhooklen [min $elen [expr {$lchar-$lstartchar+1}]]
DEBUG {puts "end\tlstartchar=$lstartchar, lendchar=$lendchar, exhooklen = $exhooklen"}
	if {$exhooklen>=$hookmax} {
		# excerpt characters form substantial enough hook
		set hooklen [string length [manHighNormalize [$t get $last-${exhooklen}c $last]]]
		set postlen 0
		set excerpttxt [manHighNormalize [$t get $last-${elen}c $last]]
	} else {
		# augment excerpt if possible
#puts "augmented"
		# when/if search across lines, don't be limited by start of line, end of line
		set posti "$last+[expr {$hookmax-$exhooklen}]c"; if {[$t compare $posti > $eei]} {set posti $eei}
		set excerpttxt [manHighNormalize [$t get $last-${elen}c $posti]]
		set prei "$last-${elen}c"; if {[$t compare $prei < $esi]} {set prei $esi}
		set hooklen [string length [manHighNormalize [$t get $prei $posti]]]
		set postlen [expr {$hooklen-[string length [manHighNormalize [$t get $prei $last]]]}]
	}
	set lasttag [list $rlen $excerpttxt $postlen $hooklen]
DEBUG {puts "|$excerpttxt|, $hooklen, $postlen"}

	return [list $firsttag $lasttag]
}


# hyphens ignored, any whitespace matches any whitespace (space matches tab, e.g.)
# essential for searching across reformats, but also good for storing in ~/.tkman

proc manHighNormalize {raw {maxlen 0}} {
	set new [string trim $raw]

	# zap changebars
	regsub "\\|+\n" $new "\n" new
	#regsub -all "\n\\|" $new "\n" new
	regsub {^\|+\s} $new "\n" new

	# linebreaks (hyphens and whitespace) ignored and word spacing ignored
	regsub -all -- "-\n" $new "\n" new
	regsub -all {\s+} $new " " new

	if {$maxlen} { set new [string range $new 0 $maxlen] }

	return $new
}

proc manHighRegexp {normal} {
	set regexp [stringregexpesc $normal]
	# ok to match change bar and hyphen too
	regsub -all {\s+} $regexp {[\s|-]*} regexp
	return $regexp
}


# try to reattach new style highlights
proc manHighlightAttach {t first firsttxt predelta fhooklen  ldelta lasttxt postdelta lhooklen   {status "GOOD"}} {
	global manx curwin
	DEBUG {puts "ATTACH: $first $firsttxt $predelta $fhooklen   $ldelta $lasttxt $postdelta $lhooklen  $status"}

	if {!$fhooklen} { set fhooktxt $firsttxt } else {
		set len [string length $firsttxt]
		set fhooktxt [string range $firsttxt 0 [expr {$fhooklen-1}]]
		set fextxt [string range $firsttxt $predelta end]
		set fpretxt [string range $firsttxt 0 [expr {$predelta-1}]]
#puts "fhooktxt=|$fhooktxt|, fextxt=|$fextxt|, fpretxt=|$fpretxt|"
	}
	if {!$lhooklen} { set lhooktxt $lasttxt } else {
		set len [string length $lasttxt]
		set lhooktxt [string range $lasttxt [expr {$len-$lhooklen}] end]
		set lextxt [string range $lasttxt 0 [expr {$len-$postdelta-1}]]
		set lhookextxt [string range $lhooktxt 0 [expr {[string length $lhooktxt]-$postdelta-1}]]
		set lposttxt [string range $lasttxt [expr {$len-$postdelta}] end]
#puts "lhooktxt=|$lhooktxt| / |$lhookextxt|, lextxt=|$lextxt|, lposttxt=|$lposttxt|"
	}

	DEBUG {puts "first = $first, |$fhooktxt|\nlast = +$ldelta, |$lhooktxt|"}


	### attach start of range

	if {[$t compare $first >= end]} { set first [$t index end-1l] }
	set flen [string length $fhooktxt]
	set fpt ""

	# first check for exact match for first part
	set found 0
	set fregexp [manHighRegexp $fhooktxt]
#puts "searching forward for $fregexp"
	set viz [expr {$manx(tryoutline$curwin)?"-elide":"--"}]
	# Tk doesn't search across lines!
	set ffw [$t search -forwards -regexp $viz $fregexp $first end]
	set fbk [$t search -backwards -regexp $viz $fregexp $first 1.0]
	if {$ffw eq "" && $fbk eq ""} {
		# nothing yet
	} elseif {$ffw eq ""} {
		set fpt $fbk
		set found 1
		DEBUG {puts "only found backward from $first at $fbk"}
	} elseif {$fbk eq ""} {
		set fpt $ffw
		set found 1
		DEBUG {puts "only found foward from $first at $ffw"}
	} else {
		# matches forward and backward.  pick closer one
		scan $first "%d.%d" line char
		scan $ffw "%d.%d" fline fchar; set difffw [expr {$fline-$line}]; set dcfw [expr {abs($fchar-$char)}]
		scan $fbk "%d.%d" bline bchar; set diffbk [expr {$line-$bline}]; set dcbk [expr {abs($char-$bchar)}]
		if {$diffbk<$difffw} {set fpt $fbk} elseif {$difffw<$diffbk} {set fpt $ffw} else {
			# tie, go to characters
			if {$dcbk<$dcfw} {set fpt $fbk} else {set fpt $ffw}
		}
		set found 1
		DEBUG {puts "found point $first forward ($ffw) and back ($fbk), closer is $fpt"}
	}
	scan $fpt "%d.%d" fline fchar


	# adjustments to search: disqualifications and tweaks
	if {$found} {
		if {$fhooklen} {
			# searching by hooks: verify match on excerpt
			# and get real start of highlight (controlling for spaces)

			# bump over hook context
			# this had better match!
			set must [$t search -forwards -regexp -count delta $viz [manHighRegexp $fpretxt] $fpt end]
			set fpt [$t index "$fpt+${delta}c"]

			set txt [$t get $fpt "$fpt+1000c"]
			if {![regexp -indices -- [manHighRegexp $fextxt] $txt all]} { set found 0 }

		} elseif {$flen>=20} {
			# searching by long excerpt
			# if match far away, axe it, in favor of possible closer if shorter match
			if {[expr {abs($line-$fline)>200}]} { set found 0 }
		}
	}

	if {!$found} {
		# back off strategies:
		# if searching by hooks, dump hooks for excerpt text
		if {$fhooklen} {
			return [manHighlightAttach $t $first $fextxt 0 0  $ldelta $lasttxt $postdelta $lhooklen  $status]

		# if searching by long excerpt text, chop it and try again
		} elseif {$flen>10} {
			set chop [max 9 [expr {int($flen/2)}]]
			return [manHighlightAttach $t $first [string range $fhooktxt 0 $chop] 0 0  $ldelta $lasttxt $postdelta $lhooklen "DICEY"]
		} else {
			return "LOSE"
		}
	}


	### attach end of range

	# now search forward from first match to find end
	# at approximately the same number of characters forward as old one
	set found 0
	set llen [string length $lhooktxt]
	set last "$fpt+${ldelta}c-${llen}c"
	set lregexp [manHighRegexp $lhooktxt]
#puts "searching backward for $lregexp"
	set lfw [$t search -forwards -regexp -count lfwcnt $viz $lregexp $last end]
	set lbk [$t search -backwards -regexp -count lbkcnt $viz $lregexp $last $fpt]
	if {$lfw eq "" && $lbk eq ""} {
	} elseif {$lfw eq ""} {
		set lpt $lbk
		set llen $lbkcnt
		set found 1
		DEBUG {puts "end only found backward from $fpt at $lbk"}
	} elseif {$lbk eq ""} {
		set lpt $lfw
		set llen $lfwcnt
		set found 1
		DEBUG {puts "end only found foward from $fpt at $lfw"}
	} else {
		# match forward and backward.  pick closer one -- need to adjust for length of match
		scan $fpt "%d.%d" line char
		scan $lfw "%d.%d" fline fchar; set difffw [expr {$fline-$line}]; set dcfw [expr {abs($fchar-$char)}]
		scan $lbk "%d.%d" bline bchar; set diffbk [expr {$line-$bline}]; set dcbk [expr {abs($char-$bchar)}]
		if {$diffbk<$difffw} {set lpt $lbk; set llen $lbkcnt} elseif {$difffw<$diffbk} {set lpt $lfw; set llen $lfwcnt} else {
			# tie, go to characters
			if {$dcbk<$dcfw} {set lpt $lbk; set llen $lbkcnt} else {set lpt $lfw; set llen $lfwcnt}
		}
		set found 1
		DEBUG {puts "found end point $fpt forward ($lfw) and back ($lbk), closer is $lpt"}
	}
	

	if {$found} {
		if {$lhooklen} {
			# should make this check when do $t search ...
			# match only as far as excerpt (not hook) -- chop off trailing context
			set rx [manHighRegexp $lhookextxt]
			# this had better match!
			set posti [$t search -count llen -regexp $viz $rx $lpt end]
			DEBUG {puts "$t search -count llen -regexp $viz $rx $lpt end"}
			# off by one error in searching backwards
#			DEBUG {puts "backward must = $must, delta=$delta, llen=$llen"}
#			set llen [string length [$t get $fpt "$lpt+${len}c"]]
#			incr llen -$delta


			set rx [manHighRegexp $lextxt]; append rx "\$"
			set txt [$t get "$lpt-1000c" "$lpt+${llen}c"]
#puts "backward regexp [regexp $rx $txt]: find |$lextxt| in |[string range $txt [expr [string length $txt]-100] end]|"
			if {![regexp -indices -- $rx $txt all]} {set found 0}
#puts "*** no match to excerpt"; #
		}

		set nldelta [string length [$t get $fpt "$lpt+${llen}c"]]

		if {$llen>=20} {
			# if new end too far down, assume it was searching for common text 
			# and latched onto an unsuspecting host
			if {$nldelta>[expr {10*$ldelta}]} {set found 0}
		}
	}

	if {!$found} {
		if {$lhooklen} {
			return [manHighlightAttach $t $fpt $firsttxt $predelta $fhooklen   $ldelta $lextxt 0 0  $status]

		} elseif {$llen>10} {
			set chop [max 9 [expr {int($llen/2)}]]
			# keep end $chop characters
			set d [expr {$llen-$chop}]; set lhooktxt [string range $lhooktxt $d end]
			return [manHighlightAttach $t $fpt $firsttxt $predelta $fhooklen  $ldelta $lhooktxt 0 0  "DICEY"]

		} else {
			#return "LOSE"
			# if didn't find the end, just assume it's the same distance away that it used to be
			set nldelta $ldelta
			set status DICEY
		}
	}


	# got a match
	return [list $status $fpt $nldelta]
}
