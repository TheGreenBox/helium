@echo ------------------------------------------------------
@echo Removing build/product directory
@echo ------------------------------------------------------
@echo.

@set folderToDelete=product

@if Exist "%folderToDelete%\*.*" (
    @rd /s /q product
    @echo All done!
) Else (
    @Echo Folder %folderToDelete% does not exist, nothing to clean!
)
