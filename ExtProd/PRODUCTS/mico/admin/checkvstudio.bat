@if EXIST "%VSINSTALLDIR%\Common7\Tools\vsvars32.bat" (

@echo This is VSTUDIO 2005
@echo #AUTOMATICALLY GENERATED FILE. DO NOT MODIFY >  vstudio.win32
@echo # >> vstudio.win32
@echo # This is for VSTUDIO 2005 >> vstudio.win32
@echo MT=mt.exe >> vstudio.win32
@echo MANIFEST=/manifest >> vstudio.win32
@echo VC8=1 >> vstudio.win32
@echo CXXVC=/D_CRT_SECURE_NO_DEPRECATE >> vstudio.win32

) else if EXIST "%VCINSTALLDIR%\Common7\Tools\vsvars32.bat" (

@echo This is VSTUDIO prior to version 2005
@echo #AUTOMATICALLY GENERATED FILE. DO NOT MODIFY >  vstudio.win32
@echo # >> vstudio.win32
@echo # This is for VSTUDIO prior to version 2005 >> vstudio.win32
@echo #VC8 symbol is not defined >> vstudio.win32
@echo MT= >> vstudio.win32
@echo MANIFEST= >> vstudio.win32
@echo CXXVC= >> vstudio.win32

)
