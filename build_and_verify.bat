@echo off
echo Setting up VS 2022 x86 environment...
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
if %errorlevel% neq 0 (
    echo Failed to setup environment!
    exit /b %errorlevel%
)

echo Compiling...
cl /EHsc /std:c++17 src/verify_sizes.cpp src/tribe/TRIBE_Game.cpp src/rge/RGE_Base_Game.cpp src/rge/TRegistry.cpp src/rge/TCommunications_Handler.cpp src/rge/RESFILE.cpp user32.lib gdi32.lib kernel32.lib ole32.lib /Fe:verify.exe
if %errorlevel% neq 0 (
    echo Compilation of verify.exe Failed!
    exit /b %errorlevel%
)

echo Compiling empiresx.exe...
cl /EHsc /std:c++17 src/main.cpp src/tribe/TRIBE_Game.cpp src/rge/RGE_Base_Game.cpp src/rge/TRegistry.cpp src/rge/TCommunications_Handler.cpp src/rge/RESFILE.cpp user32.lib gdi32.lib kernel32.lib ole32.lib /Fe:empiresx.exe
if %errorlevel% neq 0 (
    echo Compilation of empiresx.exe Failed!
    exit /b %errorlevel%
)

echo Running Verification...
verify.exe
