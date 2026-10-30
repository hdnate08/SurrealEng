include(FetchContent)

# downloads googletest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)

FetchContent_MakeAvailable(googletest)

# force gtest to build with c++17
set_target_properties(gtest gtest_main gmock gmock_main PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

add_executable(unit_tests
    test_vector3.cpp
)

target_link_libraries(unit_tests PRIVATE surreal_core gtest_main)

target_include_directories(unit_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

include(GoogleTest)
gtest_discover_tests(unit_tests)