@echo off
set "VSCMD_START_DIR=%CD%"
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
cl /EHsc /std:c++17 /MDd /D_DEBUG /DWIN32 /D_X86_ /I"src\third_party\directplay\Include" /I"src\game\include" /c src\game\src\Mouseptr.cpp > sizes_mouse.txt 2>&1
cl /EHsc /std:c++17 /MDd /D_DEBUG /DWIN32 /D_X86_ /I"src\third_party\directplay\Include" /I"src\game\include" /c src\game\src\Chat.cpp > sizes_chat.txt 2>&1
