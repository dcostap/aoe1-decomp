@echo off
echo Setting up VS 2022 x86 environment...
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
if %errorlevel% neq 0 (
    echo Failed to setup environment!
    exit /b %errorlevel%
)

if not exist "build" mkdir build


echo Compiling empiresx.exe...
cl /EHsc /std:c++17 /D_DEBUG /Fo"build\\" src/main.cpp src/rge/*.cpp src/tribe/*.cpp user32.lib gdi32.lib kernel32.lib ole32.lib ddraw.lib dxguid.lib /Fe"build\\empiresx.exe"
if %errorlevel% neq 0 (
    echo Compilation of empiresx.exe Failed!
    exit /b %errorlevel%
)

