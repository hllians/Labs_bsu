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
        cout << "Input the number of elements (1-" << MAX_SIZE << "): ";
        cin >> n;
    } while (n < 1 || n > MAX_SIZE);

    cout << "Filling method (1 - manual, not 1 - random): ";
    cin >> choice;
    
    if (choice == 1) {
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) cin >> arr[i];
    } else {
        double a, b;
        cout << "Enter array boundaries: ";
        cin >> a >> b;
        srand(time(0));
        for (int i = 0; i < n; i++) 
            arr[i] = a + (rand() / (double)RAND_MAX) * (b - a);
    }

    cout << fixed << setprecision(2);
    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "Local minimum indices: ";
    bool foundLocalMin = false;
    for (int i = 0; i < n; i++) {
        if ((i == 0 && n > 1 && arr[i] < arr[i + 1]) ||
            (i == n - 1 && n > 1 && arr[i] < arr[i - 1]) ||
            (i > 0 && i < n - 1 && arr[i] < arr[i - 1] && arr[i] < arr[i + 1])) {
            cout << i + 1 << " ";
            foundLocalMin = true;
        }
    }
    if (!foundLocalMin) cout << "none";
    cout << endl;

    int firstMinIndex = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[firstMinIndex])
            firstMinIndex = i;

    if (firstMinIndex == n - 1) {
        cout << "No elements after the first minimum" << endl;
    } else {
        double sum = 0;
        for (int i = firstMinIndex + 1; i < n; i++) 
            sum += arr[i];
        cout << "Sum after first minimum: " << sum << endl;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (fabs(arr[j]) > fabs(arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Sorted by absolute values: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}