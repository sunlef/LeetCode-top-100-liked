cmake_minimum_required(VERSION 3.13)

project(top-100-liked)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_SOURCE_DIR}/solutions)

add_executable(main ${CMAKE_SOURCE_DIR}/util/main.cpp)
target_precompile_headers(main PRIVATE ${CMAKE_SOURCE_DIR}/util/common.h)
target_compile_options(main PRIVATE -O2 -Wall -Wextra)
target_compile_definitions(main PRIVATE LOCAL)