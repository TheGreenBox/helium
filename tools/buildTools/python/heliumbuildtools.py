#-*- utf-8 -*-

import sys
import subprocess

def runCmd( cmd, logFile ):
    cmakeProc = subprocess.Popen(cmd, stdout=subprocess.PIPE)
    log, logEr = cmakeProc.communicate()
    
    if log:
        logFile.write(log)
        print("Stdout:\n")
        print(log)
        
    if logEr:
        logFile.write(logEr)
        print("Error out:\n")
        print(logEr)
    return

def cmakeGenerate( buildType, cmakeGenerator, srcDir, otherOpt, log_file ):

    cmakeBuildType = '-DCMAKE_BUILD_TYPE='+buildType
    luaCmakeCmd = [ 'cmake',
                    cmakeGenerator,
                    cmakeBuildType ]
    luaCmakeCmd = luaCmakeCmd + otherOpt
    luaCmakeCmd.append(srcDir)
    
    print("Cmake generating...")
    runCmd(luaCmakeCmd, log_file)
    return

def buildProject( buildType, log_file ):
    if sys.platform == 'linux2':
        runCmd(['make'], log_file)
        print("Try to make install, wait few second please...")
        runCmd(['make', 'install'], log_file)
    
    elif sys.platform == 'win32':
        cmd = 'c:/Windows/Microsoft.NET/Framework/v4.0.30319/MSBuild.exe'
        arg1 = 'ALL_BUILD.vcxproj'
        arg2 = '/p:Configuration='+buildType
        arg3 = '/nologo'
        runCmd([cmd, arg1, arg2, arg3], log_file)
    return
