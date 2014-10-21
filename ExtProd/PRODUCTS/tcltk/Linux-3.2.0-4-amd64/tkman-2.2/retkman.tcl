#	re-tkman, suggested by Howard Moftich
#
#	kill if necessary, then restart TkMan
#	for use after changes to the MANPATH in the shell, as by a modules package

# kill old TkMen
set tkmen {}
foreach interp [winfo interps] {if {[string match "tkman*" $interp]} {lappend tkmen $interp}}

set cnt [llength $tkmen]
if {$cnt==1} {
	catch {send tkmen "manSave; exit 0"}
} elseif {$cnt>1} {
	# if multiple instantiations, find one on same machine
	set hostname [info hostname]
	foreach man $tkmen {
		if {[send $man info hostname] eq $hostname} {
			catch {send $man "manSave; exit 0"}
			break
		}
	}
}

# start a new one, with this script's MANPATH
exec tkman &

# exit this interpreter
exit 0
