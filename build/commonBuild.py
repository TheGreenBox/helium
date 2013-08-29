#!/bin/env python
#-*- utf-8 -*-

#---------------------------------------
import os
import sys
import string
import shutil
#---------------------------------------

rootScriptName = os.path.abspath(os.path.dirname(__file__))
buildToolsDir = os.path.normpath(rootScriptName+'/../tools/buildTools/python')

if buildToolsDir not in sys.path:
    sys.path.append(buildToolsDir)
import heliumbuildtools
#---------------------------------------

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
 

header = \
    '------------------------------------------------------------\n'+\
    '\tHelium buld : buildType      : '+ buildType+'\n'+\
    '\tHelium buld : cmakeGenerator : '+ cmakeGenerator+'\n'+\
    '\tHelium buld : platform       : '+ targetPlatform+'\n'+\
    '------------------------------------------------------------\n'
print('\n')
print(header)

sandboxDir = rootScriptName + '/product'

if not os.path.isdir(sandboxDir):
    os.mkdir(sandboxDir)

buildDir = sandboxDir + '/' + buildType

if os.path.isdir(buildDir):
    shutil.rmtree(buildDir)
os.mkdir(buildDir)

log_file = open(buildDir+'/Heluim_'+buildType+'_build.log', 'w')
log_file.write(header)
log_file.write('\n')

os.chdir(buildDir)

heliumbuildtools.cmakeGenerate( buildType, cmakeGenerator, '../../..',[''], log_file )
heliumbuildtools.buildProject( buildType, log_file )
heliumbuildtools.installProject( buildType, log_file )

log_file.close()

os.chdir(rootScriptName)

