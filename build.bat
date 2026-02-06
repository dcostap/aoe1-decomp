@echo off
setlocal

REM ============================================================================
REM Age of Empires 1 Decompilation - Build Script
REM ============================================================================
REM Structure:
REM   src/          - Source code (.cpp, .h, .cpp.asm)
REM   build/        - Compiler artifacts (.obj, .pdb)
REM   dist/         - Game sandbox (RELEASE game assets are here, exe is output here)
REM ============================================================================

pushd "%~dp0"

REM --- Configuration ---
set "VC_VARS=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat"
set "DP_INC=src\third_party\directplay\Include"
set "DP_LIB=src\third_party\directplay\Lib\x86"
set "SRC_DIR=src\game\src"
set "INC_DIR=src\game\include"
set "OBJ_DIR=build"
set "OUT_DIR=dist"

REM --- Setup VS Environment (only if not already set) ---
if not defined DevEnvDir (
    echo Setting up VS 2022 x86 environment...
    call "%VC_VARS%" x86
    if %errorlevel% neq 0 (
        echo Failed to setup environment!
        popd
        exit /b %errorlevel%
    )
)

REM --- Create directories ---
if not exist "%OBJ_DIR%" mkdir "%OBJ_DIR%"
if not exist "%OUT_DIR%" mkdir "%OUT_DIR%"

taskkill /im empiresx.exe /f >nul 2>nul
del /f /q "%OUT_DIR%\empiresx.exe" >nul 2>nul

REM --- Sanity checks ---
if not exist "%DP_INC%\dplay.h" (
    echo ERROR: dplay.h not found at "%DP_INC%\dplay.h"
    popd
    exit /b 1
)

if not exist "%OUT_DIR%\languagex.dll" (
    echo WARNING: languagex.dll not found in %OUT_DIR%
    echo          Copy game assets to %OUT_DIR% before running!
)

echo.
echo [1/2] Compiling resources...
rc /fo"%OBJ_DIR%\empires.res" %SRC_DIR%\empires.rc
if %errorlevel% neq 0 (
    echo Resource compilation FAILED!
    popd
    exit /b %errorlevel%
)

echo [2/2] Compiling code...
cl /nologo /EHsc /std:c++17 /MDd /D_DEBUG /DWIN32 /D_X86_ ^
   /I"%INC_DIR%" /I"%DP_INC%" ^
   /Fo"%OBJ_DIR%\\" /Fd"%OBJ_DIR%\empiresx.pdb" ^
   "%OBJ_DIR%\empires.res" ^
   %SRC_DIR%\main.cpp ^
   %SRC_DIR%\tribegam.cpp ^
   %SRC_DIR%\basegame.cpp ^
   %SRC_DIR%\RGE_Game_World.cpp ^
   %SRC_DIR%\TRIBE_World.cpp ^
   %SRC_DIR%\RGE_Player.cpp ^
   %SRC_DIR%\TRIBE_Player.cpp ^
   %SRC_DIR%\RGE_Static_Object.cpp ^
   %SRC_DIR%\RGE_Map.cpp ^
   %SRC_DIR%\com_hand.cpp ^
   %SRC_DIR%\globals.cpp ^
   %SRC_DIR%\Res_file.cpp ^
   %SRC_DIR%\sceninfo.cpp ^
   %SRC_DIR%\gameinfo.cpp ^
   %SRC_DIR%\file_stf.cpp ^
   %SRC_DIR%\getdxver.cpp ^
   %SRC_DIR%\TRegistry.cpp ^
   %SRC_DIR%\TDebuggingLog.cpp ^
   %SRC_DIR%\Mouseptr.cpp ^
   %SRC_DIR%\TShape.cpp ^
   %SRC_DIR%\Chat.cpp ^
   %SRC_DIR%\debug_helpers.cpp ^
   %SRC_DIR%\screens.cpp ^
   %SRC_DIR%\TPanel.cpp ^
   %SRC_DIR%\TButtonPanel.cpp ^
   %SRC_DIR%\TTextPanel.cpp ^
   %SRC_DIR%\Panel_ez.cpp ^
   %SRC_DIR%\Pnl_scr.cpp ^
   %SRC_DIR%\Scr_main_impl.cpp ^
   %SRC_DIR%\TPanelSystem.cpp ^
   %SRC_DIR%\Dib.cpp ^
   %SRC_DIR%\Drawarea.cpp ^
   %SRC_DIR%\spanlist.cpp ^
   %SRC_DIR%\RGE_Color_Table.cpp ^
   %SRC_DIR%\Pnl_pic.cpp ^
   /link /LIBPATH:"%DP_LIB%" ^
   kernel32.lib user32.lib gdi32.lib advapi32.lib ole32.lib ^
   ddraw.lib dxguid.lib dplayx.lib dplay.lib uuid.lib winmm.lib ws2_32.lib ^
   /OUT:"%OUT_DIR%\empiresx.exe"

if %errorlevel% neq 0 (
    echo.
    echo Compilation FAILED!
    popd
    exit /b %errorlevel%
)

echo [3/3] Build successful!
echo.
echo Output: %OUT_DIR%\empiresx.exe
echo.

popd
