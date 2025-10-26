#include <iostream>

// A
char* my_strpbrk(char* str, const char* set) {
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
    std::cout << "enter string: ";
    std::cin.getline(s, 300);
    
    char* lastMaxWord = nullptr;
    char* prevMaxWord = nullptr;
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
                prevMaxWord = nullptr;
                lastMaxWord = &s[start];
            } else if (ones == maxOnes) {
                prevMaxWord = lastMaxWord;
                lastMaxWord = &s[start];
            }
        }
        
        if (s[i] == '\0') break;
    }
    
    if (prevMaxWord) {
        std::cout << "found multiple words with maximum number of 1, showing penultimate: ";
        for (char* p = prevMaxWord; *p != ' ' && *p != '\0'; p++) {
            std::cout << *p;
        }
        std::cout << std::endl;
    } else if (lastMaxWord) {
        std::cout << "word with maximum number of 1: ";
        for (char* p = lastMaxWord; *p != ' ' && *p != '\0'; p++) {
            std::cout << *p;
        }
        std::cout << std::endl;
    } else {
        std::cout << "no suitable word found" << std::endl;
    }
}

int main() {
    // A
    std::cout << "A: " << std::endl;
    std::cout << "testing: searching for 'o' or 'w' in 'Hello world'" << std::endl;
    char* res = my_strpbrk("Hello world", "ow");
    if (res) std::cout << "result: found '" << *res << "' at position " << (res - "Hello world") << std::endl;
    else std::cout << "result: no matching characters found" << std::endl;
    
    // B
    std::cout << "B: " << std::endl;
    findWord();
    return 0;
}