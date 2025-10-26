#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string inputFile, outputFile;
    
    cout << "input file name: ";
    cin >> inputFile;
    
    cout << "output file name: ";
    cin >> outputFile;
    
    ifstream inFile(inputFile);
    if (!inFile) {
        cout << "error (opening input file)" << endl;
        return 1;
    }
    
    ofstream outFile(outputFile);
    if (!outFile) {
        cout << "error (creating output file)" << endl;
        return 1;
    }
    
    cout << "\ninput file content:\n";
    string line, prevLine = "";
    bool firstLine = true;
    while (getline(inFile, line)) {
        cout << line << endl;
        
        if (firstLine || line != prevLine) {
            outFile << line << endl;
        }
        prevLine = line;
        firstLine = false;
    }
    
    inFile.close();
    outFile.close();
    
    cout << "\noutput file content:\n";
    ifstream resultFile(outputFile);
    
    if (resultFile) {
        string content;
        bool isEmpty = true;
        
        while (getline(resultFile, content)) {
            cout << content << endl;
            isEmpty = false;
        }
        
        if (isEmpty) {
            cout << "(file is empty)" << endl;
        }
        
        resultFile.close();
    }
    
    return 0;
}