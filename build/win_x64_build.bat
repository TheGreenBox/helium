@title helium for Win: bulding script
type ..\readme.md

call win_clean.bat

@echo ------------------------------------------------------
@echo Generating makefiles
@echo ------------------------------------------------------
@echo Creating product directory...

@cd ../
@md product
@cd product
@md debug
@cd debug
@echo.

cmake ../../
@echo.

@echo ------------------------------------------------------
@echo Building
@echo ------------------------------------------------------

@make

@pause