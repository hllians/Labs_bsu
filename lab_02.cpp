#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_SIZE = 100;

int main() {
    double arr[MAX_SIZE];
    int n, choice;

    do {
        cout << "input the number of elements (1-" << MAX_SIZE << "): ";
        cin >> n;
    } while (n < 1 || n > MAX_SIZE);

    cout << "filling method (1 - manual, 2 - random): ";
    cin >> choice;
    if (choice == 1) {
        for (int i = 0; i < n; i++) cin >> arr[i];
    } else {
        int a, b;
        cout << "array boundaries: ";
        cin >> a >> b;
        srand(time(0));
        for (int i = 0; i < n; i++) arr[i] = a + rand() % (b - a + 1);
    }

    cout << "array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "local min: ";
    for (int i = 1; i < n - 1; i++)
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
            cout << i + 1 << " ";
    cout << endl;

    int firstMinIndex = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[firstMinIndex])
            firstMinIndex = i;

    if (firstMinIndex == n - 1) {
        cout << "no elements after the first min" << endl;
    } else {
        double sum = 0;
        for (int i = firstMinIndex + 1; i < n; i++) sum += arr[i];
        cout << "sum after the first min: " << sum << endl;
    }

    for (int i = 0; i < n - 1; i++) //пузырьковая сортировка
        for (int j = 0; j < n - i - 1; j++)
            if (fabs(arr[j]) > fabs(arr[j + 1]))
                swap(arr[j], arr[j + 1]);

    cout << "sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}