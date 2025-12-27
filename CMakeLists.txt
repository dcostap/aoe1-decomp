cmake_minimum_required(VERSION 3.20)
project(AoE1Decomp LANGUAGES CXX)

# 1. Force 32-bit (x86) check
# Memory layout must match the original 32-bit EXE exactly (4-byte pointers)
if(MSVC)
    if(CMAKE_CL_64)
        message(FATAL_ERROR "Target is 64-bit. This project MUST be built as x86 (32-bit). Please select the x86 Kit in VS Code.")
    endif()
endif()

# 2. Runtime Library settings
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

# 3. Collect Source Files
# Add new .cpp files here as you create them
set(SOURCES
    src/main.cpp
    src/tribe/TRIBE_Game.cpp
)

# 4. Define the Executable
add_executable(AoE1Decomp WIN32 ${SOURCES})

# 5. Compiler Features & Global Definitions
target_compile_features(AoE1Decomp PRIVATE cxx_std_17)
target_compile_definitions(AoE1Decomp PRIVATE 
    WIN32_LEAN_AND_MEAN
    _CRT_SECURE_NO_WARNINGS   # Allows use of strcpy/sprintf like the original code
)

# 6. Include Directories
# This allows you to use #include "rge/..." or #include "types.h" easily
target_include_directories(AoE1Decomp PRIVATE src)

# 7. Core Windows Libraries
# Added ole32 for GUID support
target_link_libraries(AoE1Decomp PRIVATE 
    user32 
    gdi32 
    kernel32 
    ole32
)

# 8. Linker Options
if (MSVC)
  target_link_options(AoE1Decomp PRIVATE /SUBSYSTEM:WINDOWS)
  
  # Optional: Helpful for decompilation to see precise memory offsets in maps
  target_link_options(AoE1Decomp PRIVATE /MAP) 
endif()