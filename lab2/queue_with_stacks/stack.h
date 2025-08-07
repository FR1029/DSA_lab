#include <cstdlib>
#include <cstddef>
#pragma once

/*
 * You must NOT add ANY other includes than this.
 * The purpose of this file is to implement the functioning of a stack in C++.
 * Implement all the method functions in this file, your way.
 * Ensure that ALL of them are on average constant time. Amortized O(1) is OK.
 * You must NOT change the method signature of any of the methods.
 * You may add any additional methods or data members as you need.
 * Those methods and data members should be protected.
 */

template <typename T>
class Stack {
    // ADD ANY ADDITIONAL DATA MEMBERS OR METHODS HERE
    T* arr;
    size_t capacity;
    size_t size;
    void resize() {
        capacity *= 2;
        T* new_arr = new T[capacity];
        for(size_t i = 0; i < size; i++) new_arr[i] = arr[i];
        delete[] arr;
        arr = new_arr;
    }
    // DO NOT CHANGE THE METHOD SIGNATURES BELOW
public:
    Stack();
    ~Stack();
    void push(T value);
    T pop();
    T peek();
    bool isEmpty();
    size_t getSize();
};

// ENTER YOUR IMPLEMENTATIONS OF METHODS BELOW

template <typename T>
Stack<T>::Stack() : capacity(4), size(0) {
    arr = new T[capacity];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] arr;
}

template <typename T>
void Stack<T>::push(T value) {
    if (size == capacity) resize();
    arr[size++] = value;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) throw std::runtime_error("Stack underflow");
    return arr[--size];
}

template <typename T>
T Stack<T>::peek() {
    if (isEmpty()) throw std::runtime_error("Stack underflow");
    return arr[size - 1];
}

template <typename T>
bool Stack<T>::isEmpty() {
    return size == 0;
}

template <typename T>
size_t Stack<T>::getSize() {
    return size;
}