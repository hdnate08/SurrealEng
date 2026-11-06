cmake_minimum_required(VERSION 3.25)
project(SurrealEng LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_compile_options(-Wall -Wextra -Werror -Wpedantic -Wshadow -Wconversion)

add_library(surreal_core src/core.cpp src/particle.cpp)
target_include_directories(surreal_core
                           PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# main executable which links against the surreal_core library
add_executable(SurrealEngApp src/main.cpp)
target_link_libraries(SurrealEngApp PRIVATE surreal_core)

add_subdirectory(src/demos)
add_subdirectory(tests)
