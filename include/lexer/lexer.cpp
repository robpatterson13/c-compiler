//
// Created by Rob Patterson on 7/27/24.
//

#include <string>
#include <algorithm>

#include "lexer.hpp"

Token Lexer::tokenize_word() {
    auto end_of_word = std::find(
        source_iter_,
        source_.end(),
        [](const char c) {
            return (std::isalnum(c) == 0) || (c != '_');
        });

    std::string word{source_iter_, end_of_word};

    source_iter_ = std::move(++end_of_word); // NOLINT - want to use move assignment

    if (word == "int" || word == "return" || word == "void") {
        return { KEYWORD, word };
    }

    return { IDENTIFIER, word };
}

Token Lexer::tokenize_number() {
    const auto end_of_number = std::find(
        source_iter_,
        source_.end(),
        [](const char c) {
            return !std::isdigit(c);
        });

    std::string number{source_iter_, end_of_number};

    source_iter_ = end_of_number + 1;

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
        return (c == '(' ||
            c == ')' ||
            c == '{' ||
            c == '}' ||
            c == ';');
    }
}

std::vector<Token> Lexer::lex() {
    std::vector<Token> tokens{};

    while (const auto& c = *source_iter_) {
        if (std::isalpha(c) || (c != '_')) {
            tokens.push_back(tokenize_word());
        } else if (std::isdigit(c)) {
            tokens.push_back((tokenize_number()));
        } else if (utility::is_valid_symbol(c)) {
            tokens.push_back(tokenize_symbol());
        }
        // throw error for unknown symbol here
    }

    return tokens;
}
