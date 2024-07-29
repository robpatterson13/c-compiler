//
// Created by Rob Patterson on 7/29/24.
//

#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <memory>
#include <string>
#include <format>

using IdentifierASTNode = std::string;

struct ASTNode {
    // NOLINTNEXTLINE
    void print(this auto const& self) const {
        self.print();
    }
};

struct ExpressionASTNode : ASTNode {};

struct ConstantIntegerExpressionASTNode : ExpressionASTNode {
    int value;

    void print() const {
        std::cout << std::vformat(std::string_view("Constant({})\n"), std::make_format_args(value));
    }
};

struct StatementASTNode : ASTNode {};

struct ReturnStatementASTNode : StatementASTNode {
    std::unique_ptr<ExpressionASTNode> expression_node;

    void print() const {
        std::cout << "Return(\n";
        expression_node->print();
        std::cout << ")\n";
    }
};

struct FunctionASTNode {
    IdentifierASTNode identifier_node;
    std::unique_ptr<StatementASTNode> statement_node;

    void print() const {
        std::cout << "Function(\n";
        std::cout << std::vformat(std::string_view("name={},\n"), std::make_format_args(identifier_node));
        std::cout << "body=";
        statement_node->print();
        std::cout << ")\n";
    }
};

struct ProgramRootASTNode {
    std::unique_ptr<FunctionASTNode> function_node;

    void print() const {
        std::cout << "Program(\n";
        function_node->print();
        std::cout << ")" << std::endl;
    }
};

#endif //AST_HPP
