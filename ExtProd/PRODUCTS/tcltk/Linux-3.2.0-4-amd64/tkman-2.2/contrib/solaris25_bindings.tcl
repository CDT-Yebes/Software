# volume titles for Solaris 2.5 and 2.5.1
# written by Peter Dyballa (pete@thi.informatik.uni-frankfurt.de)
# on October 10 1997.
#
# With its default settings TkMan collects all volumes starting
# with the same character under a single section (for instance,
# 1, 1b, 1c, 1f, 1m and 1s are all collected under section 1).
# If multiple volumes share the same initial character
# in their man(manList) abbreviation, these
# sections are separated out in the Volumes menu.  The settings
# below separate out all volumes for Solaris 2.5 and 2.5.1.

# New users (those without ~/.tkman startup files) pick up these
# settings automatically.  The settings can also be interpolated
# into an existing startup file manually.

 
set man(manList) {1 1b 1c 1f 1m 1s 2 3 3b 3c 3e 3g 3i 3k 3m 3n 3r 3s
                  3t 3x 4 4b 5 6 7 7d 7fs 7i 7m 7p 9 9e 9f 9s l n}
set man(manTitleList) {
        "User Commands" "BSD Compat Commands" Communications
        "FMLI Commands" "Maintenance Commands" "SunOS Specific Commands"
	"System Calls" Subroutines "BSD Subroutines" "Standard C Library"
        "ELF Subroutines" "Regexp Subroutines" "Intl Subroutines"
        "Kvm Subroutines" "Math Subroutines" "Networking Subroutines" 
        "Realtime Subroutines" "Standard I/O Subroutines"
        "Threads Subroutines" "Specialized Subroutines" "File Formats"
        "plot graphics interface" "Headers, Tables, and Macros"
        "Games and Demos" "Devices/Special Files" "STREAMS/Device Drivers"
        "SunOS File Systems" ioctl "STREAMS modules" "Network Protocols"
        "DDI/DKI (Device Drv Interfaces)" "DDI/DKI Entry Points"
        "DDI/DKI Kernel Functions" "DDI/DKI Data Structures" Local New
}

set man(subsect) -b
