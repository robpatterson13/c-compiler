//
// Created by Rob Patterson on 7/27/24.
//

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <optional>
#include <string>

enum TokenType {
    KEYWORD, IDENTIFIER, CONSTANT,

    SEMICOLON, OPEN_PAREN, CLOSE_PAREN, OPEN_BRACE, CLOSE_BRACE
};

struct Token {
    TokenType type;
    std::optional<std::string> value;
};

#endif //TOKEN_HPP
