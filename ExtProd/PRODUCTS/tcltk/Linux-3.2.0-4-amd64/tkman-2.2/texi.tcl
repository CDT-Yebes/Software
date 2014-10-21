# protocol: show directory, show file.  works for GNU info, Tcl proc browser, Java class browser

#
# GNU info *source* reader
# 1997 January 19
#
# 1997
# 19 Jan	basically works
# 20		nested table, itemize, enumerate
# 21		index builder
# 28		dynamic index building
# 31		support indexes and crossreferences
#			back to the disk database, sigh, but two orders of magnitude smaller than compiled info
# 20 Dec	regexp search within Texinfo
#
# 1998
# 20 Feb	glimpse across Texinfo
#  2 Apr	sped up markup by processing with regsub before putting into text buffer
# 13 May	two-stage search: existing text plus index, then full-text on disk
#
# 1999
# 22 Jan	update to Tcl 8.1 regexp
#

# Pretends it's an info.  Would be better to pretend to be tex, but then get raw TeX commands.

# find <l>...@end <l> in text widget, delete that text, return range of bracked text
proc texiRegionFind {t l start end point} {
#puts "texiRegionFind $start $end"
#puts "[clock clicks]: texiRegionFind $l"
	set ws {[ \t]}
	# find first end to get innermost nested
	set close [$t search -regexp -elide -- "^@end$ws+${l}($ws+|\$)" $point $end]
	if {$close eq ""} return
	set tag [$t get "$close+5c wordstart" "$close+5c wordend"]

	# find corresponding start at same nesting level
	set rx "^@(end$ws+)?${tag}($ws+|\$)"; # also ended by another instance of same tag
	set cnt -1
	for {set open $close} {$cnt} {} {
		set open [$t search -regexp -elide -backwards -count openlen -- $rx $open-1c $start]
		if {$open eq ""} return; # unmatched tags do happen
		if {[$t get $open+1c $open+5c] eq "end "} {incr cnt -1} else {incr cnt 1}
	}
	set arg [$t get $open+${openlen}c "$open lineend"]

	# delete labels
	$t delete $close "$close+1l"; $t delete $open "$open+1l"

	# return range of bracketed text
	return [list $tag $arg $open [$t index $close-1l]]
}




# only one client, so could inline, but wouldn't gain much
proc texiRevLineFindAll {t l start end} {
#puts "[clock clicks]: texiLineFind $l"
	set alllines {}
	set rx "^@${l}( |\$)"
	while {[set end [$t search -backwards -regexp -elide -count startlen -- $rx $end $start]] ne ""} {
		#set tag [lindex [$t get $end+1c $end+${startlen}c-1c] 0]; #8.1 wordstart/wordend
		set tag [$t get "$end+1c wordstart" "$end+1c wordend"]
		$t delete $end $end+${startlen}c
		lappend alllines $tag [string trim [$t get $end "$end lineend"]] $end
	}
	return $alllines
}


# no separate texiTagFind because of tricky case of nested tags
# that's ok since no client for one anyway
proc texiTagFindAll {t l start end} {
#puts "texiTagFind $start $end"
#puts "[clock clicks]: texiTagFind $l"
	set all {}

	set orx "(^|@@|\[^@])@($l)\{"; set crx {[^@]@[a-z]+{|}}
	while {[set open [$t search -regexp -elide -count openlen -- $orx $start $end]] ne ""} {
		set opentxt [$t get $open $open+3c]
		if {$opentxt eq "@@@"} {append open "+2c"; incr openlen -2
		} elseif {[string index $opentxt 0] ne "@"} {append open "+1c"; incr openlen -1}
		set openend "$open+${openlen}c"
		set ocnt 1; set close $openend-1c
		# handle nested braces
		set closeadj ""
		while {$ocnt} {
			set newclose [$t search -regexp -elide -count insidelen -- $crx $close+1c $end]
			if {$newclose eq ""} break else {set close $newclose}
			set t3 [$t get $close-2c $close+1c]
			if {[string index $t3 2] eq "\}"} {
				if {[string index $t3 1] ne "@" || [string index $t3 0] eq "@"} {incr ocnt -1}
			} else {incr ocnt; append closeadj "-${insidelen}c-1c"}
		}
		if {$ocnt} break; # not properly nested
		set closeret [$t index $close]; if {[$t index "$open linestart"]==[$t index "$close linestart"]} {append closeret "-${openlen}c"}
		lappend all [$t get $open+1c $openend-1c] $open [$t index $closeret$closeadj]

		# delete labels
		$t delete $close; $t delete $open $openend

		set start $open
	}

	return $all
}

proc texiRevTagFindAll {t l start end} {
	return [lreverse [texiTagFindAll $t $l $start $end] 3]
}



# c=concept, f=function, v=variable, k=keystroke, t=data type
# index category <whatever>+
array set texidef {
	deffn {findex category name arguments}
	defun {findex "Function" name arguments}
	defmac {findex "Macro" name arguments}
	defspec {findex "Special Form" name arguments}
	defvr {vindex category name}
	defvar {vindex "Variable" name}
	defopt {vindex "Option" name}
	deftypefn {tindex category datatype name arguments}
	deftypefun {tindex "Function" datatype name arguments}
	deftypevr {vindex category datatype name}
	deftypevar {vindex "Variable" datatype name}
	deftypecv {vindex category class name}
	deftypeivar {vindex "Instance Variable" class name}
	defop {findex category class name arguments}
	defmethod {findex "Method" class name arguments}
	defp {tindex category name attributes}
}


array set texitrans {
	"dots" "..."  "enddots" "... ."  "bullet" "\xb7"  "copyright" "\xa9"
	"result" "=>"  "equiv" "=="  "error" "error-->"  "expansion" "==>"  "point" "-!-"
	"print" "-|"   "result" "=>"   "minus" "-"  "sp" "\n"  "exclamdown" "\xa1"  "questiondown" "\xbf"
	"AA" "\xc5"  "aa" "\xe5"  "AE" "\xc6"  "ae" "\xe6"  "O" "\xd8"  "o" "\xf8"  "OE" "OE"  "oe" "oe"
	"pounds" "\xa3"
}
set texitrans(today) [clock format [clock seconds] -format "%d %B, %Y"]
set texitrans(regexp) [join [array names texitrans] "|"]

