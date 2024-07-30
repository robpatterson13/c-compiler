//
// Created by Rob Patterson on 7/27/24.
//

#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>

#include "token.hpp"

class Lexer {
public:
    explicit Lexer(std::string& source) : source_(std::move(source)) {}
    [[nodiscard]] std::vector<Token> lex();
private:
    std::string source_;
    std::string::iterator source_iter_{ source_.begin() };

    [[nodiscard]] Token tokenize_word();
    [[nodiscard]] Token tokenize_number();
};

#endif //LEXER_HPP
