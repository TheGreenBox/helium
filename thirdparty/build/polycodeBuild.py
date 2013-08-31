#-*- utf-8 -*-

#---------------------------------------
import os
import sys
import string
import shutil
#---------------------------------------

rootScriptName = os.path.abspath(os.path.dirname(__file__))
buildToolsDir = os.path.normpath(rootScriptName+'/../../tools/buildTools/python')
if buildToolsDir not in sys.path:
    sys.path.append(buildToolsDir)
import heliumbuildtools

polycodeGitURL = 'https://github.com/TheGreenBox/Polycode.git'

def _polycode_dependencies_build( buildPath, buildType, log_file ):
    
    if sys.platform == 'linux2':
        typePth = buildPath + '/' +buildType
        if not os.path.isdir(typePth):
            os.mkdir(typePth)
        os.chdir(typePth)

        heliumbuildtools.cmakeGenerate( buildType, 'Unix Makefiles', '../..', [], log_file )
        heliumbuildtools.runCmd(['make'], log_file)

    elif sys.platform == 'win32':
        os.chdir(dependPth)
        heliumbuildtools.cmakeGenerate( buildType, 'Visual Studio 10', '..', [], log_file )
        
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
        typePth = buildPath + '/' + buildType
        if not os.path.isdir(typePth):
            os.mkdir(typePth)
        os.chdir(typePth)

        heliumbuildtools.cmakeGenerate( buildType, 'Unix Makefiles', '../..', [], log_file )
        heliumbuildtools.runCmd(['make'], log_file)
        heliumbuildtools.runCmd(['make', 'install'], log_file)

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
    
    buildRootPath = os.path.normpath(rootScriptName + '/' + buildRootPath)
    log_file = open(buildRootPath+'/Polycode_build.log', 'w')
    
    srcPath = buildRootPath + '/polycode_src'
    if not os.path.isdir(srcPath):
        os.mkdir(srcPath)
    os.chdir(srcPath)
    _polycode_upload( log_file )
  
    dependPath = srcPath + '/Dependencies/Build'
    if os.path.isdir(dependPath):
        shutil.rmtree(dependPath)
    os.mkdir(dependPath)
   
    _polycode_dependencies_build( dependPath, 'Debug', log_file )
    _polycode_dependencies_build( dependPath, 'Release', log_file )
    
    buildPath = srcPath + '/Build'
    if os.path.isdir(buildPath):
        shutil.rmtree(buildPath)
    os.mkdir(buildPath)
    
    _polycode_build_and_install( buildPath, 'Debug', log_file )
    _polycode_build_and_install( buildPath, 'Release', log_file )
    
    log_file.close()
    return 
