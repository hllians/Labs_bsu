#include <iostream>
#include <cassert>
#include "stack.h"
#include "calculator.h"

void testStack() {
    std::cout << "stack testing..." << std::endl;
    
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    assert(s1.size() == 3);
    assert(s1[0] == 10);
    assert(s1[2] == 30);
    std::cout << "test 1 passed" << std::endl;
    
    assert(s1.pop() == 30);
    assert(s1.pop() == 20);
    assert(s1.size() == 1);
    std::cout << "test 2 passed" << std::endl;
    
    Stack s2;
    s2 << 100 << 200;
    int val;
    s2 >> val;
    assert(val == 200);
    std::cout << "test 3 passed" << std::endl;
    
    Stack s3;
    s3.push(1);
    s3.push(2);
    Stack s4 = s3;
    assert(s4 == s3);
    std::cout << "test 4 passed" << std::endl;
    
    Stack s5;
    s5.push(1);
    Stack s6;
    s6.push(1);
    s6.push(2);
    assert(s5 < s6);
    std::cout << "test 5 passed" << std::endl;
    
    std::cout << "Tests passed!" << std::endl << std::endl;
}

void testCalculator() {
    std::cout << "calculator testing..." << std::endl;
    
    Calculator calc;
    
    calc.setExpression("(2+6)/(7-5)");
    assert(calc.isValidExpression() == true);
    
    calc.setExpression("(5+7/2");
    assert(calc.isValidExpression() == false);
    
    calc.setExpression("3+");
    assert(calc.isValidExpression() == false);
    std::cout << "test 1 passed" << std::endl;
    
    calc.setExpression("2+3*4");
    assert(calc.evaluate() == 14);
    
    calc.setExpression("(2+6)/(7-5)");
    assert(calc.evaluate() == 4);
    
    calc.setExpression("10/2+3");
    assert(calc.evaluate() == 8);
    std::cout << "test 2 passed" << std::endl;
    
    std::cout << "Tests passed!" << std::endl;
}

int main() {
    testStack();
    testCalculator();
    std::cout << "\nAll tests passed successfully!" << std::endl;
    return 0;
}