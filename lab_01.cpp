#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    long double x;
    int k;
    
    cout << "Input x, k: ";
    cin >> x >> k;
    
    long double epsilon = pow(10, -k);
    long double sum = 1.0;
    long double term = 1.0;
    int n = 1;
    
    while (fabs(term) >= epsilon) {
        term = term * x * x / ((2*n - 1) * (2*n));
        sum += term;
        n++;
    }
    
    long double exact = (exp(x) + exp(-x)) / 2;
    
    cout << fixed << setprecision(k);
    cout << "Ряд Тейлора:  ch(" << x << ") = " << sum << endl;
    cout << "Стандартная:  ch(" << x << ") = " << exact << endl;
}