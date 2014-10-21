@rem Params are:
@rem %1 = VC,VCE, VSE (Exception type)
@rem %2 = debug, delease (Target)
set VER=2

set buildtype=%1
set target=%2
set empty=

@rem default is VC release

set shorttarget=

if  "%buildtype%" == ""  (
set buildtype=VC
)

if /i "%target%" == "debug"  (
set target=-debug
set shorttarget=d
@echo Build Debug target
) else (
set target=
set shorttarget=
@echo Build Release target
)

@echo Checking and building (if necessary) PThreads for %buildtype% exception type and %target% build

set name=pthread%buildtype%%VER%%shorttarget%
echo Building  %name%


@if NOT EXIST win32-bin\%name%.dll goto print1
@if NOT EXIST win32-bin\lib\%name%.lib goto print2

@echo DLLs and LIBs found. PThreads usage is enabled

@goto end

:print1
@echo The file win32-bin\%name%.dll was not found
goto build

:print2
@echo  The file win32-bin\lib\%name%.lib was not found
goto build

:build
	@cd contrib\pthreads

	@rem Adapt the line below for your VSTUDIO version
	@rem or use devenv instead of nmake to include manifests automatically in vc8



	@nmake clean %buildtype%%target%
	@IF EXIST "%VS80COMNTOOLS%vsvars32.bat" (
	mt.exe -manifest %name%.dll.manifest -outputresource:%name%.dll;#1

	)

	@copy %name%.dll ..\..\win32-bin
	@copy %name%.lib ..\..\win32-bin\lib
	@cd ..\..

@echo #AUTOMATICALLY GENERATED FILE. DO NOT MODIFY > makevars.win32.pth
@echo #Library files were installed in win32-bin and win32-bin\lib. >> makevars.win32.pth
@echo #>> makevars.win32.pth

@echo HAVE_PTHREADS = 1 >> makevars.win32.pth
@echo HAVE_THREADS = 1 >> makevars.win32.pth
@echo #>> makevars.win32.pth
@echo #Exception model>> makevars.win32.pth
@echo HAVE_PTHREADS_%1 = 1 >> makevars.win32.pth


:end
@