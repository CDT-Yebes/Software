#
# ButtonMenubutton
#    act like a button for quick clicks
#    act like a menu if hold down button
#
# 1997 July 22 by Tom Phelps (phelps@ACM.org),
#    on top of Tk's button and menubutton bindings
# 2003 March 12 updated for Tk 8.4 (tkPriv => ::tk::Priv)
#

# To use, create a menubutton and pass it and the command to execute
#    if it's invoked as a button to the proc "buttonmenubutton"
#
# To convert to button-only operation,
#    <widget-name> configure -menu ""
# To convert to menu-only operation,
#    set bmb(<widget-name>) to ""
# If you save the former value, you can reverse these conversions
#    by restoring the former values.
# If you disable the original menubutton, both button and menubutton
#    behaviors are disabled.


set bmb(menubutton-delay) 250
set bmb(type) ""
set bmb(after) ""
set bmb(relief) ""
set bmb(w) ""
set bmb(x) ""; set bmb(y) ""
#set bmb(<widget-name>) <button-command>

proc buttonmenubutton {mb {cmd ""}} {
	global bmb

	if {[winfo class $mb] ne "Menubutton"} {error "$mb must be a menubutton"}

	# store commands
	set bmb($mb) $cmd

	# on Button-1, assume it's a click, correct later according to timer
	bind $mb <Button-1> {if [catch {bmbB1Down %W %X %Y}] break}
	bind $mb <B1-Motion> {if {$bmb(type) eq "button"} break}
	bind $mb <ButtonRelease-1> {if [catch {bmbB1Up %W}] break}
}

proc bmbB1Down {w x y} {
	global bmb

	# would be nice if break and continue could be thrown as exceptions
	# to be recognized in bindings
	if {$::tk::Priv(postedMb) ne ""} {::tk::MbButtonUp $w; return -code break}
	if {$bmb(type) ne ""} {return -code break}

	set bmb(w) $w; set bmb(relief) [$w cget -relief]
	set bmb(x) $x; set bmb(y) $y

	# if no command, treat as a menu straight away
	if {$bmb($w) eq ""} {set bmb(type) ""; return}; # continue with menubutton bindings

	# pretend you're a button at first
	set bmb(type) "button"
	catch {[::tk::ButtonDown $w]}; # brute force: -repeatdelay on button only not menubutton
	# if have a menu, possibility of converting to menubutton operation
	if {[$w cget -menu] ne "" && [[$w cget -menu] index end] ne "none"} {
		set bmb(after) [after $bmb(menubutton-delay) bmbConvert]
	}
	return -code break
}

proc bmbB1Up {w} {
	global bmb

	if {$bmb(type) eq "button"} {bmbButtonUp $w} else {::tk::MbButtonUp $w}
	# clean up for button
	set bmb(type) ""
	if {$bmb(after) ne ""} {after cancel $bmb(after)}
	set bmb(after) ""
	$bmb(w) configure -relief $bmb(relief)
	return -code break
}

proc bmbConvert {} {
	global bmb

	# if already finished as button, we're done
	if {$bmb(type) eq ""} return
	set ::tk::Priv(buttonWindow) ""; # clean up
	set bmb(after) ""

	$bmb(w) configure -relief $bmb(relief)
	set bmb(type) ""; # give control over to the menu system
	set ::tk::Priv(inMenubutton) $bmb(w)
	::tk::MbPost $bmb(w) $bmb(x) $bmb(y)
	$bmb(w) configure -relief sunken; # that's how Netscape does it
}

proc bmbButtonUp {w} {
	global bmb

	if {$w eq $::tk::Priv(buttonWindow)} {
		set ::tk::Priv(buttonWindow) ""
		if {[$w cget -state] ne "disabled"} {
			uplevel #0 $bmb($w)
		}
	}
}