# maybe expand this with Tk 8.1's internationalization
array set texiaccent {
	`A "\xc0" 'A "\xc1" ^A "\xc2" ~A "\xc3" \"A "\xc4"
	,C "\xc7"
	`E "\xc8" 'E "\xc9" ^E "\xca" \"E "\xcb"
	`I "\xcc" 'E "\xcd" ^I "\xce" \"I "\xcf"
	barD "\xd0"
	~N "\xd1"
	`O "\xd2" 'O "\xd3" ^O "\xd4" ~O "\xd5" \"O "\xd6"
	`U "\xd9" 'U "\xda" ^U "\xdb" \"U "\xdc"
	'Y "\xdd"
	`a "\xe0" 'a "\xe1" ^a "\xe2" ~a "\xe3" a-\" "\xe4"
	,c "\xe7"
	`e "\xe8" 'e "\xe9" ^e "\xea" e-\" "\xeb"
	`i "\xcc" 'i "\xcd" ^i "\xee" i-\" "\xef"
	bard "\xf0"
	~n "\xf1"
	`o "\xf2" 'o "\xf3" ^o "\xf4" ~o "\xf5" \"o "\xf6"
	`i "\xf9" 'i "\xfa" ^e "\xfb" \"e "\xfc"
	'y "\xfd" y-\" "\xfd"
}

