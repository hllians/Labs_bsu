#include <iostream>
#include "fraction.h"

int main() {
    try {
        Fraction f1(-3, 5);
        Fraction f2(2, 8);
        
        std::cout << "f1 = "; f1.print(); std::cout << std::endl;
        std::cout << "f2 = "; f2.print(); std::cout << std::endl;
        
        Fraction f3(f1);
        std::cout << "f3 = "; f3.print(); std::cout << std::endl;
        
        std::cout << "f1 numerator: " << f1.getNumerator() << std::endl;
        std::cout << "f1 denominator: " << f1.getDenominator() << std::endl; 

        Fraction sum = f1.add(f2);
        std::cout << "f1 + f2 = "; sum.print(); std::cout << std::endl;
        
        Fraction prod = f1.multiply(f2);
        std::cout << "f1 * f2 = "; prod.print(); std::cout << std::endl;
        
        Fraction quot = f1.divide(f2);
        std::cout << "f1 / f2 = "; quot.print(); std::cout << std::endl;
                
        std::cout << "trying to create Fraction(1, 0): ";
        try {
            Fraction err(1, 0);
            std::cout << "created (should not happen)" << std::endl;
        } catch (const std::exception& e) {
            std::cout << "error: " << e.what() << std::endl;
        }
        
        std::cout << "\ndivision by zero fraction:\n";
        try {
            Fraction zero(0, 5);
            std::cout << "created zero fraction: "; zero.print(); std::cout << std::endl;
            std::cout << "trying: f1 / zero_fraction = ";
            Fraction result = f1.divide(zero);
            result.print();
            std::cout << std::endl;
        } catch (const std::exception& e) {
            std::cout << "error: " << e.what();
        }
        
    } catch (const std::exception& e) {
        std::cerr << "unexpected error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}