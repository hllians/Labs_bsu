#include "calculator.h"
#include <stdexcept>
#include <sstream>
#include <cctype>

void Calculator::setExpression(const std::string& expr) {
    expression = expr;
}

bool Calculator::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool Calculator::isDigit(char c) const {
    return std::isdigit(c);
}

int Calculator::getPriority(char op) const {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int Calculator::applyOperation(int a, int b, char op) const {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw std::runtime_error("Division by zero");
            return a / b;
        default: throw std::runtime_error("Invalid operator");
    }
}

bool Calculator::isValidExpression() const {
    Stack parentheses;
    
    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];
        
        if (c == '(') {
            parentheses.push(1);
        } else if (c == ')') {
            if (parentheses.isEmpty()) {
                return false;
            }
            parentheses.pop();
        } else if (isOperator(c)) {
            if (i == 0 || i == expression.length() - 1) {
                return false;
            }
            if (isOperator(expression[i-1]) || isOperator(expression[i+1])) {
                return false;
            }
        } else if (!isDigit(c) && c != ' ') {
            return false;
        }
    }
    
    return parentheses.isEmpty();
}

int Calculator::evaluate() {
    if (!isValidExpression()) {
        throw std::runtime_error("Invalid expression");
    }
    
    Stack values;
    Stack operators;
    
    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];
        
        if (c == ' ') {
            continue;
        } else if (c == '(') {
            operators.push('(');
        } else if (isDigit(c)) {
            int num = 0;
            while (i < expression.length() && isDigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            values.push(num);
        } else if (c == ')') {
            while (!operators.isEmpty() && operators[operators.size()-1] != '(') {
                char op = operators.pop();
                int b = values.pop();
                int a = values.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.pop();
        } else if (isOperator(c)) {
            while (!operators.isEmpty() && getPriority(operators[operators.size()-1]) >= getPriority(c)) {
                char op = operators.pop();
                int b = values.pop();
                int a = values.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.push(c);
        }
    }
    
    while (!operators.isEmpty()) {
        char op = operators.pop();
        int b = values.pop();
        int a = values.pop();
        values.push(applyOperation(a, b, op));
    }
    
    return values.pop();
}