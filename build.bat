@echo off
setlocal EnableExtensions EnableDelayedExpansion

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
set "RES_FILE=%OBJ_DIR%\empires.res"
set "OUT_EXE=%OUT_DIR%\empiresx.exe"
set "BUILD_STAMP=%OBJ_DIR%\build.stamp"
set "EXCLUDE_FILE=build_exclude_sources.txt"

if not exist "%SRC_DIR%\StrategyAIModule.cpp" (
    echo ERROR: missing required source "%SRC_DIR%\StrategyAIModule.cpp"
    popd
    exit /b 1
)
if not exist "%SRC_DIR%\TribeStrategyAIModule.cpp" (
    echo ERROR: missing required source "%SRC_DIR%\TribeStrategyAIModule.cpp"
    popd
    exit /b 1
)

REM --- Setup VS Environment (only if required tools are not already available) ---
where cl >nul 2>nul
set "HAS_CL=%errorlevel%"
where rc >nul 2>nul
set "HAS_RC=%errorlevel%"
where link >nul 2>nul
set "HAS_LINK=%errorlevel%"

if "%HAS_CL%"=="0" if "%HAS_RC%"=="0" if "%HAS_LINK%"=="0" goto :have_vs_env

echo Setting up VS 2022 x86 environment...
if not exist "%VC_VARS%" (
    echo Failed to setup environment: vcvarsall.bat not found!
    echo Expected at: "%VC_VARS%"
    popd
    exit /b 1
)
call "%VC_VARS%" x86
if errorlevel 1 (
    echo Failed to setup environment!
    popd
    exit /b 1
)

:have_vs_env

REM --- Create directories ---
if not exist "%OBJ_DIR%" mkdir "%OBJ_DIR%"
if not exist "%OUT_DIR%" mkdir "%OUT_DIR%"
if not exist "%EXCLUDE_FILE%" (
    > "%EXCLUDE_FILE%" echo TRIBE_Panel_Button.cpp
)

REM --- Ensure output EXE can be replaced ---
set "RUNNING_EXE=0"
for /f %%P in ('tasklist /FI "IMAGENAME eq empiresx.exe" /NH 2^>nul ^| find /I "empiresx.exe"') do set "RUNNING_EXE=1"
if "%RUNNING_EXE%"=="1" (
    taskkill /im empiresx.exe /f >nul 2>nul
    if errorlevel 1 (
        echo ERROR: empiresx.exe is running and could not be terminated.
        echo        Close the game manually and rerun build.
        popd
        exit /b 1
    )
)

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

REM --- Required AI item source files ---
for %%F in (BuildItem.cpp ConstructionItem.cpp ResearchItem.cpp TechItem.cpp) do (
    if not exist "%SRC_DIR%\%%F" (
        echo ERROR: required source file missing: %SRC_DIR%\%%F
        popd
        exit /b 1
    )
)

REM --- Header invalidation ---
set "REBUILD_ALL=0"
if not exist "%BUILD_STAMP%" (
    set "REBUILD_ALL=1"
) else (
    for /f %%I in ('powershell -NoProfile -Command "$s=(Get-Item '%BUILD_STAMP%').LastWriteTimeUtc; if (Get-ChildItem '%INC_DIR%' -File -Recurse -Filter *.h | Where-Object { $_.LastWriteTimeUtc -gt $s } | Select-Object -First 1) { '1' } else { '0' }"') do set "REBUILD_ALL=%%I"
)

REM --- Incremental resource compile ---
set "RES_CHANGED=0"
set "NEED_RES_COMPILE=0"
if not exist "%RES_FILE%" (
    set "NEED_RES_COMPILE=1"
) else (
    for /f %%I in ('powershell -NoProfile -Command "if ((Get-Item '%SRC_DIR%\empires.rc').LastWriteTimeUtc -gt (Get-Item '%RES_FILE%').LastWriteTimeUtc) { '1' } else { '0' }"') do set "NEED_RES_COMPILE=%%I"
)

