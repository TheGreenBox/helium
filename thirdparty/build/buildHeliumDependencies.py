#-*- utf-8 -*-


import os
import sys
import time
import zipfile
import subprocess
import shutil

print("Platform: ", sys.platform )

rootScriptName = os.path.abspath(os.path.dirname(__file__))
outputDirName = rootScriptName+'/product'
print(rootScriptName)

luaHeliumDir = os.path.normpath(rootScriptName + '/../lua')
luaArchiveWithSrcs = os.path.expanduser("~/Dropbox/game_project/helium_resource/thirdparty_libraries/lua-5.2.2.zip")

if not os.path.isdir(rootScriptName+'/log'):
    os.mkdir(rootScriptName+'/log')

log_file = open("log/heluim_thirdparty_buildlog_"+time.strftime("%m.%d_%H.%M.%S") + '.log', 'a')

def luaDownloadAndBuild ( buildType ):
    
    luaHeliumWorkingDir = os.path.normpath(rootScriptName + '/../lua/build')
    log_file.write('Lua ' + buildType + ' building ')
    print('Lua ' + buildType + ' building ')
    
    luaArch = zipfile.ZipFile(luaArchiveWithSrcs, 'r')
    luaArch.extractall(luaHeliumDir)
    
    log_file.write('downloaded: '+luaArchiveWithSrcs + '\n')
    print('downloaded: '+luaArchiveWithSrcs)
    log_file.write('and extracted to: '+luaHeliumDir + '\n')
    print('and extracted to: '+luaHeliumDir)
    
    if os.path.isdir(luaHeliumWorkingDir):
        shutil.rmtree(luaHeliumWorkingDir)
        
    os.mkdir(luaHeliumWorkingDir)
    cmakeBuildType = ''
    
    cmakeGenerator = ''
    if sys.platform == 'linux2':
        cmakeGenerator = '-GUnix Makefiles'
        if buildType != 'Release':
            buildType = 'Debug'
        luaHeliumWorkingDir = luaHeliumWorkingDir + '/' + buildType
        os.mkdir(luaHeliumWorkingDir)
        cmakeBuildType = '-DCMAKE_BUILD_TYPE='+buildType
    
    elif sys.platform == 'win32':
        cmakeGenerator = '-GVisual Studio 11'
        
    os.chdir(luaHeliumWorkingDir)

    cmakeInstallParam = '-DHELIUM_THIRD_PARTY_OUTPUT_PATH='+outputDirName
    luaCmakeCmd = [ 'cmake',
                    cmakeGenerator,
                    cmakeBuildType,
                    cmakeInstallParam,
                    luaHeliumDir    ]
    
    print("Cmake generating...")
    runCmd(luaCmakeCmd, log_file)

    print("Try to build, wait please...")
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
    
    os.chdir(rootScriptName)
    return

try:
   luaDownloadAndBuild ('Release')
   luaDownloadAndBuild ('Debug')

except Exception as e:
    print("Something wrong ...")
    print(e)

finally:
    log_file.close()

