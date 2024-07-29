//
// Created by Rob Patterson on 7/29/24.
//

#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>

#include "../lexer/token.hpp"
#include "ast.hpp"

class Parser {
public:
    explicit Parser(std::vector<Token>& tokens) : tokens_(std::move(tokens)) {}
    [[nodiscard]] ProgramRootASTNode parse();
private:
    std::vector<Token> tokens_;
    std::vector<Token>::iterator token_iter_{ tokens_.begin() };
};

#endif //PARSER_HPP
