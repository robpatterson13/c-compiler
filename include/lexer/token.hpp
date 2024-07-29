//
// Created by Rob Patterson on 7/27/24.
//

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <optional>
#include <string>
#include <iostream>
#include <format>

enum TokenType {
    KEYWORD, IDENTIFIER, CONSTANT,

    SEMICOLON, OPEN_PAREN, CLOSE_PAREN, OPEN_BRACE, CLOSE_BRACE,

    EOF_T
};

struct Token {
    TokenType type;
    std::optional<std::string> value;

    friend std::ostream& operator<< (std::ostream& os, const Token& token) {
        std::string token_string;

        switch (token.type) {
            case KEYWORD:
                token_string = std::vformat(std::string_view("Keyword({})"), std::make_format_args(token.value.value()));
                break;
            case IDENTIFIER:
                token_string = std::vformat(std::string_view("Identifier({})"), std::make_format_args(token.value.value()));
                break;
            case CONSTANT:
                token_string = std::vformat(std::string_view("Constant({})"), std::make_format_args(token.value.value()));
                break;
            case SEMICOLON:
                token_string = std::string("Semicolon");
                break;
            case OPEN_PAREN:
                token_string = std::string("Open_Paren");
                break;
            case CLOSE_PAREN:
                token_string = std::string("Close_Paren");
                break;
            case OPEN_BRACE:
                token_string = std::string("Open_Brace");
                break;
            case CLOSE_BRACE:
                token_string = std::string("Close_Brace");
                break;
            case EOF_T:
                token_string = std::string("EOF");
        }

        os << token_string;

        return os;
    }
};

#endif //TOKEN_HPP
