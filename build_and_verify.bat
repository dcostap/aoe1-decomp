@echo off
setlocal

REM Always run from the folder where this .bat lives
pushd "%~dp0"

echo Setting up VS 2022 x86 environment...
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
if %errorlevel% neq 0 (
    echo Failed to setup environment!
    popd
    exit /b %errorlevel%
)

set "DP_INC=%~dp0src\third_party\directplay\Include"
set "DP_LIB=%~dp0src\third_party\directplay\Lib\x86"

echo DP_INC = "%DP_INC%"
echo DP_LIB = "%DP_LIB%"

REM Sanity check
if not exist "%DP_INC%\dplay.h" (
    echo ERROR: dplay.h not found at "%DP_INC%\dplay.h"
    popd
    exit /b 1
)

if not exist "build" mkdir build

echo Compiling empiresx.exe...
cl /EHsc /std:c++17 /MDd /D_DEBUG ^
  /I"%DP_INC%" ^
  /Fo"build\\" ^
  src\main.cpp src\game\tribegam.cpp src\game\basegame.cpp src\game\Res_file.cpp ^
  user32.lib gdi32.lib kernel32.lib ole32.lib ddraw.lib dxguid.lib ^
  /link /LIBPATH:"%DP_LIB%" dplayx.lib dplay.lib uuid.lib winmm.lib ws2_32.lib ^
  /OUT:"build\empiresx.exe"

if %errorlevel% neq 0 (
    echo Compilation of empiresx.exe Failed!
    popd
    exit /b %errorlevel%
)

echo Build OK.
popd
