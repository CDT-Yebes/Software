@echo Checking OpenSSL install

@if NOT EXIST win32-bin\libeay32.dll goto error
@if NOT EXIST win32-bin\lib\libeay32.lib  goto error
@if NOT EXIST win32-bin\ssleay32.dll  goto error
@if NOT EXIST win32-bin\lib\ssleay32.lib goto error


@echo Found SSL Libraries installed
@rem @admin\cntfiles.exe contrib\openssl\openssl 56

@if not exist contrib\openssl\openssl\objects.h goto error
@if not exist contrib\openssl\openssl\crypto.h goto error
@if not exist contrib\openssl\openssl\buffer.h goto error
@if not exist contrib\openssl\openssl\bio.h goto error
@if not exist contrib\openssl\openssl\ssl.h goto error
@if not exist contrib\openssl\openssl\x509.h goto error

@echo Found SSL header files installed
@goto end


:error
@echo OpenSSL libraries not found. MICO SSL support disabled
@echo #AUTOMATICALLY GENERATED FILE. DO NOT MODIFY > makevars.win32.ssl
@echo #No library files were found in win32-bin.Disabling OPENSSL build >> makevars.win32.ssl
@echo #>> makevars.win32.ssl
@echo #HAVE_SSL = 0 >> makevars.win32.ssl
@goto finish

:end
@echo MICO SSL support enabled
@echo #AUTOMATICALLY GENERATED FILE. DO NOT MODIFY > makevars.win32.ssl
@echo HAVE_SSL = 1 >> makevars.win32.ssl
@

:finish
@