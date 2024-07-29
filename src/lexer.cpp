//
// Created by Rob Patterson on 7/27/24.
//

#include <string>

#include "../include/lexer/lexer.hpp"
#include "../lib/utility.hpp"
#include "../lib/debug.hpp"

Token Lexer::tokenize_word() {
    auto word{ utility::range_by_predicate<std::string>(
        source_iter_,
        [](const int c) {
            return std::isalnum(c);
        }) };

    if (word == "int" || word == "return" || word == "void") {
        return { KEYWORD, word };
    }

    return { IDENTIFIER, word };
}

Token Lexer::tokenize_number() {
    auto number{ utility::range_by_predicate<std::string>(
        source_iter_,
        [](const int c) {
            return std::isdigit(c);
        }) };

    return { CONSTANT, number };
}

Token Lexer::tokenize_symbol() {
    const auto c {*(source_iter_++)};

    if (c == '{') {
        return { OPEN_BRACE };
    }
    if (c == '}') {
        return { CLOSE_BRACE };
    }
    if (c == '(') {
        return { OPEN_PAREN };
    }
    if (c == ')') {
        return { CLOSE_PAREN };
    }

    return { SEMICOLON };
}

namespace utility {
    bool is_valid_symbol(const char c) {
        return c == '(' || c == ')' || c == '{' || c == '}' || c == ';';
    }
}

std::vector<Token> Lexer::lex() {
    std::vector<Token> tokens{};

    while (const auto c = *source_iter_) {
        if (std::isspace(c)) {
            ++source_iter_;
        } else if (std::isalpha(c)) {
            tokens.push_back(tokenize_word());
        } else if (std::isdigit(c)) {
            tokens.push_back(tokenize_number());
        } else if (utility::is_valid_symbol(c)) {
            tokens.push_back(tokenize_symbol());
        }
        // throw error for unknown symbol here
    }

    tokens.push_back({ EOF_T });

#ifdef DEBUG_HPP
    for (const auto& token : tokens) {
        std::cout << token;
        if (token != *tokens.cend()) std::cout << "\n";
    }
    std::cout << std::endl;
#endif

    return tokens;
}
