@echo ------------------------------------------------------
@echo Removing build/product directory
@echo ------------------------------------------------------
@echo.

@set folderToDelete=product

:while1
@if Exist "%folderToDelete%\*.*" (
	@rd /s /q product
    @echo Deleting "%folderToDelete%" folder, please wait...
	@sleep 2
	@goto :while1
) Else (
    @Echo "%folderToDelete%" folder was successfully deleted!
)