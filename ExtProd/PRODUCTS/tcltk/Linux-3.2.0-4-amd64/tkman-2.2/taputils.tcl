#
# some functions which should be part of Tcl, but aren't
#
# Tom Phelps (phelps@ACM.org)
#


#
# UNIXish
#

# like find, but just for -name <pattern> for now
# could have signature of find <dir> <expr w/file(xxx) as returned by Tcl's file stat, with fast path for just name>
# why not just exec find?  sidestep exec, available on non-UNIX, standardizes options
# symbolic links always followed

# tests: <, =, >, <=, >=, !=  on "depth" and "file" variables, and "f()" array of "file stat <file>"
# fields of f: atime, ctime, dev, gid, ino, mode, mtime, nlink, size, type, uid
# refer to file(n)/file stat
# always have to do a stat so know what the directories are (sigh)

set findx(matches) {}
set findx(expr) {}
set findx(rexpr) {}
set findx(seen) 0
# starting directory, expression to match, expression for recurse
# e.g., find . *.txt
#       find /usr/sww/doc/RFC {[string match rfc*.txt $file]} {[llength $findx(matches)]==0 || $depth>3}
proc findfile {dir filepattern} {
	find $dir [subst -nocommands {[string match $filepattern \$file]}]
}
#proc fib {depth} { find / {[regexp {^s?bin$} $f(tail)]} "\$depth<=$depth" }
#proc fim {depth} { find / {[regexp {^s?man$} $f(tail)]} "\$depth<=$depth" }
# terrible bug if depth<=3 or 4 -- Tcl's fault?
proc find {dir expr {rexpr 1}} {
	global findx
	set olddir [pwd]

	set findx(matches) {}
	set findx(expr) $expr
	set findx(rexpr) $rexpr
	set findx(seen) 0
	# can handle time elapsed in "user space"
#	cd [file dirname $dir]
	find1 $dir 0 $olddir

#	cd $olddir
	return $findx(matches)
}

proc find1 {dir depth updir} {
	global findx

	# matches in current directory
#puts "$findx(rexpr) => [expr $findx(rexpr)]"
	if {$findx(rexpr) eq ""} return
#puts "[llength $findx(matches)], $depth"
#	if {$dir ne "/" && [catch {cd [file tail $dir]}]} return
#puts [expr {$dir ne "/" && [catch {cd $dir}]}]
	if {[catch {cd $dir}]} return
#	set curdir [pwd]
	set f(dir) $dir
	foreach file [glob -nocomplain *] {
		incr findx(seen)
		#if {[pwd] ne $curdir} {cd $curdir}
		if {[catch {file lstat $file f}]} continue
		set subupdir ..; if {$f(type) eq "link" && [file isdirectory $file]} {set f(type) "directory"; set subupdir [pwd]}
		set f(tail) $file
		set relpath [file join $dir $file]
#puts "$findx(expr) => [expr $findx(expr)] ($file in $dir)"
		# no brackets around $findx(expr)
#puts "$findx(expr), file=$file => [subst $findx(expr)]"
		if {[subst $findx(expr)]} {lappend findx(matches) $relpath}

		# matches in subdirectories
		if {[file isdirectory $relpath]} {
			foreach match [find1 $relpath [expr {$depth+1}] $subupdir] {lappend findx(matches) $match}
		}
	}
#	cd ..; # weird symbolic links sometimes so [pwd]!=$curdir kludge above
#if {$updir ne ".."} {puts "$dir up to $updir"}
	cd $updir
}


# pipeexp - expand file names in a pipe
proc pipeexp {p} {
	set p [string trim $p]

	set expp ""
	foreach i $p {
		if {[regexp {^[.~/$]} $i]} {lappend expp [fileexp $i]} \
		else {lappend expp $i}
	}
	return $expp
}

proc assert {bool msg {boom 0}} {
	if {!$bool} {
		puts stderr $msg
		if {$boom} {exit 1}
	}
}