# searching in text widget linearizes the text a line at a time, so maximize patterns per search
proc texiMarkup {t start end {force 0}} {
#puts "texiMarkup $start .. $end"
	global texi texidef texiaccent

	cursorBusy

	foreach per $texi(persistent) {upvar #0 ${per}$t $per}


	### text movement before tag adding!

	foreach {tag s e} [texiRevTagFindAll $t "footnote" $start $end] {
		# source
		set footnote [$t get $s $e]
		$t delete $s $e
		$t insert $s "*"
		$t tag add superscript $s

		# footnote text
		$t mark set insert [set m [$t index $end-1l]]
		$t insert insert " *$footnote\n"
		$t tag add superscript $m+1c; $t tag add sc $m insert
	}


	### LINES
	foreach {tag ctnt s} [texiRevLineFindAll $t "(printindex|majorheading|heading|subheading|subsubheading|subtitle|author|center|vskip)" $start $end] {
		switch -exact $tag {
			printindex {
				$t delete $s "$s lineend+1c"

				# name gives type to print: cp, fn, vr, ky, pg, tp + user defined
				# tuple: entry title font
				$t mark set $ctnt insert
				set txtindex {}; set lastletter ""; set icnt 0
				foreach tuple $texiindex($ctnt) {
					foreach {iname isect ifont} $tuple break
					set curletter [string tolower [string index $iname 0]]
					if {$curletter eq $lastletter} {
						lappend txtindex "  " tt "/" "" "  " tt; incr icnt
						# don't want icnt, but long lines don't scroll well and take enormously longer to format(!)
						if {$icnt==10} {lappend txtindex "\n" ""; set icnt 0}
					} elseif {$lastletter ne ""} {lappend txtindex "\n\n " ""; set icnt 0}
					lappend txtindex " $iname" [list texixref $ifont]
					set lastletter $curletter
				}
				lappend txtindex "\n"

				$t mark set insert $s; eval $t insert insert $txtindex; $t tag add index $s insert
			}

			vskip {$t delete $s "$s lineend"; $t insert $s "\n\n"}

			# add tag only
			majorheading -
			heading -
			subheading -
			subsubheading {
				$t tag add $tag $s $s+1l
			}

			# add tag + no line wrapping
			subtitle -
			author -
			center {
				if {[$t get $s+1l] ne " "} {$t insert $s+1l " "}
				$t insert $s " "; $t tag add $tag $s $s+1l
			}
		}
	}


	### REGIONS: example, tables, lists
	set point $start
	while 1 {
		set tag ""
		foreach {tag arg s e} [texiRegionFind $t {(quotation|display|example|smallexample|lisp|smalllisp|format|flushleft|flushright|def\S+)} $start $end $point] {set point $s}
		if {$tag eq ""} break

		switch -glob $tag {
			quotation {
				# add tag only
				$t tag add $tag $s $e
			}

			def* {
				# name, args left margin; category right margin; entered into index
				if {[string match "def*index" $tag] || $tag eq "definfoenclose"} continue
				$t insert $s "\n"

				while 1 {
					set spec $texidef($tag)
					set inx 0; set category [lsecond $texidef($tag)]
					if {$category eq "category"} {set category [lfirst $arg]; incr inx}
					$t insert $s " " {} [lindex $arg $inx] code "  " {} [lrange $arg [expr {1+$inx}] end] i "\t$category"
					$t tag add rmtab $s "$s lineend"

					# process def.*x
					append s "+1l"
					if {[$t get $s] eq "@" && [string match "def*" [set tag [$t get $s+1c "$s+1c wordend-1c"]]]} {
						set arg [$t get "$s+1c wordend+1c" "$s lineend"]
						$t delete $s "$s lineend"
					} else {$t insert $s " \t"; break}
					# initial space before \t above to prevent conjoining with line above
				}
			}

			# default = example|smallexample|lisp|smalllisp|format|flushleft|flushright
			default {
				# special markup with arg
				if {[string match "flush*" $tag]} {set ichar " "} elseif {$tag eq "format"} {set ichar " "; set tag "r"} else {set ichar " \t"}
				for {scan $e "%d" i; incr i -1} {$i>=$s} {incr i -1} {
					$t insert $i.0 $ichar; # can't add $tag here too because want to pick up ALL existing tags
#					$t tag add $tag $i.0
				}
				$t tag add $tag $s $e
				if {[$t get $e] ne "\n"} {$t insert $e "\n"}
			}
		}
	}

	# SPECIAL HANDLING: tables
	# tables last before character ranges, as its tabs disable further region and line identification
	set point $start
	while 1 {
		set tag ""
		foreach {tag type s e} [texiRegionFind $t "(.?table|multitable|itemize|enumerate)" $start $end $point] {set point $s}
		if {$tag eq ""} break

		set mt [string equal $tag "multitable"]; if {[string match "*table" $tag]} {set tag "table"}
		set tabtag "list"
		if {$mt} {
			set tabtag "multitable[incr texi(multitablecnt$t)]"
			set mttabs ""
			# collect @columnfractions or prototype row, if any
			set scrnw [expr {[winfo width $t]-20}]
			if {[lfirst $type] eq "@columnfractions"} {
				# could check that each $fract<=1.0 and sum over $fract <=1.0, but not my problem
				foreach fract [lrange $type 1 end] {lappend mttabs "[expr {int($scrnw*$fract)}]p"}
			} else {
				# prototype columns
				set frlen 0; foreach fract $type {incr frlen [string length $fract]}
				set tabposn 0
				foreach fract $type {
					incr tabposn [expr {int($scrnw*[string length $fract]/$frlen)}]
					lappend mttabs ${tabposn}p
				}
				lappend mttabs "[expr {$tabposn+100}]p"; # in case miscount columns
			}
			$t tag configure $tabtag -tabs $mttabs
#puts "\atabs $mttabs"
		} elseif {$tag eq "table"} {
			set tabtag "table"

		} elseif {$tag eq "itemize"} {
			switch -glob -- $type {
				@bullet* {set mark " \xb7\t"}
				@minus* {set mark " -\t"}
				default {set mark " $type"}
			}
		} elseif {$tag eq "enumerate"} {
			set icnt 1
			set format " %d.\t"
			if {[regexp {\d+} $type num]} {set icnt $num} \
			elseif {[regexp {[:alpha:]} $type letter]} {scan $letter "%c" icnt; set format " %c.\t"}
		}

		set needindent 0
		set itemlinelen 0
		for {scan $s "%d" i; scan $e "%d" ie} {$i<$ie} {incr i} {
#puts "$i<$ie   [$t get $i.0 [list $i.0 lineend]]"
			# replace @item, @itemx by @table's argument
			set linetag [$t get $i.0 $i.5]; set ch [string index $linetag 0]
			if {$mt && ($linetag eq "@item" || $linetag eq "@tab ")} {
				$t delete $i.0 $i.5
				if {$linetag eq "@tab "} {$t insert $i.0 "\t"}
				$t insert $i.0 " "
				set needindent 0
			} elseif {$linetag eq "@item"} {
				set ex [string equal [$t get $i.5] "x"]
				$t delete $i.0 $i.6+${ex}c; # @item+space
				set itemlen 0; if {!$ex} {set itemlinelen 0}
				if {$tag eq "itemize"} {
					if {[string trim [$t get $i.0 "$i.0 lineend"]] eq ""} {
#puts "trim = [string trim [$t get $i.0 {$i.0 lineend}]]"
						# not according to spec but fileutils' getdate.texi does it
						$t delete $i.0 $i.0+1l; incr ie -1; #incr i -1; # preserves line end ("\n")
					}
					$t insert $i.0 $mark
				} elseif {$tag eq "enumerate"} {
					$t delete $i.0 $i.0+1l; incr ie -1
					$t insert $i.0 [format $format $icnt]
					incr icnt
				} else {
					# table, multitable
					scan [$t index "$i.0 lineend"] "%d.%d" junk itemlen
#puts "expr $itemlinelen+$itemlen for [$t get $i.0 $i.$itemlen]"
					$t insert $i.0 "$type\{"
					$t insert "$i.0 lineend" "\}\t"
					if {$itemlinelen+$itemlen>12 && [$t get "$i.0+1l" "$i.0+1l+5c"] ne "@item"} {$t insert "$i.0+1l" " \t"}
				}
				if {$ex && [expr {$itemlinelen+$itemlen}]<50} {
					if {$tag eq "table"} {$t delete $i.0-2c}
					$t insert $i.0-1c ", "
					$t delete $i.0-1c
					incr i -1; incr ie -1
					incr itemlinelen $itemlen
				} else {$t insert $i.0 " "; set itemlinelen $itemlen}
				set needindent 0
			} elseif {$ch eq " " || $ch eq "\t"} {
				$t insert $i.1 "   "; # nested list/table (tried ... $i.0 " \t")
			} elseif {$ch eq ""} {
				set needindent 1
			} elseif {$needindent} {
#puts "inserting tab to: [$t get $i.0 [list $i.0 lineend]]"
				$t insert $i.0 "\t"; # sole place where initial \t OK
				set needindent 0
			}
		}

		if {[$t get $ie.0] ne "\n"} {$t insert $ie.0 "\n"}
		$t tag add $tabtag $s $ie.0
#puts "[$t get $s $ie.0]\n\n"
	}


	### TAGS
	# styles and replacement text
	# replacement text (with tags)
	# important to respect existing tags as may be in footnote or table
	foreach {tag s e} [texiRevTagFindAll $t "sc|uref|email|samp|dmn|math|,|v|H|u|ubaraccent|underdot|dotaccent|ringaccent|tieaccent|udotaccent|dotless|TeX|xref|ref|pxref|inforef|$texienclose(enregexp)" $start $end] {
		set txt [$t get $s $e]; $t delete $s $e

		switch -exact $tag {

			xref -
			ref -
			pxref -
			inforef {
				foreach {nodename xrefname topic infofile printedmanual} [split $txt ","] break
				if {$tag eq "inforef"} {set tag "xref"}
				set txt ""; if {$tag eq "xref"} {set txt "See "} elseif {$tag eq "pxref"} {set txt "see "}
				$t insert $s "$txt$nodename"; $t tag add texixref $s+[string length $txt]c "$s+[string length $txt]c+[string length $nodename]c"
#				if {$xrefname ne ""} {$t insert insert $xrefname}
			}

			# tags with no effect
			dmn -
			math {$t insert $s $txt}

			# accented characters with alphabetic tags (these have {} around argument)
			v -
			, -
			H -
			ubaraccent -
			underdot -
			dotaccent -
			ringaccent -
			tieaccent -
			udotaccent -
			dotless -
			u {
#				if [catch {set txt $texiaccent($tag$txt)}] {set txt "($tag)$txt"}
				catch {set txt $texiaccent($tag$txt)}
				$t insert $s $txt
			}

			sc {$t insert $s [string toupper $txt]; $t tag add sc $s "$s+[string length $txt]c"}
			samp {$t insert $s "`$txt'"; $t tag add tt $s+1c $e+1c}
			email -
			uref {
				foreach {uref ureftxt} [split $txt ","] break
				$t insert $s "<$uref>"; $t tag add tt $s "$s+[expr {2+[string length $uref]}]c"
				if {$ureftxt ne ""} {$t insert $s "$ureftxt "}
			}
			TeX {$t insert $s "TEX"; $t tag add subscript $s+1c}

			# must be texienclose(enregexp)
			default {
#				if {[regexp $texienclose(enregexp) $tag]} {
					$t insert $s "[lfirst $texienclose($tag)]$txt[lsecond $texienclose($tag)]"
#				} else {
#				}
			}
		}
	}


	### CLEAN UP

	# text styles
	# first pass done by regsub, but can have nesting in tables (not with all these styles though) -> later push these down into table handling (just has to check for formatting and apply tag)
# can combine with above TagFind it above is last pass through text
	foreach {tag s e} [texiTagFindAll $t "asis|r|i|b|t|w|code|kbd|key|file|url|var|dfn|emph|strong|titlefont|subtitle|author|cite" $start $end] {$t tag add $tag $s $e}

	# finally unquote metachars and zap single newlines to let Tk word wrap
	# and accents with immediate letter (no {})
	set rx {@[{}@:.?!*"'`~^\s]}
	for {set s $start-1c} {[set s [$t search -regexp -elide $rx $s+1c $end]] ne ""} {} {
		set ch [$t get $s+1c]
		switch -regexp $ch {
			{\*} {
				$t delete $s $s+2c
				if {[$t compare $s != [list $s lineend]]} {$t insert $s "\n"}
				$t insert $s+1c " "
			}
			: {$t delete $s $s+2c}
			{["'`~^]} {
				# could handle these in regsub, careful to handle booms as with value, but not worth it
				set txt [$t get $s+1c $s+3c]; $t delete $s $s+3c
				catch {set txt $texiaccent($txt)}
				$t insert $s $txt
			}
			default {$t delete $s}
		}
	}

	if {$force} return

	scan [$t index $start+1l] "%d" stop
	# LATER condense multiple blank lines to one
	# leave exactly one newline at end
	for {scan [$t index $end-2l] "%d" i} {$i>$stop && [$t get $i.0] eq "\n"} {incr i -1} {$t delete $i.0}
	for {scan [$t index $end-1l] "%d" i} {$i>$stop} {incr i -1} {
		if {[string first [$t get $i.0] " \n"]==-1 && [string first [$t get $i.0-1l] "\n"]==-1} {$t insert $i.0-1c " "; $t delete $i.0-1c}
	}
	for {scan [$t index $start] "%d" i} {[$t get $i.0] eq "\n"} {incr i} {}
	$t delete $start+1l $i.0

	$t tag raise table

	cursorUnset
}


#--------------------------------------------------


# process file:
#	collect @include, @(chapter|{,sub,subsub}section), with byte offsets
#	process in order: on include, recurse; otherwise write out

set texilevelx(names) {chapter section subsection subsubsection}
array set texilevelx {
	0 chapter 1 section 2 subsection 3 subsubsection
	chapter 0 centerchap 0 unnumbered 0 appendix 0 chapheading 0
	section 1 unnumberedsec 1 appendixsec 1
	subsection 2 unnumberedsubsec 2 appendixsubsec 2
	subsubsection 3 unnumberedsubsubsec 3 appendixsubsubsec 3
}

proc texiStruct {t type sectdelta name file byte} {
	global texi texilevel texilevelx

	set x [$t index end-1l]
	set lev [expr {$texilevelx($type)+$sectdelta}]
	if {$lev<0} {set lev 0}; if {$lev>3} {set lev 3} elseif {$lev<0} {set lev 0}
	incr texilevel($lev)
	set n $texilevel(0)
	for {set i 1} {$i<=$lev} {incr i} {append n ".$texilevel($i)"}
	for {set i [expr {$lev+1}]} {$i<4} {incr i} {set texilevel($i) 0}
	$t insert end "$name\n" $texilevelx($lev)
#	$t insert end "$n  $name" $texilevelx($lev) "\n"; # -- numbered sections -> do at runtime if you want it but not in cache
	# just number the toplevel?
#	if {$lev==0} {
#		set txt "$n  $name"; if {$type eq "appendix"} {set txt [format "%c  %s" [expr $n+65] $name]}
#		$t insert end $txt $texilevelx($lev) "\n"
#	}

	set m "js$n"
	$t mark set $m $x

	return $m
}



proc texiProcess {t file {curnode "Front Matter"}} {
	global texi texised texiimap texiifont texidef teximacro texitrans texilevelx man manx

	foreach per $texi(persistent) {upvar #0 ${per}$t $per}
# texiprof
	set sumbytes 0
	set sectdelta 0
	set broodrx {^@(\S+)\s*((\S+)\s*(\S+(\s+\S+)*)?)?}

	set region "set|clear|ifset|end ifset|ifclear|end ifclear|ignore|end ignore|iftex|end iftex|tex|end tex|ifhtml|end ifhtml|include|macro|end macro"
	set struct "node|chapter|centerchap|unnumbered|appendix|chapheading|section|unnumberedsec|appendixsec|subsection|unnumberedsubsec|appendixsubsec|subsubsection|unnumberedsubsubsec|appendixsubsubsec|titlepage|\[\[:lower:]]+index|def|bye|raisesections|lowersections|vtable|end vtable|ftable|end ftable|item|itemx"
	# remove unnumbered* ?

	set rx "^@($region|$struct)\\M"
	set valuerx "(^|\[^@])@value{(\[^\}]+)}"
	set commentrx "(^|\[^@])@(c|comment)\\M.*"

	# at this point just ignore errors (usually for index.texi, which we generate ourselves)
#	if {[string match "*.tar.gz/*" $file]} {
#		# less error checking done with tar's
#		set realf $file
#	} else {
		set realf [lfirst [glob -nocomplain $file$manx(zoptglob)]]
		if {$realf eq "" || ![file readable $realf]} {return $sumbytes}
#	}
	set fid [open "|[manManPipe $realf]"]
	fconfigure $fid -buffersize 102400; # helps a tiny bit
	set filecontents [read $fid]
	close $fid

	set on 1; set inmacro 0; set endsed ""; set inftable 0; set invtable 0
	set lastbyte -1; set curmark ""
	set byte 0
	foreach line [split $filecontents "\n"] {
		set linelen [string length $line]; incr linelen; # add newline back into count
		set byte0 $byte
		incr byte $linelen
		#if {![regexp $rx $line]} continue -- seems faster

		regsub $commentrx $line {\1} line; # expensive but gotta do it
	    	# collect @macro bodies
		if {$inmacro} {
#puts "in macro: $line"
		    if {[string match "@end macro*" $line]} {
			set teximacro($macroname) [list $macroargs $macrobody]
			set inmacro 0; set macrobody ""
		    } else {append macrobody "\n$line"}
		}
		# collect @value's, make sure each has a value
		# collect @xref, @ref, @pxref, @inforef; only save node=>posn if needed
		for {set vline $line} {[regexp -indices $valuerx $vline all junk vari]} {set vline [string range $vline [expr {[lsecond $all]+1}] end]} {
			set var [string range $vline [lfirst $vari] [lsecond $vari]]
			#puts "$var => [info exists texiinfovar($var)]"
			if {![info exists texiinfovar($var)]} {set texiinfovar($var) "*No value for $var*"}
		}


		if {[regexp $rx $line]} {

		# sed
		# one regexp that feeds the brood
		regexp $broodrx $line all type name arg1 arg2
#		foreach {type name arg1 arg2} [string range $line 1 end] break => arg2 can have multiple words (or be null)
		set typename "$type $arg1"
		if {$on} {
			if {[info exists texised([set hit $typename])] || [info exists texised([set hit $type])]} {
				set on 0; set endsed $texised($hit); continue
			}
		} else {
			if {$endsed eq "end iftex" && [regexp $struct $type]} {
				# some Texinfo (e.g., emacs) hides structure within iftex -- skip the continue and process anyhow
			} else {
				if {$type eq $endsed || $typename eq $endsed} {set on 1}
				continue
			}
		}



		switch -glob -- $type {
			# collect set/clear, add to regions to ignore according to @ifset/@ifclear
			# set/clear status could change (be set multiple times), but doesn't in practice
			# set global texiinfovar so to communicate to possible include's
			set { set texiinfovar($arg1) $arg2 }
			clear {	catch {unset texiinfovar($arg1)} }
			ifset {	if {![info exists texiinfovar($arg1)]} {set on 0; set endsed "end ifset"} }
			ifclear { if {[info exists texiinfovar($arg1)]} {set on 0; set endsed "end ifclear"} }
			macro {
			    # don't do macros at all
			    #set macroname $arg1; set macroargs $arg2
			    #set inmacro 1
#puts "macro |$arg1|, |$arg2|, |$line|"
			}
			end {
				if {$arg1 eq "ftable"} {set inftable 0} elseif {$arg1 eq "vtable"} {set invtable 0}
			}


			node {
				# used as destination for xrefs.  could just save nodes that are destinations and differ from corresponding chapter/section text
				# nodename => chapter title => Tk mark.  really slows things down, but unavoidable
				set nodename [string trim [lfirst [split $name ","]]]
#				regexp {[^,]+} $name nodename
				#set texinode([set curnode $nodename]) ""; # mark set with following chapter/section/...
				set curnode $nodename
			}

			# set sectdelta 0 if recursing out of an include?
			raisesections {incr sectdelta -1}
			lowersections {incr sectdelta}

			include {incr sumbytes [texiProcess $t $arg1 $curnode]}
			# don't save index if no printindex (if axe this, still need keep pattern to keep out of clutches of *index)
			printindex {lappend texi(printindexes) $arg1; lappend texi(printindex) $curmark}
			synindex -
			syncodeindex  {
				# "Write an `@syncodeindex' command ... at the beginning of a Texinfo file"
				# merged-from always keeps its font
				set mapfrom "${arg1}index"
				foreach i [array names texiimap] {	if {$arg1 eq $texiimap($i)} {set mapfrom $i; break}  }
				set texiimap($mapfrom) $arg2
			}
			defindex {lappend texiimap(${arg1}index) $arg1; lappend texiifont(${arg1}index) "asis"}
			defcodeindex {lappend texiimap(${arg1}index) $name; lappend texiifont(${arg1}index) "code"}
			definfoenclose {
				# have to propagate these out to cache
				foreach {cmd before after} [split $name ","] break
				set texienclose([string trim $cmd]) [list [string trim $before] [string trim $after]]
			}
			def* {
				if {[string match "*x" $type]} {set type [string range $type 0 [expr {[string length $type]-1-1}]]}
				set spec $texidef($type)
				foreach {index category} $spec break
				set inx [expr {[lsearch $spec "name"]-2+1}]; if {$category eq "category"} {incr inx}
				set name [lindex $all $inx]
				lappend texiindex($texiimap($index)) [list $name $curnode $texiifont($index)]
			}

			ftable {set inftable 1}
			vtable {set invtable 1}
			item - itemx {
				# keep texiimap in case remapped, but keep original texiifont
				if {$inftable} {lappend texiindex($texiimap(findex)) [list $name $curmark $texiifont(findex)]
				} elseif {$invtable} {lappend texiindex($texiimap(vindex)) [list $name $curmark $texiifont(vindex)]}
			}
			# put slow *XXX at end of chain
			*index {lappend texiindex($texiimap($type)) [list $name $curmark $texiifont($type)]}

			default {
				# chapter, section, subsection, ...
				set skipbyte [expr {$byte0+$linelen}]
				if {$type eq "titlepage"} {set type "chapter"; set name "Title Page"
				} elseif {$type eq "centerchap"} {set type "chapter"}
				#set name [string trimright $name "."]; # gdbm has periods after each section
				if {[info exists texilevelx($type)] && $texilevelx($type)==0} {$t see end; update idletasks}

				regsub -all -- {([^\{])---} $name {\1--} name
				while {[regsub -all "(\[^@])@($texitrans(regexp)){}" $name {\1$texitrans(\2)} name]} {}
				while {[regsub -all "(^|\[^@])@value{(\[^\}]+)}" $name {\1$texiinfovar(\2)} name]} {}
				set name [subst -nobackslashes -nocommands $name]

				if {$lastbyte!=-1} {lappend texix($curmark) [expr {$byte0-$lastbyte}]}
				if {$type eq "bye"} break
				set curmark [texiStruct $t $type $sectdelta $name $file $skipbyte]
				set texix($curmark) [list $file $byte]; set texinode($curnode) $curmark
				set lastbyte $skipbyte
			}
		}
	}
	}
	if {$lastbyte!=-1 && $type ne "bye"} {lappend texix($curmark) [expr {$byte0-$lastbyte}]}

	incr sumbytes $byte
	return $sumbytes
}


# process callback string: fault in text, mark it up
proc texiCallback {t sect} {
	global manx curwin

	texiFault $t $sect

	set next [lindex $manx(nextposns$curwin) [lsearch $manx(sectposns$curwin) $sect]]
	manAutosearch [winfo parent $t] $t $sect $next; # if put in Fault then show up when prefetch and full text search.  here, repeat search every time open, but that's ok
	manAutokey $t $sect $next

	# prefetch next section while reading current
	# (maybe want to condition this on size)
	if {$next ne "endcontent" && $next ne ""} {after 100 texiFault $t $next}
#puts "read $sect, fault $next/$nextnext"
}

#proc texiFaultName {t sect} {}; # better to fault in by name
proc texiFault {t sect} {
	global texi manx texitrans curwin
	foreach per {texix texiinfovar teximacro} {upvar #0 ${per}$t $per}; # maybe expand to $texi(persistent)

	if {$texix($sect) eq ""} return
	set next [lindex $manx(nextposns$curwin) [lsearch $manx(sectposns$curwin) $sect]]

	set txtstate [$t cget -state]; $t configure -state normal

	foreach {f s len} $texix($sect) break
	set point "$sect linestart+1l"
	if {$texi(lastfile$t) ne $f} {
		cd $texi(cd$t)
		set realf [lfirst [glob $f$manx(zoptglob)]]
		set fid [open "|[manManPipe $realf]"]
		# setting to [file size] isn't perfect because file might be compressed
		fconfigure $fid -buffersize 102400
		set texi(lastfilecontents$t) [read $fid]
		close $fid
		set texi(lastfile$t) $f
	}


	### markup as much as you can before putting into buffer (regsub is the greatest!)
	$t mark set endinsert $point

	# normalize to escape out Tcl meta chars
	regsub -all {[][$"\\]} "\n[string trim [string range $texi(lastfilecontents$t) $s [expr {$s+$len-1}]]]\n\n" {\\&} tcltxt

	# KILL IRRELEVANT TEXT: comments, menu, ifhtml, ...
	# regsub faster here because text widget's regexp builds string from btree leaves
	set sot {(?n)^@}; set soet {(?n)^@end[ \t]+}; set eot {([^\w\n][^\n]*)?\n}; # not guaranteed to be in newline-sensitive mode for eot

	# REGIONS
	set shorttxt ""
#puts "looking for menu on\n$tcltxt===================="
	while 1 {
		# should @ignore takes precedence in not well nested case?
		if {![regexp -indices -- "${sot}(ignore|iftex|tex|ifhtml|ifnotinfo|menu|ifset|ifclear)$eot" $tcltxt indices]} break
		foreach {s0 s1} $indices break
		foreach {tag arg} [string range $tcltxt [expr {$s0+1}] $s1] break
		if {![regexp -indices -- "$soet$tag$eot" $tcltxt indices]} break
		foreach {e0 e1} $indices break
		if {$s1>$e0} break

		append shorttxt [string range $tcltxt 0 [expr {$s0-1}]]

		if {[regexp "ifset|ifclear" $tag]
			&& ([string equal $tag "ifset"] ^ ![info exists texiinfovar($arg)])} {
			set tcltxt "[string range $tcltxt $s1 [expr {$e0-1}]][string range $tcltxt $e1 end]"
#			puts "\a$tag [lfirst $arg] => IN"
		} else {set tcltxt [string range $tcltxt $e1 end]}
# else {puts "\a$tag [lfirst $arg] => OUT"}
	}
	append shorttxt $tcltxt; set tcltxt $shorttxt


	# zap irrelevant LINES
	# kill true if regions: ifinfo, ifnothtml

	# kill page break control: group, titlepage
	# kill @comment, @node (use chapter/section/...), @[fc]index (just use full text search)
	# make exactly one pass when there's nothing to do
	# but need opening \n for correctness and regsub steps past this opener to match subsequent ones
	# ifinfo/ifset/iftex for unpaired tags in this region (it happens)
	while {[regsub -all "(?n)^@(ifinfo|end ifinfo|ifnottex|end ifnottex|group|end group|titlepage|end titlepage|ifnothtml|end ifnothtml|ifset|end ifset|ifclear|end ifclear|iftex|end iftex|tex|end tex|if html|end ifhtml|\[\[:lower:]]\[\[:lower:]]?index|def\[\[:lower:]]*index|node|unnumbered|finalout|lowersections|raisesections|null|need|sp|include|noindent|title|set|chapter|section|subsection|subsubsection|page|contents|shortcontents|summarycontents|top|footnotestyle|setchapternewpage|paragraphindent|nwnode|leftmargin|dircategory|dirindex|bye)$eot" $tcltxt "" tcltxt]} {}
	# within active text, first process macros, as these can expand to text that needs to be further processed -- just do no-arg macros for now
# 	while {[regsub -all $teximacro(RX) $tcltxt {$teximacro(\1)} tcltxt]} {}
	# comments can start anywhere
	while {[regsub -all "(^|\[^@])@(c|comment)$eot" $tcltxt {\1} tcltxt]} {}
	# strip double @'s early, so each following is a command... but they're not (some literal)?
	# @=>\001, \001\001=>@, process with \001 as guaranteed command, (no final \001=>@ because they've all been processed as commands)
	# OR @@=>\001, process with @ as guaranteed command, final \001=>@
	# refill
	regsub -all {([^@])@(refill|:)} $tcltxt {\1} tcltxt
	# no distinction made between abbrevation period [.?!:] and end-of-sentence period [.?!:]
	regsub -all {([^@])@([.!? \t{}])} $tcltxt {\1\2} tcltxt


	# text replacement, e.g., @dots{} => ...
	# dots, @samp{<txt>}=>" "" "`<txt>'" samp " => don't because might interfere with adding tags below
#	regsub -all "\n@itemx (\[^\n\]*)" tcltxt {, \1} => don't get roman comma inbetween
	regsub -all -- {([^\{])---} $tcltxt {\1--} tcltxt; # ([^\{]) for @samp{---} exception
	while {[regsub -all "(^|\[^@])@($texitrans(regexp)){}" $tcltxt {\1$texitrans(\2)} tcltxt]} {}
 	while {[regsub -all {(^|[^@])@value{([^\}]+)}} $tcltxt {\1$texiinfovar(\2)} tcltxt]} {}
	while {[regsub -all {\m@tab\M} $tcltxt "\t" tcltxt]} {}

	# DO THIS LAST + can only have one that sets fonts because can't handle tag nesting in regsub/text widget syntax
	# add tags, e.g., @code{rm} => ..." rm code "...
	# don't handle nested tags: can't write regexp, have clean up pass, and not so common as to hinder speed
	regsub -all {([^@])@(asis|r|i|b|t|w|code|kbd|key|file|url|var|dfn|emph|strong|titlefont|subtitle|author|cite){(|([^{}]*[^\{@]))}} $tcltxt {\1" "" "\4" \2 "} texttxt

	eval $t insert \$point \"$texttxt\" \"\"
	$t tag add area$sect $point-1c "$next linestart"
	
	texiMarkup $t $point endinsert


	# add tags from parent outline nodes
	$t tag add area$sect $point-1c "$next linestart"; # for stragglers--should be able to delete eventually
	for {set sup $sect} {[regexp $manx(supregexp) $sup all supnum]} {set sup "js$supnum"} {
		$t tag add areajs$supnum $point-1c "$next linestart"
	}
	set texix($sect) ""; incr texi(sectcnt) -1


	$t configure -state $txtstate
}


set texi(persistent) {texiindex texinode texiinfovar texix texienclose texiback texiprintindex teximacro}
set texi(noenclose) {^XXXNOMATCHESXXX$}; # for legacy.  could set to ""

# show one file, at least toplevel
proc texiShow {t f dir {force 0}} {
	global texi texised texiimap texiback texiifont texilevel texilevelx man manx
	foreach per $texi(persistent) {upvar #0 ${per}$t $per}

#	manNewMode [winfo parent $t] texi; uplevel incr stat(texi)
	cd [set texi(cd$t) [file dirname $f]]


	# caller should have done this checking
	set realf [lfirst [glob -nocomplain $f$manx(zoptglob)]]
	#if {![regexp {(.*\.tar[^/]*)} $file all realf]} {set realf [lfirst [glob -nocomplain $f$manx(zoptglob)]]}
	if {$realf eq ""} {$t insert end "doesn't exist!" b; return
	} elseif {![file readable $realf]} {$t insert end "not readable!" b; return
	}

	set sumbytes 0

	foreach array [concat $texi(persistent) texiimap texiifont texised] {catch {unset $array}}

	# if in texinfodir, assume Tcl version already cached
	# use CPU over disk
	set cache [lfirst [glob -nocomplain [file join $dir "[file tail $f]$manx(zoptglob)"]]]
	if {!$force && $cache ne "" && [file readable $cache] && [file mtime $cache]>[file mtime $realf] && [file mtime $cache]>$manx(mtime)} {
# && ($manx(debug) ||)
		set fid [open "|[manManPipe $cache]"]; set src [read $fid]; close $fid
		eval $src

	} else {

		array set texiimap {cindex cp findex fn vindex vr kindex ky pindex pg tindex tp}
		array set texiifont {cindex asis findex code vindex code kindex asis pindex code tindex code}
		for {set i 0} {$i<[llength $texilevelx(names)]} {incr i} {set texilevel($i) 0}
		array set texised {"ignore" "end ignore" "iftex" "end iftex" "tex" "end tex" "ifhtml" "end ifhtml"}
		set texi(printindexes) {}; set texi(printindex) {}

		cursorBusy
		set subtags {section subsection subsubsection}; # not chapter
		foreach tag $subtags {$t tag configure $tag -elide 1}
		scan [time {set sumbytes [texiProcess $t [zapZ [file tail $f]]]}] "%d" time
		foreach tag $subtags {$t tag configure $tag -elide ""}
#puts "$time us for $sumbytes bytes"
		cursorUnset


		## finishing touches

		# sort and unique indexes
#puts "\aPRINTINDEX types $texi(printindexes), texiimap = [array get texiimap]"
		# none at all for flex, Elisp(!), ...
		foreach index [array names texiindex] {
			if {[lsearch $texi(printindexes) $index]!=-1} {
				set content {}
				set last ""
				foreach tuple [lsort -dictionary -index 0 $texiindex($index)] {
					set entry [lindex $tuple 0]
					if {$entry ne $last} {lappend content $tuple; set last $entry}
				}
				set texiindex($index) $content
			} else {
				# if no printindex for some index, don't need to save that index
				# disk space saved inconsequential, but uses less memory and loads faster
				# this is robust in the face of synindex, syncodeindex, def*index, ...
				# this doesn't happen much, as synindex used to map everything into an index that is shown
DEBUG {puts "\tno printindex for $index (length = [string length $texiindex($index)])"}
				unset texiindex($index)
			}
		}

		# texienclose(enregexp)
		if {![llength [array names texienclose]]} {set texienclose(enregexp) $texi(noenclose)
		} else {set texienclose(enregexp) [join [array names texienclose] |]}

		texiMarkup $t 1.0 end 1; # grr, embedded @code{...} bits

		# write out, if helpful and possible
		# catch needed on SunOS, not on Solaris, most others(?)
		catch {file delete -force $cache}
		if {$time<1.5*1000000} {
			# don't cache the small bills
		} elseif {![file writable $dir] || ($cache ne "" && [file exists $cache])} {
# interferes with outline making
#			$t insert 1.0 "[file tail $f] not cached as $cache not writable\n" b "\n"
#			$t see 1.0
#			after 2000
		} else {
			# write out state: outline text+tags, node xref, numbered marks, index, 
			# creates long lines, but result not meant for human manipulation
			set cache $dir/[file tail $f]
			set wfid [open $cache "w"]
			puts -nonewline $wfid "\$t insert end"
# lsort -dictionary work?
			set ms [lsort -dictionary [array names texix]]
			foreach m $ms {
				set level [regsub -all {\.} $m {\.} junk]; set tag $texilevelx($level)
				puts -nonewline $wfid " [list [$t get [list $m linestart] [list $m lineend]]] $tag {\n} {}"
			}
			puts $wfid ""
			# save selected markup tags
			foreach tag {code subscript} {
				if {[llength [$t tag ranges $tag]]} {puts $wfid "\$t tag add $tag [$t tag ranges $tag]"}
			}
			puts $wfid "update idletasks"
			puts $wfid "set texi(printindex) [list $texi(printindex)]"
#{(^|[^@])@value{([^\}]+)}}
#			if {[llength [array names teximacro]]>0} {set teximacro(RX) "\\(^|\[^@\]\\)@([join [array names teximacro] "|"])\{"} else {set teximacro(RX) "^XXXNOMACTCHESXXX$"}
			foreach per $texi(persistent) {
				puts $wfid "array set $per [list [array get $per]]"
			}
			puts $wfid "set line 1; foreach m \[lsort -dictionary \[array names texix\]\] {\$t mark set \$m \$line.0; incr line}"
			puts $wfid "# $sumbytes bytes processed in $time msec on [clock format [clock seconds]]"
			close $wfid

			eval exec $man(compress) $cache &
		}
	}

	set texi(sectcnt) [llength [array names texix]]

	# back mapping file => line/section pairs + count of source files (so know when faulted them all)
	set texiback(files) {}
	foreach sect [lsort -dictionary [array names texix]] {
		foreach {file s l} $texix($sect) break
		if {![info exists hit($file)]} {lappend texiback(files) $file; set hit($file) 1}
		lappend texiback($file) [list $sect $s]
	}
	set texiback(filez) {}; foreach file $texiback(files) {lappend texiback(filez) [lfirst [glob $file$manx(zoptglob)]]}
	# sort + sentinal
	foreach file $texiback(files) {lappend texiback($file) {bogussect 100000000}}

	set texi(lastsearch$t) {}; set texi(searched$t) 0; set texi(lasthits$t) {}
	set texi(multitablecnt$t) 0
#	$t insert js2 "\n$f last updated [textmanip::recently [file mtime $realf]]" sc

#puts "out of show"
	return $sumbytes
}


# show list of files
set texi(texinfo,update) 0
proc texiDatabase {dir} {
	global texi manx
#curwin 	# already manTextOpen
	set dirfile "$dir/dir.tkman"

	if {![file exists $dirfile]} {return [list "$dirfile doesn't exist" b]}
	if {![file readable $dirfile]} {return [list "$dirfile unreadable" b]}

	# cached one still up to date?
	if {[file mtime $dirfile]>$texi(texinfo,update)} {
		set texi(texinfo,update) [file mtime $dirfile]
		set form {}
		set texi(texinfo,paths) {}
		set texi(texinfo,names) {}
		set texi(texinfo,desc) {}

#		set topregexp {^\*\s+([^:]+): \((/[^\)]+\.(texi|texinfo|info.*))\)(\.z|\.gz|\.Z)?\.\s+(.*)}
		set topregexp "^\\*\\s+(\[^:]+): \\((\[^\\)]+\\.(texi|texinfo|info.*))\\)(?:$manx(zregexp0))?\\.\\s+(.*)"

		set cnt 0
		set fid [open $dirfile]
		while {![eof $fid]} {
			gets $fid line
			if {[regexp $topregexp $line all name f suffix Zignore desc]} {
				if {$suffix eq "info"} {lappend form $f b "-- .info files are formatted text; you want .texi/.texinfo Texinfo " "" "source" i "\n" {}; continue}
				set realf [lfirst [glob -nocomplain [zapZ $f]$manx(zoptglob)]]
				#if {[regexp {(.*\.tar[^/]*)} $f all tar]} {set zapf $tar} else {set zapf $f}
				#set realf [lfirst [glob -nocomplain [zapZ $zapf]$manx(zoptglob)]]
				if {![file exists $realf]} {lappend form $f "" " -- doesn't exist\n" b; continue
				} elseif {![file readable $realf]} {lappend form $f "" " -- not readable\n" b; continue}

				# jsXXX defined after hyper, so higher priority, so called afterward, so overrides hotman var
				# point to root Texinfo
				lappend form $name [list js$cnt manref hyper] "\t$desc\n" {}
				lappend texi(texinfo,names) $name
				lappend texi(texinfo,desc) $desc
				lappend texi(texinfo,paths) $f
				incr cnt
			} else {lappend form "$line\n" {}}
		}
		close $fid
		set texi(texinfo,form) $form
	}
	return $texi(texinfo,form)
}

proc texiTop {dir t} {
	global texi curwin

	set manx(hv$curwin) texitop; # for last scroll position

	eval $t insert end [texiDatabase $dir]

	if {[info exists texi(texinfo,form)]} {
		set cnt 0
		foreach f $texi(texinfo,paths) {
			$t tag bind js$cnt <Button-1> "set manx(hotman$t) $f"
			incr cnt
		}
	}
}


# search with GNU grep, map back to Texinfo source, fault in and format.  So slow first time,
# but get results in context, so much better than usual info one-at-a-time
# If all sections already faulted in, skip grep.
# would like to show search hits as they are found
proc texiSearch {w} {
	global man manx texiback texi
	set MAXSECT 10

	if {$man(gzgrep) eq ""} return
	set t $w.show
	upvar #0 texiback$t texiback texix$t texix

	set pat $manx(search,string$w)
	if {[string trim $pat] eq ""} return
#	if {$texi(sectcnt)==0} {
#		# all sections loaded; don't have to search on disk
#	=>	# how to make visible all sections headers with hits?  regular search should do this
#		return 
#
#	} else
	if {$pat ne $texi(lastsearch$t)} {
		# Showing hits in text already faulted in.  to search all text (on disk) search again with same pattern.  unfortunately, first quick search is slow as fault in indexes
		foreach sect $texi(printindex) { texiFault $t $sect }
		after 1000 "manWinstdout $w {Index and header search done; search again for full search.}"

		set texi(searched$t) 0
		set texi(lastsearch$t) $pat

		return

	} elseif {$texi(searched$t)} {
		set secthits $texi(lasthits$t)

	} else {

		set ignorecase ""; if {[string is lower $pat]} {set ignorecase "i"}
		cd [file dirname $manx(manfull$w)]

		cursorBusy
		set secthits {}
		if {[catch {set hits [eval exec $man(gzgrep) -b$ignorecase $pat $texiback(filez) 2>/dev/null]} errinfo]} {
			manWinstderr $w "ERROR: $errinfo"
			return -code break
		}

		set lasthit ""
		foreach hit [split $hits "\n"] {
			regexp {(([^:]+):)?(\d+)} $hit all junk file b; zapZ! file
			if {$file eq ""} {set file [lfirst $texiback(filez)]}; # only one file so grep doesn't report filename
			set lastsect ""
			foreach pair $texiback($file) {
				foreach {sect s} $pair break
				if {$s>$b} {
					if {$lastsect ne "" && $lastsect ne $lasthit} {lappend secthits $lastsect}
					set lasthit $lastsect
					break
				}
				set lastsect $sect
			}
		}
		cursorUnset
		set texi(searched$t) 1
	}
	set texi(lastsearch$t) $pat; set texi(lasthits$t) $secthits

	set newsecthits {}; foreach sect $secthits {if {$texix($sect) ne ""} {lappend newsecthits $sect}}

	# always show hit's enclosing section
	after 100 "foreach sect [list $secthits] {$t tag add $man(search-show) \"\$sect linestart\" \"\$sect lineend\"}"

	foreach sect [lrange $newsecthits 0 $MAXSECT] {texiFault $t $sect}
	if {[llength $newsecthits]>$MAXSECT} {
		manWinstderr $w "Too many matches.  Showing many; search again to see more."
		set manx(search,oldstring$w) ""; # so can keep searching for same thing and getting KWIC soon enough
	}
}

# refs can be name of node or entry in index.  
# (LATER? or error, in which case search pattern match on names)
proc texiXref {t} {
	global texi
	foreach per $texi(persistent) {upvar #0 ${per}$t $per}

	set sect ""

	set ref [string trim [eval $t get [$t tag prevrange texixref current]]]
	if {[info exists texinode($ref)]} {
		set sect $texinode($ref)
	} else {
#puts "\a$ref"
		# get index group
		set inxes [array names texiindex]
		for {set mark current} {$mark ne ""} {set mark [$t mark previous $mark]} {
			if {[lsearch -exact $inxes $mark]!=-1} break
		}
		if {$mark eq ""} return; # fail
#puts "mark = $mark"

		# now count forward until get to entry
		set centry [lfirst [$t tag prevrange texixref current+1c]]; set cmark [$t index $mark]
		foreach {now next} [$t tag nextrange texixref $cmark] break
		for {set off 0} {$now ne $centry} {incr off} {
			foreach {now next} [$t tag nextrange texixref $next+1c] break
		}
#puts "off = $off"

		set sect [lsecond [lindex $texiindex($mark) $off]]
#puts "sect = $sect"
	}


#	if {$sect eq ""} { fuzzy(?) search on headings }

	if {$sect ne ""} {
#puts "hit: $sect"
		searchboxKeyNav C space 0 $t; # so C-x goes back to start
		manOutline $t 0 $sect
	}
}


proc texiClear {dir} {
	global manx
	catch {eval file delete -force [glob $dir/*.{texi,texinfo}$manx(zoptglob)]}
}
