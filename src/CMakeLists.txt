cmake_minimum_required(VERSION 3.28)

project(WindowsVersionInfo)

# Set the path to the CPP compiler
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")
# Set the path to the C compiler
set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")

# Add your source files
set(SOURCE_FILES
    main.cpp
    global.h
    logic.cpp
    gui.cpp
    error_handler.cpp
)

# Create the executable
add_executable(WinInfoVer ${SOURCE_FILES})
