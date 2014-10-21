#
# text manipulation functions
#
# Tom Phelps (phelps@ACM.org)
#
# Contents:
#	word frequency (with stop words)
#	word-grain diff's
#	plural
#	mon2Month
#	linebreaking
#	recently
#
# To do: XXX
# Possible additions: XXX
#
# 1998
# 26 Apr	pasted together


namespace eval textmanip {

# pass in # and `s' or `es'
proc plural {cnt word {s ""}} {
	if {$cnt!=1 && $cnt!=-1} {
		if {$s eq ""} { if {[string equal -nocase [string index $word end] "s"]} {set s "es"} else {set s "s"}}
		append word $s
	}
	return $word
}


proc mon2Month {m} {
	set mons {jan feb mar apr may jun jul aug sep oct nov dec}
	set Months {January February March April May June July August September October November December}
	set ml [string tolower $m]
	if {[set x [lsearch -exact $mons $ml]]!=-1} {
		set m [lindex $Months $x]
	}

	return $m
}


proc linebreak {string {breakat 70}} {
	set ch 0; set lastw ""
	set broke ""

	foreach word $string {
		# double space after periods
		if {[string match "*." $lastw]} {append broke " "}

		set wlen [string length $word]
		if {$ch+$wlen<$breakat} {
			if {$ch>0} {append broke " "; incr ch}
			append broke $word; incr ch $wlen
		} else {
			append broke "\n" $word
			set ch $wlen
		}

		set lastw $word
	}

	return $broke
}


# return dates like ls: the more recent the more information, in roughly same number of characters
proc recently {then} {
	set datainfo "%Y %B %d %H %M %S"
	set format "%d %s %d %d %s %s"
	set now [clock seconds]
	scan [clock format $now -format $datainfo] $format year month day hour min sec
	set midnight [clock scan "$day $month"]
	scan [clock format $then -format $datainfo] $format oyear omonth oday ohour omin osec

	set secday [expr {24*60*60}]
	set secmonth [expr {30*$secday}]
	set secyear [expr {365*$secday}]

	set age [expr {$now-$then}]
	if {$age>=[expr {$secyear-2*$secmonth}]} {
		set r "$oday $omonth $oyear"
	} else {
		if {$age>=$secmonth} {
			set r "$ohour:$omin, $oday $omonth"
		} else {
			set r "$ohour:$omin"
			if {[expr {$midnight-$secday}]>=$then} {
				append r ", $oday $omonth"
			} else {
				if {$day!=$oday} {
					append r " yesterday"
				} else { append r ":$osec today" }
			}
		}
	}

	return $r
}


# word frequency

# stop words for frequency counts
# single-letter all stop word already covered
# rejected stop words: money, ...
set stoplistsrc {
	an the 
	is am be been being I'm I'll I'd I've are was wasn't were weren't take took taking use used using may might made make can can't could couldn't would wouldn't will won't given gave have having haven't has hasn't had hadn't get got go went come came receive received own
	and or both yes yeah neither nor but not no also instead etc
	all some many few much more most less least each every only any up down under in out front back top bottom here there over following last next prev previous about still really better worse often usually almost lot little
	thing something anything everything one anyone everyone someone time sometime anytime everytime maybe way anyway away
	if then than such between because however yet like as just very especially again already well too even
	at of to into onto on in by with without for from so 
	example
	me my we us our they them there there's their this that these those that's which other you your you'll he him he's she her she's it its it's 
	who whose what where when why how now
	think thought say says said read write wrote feel felt believe believed need needed meet met know knew want wanted do don't doesn't did didn't sit sat stand stood see new current specified same different item entry
	please thank people

	jan feb mar apr may jun jul aug sep oct nov dec
	january february march april may june july august september october november december
	mon tue wed thu fri sat sun
	monday tuesday wednesday thursday friday saturday sunday
	north south east west
	am pm tm re

	first second third fourth fifth
	one two three four five six seven eight nine ten hundred thousand million billion trillion

	hi hello


	bug file filename path pathname directory dir home program software input output name bin script lib usr user run set command com tcp ip rpc install installed invoke invoked group argument exit id option level local code system list address addressed source binary type var variable machine mode configuration information info char character int void ok sww

	date to from subject
	org com edu gov mil net


	object oriented server protocol client string module class public private protected time database field menu version default print line expression buffer

	torithoughts smoe mlether ecto

}

# ASSERT -- duplicates ok as make patterns complete (might/may, apr/may/jun) and don't use much space
#foreach s $stoplistsrc {if [info exists stoplist($s)] {puts "\aduplicate: $s"} else {set stoplist($s) ""}}
#unset stoplist

# These words are crudely normalized into singlar: s,es,y,ies chopped off end
#set singregexp {(s|es|y|ies) }
variable singregexp {'?(s|y|ies) }
# could make output more readable by converting ies=>y and remove y|ies from truncation list
regsub -all $singregexp [string tolower $stoplistsrc] " " singstoplist
variable stoplist
foreach s $singstoplist {set stoplist($s) ""}
variable freqs
variable we {^[A-Za-z][A-Za-z0-9&_'-]+}; # ...* to be a word, but don't want single-letter words... maybe don't want two- or three-letter words either 
variable ce {[^A-Za-z0-9&_'-]+}

# LATER: more args to describe desired output
proc wordfreq {txt {top 10}} {
	variable singregexp; variable stoplist; variable freqs; variable we; variable ce

	update

	# report top n most frequent words and (really n least but that's almost always) singletons
	## get and canonicalize words: all lowercase, no punctuation
	catch {unset freqs}

	regsub -all $ce [string tolower $txt] " " words
	# crude plurals
	regsub -all $singregexp $words " " singwords
	set awords {}
	foreach word [lsort $singwords] {
		if {![info exists stoplist($word)] && [regexp $we $word]} {lappend awords $word}
	}

	update

	## compute frequencies
	set lastword "total"; set cnt [llength $awords]
	set freqpairs {}
	foreach word $awords {
		if {$word ne $lastword} {
			lappend freqpairs [list $lastword $cnt]; set freqs($lastword) $cnt
			set cnt 0; set lastword $word
		}
		incr cnt
	}
	lappend freqpairs [list $lastword $cnt]

	update

	## report frequencies
	set freqpairs [lsort -index 1 -integer -decreasing $freqpairs]

	return [lrange $freqpairs 0 [expr {$top-1}]]
}


# statistically summarize text buffer to n% sentences (5-10% good.  90% not a summary)
# algorithm: take word frequences, score sentences by sum of component frequencies, report top n
# precondition: wordfreq already taken
proc summarize {t {n 2} {sol 1.0}} {
	variable ce; variable singregexp; variable freqs

	set eolrx "^\[-># \t]+|^$|^\[A-Z]\[-a-z]+:|(^|\[ \t]+)(\[\$\"a-z0-9\]|\[A-Z\]\[A-Z\]|\[A-Z\]\[^ \t]\[^ \t]\[^ \t])\[^ \t]*\[.?!\;]\[ \t]*($|\[ \t])"
	set important "subject|important|key|central|main"

	# iterate over sentences == period ending a lowercase word
	set sent {}; # triple: text start, text end, score
	while {1} {
		if {[set eol [$t search -count endcnt -regexp $eolrx $sol end]]==""} break
		append eol "+${endcnt}c"

		# get text, score line
		regsub -all $ce [$t get $sol $eol] " " words
		regsub -all $singregexp $words " " singwords
		set score 0; set wcnt 0; set lastword ""
		foreach word [lsort $singwords] {
			set lcword [string tolower $word]
			if {$lcword!=$lastword && [info exists freqs($lcword)]} {
				set bonus 1; if {$word!=$lcword} {set bonus 2; if {$word==[string toupper $word]} {set bonus 3}}
				if {[regexp "^($important)" $lcword]} {set bonus [expr {$bonus*10}]}
				incr score [expr {$freqs($lcword)*$bonus}]
				incr wcnt; set lastword $lcword
			}
		}
		if {$score>0 && $wcnt>=5} {lappend sent [list $sol $eol [expr {$score/($wcnt/5.0)}]]}
		set sol $eol
	}
#puts "$n% of [llength $sent]"

	# show score of each sentence (approx)
	set state [$t cget -state]; $t configure -state normal
	for {set i [expr {[llength $sent]-1}]} {0 && $i>=0} {incr i -1} {
		foreach {sol eol score} [lindex $sent $i] break
		$t insert $sol "  ([format %.0f $score]) "
	}
	$t configure -state $state

	return [lrange [lsort -real -decreasing -index 2 $sent] 0 [expr {([llength $sent]*$n)/100}]]
}



# word-grain diff
# spacing not preserved
proc wdiff {oldline newline {instag "diffa"} {deltag "diffd"} {fuzz 3}} {
#puts $oldline
#puts $newline
	set tclesc {[][\\\${}"]}
	regsub -all -- $tclesc $oldline {\\&} oldline; regsub -all -- $tclesc $newline {\\&} newline
#	set oldline [stringesc $oldline]; set newline [stringesc $newline]
# NO! adds braces:	set oldline [list $oldline]; set newline [list $newline]
#	set oldline [split $oldline]; set newline [split $newline] -- good but taxes re-eval
	set diffcnt 0; # count number of words of difference
	set oldlinelen [llength $oldline]; set newlinelen [llength $newline]
	set newlinefuzz [expr {$newlinelen-$fuzz}]
	set linecomp {}

	set punct ".,?\;!"
	set matchcnt 0
	for {set i1 0; set i2 0} {$i1<$oldlinelen && $i2<$newlinelen} {} {
		set w1 [lindex $oldline $i1]; set w2 [lindex $newline $i2]
		if {$w1==$w2 || [string trim $w1 $punct]==[string trim $w2 $punct]} {incr matchcnt; incr i1; incr i2; continue}


		if {$matchcnt} {lappend linecomp "[lrange $newline [expr {$i2-$matchcnt}] [expr {$i2-1}]] " {}; set matchcnt 0}

		incr diffcnt

		# if can match next three words in old somewhere in new, assume text inserted into new
		set fIns 0
		for {set s $i2} {$s<$newlinefuzz} {incr s} {
			if {$w1==[lindex $newline $s] && [lrange $oldline $i1 [expr {$i1+$fuzz-1}]]==[lrange $newline $s [expr {$s+$fuzz-1}]]} {
				lappend linecomp "[lrange $newline $i2 [expr {$s-1}]] " $instag
				set i2 $s
				set fIns 1; break
			}
		}
		if {$fIns} continue
		# else deleted word in old
		lappend linecomp "$w1 " $deltag
		incr i1
	}

	# everything left in oldline is deleted, newline added
	if {$matchcnt} {lappend linecomp "[lrange $newline [expr {$i2-$matchcnt}] [expr {$i2-1}]] " {}}
	if {$i1<$oldlinelen} {lappend linecomp "[lrange $oldline $i1 end] " $deltag}
	if {$i2<$newlinelen} {lappend linecomp "[lrange $newline $i2 end] " $instag}

#	lappend linecomp "" {}; # make sure nonempty -- maybe not necessary

#	if {$diffcnt>[expr $oldlinelen/2]} {set linecomp [list $oldline $deltag "\n" {} $newline $instag]}

#puts "=> $linecomp"
	return $linecomp
}


# end namespace eval
}
