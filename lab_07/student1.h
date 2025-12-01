#ifndef STUDENT1_H
#define STUDENT1_H

#include "student.h"

class Student1 : public Student {
protected:
    int marks1[4];
    
public:
    Student1(const char* name, int course, const char* group, 
             const char* zachetka, const int marks[4]);
    Student1(const Student1& other);
    
    Student1() = delete;
    
    int getMark(int index) const;
    void setMark(int index, int mark);
    
    void print(std::ostream& os) const override;
    double getAverage() const override;
    double getAverageFirstSession() const override;
    
    friend double groupAvg1(Student1* students[], int count, const char* group);
};

#endif