#--------------------------------------------------
#
# check validity of MANPATH and set manx(paths)
#
#--------------------------------------------------

set manx(manpath-warnings) ""

proc manManpathCheck {} {
	global man manx env

	set manx(manpath-warnings) ""
	set manx(paths) {}
	set manpatherr ""
	set whatiserr 0
	set glimpseerr 0
	set glimpseuptodate 1
	set pass 0
	set homeman $env(HOME)/man
	set needmyman [expr {[file readable $homeman] && [llength [glob -nocomplain $homeman]]>0}]

	# would like to generate validity information for whatis, but
	# if it does exist, then that's OK (it's BSDI) and if it
	# doesn't that's OK (it's got a good whatis organization)

	# BSDI concatenates all whatis information into single file
	# share fBSDI with manualpage.tcl to find xxx.0 files
	set manx(fBSDI) [file readable [set whatis "/usr/share/man/whatis.db"]]
	set fDebian [expr {[file readable [set whatis "/usr/share/man/index.bt"]] || [file readable [set whatis "/var/cache/man/index.bt"]] || [file readable [set whatis "/usr/man/index.bt"]] || [file readable [set whatis "/var/catman/index.bt"]]}]
	# HPUX concatenates all whatis information into single file
	set fHPUX 0; if {!$manx(fBSDI) && !$fDebian} { set fHPUX [file readable [set whatis "/usr/lib/whatis"]] }


	# global checks
	if {[file exists $man(fsstnddir)] && ![file writable $man(fsstnddir)]} {
		append manx(manpath-warnings) "Backup cache directory $man(fsstnddir) not writable\n\n"
	}


	# per directory checks
	foreach root [split $manx(MANPATH0) $manx(pathsep)] {
		# canonicalize path
		# not a general solution, but expand some abbreviations
		if {$root eq "." || [string match "./*" $root] || [string match "../*" $root]} {
			# could expand relative paths, but that's not a good fit with the database ... maybe reconsider now ... no, people start TkMan from wherever and it wouldn't make sense to sometimes have extra paths
			append manpatherr "$root ignored -- relative paths are incompatible\n"
			continue
		}
#		if {$root eq "."} {set $root [pwd]}
		if {[string match "~*" $root]} {set root [glob -nocomplain $root]}
		if {[string trim $root] eq ""} continue

		if {[string match "/?*/" $root ]} {
			append manpatherr "$root -- spurious trailing slash character (\"/\")\n"
			# clean this one up and keep on going
			set root [string trimright $root "/"]
		}

		if {$root eq $homeman} {set needmyman 0}

		# validate
		if {$root eq "/"} {
			append manpatherr "$root -- root directory not allowed\n"
		} elseif {[lsearch $manx(paths) $root]>=0} {
			append manpatherr "$root -- duplicated path\n"
		} elseif {[set tmp [manPathCheckDir $root]] ne ""} {
			append manpatherr $tmp
		} elseif {![string match "*/catman" $root] && ![llength [glob -nocomplain $root/$manx(subdirs)]]} {
			# if nothing in that directory, something's probably wrong
			append manpatherr "$root -- no subdirectories matching $manx(subdirs) glob pattern\n"
			# directory too specific: a subdirectory?
			if {![string match "*/man" $root] && [llength [glob -nocomplain [file join [file dirname $root] $manx(subdirs)]]]} {
				append manpatherr "    => try changing it to [file dirname $root]\n"
			# or not specific enough?
			} elseif {[file exists [file join $root "man"]]} {
				append manpatherr "    => try changing it to $root/man\n"
			}

		# valid directory, check whatis, glimpse
		} else {
			# directory looks good, add it to list of valids
			lappend manx(paths) $root
			if {![info exists man($root)]} {set man($root) 1}
			lappend manx(pathstat) $man($root)
			set manx($root,latest) [lfirst [manLatestMan $root]]

			# check for apropos index (called windex on Solaris)
			if {!$manx(fBSDI) && !$fDebian && !$fHPUX} {
				if {![file exists [set whatis [file join $root "windex"]]]} {
					set whatis $root/whatis
				}
			}

			if {![file exists $whatis]} {
				append manpatherr "$root -- no `whatis' file for apropos\n"
				if {!$whatiserr} {
					append manpatherr "    => generate `whatis' with mkwhatis/makewhatis/catman\n"
					set whatiserr 1
				}
			} elseif {![file readable $whatis]} {
				# whatis set above
				append manpatherr "$whatis not readable\n"
			} elseif {[file mtime $whatis]<$manx($root,latest)} {
				append manpatherr "$whatis out of date\n"
			}

			# now check for Glimpse files
			if {$man(glimpse) ne ""} {
				set g $root; if {$man(indexglimpse) ne "distributed"} {set g $man(glimpsestrays)}
				set gi $g/.glimpse_index

				if {$man(indexglimpse) eq "distributed" || $pass==0} {
					if {![llength [glob -nocomplain "$g/.glimpse*"]]} {
						append manpatherr "$g -- no Glimpse support\n"
						if {!$glimpseerr} {
							append manpatherr "    => try building Glimpse database (under Occasionals)\n"
							set glimpseerr 1; set glimpseuptodate 0
						}
					} elseif {![file readable $gi]} {
						append manpatherr "$g -- Glimpse index exists but not readable\n"
					}
				}

				if {[file readable $gi] && [file mtime $gi]<$manx($root,latest)} {
						append manpatherr "$root -- Glimpse index out of date\n"
				}
			}
		}

		incr pass
	}

	if {$needmyman} {append manpatherr "~/man -- not in MANPATH, which is unusual\n"}
	if {$manpatherr ne ""} {
		append manx(manpath-warnings) "Problems in component paths of MANPATH environment variable...\n" $manpatherr "\n"
	}

	if {![llength $manx(paths)]} {
		if {$manx(manpath-warnings) ne ""} {puts stderr $manx(manpath-warnings)}
		puts stderr "NO VALID DIRECTORIES IN MANPATH!\a"
		exit 1
	}
}

proc manPathCheckDir {dir} {
	set warning ""

	if {![file exists $dir]} {
		set warning "doesn't exist"
	} elseif {![file isdirectory $dir]} {
		set warning "not a directory"
	} elseif {![file readable $dir]} {
		set warning "not readable\n    => check permissions"
	} elseif {![file executable $dir]} {
		set warning "not searchable (executable)\n    => check permissions"
	} elseif {![llength [glob -nocomplain $dir/*]]} {
		set warning "is empty"
	}

	if {$warning ne ""} {set warning "$dir -- $warning\n"}
	return $warning
}
