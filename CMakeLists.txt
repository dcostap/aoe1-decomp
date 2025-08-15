cmake_minimum_required(VERSION 3.20)
project(yourgame LANGUAGES CXX)

# Force 32-bit build if you choose the x86 kit; otherwise, pass -A Win32 in CMake Tools.
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

add_executable(yourgame WIN32
    src/main.cpp
)

target_compile_features(yourgame PRIVATE cxx_std_17)
target_compile_definitions(yourgame PRIVATE WIN32_LEAN_AND_MEAN)

# Core Win32 libs; add ddraw/dxguid later when you actually use them.
target_link_libraries(yourgame PRIVATE user32 gdi32 kernel32)

# If you want to be explicit about subsystem:
if (MSVC)
  target_link_options(yourgame PRIVATE /SUBSYSTEM:WINDOWS)
endif()
