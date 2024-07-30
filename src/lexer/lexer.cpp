//
// Created by Rob Patterson on 7/27/24.
//

#include <string>
#include <map>

#include "../../include/lexer/lexer.hpp"
#include "../../lib/utility.hpp"
#include "../../lib/debug.hpp"
#include "../../include/lexer/token_helpers.hpp"

namespace lexer_utilities {
    const std::map<const char, const Token> symbols
    {
        {';', prebuilt_tokens::semicolon_token},
        {'(', prebuilt_tokens::open_paren_token},
        {')', prebuilt_tokens::close_paren_token},
        {'{', prebuilt_tokens::open_brace_token},
        {'}', prebuilt_tokens::close_brace_token},
    };

    const std::map<const std::string, const Token> keywords
    {
        {"int", prebuilt_tokens::int_token},
        {"return", prebuilt_tokens::return_token},
        {"void", prebuilt_tokens::void_token}
    };
}

Token Lexer::tokenize_word() {
    auto word {
        utility::range_by_predicate<std::string>(
            source_iter_,
            [](const int c) {
                return std::isalnum(c);
            }
        )
    };

    if (lexer_utilities::keywords.contains(word)) {
        return lexer_utilities::keywords.at(word);
    }

    return { TokenType::IDENTIFIER, word };
}

Token Lexer::tokenize_number() {
    auto number {
        utility::range_by_predicate<std::string>(
            source_iter_,
            [](const int c) {
                return std::isdigit(c);
            }
        )
    };

    return { TokenType::CONSTANT, number };
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
        } else if (lexer_utilities::symbols.contains(c)) {
            tokens.push_back(lexer_utilities::symbols.at(c));
            ++source_iter_;
        }
        // throw error for unknown symbol here
    }

    tokens.push_back(prebuilt_tokens::eof_token);

#ifdef DEBUG_LEXER
    for (const auto& token : tokens) {
        std::cout << token;
        if (token != *tokens.cend()) std::cout << "\n";
    }
    std::cout << std::endl;
#endif

    return tokens;
}

