cmake_minimum_required(VERSION 3.10)

# Project Name
project(GRIND)

# Set C++ version
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(src)

# Add the executable
add_executable(grind
    main.cpp
    src/tracker.cpp
)
