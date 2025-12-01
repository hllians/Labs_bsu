#include <iostream>
#include "student.h"
#include "student1.h"
#include "student2.h"

int main() {
    int m1[4] = {5,4,3,5};
    Student1 s1("John", 1, "CS101", "CS001", m1);
    std::cout << "1. Student after 1st session:\n" << s1 << std::endl;
    
    int m2[4] = {4,5,4,3};
    int m3[5] = {5,4,5,4,3};
    Student2 s2("Mike", 1, "CS101", "CS002", m2, m3);
    std::cout << "2. Student after 2nd session:\n" << s2 << std::endl;
    
    Student2 s3 = s2;
    std::cout << "3. Copied student:\n" << s3 << std::endl;
    
    s1.setName("John Smith");
    s1.setCourse(2);
    s1.setGroup("CS102");
    std::cout << "4. After setters:\n" << s1 << std::endl;
    
    s1.setMark(0, 5);
    std::cout << "5. Mark changed: " << s1.getMark(0) << std::endl;
    
    const int SIZE = 4;
    Student* students[SIZE];
    
    students[0] = new Student1("Alice", 1, "CS101", "CS003", m1);
    students[1] = new Student2("Bob", 1, "CS101", "CS004", m2, m3);
    students[2] = new Student1("Charlie", 2, "CS102", "CS005", m1);
    students[3] = new Student2("David", 2, "CS101", "CS006", m2, m3);
    
    double totalAvg = 0;
    std::cout << "\n6. Array averages:\n";
    for(int i = 0; i < SIZE; i++) {
        double avg = students[i]->getAverage();
        std::cout << "Student " << i+1 << ": " << avg << std::endl;
        totalAvg += avg;
    }
    std::cout << "Total avg: " << totalAvg / SIZE << std::endl;
    
    Student1* group1[2] = {dynamic_cast<Student1*>(students[0]), 
                          dynamic_cast<Student1*>(students[2])};
    Student2* group2[2] = {dynamic_cast<Student2*>(students[1]), 
                          dynamic_cast<Student2*>(students[3])};
    
    std::cout << "\n7. Group CS101 avg after 1st: " 
              << groupAvg1(group1, 2, "CS101") << std::endl;
    std::cout << "Group CS101 avg after 2nd: " 
              << groupAvg2(group2, 2, "CS101") << std::endl;
    
    for(int i = 0; i < SIZE; i++) {
        delete students[i];
    }
    
    return 0;
}