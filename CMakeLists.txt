cmake_minimum_required(VERSION 3.25)
project(SurrealEng VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# enables testing for the project workspace
enable_testing()

add_library(surreal_core
    src/core.cpp
    include/surreal/core.hpp
    include/surreal/precision.hpp
)

target_include_directories(surreal_core PUBLIC include)

# main executable which links against the surreal_core library
add_executable(SurrealEngApp
    src/main.cpp
)
target_link_libraries(SurrealEngApp PRIVATE surreal_core)

# hook up test dir
add_subdirectory(tests)