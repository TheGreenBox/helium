#-*- utf-8 -*-

import sys
import subprocess

_win32_color = {  \
    'BLUE'   : 0x01,    \
    'GREEN'  : 0x02,    \
    'AZURE'  : 0x03,    \
    'RED'    : 0x04,    \
    'PURPLE' : 0x05,    \
    'YELLOW' : 0x06,    \
    'WHITE'  : 0x07,    \
    'GREY'   : 0x08,    \
    'BR_AZURE'  : 0x09, \
    'BR_GREEN'  : 0x0A, \
    'BR_BLUE'   : 0x0B, \
    'BR_RED'    : 0x0C, \
    'BR_PURPLE' : 0x0D, \
    'BR_YELLOW' : 0x0E, \
    'BR_WHITE'  : 0x0F }

_unix_color = { \
    'BLUE'  : 34,     \
    'GREEN' : 32,     \
    'AZURE' : 36,     \
    'RED'   : 31,     \
    'PURPLE': 35,     \
    'YELLOW': 33,     \
    'WHITE' : 37,     \
    'GREY'  : 30,     \
    'BR_AZURE' : 96,  \
    'BR_GREEN' : 92,  \
    'BR_BLUE'  : 94,  \
    'BR_RED'   : 91,  \
    'BR_PURPLE': 95,  \
    'BR_YELLOW': 93,  \
    'BR_WHITE' : 97  }

def heliumColoredPrint(toprint, color):
    if not color in _unix_color:
        color = 'WHITE'
    
    if sys.platform == 'win32':
        import ctypes
        handle = ctypes.windll.kernel32.GetStdHandle(-11)
        ctypes.windll.kernel32.SetConsoleTextAttribute(handle, _win32_color[color] )
        print (toprint)
        ctypes.windll.kernel32.SetConsoleTextAttribute(handle, _win32_color['WHITE'] )
    
    elif sys.platform == 'linux2':
        CSI = '\033['
        print (CSI + str(_unix_color[color]) + 'm' + toprint + CSI + '0m')
    
    return

