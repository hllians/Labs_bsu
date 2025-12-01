#include "student1.h"

Student1::Student1(const char* name, int course, const char* group, 
                   const char* zachetka, const int marks[4])
    : Student(name, course, group, zachetka) {
    for(int i = 0; i < 4; i++) {
        marks1[i] = marks[i];
    }
}

Student1::Student1(const Student1& other) : Student(other) {
    for(int i = 0; i < 4; i++) {
        marks1[i] = other.marks1[i];
    }
}

int Student1::getMark(int index) const {
    if(index >= 0 && index < 4) return marks1[index];
    return -1;
}

void Student1::setMark(int index, int mark) {
    if(index >= 0 && index < 4 && mark >= 1 && mark <= 10) {
        marks1[index] = mark;
    }
}

void Student1::print(std::ostream& os) const {
    Student::print(os);
    os << "marks (1st session): ";
    for(int i = 0; i < 4; i++) os << marks1[i] << " ";
    os << "\naverage: " << getAverage() << "\n";
}

double Student1::getAverage() const {
    double sum = 0;
    for(int i = 0; i < 4; i++) sum += marks1[i];
    return sum / 4.0;
}

double Student1::getAverageFirstSession() const {
    double sum = 0;
    for(int i = 0; i < 4; i++) sum += marks1[i];
    return sum / 4.0;
}

double groupAvg1(Student1* students[], int count, const char* group) {
    double total = 0;
    int cnt = 0;
    
    for(int i = 0; i < count; i++) {
        if(strcmp(students[i]->getGroup(), group) == 0) {
            total += students[i]->getAverageFirstSession();
            cnt++;
        }
    }
    
    return cnt > 0 ? total / cnt : 0;
}