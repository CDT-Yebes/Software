REM !/bin/sh
set path=%path%;..\..\..\win32-bin
SET MICORC=NUL
REM  run Micod
del /f /q micod.ref Bank.ref
start micod --forward --ior micod.ref
pause 2

REM  Add imr info
imr -ORBImplRepoIOR file://%CD%/micod.ref create Bank poa server IDL:Bank:1.0

imr -ORBImplRepoIOR file://%CD%/micod.ref activate Bank
pause 2

REM  run client
.\client
pause 1
