//
// Created by Rob Patterson on 7/27/24.
//

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <optional>
#include <string>
#include <iostream>
#include <format>

enum class TokenType {
    IDENTIFIER, CONSTANT,

    KEYWORD,

    SEMICOLON, OPEN_PAREN, CLOSE_PAREN, OPEN_BRACE, CLOSE_BRACE,

    EOF_T
};

struct Token {
    TokenType type;
    std::optional<std::string> value;

    bool operator==(const Token& other) const {
        if (value.has_value() && other.value.has_value()) {
            return type == other.type && value.value() == other.value.value();
        }
        if (!value.has_value() && !other.value.has_value()) {
            return type == other.type;
        }

        return false;
    }

    friend std::ostream& operator<< (std::ostream& os, const Token& token) {
        std::string token_string;

        switch (token.type) {
            case TokenType::KEYWORD:
                token_string = std::vformat(std::string_view("Keyword({})"), std::make_format_args(token.value.value()));
                break;
            case TokenType::IDENTIFIER:
                token_string = std::vformat(std::string_view("Identifier({})"), std::make_format_args(token.value.value()));
                break;
            case TokenType::CONSTANT:
                token_string = std::vformat(std::string_view("Constant({})"), std::make_format_args(token.value.value()));
                break;
            case TokenType::SEMICOLON:
                token_string = std::string("Semicolon");
                break;
            case TokenType::OPEN_PAREN:
                token_string = std::string("Open_Paren");
                break;
            case TokenType::CLOSE_PAREN:
                token_string = std::string("Close_Paren");
                break;
            case TokenType::OPEN_BRACE:
                token_string = std::string("Open_Brace");
                break;
            case TokenType::CLOSE_BRACE:
                token_string = std::string("Close_Brace");
                break;
            case TokenType::EOF_T:
                token_string = std::string("EOF");
        }

        os << token_string;

        return os;
    }
};

#endif //TOKEN_HPP
