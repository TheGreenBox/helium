#-*- utf-8 -*-

import sys
import subprocess

def runAndLogCmd( cmd, logFile ):
    proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    
    s = '\n'
    while s:
        print s.rstrip()
        logFile.write(s)
        s=proc.stdout.readline()
    
    err = '\n'
    errorOccur = False
    while err:
        print err.rstrip()
        logFile.write(err)
        err=proc.stderr.readline()

    proc.wait()
    return proc.returncode

def runCmd( cmd, logFile ):
    if runAndLogCmd( cmd, logFile ) != 0:
        raise Exception("Cmd error \""+cmd[0]+"\"\n")
    return

def cmakeGenerate( buildType, cmakeGenerator, srcDir, otherOpt, log_file ):

    cmakeBuildType = '-DCMAKE_BUILD_TYPE='+buildType
    luaCmakeCmd = [ 'cmake',
                    cmakeGenerator,
                    cmakeBuildType ]
    luaCmakeCmd = luaCmakeCmd + otherOpt
    luaCmakeCmd.append(srcDir)
    
    print("Cmake generating...")
    log_file.write("Cmake generating...\n")
    runCmd(luaCmakeCmd, log_file)
    return

def buildProject( buildType, log_file ):
    print("Build...")
    log_file.write("Build...\n")
    if sys.platform == 'linux2':
        runCmd(['make'], log_file)
    
    elif sys.platform == 'win32':
        cmd = 'c:/Windows/Microsoft.NET/Framework/v4.0.30319/MSBuild.exe'
        arg1 = 'ALL_BUILD.vcxproj'
        arg2 = '/p:Configuration='+buildType
        arg3 = '/nologo'
        runCmd([cmd, arg1, arg2, arg3], log_file)
    return

def installProject( buildType, log_file ):
    print("Install...")
    log_file.write("Install...\n")
    
    if sys.platform == 'linux2':
        runCmd(['make', 'install'], log_file)
    
    elif sys.platform == 'win32':
        cmd = 'c:/Windows/Microsoft.NET/Framework/v4.0.30319/MSBuild.exe'
        arg1 = 'INSTALL.vcxproj'
        arg2 = '/p:Configuration='+buildType
        arg3 = '/nologo'
        runCmd([cmd, arg1, arg2, arg3], log_file)
    return

