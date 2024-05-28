cmake_minimum_required(VERSION 3.13)

project(c-style-project)

find_package(LLVM REQUIRED CONFIG)
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

add_definitions(${LLVM_DEFINITIONS})

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${CLANG_INCLUDE_DIRS})

add_llvm_library(c-style MODULE main.cpp)

set_target_properties(c-style PROPERTIES
    COMPILE_FLAGS "-fno-rtti"
)

