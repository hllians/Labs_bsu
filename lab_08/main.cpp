#include <iostream>
#include "calculator.h"

int main() {
    Calculator calc;
    
    std::cout << "my calculator" << std::endl;
    std::cout << "             " << std::endl;
    
    std::string expressions[] = {
        "(2+6)/(7-5)",
        "3+5*2",
        "10/2+3",
        "2+3*4-6/2"
    };
    
    for (const auto& expr : expressions) {
        calc.setExpression(expr);
        
        std::cout << "expression: " << expr << std::endl;
        std::cout << "validity: " << (calc.isValidExpression() ? "yes" : "no") << std::endl;
        
        if (calc.isValidExpression()) {
            try {
                int result = calc.evaluate();
                std::cout << "result: " << result << std::endl;
            } catch (const std::exception& e) {
                std::cout << "bug: " << e.what() << std::endl;
            }
        }
        std::cout << std::endl;
    }
    
    std::cout << "\nstack work demonstration:" << std::endl;
    Stack s1;
    
    s1 << 10 << 20 << 30;
    
    std::cout << "stack after adding 10, 20, 30: ";
    for (int i = 0; i < s1.size(); i++) {
        std::cout << s1[i] << " ";
    }
    std::cout << std::endl;
    
    int value;
    s1 >> value;
    std::cout << "extracted element: " << value << std::endl;
    
    return 0;
}