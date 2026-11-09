cmake_minimum_required(VERSION 4.4)
project(SurrealEng LANGUAGES CXX)

enable_testing()

# core library
add_library(surreal_core src/core.cpp src/particle.cpp src/pfgen.cpp)
target_include_directories(surreal_core
                           PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_features(surreal_core PUBLIC cxx_std_26)
target_compile_options(surreal_core PRIVATE -Wall -Wextra -Werror -Wpedantic
                                            -Wshadow -Wconversion)

# main application
add_executable(SurrealEngApp src/main.cpp)
target_link_libraries(SurrealEngApp PRIVATE surreal_core)
target_compile_features(SurrealEngApp PUBLIC cxx_std_26)
target_compile_options(SurrealEngApp PRIVATE -Wall -Wextra -Werror -Wpedantic
                                             -Wshadow -Wconversion)

# subdirectories
add_subdirectory(src/demos)
add_subdirectory(tests)
