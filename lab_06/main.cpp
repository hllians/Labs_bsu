#include <iostream>
#include "fraction.h"

int main() {
    Fraction f1(-3, 5);
    Fraction f2(2, 8);
    
    std::cout << "f1 = "; f1.print(); std::cout << std::endl;
    std::cout << "f2 = "; f2.print(); std::cout << std::endl;
    
    Fraction f3(f1);
    std::cout << "f3 = "; f3.print(); std::cout << std::endl;
    
    std::cout << "f1 numerator: " << f1.getNumerator() << std::endl;
    std::cout << "f1 denominator: " << f1.getDenominator() << std::endl; 

    std::cout << "f1 + f2 = "; f1.add(f2).print(); std::cout << std::endl;
    std::cout << "f1 * f2 = "; f1.multiply(f2).print(); std::cout << std::endl;
    std::cout << "f1 / f2 = "; f1.divide(f2).print(); std::cout << std::endl;
        
    std::cout << "creating Fraction(1, 0): ";
    try {
        Fraction err(1, 0);
        std::cout << "success (should not happen!)" << std::endl;
    } catch (...) {
        std::cout << "error: zero denominator" << std::endl;
    }
    
    try {
        Fraction zero(0, 5);
        std::cout << "zero fraction(0, 5) created: "; zero.print(); std::cout << std::endl;
        std::cout << "f1 / zero = ";
        f1.divide(zero).print();
        std::cout << std::endl;
    } catch (...) {
        std::cout << "error: division by zero" << std::endl;
    }
    
    return 0;
}