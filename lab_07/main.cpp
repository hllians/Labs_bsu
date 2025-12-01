#include <iostream>
#include "student.h"
#include "student1.h"
#include "student2.h"

int main() {
    int marks1[4] = {9, 10, 8, 9};
    int marks2[5] = {10, 9, 10, 8, 9};
    Student2 uliana("Uliana Hlushanko", 1, "CS-4", "CS24001", marks1, marks2);
    
    int marks_acs[4] = {7, 6, 8, 7};
    Student1 ivan("Ivan Petrov", 2, "ACS-3", "ACS23015", marks_acs);
    
    Student2 kristina = uliana;
    kristina.setName("Kristinochka Shutro");
    kristina.setMark(0, 8);
    
    std::cout << "students info:\n";
    std::cout << "1. " << uliana.getName() << " (CS-4):\n" << uliana;
    std::cout << "\n2. " << ivan.getName() << " (ACS-3):\n" << ivan;
    
    std::cout << "\ntesting setters:\n";
    std::cout << "changing Uliana's course from " << uliana.getCourse();
    uliana.setCourse(2);
    std::cout << " to " << uliana.getCourse() << std::endl;
    
    std::cout << "\nmarks access:\n";
    std::cout << "Uliana's 1st mark: " << uliana.getMark(0);
    uliana.setMark(0, 10);
    std::cout << " -> improved to " << uliana.getMark(0) << std::endl;
    
    const int SIZE = 3;
    Student* students[SIZE];
    students[0] = &uliana;
    students[1] = &ivan;
    students[2] = &kristina;
    
    std::cout << "\narray averages:\n";
    double total = 0;
    for(int i = 0; i < SIZE; i++) {
        std::cout << students[i]->getName() << ": " 
                  << students[i]->getAverage() << std::endl;
        total += students[i]->getAverage();
    }
    std::cout << "total average: " << total / SIZE << std::endl;
    
    Student1* group1[] = {&uliana, &ivan, &kristina};
    Student2* group2[] = {&uliana, &kristina};
    
    std::cout << "\ngroup statistics:\n";
    std::cout << "group CS-4 after 1st session: " 
              << groupAvg1(group1, 3, "CS-4") << std::endl;
    std::cout << "group CS-4 after year: " 
              << groupAvg2(group2, 2, "CS-4") << std::endl;
    
    std::cout << "\nunique IDs:\n";
    for(int i = 0; i < SIZE; i++) {
        std::cout << students[i]->getName() << " - ID#" 
                  << students[i]->getId() << std::endl;
    }
    
    return 0;
}