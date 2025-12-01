#include "fraction.h"
#include <iostream>
#include <cmath>

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void Fraction::reduce() {
    if (denominator == 0) throw std::invalid_argument("denominator is 0");
    
    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
    
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (den == 0) throw std::invalid_argument("denominator is 0");
    reduce();
}

Fraction::Fraction(const Fraction& f) : numerator(f.numerator), denominator(f.denominator) {}

int Fraction::getNumerator() const { return numerator; }
int Fraction::getDenominator() const { return denominator; }

Fraction Fraction::add(const Fraction& f) const {
    int n = numerator * f.denominator + f.numerator * denominator;
    int d = denominator * f.denominator;
    return Fraction(n, d);
}

Fraction Fraction::multiply(const Fraction& f) const {
    int n = numerator * f.numerator;
    int d = denominator * f.denominator;
    return Fraction(n, d);
}

Fraction Fraction::divide(const Fraction& f) const {
    if (f.numerator == 0) throw std::invalid_argument("division by zero");
    int n = numerator * f.denominator;
    int d = denominator * f.numerator;
    return Fraction(n, d);
}

void Fraction::print() const {
    if (denominator == 1) std::cout << numerator;
    else if (numerator == 0) std::cout << "0";
    else {
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            std::cout << "-" << abs(numerator) << "/" << abs(denominator);
        } else {
            std::cout << abs(numerator) << "/" << abs(denominator);
        }
    }
}