#-*- utf-8 -*-

#---------------------------------------
import os
#---------------------------------------

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

def _polycode_upload( uploadDir, log_file ):
    
    log_file.write('\n\n --- git upload ---\n\n')
    if runAndLogCmd( ['git', 'status'], log_file ) != 0 :
        if runAndLogCmd( ['git', 'init'], log_file ) != 0 :
            raise Exception("git init error\n")
        if runAndLogCmd( ['git', 'remote', 'add', polycodeGitURL, 'origin'], log_file ) != 0 :
            raise Exception("git remote add origin error")
         
    if runAndLogCmd( ['git', 'pull', 'origin', 'master'], log_file ) != 0 :
        raise Exception("git pullin error")
    return

def build( buildRootPath ):
    log_file = open(buildRootPath+'/Polycode_build.log', 'w')
    
    srcPath = buildRootPath + '/polycode_src'
    if os.path.isdir(srcPath):
        os.mkdir(srcPath)
    os.chdir(srcPath)
    _polycode_upload( uploadDir, log_file )
    
    #_polycode_dependencies_build_and_install( buildPath, buildType, log_file )
    #_polycode_build_and_install( buildPath, buildType, log_file )
    return 
