cmake_minimum_required(VERSION 3.10.0)
project(counter VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=-*,clang-analyzer-*")

add_executable(counter
    src/main.cpp
    src/utils/math_utils.cpp
)