if "%NEED_RES_COMPILE%"=="1" (
    echo.
    echo [1/3] Compiling resources...
    rc /fo"%RES_FILE%" %SRC_DIR%\empires.rc
    if errorlevel 1 (
        echo Resource compilation FAILED!
        popd
        exit /b 1
    )
    set "RES_CHANGED=1"
) else (
    echo.
    echo [1/3] Resources are up to date.
)

REM --- Discover sources and compute incremental compile list ---
REM --- Includes src\game\src\InformationAIModule.cpp and TribeInformationAIModule.cpp automatically ---
set "SOURCE_META=%OBJ_DIR%\source_meta.env"
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0build_discover_sources.ps1" ^
    -SrcDir "%SRC_DIR%" ^
    -ObjDir "%OBJ_DIR%" ^
    -ResFile "%RES_FILE%" ^
    -ExcludeFile "%EXCLUDE_FILE%" ^
    -RebuildAll %REBUILD_ALL% > "%SOURCE_META%"
if errorlevel 1 (
    echo ERROR: failed to discover source file state.
    popd
    exit /b 1
)

set "OBJECT_LIST="
set "CHANGED_SOURCES_RSP="
set /a SOURCE_COUNT=0
set /a CHANGED_COUNT=0
set /a EXCLUDED_COUNT=0
for /f "usebackq delims=" %%L in ("%SOURCE_META%") do set "%%L"
del /f /q "%SOURCE_META%" >nul 2>nul

if !SOURCE_COUNT! EQU 0 (
    echo ERROR: no source files found in %SRC_DIR%
    popd
    exit /b 1
)

if !CHANGED_COUNT! GTR 0 (
    if "%REBUILD_ALL%"=="1" (
        echo [2/3] Rebuilding !CHANGED_COUNT! source file^(s^)...
    ) else (
        echo [2/3] Compiling !CHANGED_COUNT! changed source file^(s^)...
    )

    cl /nologo /c /EHsc /std:c++17 /MDd /D_DEBUG /DWIN32 /D_X86_ /MP /FS ^
       /I"%INC_DIR%" /I"%DP_INC%" ^
       /Fo"%OBJ_DIR%\\" /Fd"%OBJ_DIR%\empiresx.pdb" ^
       @"!CHANGED_SOURCES_RSP!"
    if errorlevel 1 (
        echo.
        echo Compilation FAILED!
        popd
        exit /b 1
    )
) else (
    echo [2/3] Source files are up to date.
)
if !EXCLUDED_COUNT! GTR 0 echo      Skipped !EXCLUDED_COUNT! source file^(s^) listed in %EXCLUDE_FILE%.

REM --- Incremental link ---
set "NEED_LINK=0"
if not exist "%OUT_EXE%" set "NEED_LINK=1"
if !CHANGED_COUNT! GTR 0 set "NEED_LINK=1"
if "%RES_CHANGED%"=="1" set "NEED_LINK=1"

if "%NEED_LINK%"=="1" (
    echo [3/3] Linking...
     link /nologo /DEBUG /INCREMENTAL /OUT:"%OUT_EXE%" ^
           /MAP:"%OBJ_DIR%\empiresx.map" ^
           !OBJECT_LIST! ^
           /LIBPATH:"%DP_LIB%" ^
           kernel32.lib user32.lib gdi32.lib advapi32.lib ole32.lib ^
           ddraw.lib dsound.lib dxguid.lib dplayx.lib dplay.lib uuid.lib winmm.lib vfw32.lib ws2_32.lib imm32.lib
      if errorlevel 1 (
          echo.
          echo Link FAILED!
          popd
          exit /b 1
      )
) else (
    echo [3/3] Link is up to date.
)

> "%BUILD_STAMP%" echo Build stamp %date% %time%

echo [done] Build successful.
echo.
echo Output: %OUT_EXE%
echo.

popd
