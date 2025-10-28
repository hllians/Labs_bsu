#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 100;

int main() {
    double arr[MAX_SIZE];
    int n, choice;

    do {
        cout << "enter the number of elements (1 to " << MAX_SIZE << "): ";
        cin >> n;
        if (n < 1 || n > MAX_SIZE) {
            cout << "error! number must be between 1 and " << MAX_SIZE << endl;
        }
    } while (n < 1 || n > MAX_SIZE);

    cout << "\nchoose filling method:" << endl;
    cout << "1 - manual input" << endl;
    cout << "2 - random generation" << endl;
    cout << "your choice (1 or 2): ";
    
    do {
        cin >> choice;
        if (choice != 1 && choice != 2) {
            cout << "error! please enter 1 or 2: ";
        }
    } while (choice != 1 && choice != 2);

    if (choice == 1) {
        cout << "\nenter " << n << " elements:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "element " << i + 1 << ": ";
            cin >> arr[i];
        }
    } else {
        double a, b;
        cout << "\nenter the range for random numbers (min max): ";
        cin >> a >> b;
        
        if (a > b) {
            cout << "min > max, then swapping these values..." << endl;
            swap(a, b);
        }
        
        srand(time(0));
        for (int i = 0; i < n; i++) {
            arr[i] = a + (rand() / (double)RAND_MAX) * (b - a);
        }
    }

    cout << fixed << setprecision(2);
    cout << "\narray: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "\nlocal minimum indices: ";
    bool foundLocalMin = false;
    for (int i = 0; i < n; i++) {
        bool isLocalMin = false;
        
        if (n == 1) {
            isLocalMin = true;
        } else if (i == 0) {
            isLocalMin = (arr[i] < arr[i + 1]);
        } else if (i == n - 1) {
            isLocalMin = (arr[i] < arr[i - 1]);
        } else {
            isLocalMin = (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]);
        }
        
        if (isLocalMin) {
            cout << i + 1 << " ";
            foundLocalMin = true;
        }
    }
    
    if (!foundLocalMin) {
        cout << "none";
    }
    cout << endl;

    int firstMinIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[firstMinIndex]) {
            firstMinIndex = i;
        }
    }

    cout << "\nfirst minimum element at position: " << firstMinIndex + 1 << endl;
    
    if (firstMinIndex == n - 1) {
        cout << "no elements after the first minimum element" << endl;
    } else {
        double sum = 0;
        for (int i = firstMinIndex + 1; i < n; i++) {
            sum += arr[i];
        }
        cout << "sum of elements after first minimum: " << sum << endl;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (fabs(arr[j]) > fabs(arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "\narray sorted by absolute values: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}