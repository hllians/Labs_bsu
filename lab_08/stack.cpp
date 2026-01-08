#include "stack.h"
#include <stdexcept>

Stack::Stack() : capacity(10), topIndex(-1) {
    data = new int[capacity];
}

Stack::Stack(const Stack& other) : capacity(other.capacity), topIndex(other.topIndex) {
    data = new int[capacity];
    for (int i = 0; i <= topIndex; i++) {
        data[i] = other.data[i];
    }
}

Stack::~Stack() {
    delete[] data;
}

void Stack::resize() {
    capacity *= 2;
    int* newData = new int[capacity];
    for (int i = 0; i <= topIndex; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

void Stack::push(int value) {
    if (topIndex + 1 >= capacity) {
        resize();
    }
    data[++topIndex] = value;
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return data[topIndex--];
}

bool Stack::isEmpty() const {
    return topIndex == -1;
}

int Stack::size() const {
    return topIndex + 1;
}

void Stack::clear() {
    topIndex = -1;
}

Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        topIndex = other.topIndex;
        data = new int[capacity];
        for (int i = 0; i <= topIndex; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

bool Stack::operator==(const Stack& other) const {
    if (topIndex != other.topIndex) return false;
    for (int i = 0; i <= topIndex; i++) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

bool Stack::operator<(const Stack& other) const {
    return size() < other.size();
}

int Stack::operator[](int index) const {
    if (index < 0 || index > topIndex) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

Stack& operator<<(Stack& stack, int value) {
    stack.push(value);
    return stack;
}

Stack& operator>>(Stack& stack, int& value) {
    value = stack.pop();
    return stack;
}