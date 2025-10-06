#include <iostream>
#include <iomanip>

using namespace std;

int** createMatrix(int n) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    return matrix;
}

void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void inputMatrix(int** matrix, int n) {
    cout << "input matrix: " << n << "x" << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

bool checkSymmetric(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool isZeroRow(int** matrix, int row, int n) {
    for (int j = 0; j < n; j++) {
        if (matrix[row][j] != 0) {
            return false;
        }
    }
    return true;
}

bool isZeroColumn(int** matrix, int col, int n) {
    for (int i = 0; i < n; i++) {
        if (matrix[i][col] != 0) {
            return false;
        }
    }
    return true;
}

int** compressMatrix(int** matrix, int n, int& newSize) {
    bool* keepRow = new bool[n];
    bool* keepCol = new bool[n];
    
    for (int i = 0; i < n; i++) {
        keepRow[i] = !isZeroRow(matrix, i, n);
        keepCol[i] = !isZeroColumn(matrix, i, n);
    }
    
    int rowCount = 0;
    int colCount = 0;
    for (int i = 0; i < n; i++) {
        if (keepRow[i]) rowCount++;
        if (keepCol[i]) colCount++;
    }
    
    newSize = min(rowCount, colCount);
    
    if (newSize == 0) {
        delete[] keepRow;
        delete[] keepCol;
        return nullptr;
    }
    
    int** newMatrix = createMatrix(newSize);
    
    int newI = 0;
    for (int i = 0; i < n && newI < newSize; i++) {
        if (keepRow[i]) {
            int newJ = 0;
            for (int j = 0; j < n && newJ < newSize; j++) {
                if (keepCol[j]) {
                    newMatrix[newI][newJ] = matrix[i][j];
                    newJ++;
                }
            }
            newI++;
        }
    }
    
    delete[] keepRow;
    delete[] keepCol;
    return newMatrix;
}

int findFirstZeroRow(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "input matrix size (1-10): ";
    cin >> n;

    while (n < 1 || n > 10) {
    cout << "invalid size" << endl;
    cout << "input matrix size (1-10): ";
    cin >> n;
}
    
    int** matrix = createMatrix(n);
    inputMatrix(matrix, n);
    
    cout << "\noriginal matrix:" << endl;
    printMatrix(matrix, n);
    
    if (!checkSymmetric(matrix, n)) {
        cout << "matrix is not symmetric" << endl;
        deleteMatrix(matrix, n);
        return 1;
    }
    
    cout << "matrix is symmetric" << endl;
    
    int newSize;
    int** compressed = compressMatrix(matrix, n, newSize);
    
    if (compressed == nullptr) {
        cout << "after compression the matrix is ​​empty!" << endl;
    } else {
        cout << "\ncompressed matrix:" << endl;
        printMatrix(compressed, newSize);
        
        int zeroRow = findFirstZeroRow(compressed, newSize);
        if (zeroRow != -1) {
            cout << "first string with 0: " << zeroRow << endl;
        } else {
            cout << "no 0 in matrix" << endl;
        }
        
        deleteMatrix(compressed, newSize);
    }
    
    deleteMatrix(matrix, n);
    return 0;
}