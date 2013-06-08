@title helium for Win: removing script
@echo Removing /product directory...
@echo . . .
@echo . .
@echo .

@set folderToDelete=..\product

@if Exist "%folderToDelete%\*.*" (
    @rmdir /s /q ..\product
    @echo All done!
) Else (
    @Echo Folder %folderToDelete% does not exist, nothing to clean!
)