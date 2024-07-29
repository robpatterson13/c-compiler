#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include "include/lexer/lexer.hpp"

int main(const int argc, char *argv[]) {
    if (argc > 1 && std::filesystem::exists(argv[1])) {
        std::ifstream file{ argv[1] };
        std::string line{};
        std::string file_contents{};
        while (std::getline(file, line))
        {
            file_contents += line;
            if (file.peek() != EOF) file_contents.push_back('\n');
        }
        Lexer lexer{ file_contents };
        auto result = lexer.lex();
    } else {
        std::cerr << std::string_view("Error: Need a valid file") << std::endl;
    }
}
