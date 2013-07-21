@echo ------------------------------------------------------
@echo Removing build/product directory
@echo ------------------------------------------------------
@echo.

@set folderToDelete=product

:while1
@if Exist "%folderToDelete%\*.*" (
	@rd /s /q product
    @echo Deleting "%folderToDelete%" folder, please wait...
	@timeout /T 2 /NOBREAK
	@goto :while1
) Else (
    @Echo "%folderToDelete%" folder was successfully deleted!
)