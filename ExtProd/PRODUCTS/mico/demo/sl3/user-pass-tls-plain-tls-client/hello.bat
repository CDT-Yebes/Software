REM !/bin/sh
set path=%path%;..\..\..\win32-bin
SET MICORC=NUL
REM  run Server
del /f /q hello.ref
start .\server -ORBSL3 -ORBCSIv2
pause 2


REM  run client
.\client -ORBSL3

