REM !/bin/sh
set path=%path%;..\..\..\win32-bin
SET MICORC=NUL

REM run nsd
del /f /q NameService-root.inf
start nsd -ORBIIOPAddr inet:localhost:12456
pause 2

REM  run Server
del /f /q hello.ref
start .\server -ORBSL3 -ORBInitRef NameService=corbaloc::localhost:12456/NameService
pause 2


REM  run client
.\client -ORBSL3  -ORBInitRef NameService=corbaloc::localhost:12456/NameService