# fileexp perform file spec expansion: ~ . .. $
proc fileexp {f} {
	global env

	set f [string trim $f]
	set l [string length $f]
	set expf ""

	set dir [pwd]
	foreach i [split $f "/"] {
#puts "$dir | $expf + $i"
		switch -glob $i {
			"" {set dir ""}
			{[A-Za-z]:} {set dir "$i"}
			~  {set dir $env(HOME)}
		 $* {set val $env([string trim [string range $i 1 end] ()])
				 if {[string match /* $val]} {set dir $val} else {append expf /$val)}}
			.  {set dir $dir}
	 .. {set dir [file dirname $dir]}
	 default {append expf /$i}
		}
	}

	return $dir$expf
}


# in:  f = (partial) file name
# out:   "" (NULL) if no matches
#        full name if exactly one match
#        list      w/first==longest match, if multiple matches

# on /usr/sww/, Tcl's file tail returns sww -- want ""
proc filetail {f} {
	set tail [file tail $f]
	if {[string match */ $f]} {set tail ""}
	return $tail
}
proc filedirname {f} {
	set dirname [file dirname $f]
	if {[string match ?*/ $f]} {set dirname [string range $f 0 [expr {[string length $f]-2}]]}
	return $dirname
}

proc filecomplete {f} {
	set expf [fileexp [filedirname $f]]/[filetail $f]
	set posn [string last [filetail $f] $f]; if {[string match */ $f]} {set posn [string length $f]}
	#if [string match */ $f] {set expf $f; set tail ""; set posn [string length $f]}
#puts "$posn, expf=$expf"
	set l [glob -nocomplain $expf*]
	set ll [llength $l]

	if {!$ll} {
		# maybe indicate that partial name not good
		set tail ""
	} elseif {$ll==1} {
		set tail [file tail $l]
		if {[file isdirectory $l]} {append tail /}
	} else {
		# determine the longest common prefix
		set lf [lfirst $l]; set lfl [string length $lf]
		set last $lfl
		set ni [expr {[string last / $lf]+1}]
		foreach i $l {
			for {set j $ni} {$j<=$last} {incr j} {
				if {[string index $lf $j] ne [string index $i $j]} break
			}
			set last [min $last [expr {$j-1}]]
		}
		set tail [filetail [string range [lfirst $l] 0 $last]]
	}

#puts "$ll, $tail"
	# compose original directory specification with (possibly) new tail
	if {$posn>0 && $ll} {
		# can't use dirname because it expands ~'s
		set tail [string range $f 0 [expr {$posn-1}]]$tail
	}

	if {$ll<2} {return $tail} else {return "$tail $l"}
}


proc tr {s c1 c2} {
#	regsub -all \\$c1 $s $c2 s2
	regsub -all "\[$c1\]" $s $c2 s2
	return $s2
}

# reverse glob
#    pass expanded filename, list of shortenings
#set file(globList) ~
proc bolg {f {l ""}} {
	if {$l eq ""} {global file; set l $file(globList)}

	foreach i $l {
		if {[regsub ([glob -nocomplain $i])(.*) $f "$i\\2" short]} {return $short}
	}
	return $f
}


proc setinsert {l i e} {
	return [linsert [lfilter $e $l] $i $e]
}
# short enough to just inline: if [lsearch $l $e]==-1 {lappend $l $e}
#proc setinsert {l e} {
#   if {[lsearch $l $e]==-1} {
#      return [lappend $l $e]
#   } else {
#      return $l
#   }
#}


proc unsplit {l c} {
	foreach i $l {
		append l2 $i $c
	}
#   return [string trimright $l2 $c]
	return [string range $l2 0 [expr {[string length $l2]-2}]]
}

proc bytes2prefix {x} {
	set pfx {bytes KB MB GB TB QB}
	set k 1024.0
	set sz $k

	if {$x<$k} {return "$x bytes"}

	set y BIG
	for {set i 0} {$i<[llength $pfx]} {incr i} {
		if {$x<$sz} {
			return [format " %0.1f [lindex $pfx $i]" [expr {$x/($sz/$k)}]]
		}
		set sz [expr {$sz*$k}]
	}
}



#
# Lispish
#

# unfortunately, no way to have more-convenient single quote form
proc quote {x} {return $x}

# should sort beforehand
proc uniqlist {l} {
	set e ""
	set l2 ""
	foreach i $l {
		if {$e ne $i} {
			lappend l2 $i
			set e $i
		}
	}
	return $l2
}


proc min {args} {
	if {[llength $args]==1} {set args [lindex $args 0]}
	set x [lindex $args 0]
	foreach i $args {
		if {$i<$x} {set x $i}
	}
	return $x
}

proc avg {args} {
	set sum 0.0

	if {[string $args ""]} return
	
	foreach i $args {set sum [expr {$sum+$i}]}
	return [expr {($sum+0.0)/[llength $args]}]
}

proc max {args} {
	if {[llength $args]==1} {set args [lindex $args 0]}
	set x [lindex $args 0]
	foreach i $args {
		if {$i>$x} {set x $i}
	}
	return $x
}


proc lfirst {l} {return [lindex $l 0]}
proc lsecond {l} {return [lindex $l 1]}
proc lthird {l} {return [lindex $l 2]}
proc lfourth {l} {return [lindex $l 3]}
# five is enough to get all pieces of `configure' records
proc lfifth {l} {return [lindex $l 4]}
proc lsixth {l} {return [lindex $l 5]}
proc lseventh {l} {return [lindex $l 6]}
proc lrest {l} {return [lrange $l 1 end]}

proc llast {l} {
	return [lindex $l end]
}

proc setappend {l e} {
	return "[lfilter $e $l] $e"
}

# filter out elements matching pattern p from list l
proc lfilter {p l} {
	set l2 ""

	foreach i $l {
		if {![string match $p $i]} "lappend l2 [list $i]"
	}
	return $l2
}

# keep elements matching pattern p in list l
proc lmatches {p l} {
	set l2 ""
	foreach i $l { if {[string match $p $i]} {lappend l2 [list $i]} }
	return $l2
}

proc lassoc {l k} {
	foreach i $l {
		if {[lindex $i 0]==$k} {return [lrange $i 1 end]}
	}
	return ""
}

# (ab)use foreach <var-list> <val-list> {}
#proc lset {l args} {
#	foreach val $l var $args {
#		upvar $var x
#		set x $val
#	}
#}

# like lassoc, but search on second element, returns first
proc lbssoc {l k} {

	foreach i $l {
		if {[lindex $i 1]==$k} {return [lindex $i 0]}
	}
	return ""
}

proc lreverse {l {block 1}} {
	set lrev {}
	for {set i [expr {[llength $l]-$block}]} {$i>=0} {incr i -$block} {
		lappend lrev [lrange $l $i [expr {$i+$block-1}]]
	}
	set flatten [eval concat $lrev]
	return $flatten
}


#
# X-ish
#

proc geom2posn {g} {
	if {[regexp {(=?\d+x\d+)([-+]+\d+[-+]+\d+)} $g both d p]} {
		return $p
	} else { return $g }
}

proc geom2size {g} {
	if {[regexp {(=?\d+x\d+)([-+]+\d+[-+]+\d+)} $g both d p]} {
		return $d
	} else { return $g }
}



#
# Tcl-ish
#


# translate ascii names into single character versions
# this should be a bind option

set name2charList {
	minus plus percent ampersand asciitilde at less greater equal
	numbersign dollar asciicircum asterisk quoteleft quoteright
	parenleft parenright bracketleft bracketright braceleft braceright
	semicolon colon question slash bar period underscore backslash
	exclam comma
}

proc name2char {c} {
	global name2charList

	if {[set x [lsearch $name2charList $c]]!=-1} {
		 return [string index "-+%&~@<>=#$^*`'()\[\]{};:?/|._\\!," $x]
	} else {return $c}
}

# 0=none="", 1=Shift=S, 2=Alt?, 4=Ctrl=C, 8=meta=M, 16=Alt?, 32=Alt or NumLock, 64=NumLock
proc key_state2mnemon {n} {
	set mod ""

#	set trans "SLCMAAN"
	set trans "S CMA  "; # ignore spaced modifiers

	for {set bp 0} {$bp<[string length $trans]} {incr bp} {
		set t [string index $trans $bp]
		if {$t ne " " && $n&(1<<$bp)} {append mod $t}
	}

	return $mod
}

proc lmatch {mode list {pattern ""}} {
	if {$pattern eq ""} {set pattern $list; set list $mode; set mode "-glob"}
	return [expr {[lsearch $mode $list $pattern]!=-1}]
}


# remove all char c from string s

proc stringremove {s {c " "}} {
	regsub -all -- \\$c $s "" s2
	return $s2
}


# backquote all regular expression meta-characters
proc stringregexpesc {s} { 
	return [stringesc $s {\||\*|\+|\?|\.|\^|\$|\\|\[|\]|\(|\)|\-}]
# try this:	return [stringesc $s {[][|*+?.^$\\()-]}]
#	return [stringesc $s {[\|\*\+\?\.\^\$\\\[\]\(\)\-]}]
}
# backquote Tcl meta-characters
#proc stringesc {s {c {\\|\$|\[|\{|\}|\]|\"}}} {
proc stringesc {s {c {[][\\\${}"]}}} {
	regsub -all -- $c $s {\\&} s2
	return $s2
}


proc tk_listboxNoSelect args {
	 foreach w $args {
		  bind $w <Button-1> {format x}
	bind $w <B1-Motion> {format x}
	bind $w <Shift-1> {format x}
	bind $w <Shift-B1-Motion> {format x}
	 }
}

# could do with "listbox select&highlight pattern"

proc listboxshowS {lb s {first 0} {cnstr yes}} {
	set sz [$lb size]

	for {set i $first} {$i<$sz} {incr i} {
		if {[string match $s [$lb get $i]]} {
			listboxshowI $lb $i $cnstr
			return $i
		}
	}
	return -1
}

proc listboxshowI {lb high {cnstr yes}} {
#   if {$high>=[$lb size] || $high<0} return
	set high [max 0 [min $high [expr {[$lb size]-1}]]]

	set hb [lindex [split [$lb cget -geometry] x] 1]
	set hx [max 0 [expr {[$lb size]-$hb}]]
	if {$cnstr eq "yes"} {set hl [expr {$high<$hb?0:[min $high $hx]}]} else {set hl $high}
	$lb select from $high
	$lb yview $hl
}

proc listboxreplace {lb index new} {
	$lb delete $index
	$lb insert $index $new
	# don't lose selection
	$lb select from $index
}


# preserves selection, yview

proc listboxmove {l1 l2} {
	listboxcopy $l1 $l2
	$l1 delete 0 end
}

proc listboxcopy {l1 l2} {

	$l2 delete 0 end
	listboxappend $l1 $l2
	catch {$l2 select from [$l1 curselection]}
# use NEW yview to keep same yview position
#   catch {$l2 yview [$l1 yview]}
}

proc listboxappend {l1 l2} {

	set size [$l1 size]

	for {set i 0} {$i<$size} {incr i} {
		$l2 insert end [$l1 get $i]
	}
}

###

#option add *Entry.relief sunken
#option add *Text.relief sunken
option add *Text.borderwidth 2
#option add *Menubutton.relief raised
#option add *Radiobutton.relief ridge
#option add *Radiobutton.borderwidth 3
#option add *Checkbutton.relief ridge
#option add *Button.relief ridge
#option add *Button.borderwidth 3

###


proc tabgroup {args} {
	if {[llength $args]==1} {set wins [lindex $args 0]} else {set wins $args}

	set l [llength $wins]
	for {set i 0} {$i<$l} {incr i} {
		set w [lindex $wins $i]
		set pw [lindex $wins [expr {($i-1)%$l}]]
		set nw [lindex $wins [expr {($i+1)%$l}]]

		bind $w <KeyPress-Tab> "focus $nw; break"
		bind $w <Shift-KeyPress-Tab> "focus $pw; break"
	}
}


proc winstderr {w msg {type "bell & flash"}} {
	if {![winfo exists $w]} return
	set bell [string match "*bell*" $type]
	set flash [string match "*flash*" $type]
#	regsub -all "\n" $msg " // " msg

	set fg [$w cget -foreground]; set bg [$w cget -background]

	set msgout [string range $msg 0 250]
	if {[string length $msg]>250} {
		append msgout " ... (truncated; full message sent to stdout)"
		puts stderr $msg
	}
	winstdout $w $msgout
	if {$flash} {$w configure -foreground $bg -background $fg}
	if {$bell} bell
	if {$flash} {
		update idletasks; after 500
		$w configure -foreground $fg -background $bg
	}
}

proc winstdout {w {msg AnUnLiKeMeSsAgE} {update 0}} {
	if {![winfo exists $w]} return
	if {$update eq "update"} {set update 1}

	if {$msg ne "AnUnLiKeMeSsAgE"} {
		$w configure -text $msg
		if {$update} { update idletasks }
	}
	return [$w cget -text]
}

proc yviewcontext {w l c} {
	if {$l eq "sel"} {
		set cnt [scan [$w tag ranges sel] %d l]
		if {$cnt<=0} return
	}

	incr l -1; # 0-based!

	scan [$w index end] %d n
	set prev [expr {$l-$c}]; set next [expr {$l+$c}]

	if {$prev>=0} {$w yview -pickplace $prev}
	if {$next<=$n} {$w yview -pickplace $next}
	$w yview -pickplace $l
}


proc screencenter {xy wh} {
	if {$xy eq "x"} {
		return [expr {([winfo screenwidth .]-$wh)/2}]
	} else {
		return [expr {([winfo screenheight .]-$wh)/2}]
	}
}

# this doesn't work
#button .a -cursor watch
#proc cursorBusy {} {
#   focus .a; grab .a
#}
#
#proc cursorUnBusy {} {
#   global win
#   grab release .a; focus \$win.list
#}

proc cursorBusy {{up 1}} {
	if {[. cget -cursor] ne "watch"} {
		cursorSet watch; if {$up} {update idletasks}
	}
}
proc cursorSet {c {w .}} {
	global cursor
#if {$w eq "."} {puts "cursorSet"}
	set cursor($w) [$w cget -cursor]
#puts "cursor($w) = $cursor($w)"
	$w configure -cursor $c
	foreach child [winfo children $w] {cursorSet $c $child}
}
proc cursorUnset {{w .}} {
	global cursor
#if {$w eq "."} {puts "cursorUnset"}
	catch {$w configure -cursor $cursor($w)}
	foreach child [winfo children $w] {cursorUnset $child}
}

proc configurestate {wins {flag "menu"}} {
	set flag0 $flag
	foreach w $wins {
		set flag $flag0
		if {$flag eq "menu"} {
			if {[winfo class $w] eq "Menubutton"} {
				set m [$w cget -menu]; set end [$m index end]
				set flag [expr {$end ne "none" && (![$m cget -tearoff] || $end>0)} ]
			} else { set flag 0 }
		}
		$w configure -state [expr {$flag?"normal":"disabled"}]
	}
}

# Tk-related

# singleton menu
proc smenu {m args} {
	if {![winfo exists $m]} {eval menu $m $args}
	return $m
}
