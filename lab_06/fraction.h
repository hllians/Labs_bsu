#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int numerator;
    int denominator;
    void reduce();
    
public:
    Fraction() = delete;
    Fraction(int num, int den);
    Fraction(const Fraction& f);
    
    int getNumerator() const;
    int getDenominator() const;
    
    Fraction add(const Fraction& f) const;
    Fraction multiply(const Fraction& f) const;
    Fraction divide(const Fraction& f) const;
    
    void print() const;
};

#endif