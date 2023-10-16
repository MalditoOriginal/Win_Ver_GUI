cmake_minimum_required(VERSION 3.28.0-rc1)

project(WindowsVersionInfo)

# Set the path to the C compiler
set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")

# Add your source files
set(SOURCE_FILES
    win_main.c
    WndProc.c
    win_ver.h
    win_ver.c
)

# Create the executable
add_executable(WinInfoVer ${SOURCE_FILES})
