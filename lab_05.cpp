#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string inputFile, outputFile;
    
    cout << "Введите имя входного файла: ";
    cin >> inputFile;
    
    cout << "Введите имя выходного файла: ";
    cin >> outputFile;
    
    ofstream outFile(outputFile);
    if (!outFile) {
        cout << "Ошибка создания выходного файла!" << endl;
        return 1;
    }
    
    ifstream inFile(inputFile);
    if (!inFile) {
        cout << "Ошибка открытия входного файла!" << endl;
        return 1;
    }
    
    cout << "\nСодержимое входного файла:\n";
    string line, prevLine = "";
    bool hasContent = false;
    
    while (getline(inFile, line)) {
        cout << line << endl;
        
        if (line != prevLine) {
            outFile << line << endl;
            prevLine = line;
            hasContent = true;
        }
    }
    
    inFile.close();
    outFile.close();
    
    cout << "\nСодержимое выходного файла:\n";
    ifstream resultFile(outputFile);
    
    if (resultFile) {
        string content;
        bool isEmpty = true;
        
        while (getline(resultFile, content)) {
            cout << content << endl;
            isEmpty = false;
        }
        
        if (isEmpty) {
            cout << "(файл пуст)" << endl;
        }
        
        resultFile.close();
    }
    
    return 0;
}