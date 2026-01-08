#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack {
private:
    int* data;
    int capacity;
    int topIndex;
    
    void resize();
    
public:
    Stack();
    Stack(const Stack& other);
    ~Stack();
    
    void push(int value);
    int pop();
    bool isEmpty() const;
    int size() const;
    void clear();
    
    Stack& operator=(const Stack& other);
    bool operator==(const Stack& other) const;
    bool operator<(const Stack& other) const;
    int operator[](int index) const;
    
    friend Stack& operator<<(Stack& stack, int value);
    friend Stack& operator>>(Stack& stack, int& value);
};

#endif