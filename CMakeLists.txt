cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(top-100-liked)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra)
endif()

add_executable(main util/main.cpp)
include_directories(solutions)

target_compile_definitions(main PRIVATE LOCAL)
target_precompile_headers(main PRIVATE util/common.h)