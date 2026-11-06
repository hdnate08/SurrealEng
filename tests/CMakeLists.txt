cmake_minimum_required(VERSION 3.25)
project(SurrealEngTests LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.18.0)
FetchContent_MakeAvailable(googletest)

add_executable(unit_tests test_vector3.cpp)
target_compile_features(unit_tests PRIVATE cxx_std_26)
target_link_libraries(unit_tests PRIVATE surreal_core gtest_main)
target_include_directories(unit_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

include(GoogleTest)
gtest_discover_tests(unit_tests)
