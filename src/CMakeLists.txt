cmake_minimum_required(VERSION 3.0)

project(WindowsVersionInfo)

# Set C++ standard (you can change this to your desired version)
set(CMAKE_C_STANDARD 11)

# Set the path to the C compiler
set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")

# Add your source files
set(SOURCE_FILES
    win_main.C
    WndProc.C
    win_ver.h
    win_ver.C
)

# Create the executable
add_executable(WindowsVersionInfo ${SOURCE_FILES})
