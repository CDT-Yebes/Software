@echo off
@rem
@rem This script is intended to be used to build MICO from
@rem environments where it is not possible to invoke
@rem Visual Studio command-line directly (i.e. buildbot)
@rem
@rem The first parameters is a batch file which sets all
@rem appropriate environment variables (i.e. vsvars32.bat)
@rem Other parameters are then sent to nmake directly
@rem
@echo setup script is %1
call %1
nmake /f Makefile.win32 %2 %3 %4 %5 %6 %7
