#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

class Student {
protected:
    int id;
    char* name;
    int course;
    char group[10];
    char zachetka[15];
    
    static int nextId;
    
public:
    Student(const char* name, int course, const char* group, const char* zachetka);
    Student(const Student& other);
    virtual ~Student();
    
    Student() = delete;
    
    void setName(const char* name);
    void setCourse(int course);
    void setGroup(const char* group);
    
    int getId() const { return id; }
    const char* getName() const { return name; }
    int getCourse() const { return course; }
    const char* getGroup() const { return group; }
    const char* getZachetka() const { return zachetka; }
    
    virtual void print(std::ostream& os) const;
    virtual double getAverage() const = 0;
    virtual double getAverageFirstSession() const = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

#endif