#-*- utf-8 -*-

#---------------------------------------
import os
import sys
#---------------------------------------

rootScriptName = os.path.abspath(os.path.dirname(__file__))
buildToolsDir = os.path.normpath(rootScriptName+'/../../tools/buildTools/python')
if buildToolsDir not in sys.path:
    sys.path.append(buildToolsDir)
import heliumbuildtools

polycodeGitURL = 'https://github.com/TheGreenBox/Polycode.git'

def _polycode_dependencies_build_and_install( buildPath, buildType, log_file ):

    if sys.platform == 'linux2':
        heliumbuildtools.runCmd(['make'], log_file)

    elif sys.platform == 'win32':
        cmd = 'c:/Windows/Microsoft.NET/Framework'
        arg1 = 'ALL_BUILD.vcxproj'                   
        arg2 = '/p:Configuration='+buildType
        arg3 = '/nologo'
        heliumbuildtools.runCmd([cmd, arg1, arg2, arg3], log_file)
        arg1 = 'glext.vcxproj'                   
        heliumbuildtools.runCmd([cmd, arg1, arg2, arg3], log_file)
        arg1 = 'wglext.vcxproj'                   
        heliumbuildtools.runCmd([cmd, arg1, arg2, arg3], log_file)
    
    return

def _polycode_build_and_install( buildPath, buildType, log_file ):

    if sys.platform == 'linux2':
        heliumbuildtools.runCmd(['make'], log_file)

    elif sys.platform == 'win32':
        cmd = 'c:/Windows/Microsoft.NET/Framework'
        arg1 = 'ALL_BUILD.vcxproj'                   
        arg2 = '/p:Configuration='+buildType
        arg3 = '/nologo'
        heliumbuildtools.runCmd([cmd, arg1, arg2, arg3], log_file)
        arg1 = 'INSTALL.vcxproj'                   
        heliumbuildtools.runCmd([cmd, arg1, arg2, arg3], log_file)
    
    return

def _polycode_upload( log_file ):
    urlHead = 'polycode_origin'
    log_file.write('\n\n --- git upload ---\n\n')
    if heliumbuildtools.runAndLogCmd( ['git', 'remote', '-v', 'show', urlHead], log_file ) != 0 :
        if heliumbuildtools.runAndLogCmd( ['git', 'init'], log_file ) != 0 :
            raise Exception("git init error\n")
        if heliumbuildtools.runAndLogCmd( ['git', 'remote', 'add', urlHead, polycodeGitURL], log_file ) != 0 :
            raise Exception("git remote add origin error")
         
    if heliumbuildtools.runAndLogCmd( ['git', 'pull', urlHead, 'master'], log_file ) != 0 :
        raise Exception("git pullin error")
    return

def build( buildRootPath ):
    log_file = open(buildRootPath+'/Polycode_build.log', 'w')
    
    srcPath = buildRootPath + '/polycode_src'
    if not os.path.isdir(srcPath):
        os.mkdir(srcPath)
    os.chdir(srcPath)
    _polycode_upload( log_file )
    
    #_polycode_dependencies_build_and_install( buildPath, buildType, log_file )
    #_polycode_build_and_install( buildPath, buildType, log_file )
    return 
