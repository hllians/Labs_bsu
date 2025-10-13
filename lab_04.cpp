#include <iostream>

// A
char* _strpbrk(char* str, const char* set) {
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; set[j] != '\0'; j++) {
            if (str[i] == set[j]) return &str[i];
        }
    }
    return nullptr;
}

// B
void findWord() {
    char s[301];
    std::cout << "Enter string: ";
    std::cin.getline(s, 300);
    
    char* result = nullptr;
    char* prevResult = nullptr;
    int maxOnes = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') continue;
        int start = i;
        while (s[i] != ' ' && s[i] != '\0') i++;
        int end = i - 1;
        
        bool onlyDigits = true;
        int ones = 0;
        for (int j = start; j <= end; j++) {
            if (s[j] >= '0' && s[j] <= '9') {
                if (s[j] == '1') ones++;
            } else {
                onlyDigits = false;
                break;
            }
        }
        
        if (onlyDigits && ones > 0) {
            if (ones > maxOnes) {
                maxOnes = ones;
                prevResult = result;
                result = &s[start];
            } else if (ones == maxOnes) {
                prevResult = result;
                result = &s[start];
            }
        }
        
        if (s[i] == '\0') break;
    }
    
    if (prevResult) {
        for (char* p = prevResult; *p != ' ' && *p != '\0'; p++) {
            std::cout << *p;
        }
        std::cout << std::endl;
    } else {
        std::cout << "No suitable word found" << std::endl;
    }
}

int main() {
    // A
    char test1[] = "Hello world";
    char* res = _strpbrk(test1, "ow");
    if (res) std::cout << "Found: " << *res << std::endl;
    
    // B
    findWord();
    return 0;
}