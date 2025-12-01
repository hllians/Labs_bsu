#include "student.h"

int Student::nextId = 1;

Student::Student(const char* name, int course, const char* group, const char* zachetka) 
    : course(course), id(nextId++) {
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    strcpy(this->group, group);
    strcpy(this->zachetka, zachetka);
}

Student::Student(const Student& other) 
    : id(nextId++), course(other.course) {
    
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    strcpy(group, other.group);
    strcpy(zachetka, other.zachetka);
}

Student::~Student() {
    delete[] name;
}

void Student::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Student::setCourse(int course) {
    this->course = course;
}

void Student::setGroup(const char* group) {
    strcpy(this->group, group);
}

void Student::print(std::ostream& os) const {
    os << "ID: " << id << "\n";
    os << "name: " << name << "\n";
    os << "course: " << course << "\n";
    os << "group: " << group << "\n";
    os << "zachetka: " << zachetka << "\n";
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    student.print(os);
    return os;
}