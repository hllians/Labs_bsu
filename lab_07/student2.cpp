#include "student2.h"

Student2::Student2(const char* name, int course, const char* group, 
                   const char* zachetka, const int marks1[4], const int marks2[5])
    : Student1(name, course, group, zachetka, marks1) {
    for(int i = 0; i < 5; i++) {
        this->marks2[i] = marks2[i];
    }
}

Student2::Student2(const Student2& other) : Student1(other) {
    for(int i = 0; i < 5; i++) {
        marks2[i] = other.marks2[i];
    }
}

int Student2::getMark2(int index) const {
    if(index >= 0 && index < 5) return marks2[index];
    return -1;
}

void Student2::setMark2(int index, int mark) {
    if(index >= 0 && index < 5 && mark >= 1 && mark <= 10) {
        marks2[index] = mark;
    }
}

void Student2::print(std::ostream& os) const {
    Student::print(os);
    os << "marks (1st session): ";
    for(int i = 0; i < 4; i++) os << marks1[i] << " ";
    os << "\nmarks (2nd session): ";
    for(int i = 0; i < 5; i++) os << marks2[i] << " ";
    os << "\nyear average: " << getAverage() << "\n";
}

double Student2::getAverage() const {
    double sum = 0;
    for(int i = 0; i < 4; i++) sum += marks1[i];
    for(int i = 0; i < 5; i++) sum += marks2[i];
    return sum / 9.0;
}

double Student2::getAverageFirstSession() const {
    double sum = 0;
    for(int i = 0; i < 4; i++) sum += marks1[i];
    return sum / 4.0;
}

double groupAvg2(Student2* students[], int count, const char* group) {
    double total = 0;
    int cnt = 0;
    
    for(int i = 0; i < count; i++) {
        if(strcmp(students[i]->getGroup(), group) == 0) {
            total += students[i]->getAverage();
            cnt++;
        }
    }
    
    return cnt > 0 ? total / cnt : 0;
}