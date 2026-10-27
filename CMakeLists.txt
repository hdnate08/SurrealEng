cmake_minimum_required(VERSION 3.25)
project(SurrealEng VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SurrealEng
    src/main.cpp
    src/core.cpp
    include/surreal/core.hpp
    include/surreal/precision.hpp
)

target_include_directories(SurrealEng
    PRIVATE
        include
)