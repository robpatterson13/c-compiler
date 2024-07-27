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
    [[nodiscard]] std::vector<Token> lex() const;
private:
    std::string source_;
    std::string::const_iterator source_iter_ = source_.cbegin();
};

#endif //LEXER_HPP
