#-*- utf-8 -*-

#---------------------------------------
import os
import sys
import string
import shutil
#---------------------------------------

header = \
    '------------------------------------------------------------\n'+\
    '\tHelium thirdparty build\n'+ \
    '\t * platform       : '+ sys.platform +'\n'+\
    '------------------------------------------------------------\n'
print('\n')
print(header)

rootScriptName = os.path.abspath(os.path.dirname(__file__))
buildToolsDir = os.path.normpath(rootScriptName+'/../../tools/buildTools/python')

if buildToolsDir not in sys.path:
    sys.path.append(buildToolsDir)
import heliumbuildtools

import polycodeBuild
import luaBuild

polycodeBuild.build('../polycode')
#luaBuild.build()

