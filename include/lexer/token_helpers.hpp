//
// Created by Rob Patterson on 7/29/24.
//

#ifndef TOKEN_HELPERS_HPP
#define TOKEN_HELPERS_HPP

#include "token.hpp"

namespace prebuilt_tokens {
    const Token return_token { TokenType::KEYWORD, "return" };
    const Token void_token { TokenType::KEYWORD, "void" };
    const Token int_token { TokenType::KEYWORD, "int" };

    // symbols
    const Token semicolon_token { TokenType::SEMICOLON };
    const Token open_paren_token { TokenType::OPEN_PAREN };
    const Token close_paren_token { TokenType::CLOSE_PAREN };
    const Token open_brace_token { TokenType::OPEN_BRACE };
    const Token close_brace_token { TokenType::CLOSE_BRACE };

    // EOF
    const Token eof_token { TokenType::EOF_T };
}

#endif