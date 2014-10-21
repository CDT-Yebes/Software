REM !/bin/sh
set path=%path%;..\..\..\win32-bin
SET MICORC=NUL
REM  run Server
del /f /q hello.ref
start .\server -ORBThreadPool -ORBRequestLimit 100 -ORBConnLimit 1000
pause 2


REM  run client
.\client -ORBClientThreaded -ORBRequestLimit 20 -ORBConnLimit 30
.\client -ORBClientReactive -ORBRequestLimit 2 -ORBConnLimit 2
.\client -ORBClientThreadedBlocking -ORBRequestLimit 8 -ORBConnLimit 8

