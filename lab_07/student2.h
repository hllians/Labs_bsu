#ifndef STUDENT2_H
#define STUDENT2_H

#include "student1.h"

class Student2 : public Student1 {
private:
    int marks2[5];
    
public:
    Student2(const char* name, int course, const char* group, 
             const char* recordBook, const int marks1[4], const int marks2[5]);
    Student2(const Student2& other);
    
    Student2() = delete;
    
    int getMark2(int index) const;
    void setMark2(int index, int mark);
    
    void print(std::ostream& os) const override;
    double getAverage() const override;
    
    friend double groupAvg2(Student2* students[], int count, const char* group);  // БЕЗ const
};

#endif