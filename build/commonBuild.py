#-*- utf-8 -*-
#!/bin/env python


import sys
import string

argLen = len(sys.argv)

buildType = 'Debug'
cmakeGenerator = ''
targetPlatform = ''

for arg in sys.argv:
    print (arg)

    if arg == 'Release' or arg == 'Debug' or arg == 'release' or arg == 'debug':
        buildType = arg.title()

    elif arg == 'MSVC10' or arg == 'msvc10':
        cmakeGenerator = '-GVisual Studio 10'

    elif arg == 'MSVC11' or arg == 'msvc11':
        cmakeGenerator = '-GVisual Studio 11'

    elif arg == 'MSVC12' or arg == 'msvc12':
        cmakeGenerator = '-GVisual Studio 12'

    elif arg == 'make':
        cmakeGenerator = '-GUnix Makefiles'
    
    elif arg == 'x32' or arg == 'x64' or arg == 'X32' or arg == 'X64':
        targetPlatform = arg.lower()


if cmakeGenerator == '':
    if sys.platform == 'linux2':
        cmakeGenerator = '-GUnix Makefiles'
    elif sys.platform == 'win32':
        cmakeGenerator = '-GVisual Studio 11'
  
print( 'buildType:', buildType )
print( 'cmakeGenerator:', cmakeGenerator )
print( 'platform:', targetPlatform )

