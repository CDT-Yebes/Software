REM !/bin/sh
set path=%path%;..\..\..\win32-bin
SET MICORC=NUL
REM  run Server
del /f /q hello.ref
start .\server thread-pool 100 1000
pause 2


REM  run client
.\client threaded 20 30
.\client reactive 2 2
.\client blocking-threaded 8 8
