cmake_minimum_required(VERSION 3.28)
project(c_compiler)

set(CMAKE_CXX_STANDARD 23)

add_executable(c_compiler main.cpp
        include/lexer/lexer.hpp
        include/lexer/token.hpp
        src/lexer/lexer.cpp
        lib/utility.hpp
        lib/debug.hpp
        include/parser/parser.hpp
        include/parser/ast.hpp
        src/parser/parser.cpp)