@title helium for Win: bulding script
type ..\readme.md

call win_clean.bat

@echo ------------------------------------------------------
@echo Generating makefiles
@echo ------------------------------------------------------
@echo Creating product directory...

::@cd ../
@md product
@cd product
@md debug
@cd debug
@echo.

@echo ------------------------------------------------------
@echo CMAKE
@echo ------------------------------------------------------
@echo Please wait...
@cmake -G "Visual Studio 11" -DCMAKE_BUILD_TYPE=Debug ../../../ >> helium_build_log.txt
@echo.

@echo ------------------------------------------------------
@echo Building
@echo ------------------------------------------------------

@%SYSTEMROOT%\Microsoft.NET\Framework\v4.0.30319\msbuild.exe ALL_BUILD.vcxproj /t:Rebuild /p:Configuration=Debug /p:Platform=Win32 /nologo /fl /flp:logfile=helium_build_log.txt;verbosity=minimal;append=true;

@pause
