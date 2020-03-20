cmake_minimum_required(VERSION 2.6)
project(Tutorial)

## Version counter
set(VERSION 0.1)
# Copy version.h.in to version.h and modify the file in the process.
# cmake-Variable foo gets substituted for every @foo@ in version.h.in.
configure_file(
    "${PROJECT_SOURCE_DIR}/version.h.in"
    "${PROJECT_BINARY_DIR}/version.h"
    )
# Add binary tree to search path for include files.
include_directories("${PROJECT_BINARY_DIR}")

## Add an option (whether to use a library).
# Add an `#cmakedefine' entry in version.h.in.
# `#cmakedefine VAR' will be replaced with either `#define VAR' or `/* #undef
# VAR  */' depending on  the  setting  of  VAR in CMake."
option(USE_MYSQUARE "Use the self written version of sqr" ON)

## Add a ibrary.
if (USE_MYSQUARE)
    add_library(MySquare sqr.cpp)
endif (USE_MYSQUARE)

## Executable
add_executable(tutorial tutorial.cpp)
if (USE_MYSQUARE)
    target_link_libraries(tutorial MySquare)
endif (USE_MYSQUARE)
