//
// Created by Rob Patterson on 7/27/24.
//

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <optional>
#include <string>

enum TokenType {

};

struct Token {
    TokenType type;
    std::optional<std::string> value;
};

#endif //TOKEN_HPP
