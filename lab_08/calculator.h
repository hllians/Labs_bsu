#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include "stack.h"

class Calculator {
private:
    std::string expression;
    
    bool isOperator(char c) const;
    int getPriority(char op) const;
    int applyOperation(int a, int b, char op) const;
    bool isDigit(char c) const;
    
public:
    Calculator() = default;
    
    void setExpression(const std::string& expr);
    bool isValidExpression() const;
    int evaluate();
};

#endif