cmake_minimum_required(VERSION 3.28)
project(c_compiler)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

add_executable(c_compiler main.cpp
        include/lexer/lexer.hpp
        include/lexer/token.hpp
        src/lexer.cpp
        tests/lexer_tests.cpp)

target_link_libraries(
        c_compiler
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests()