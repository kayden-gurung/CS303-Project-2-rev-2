#pragma once
#include <iostream>  // For basic I/O operations
#include <stdexcept> // For exception handling

using namespace std;

// Template class for a simple Stack
template <typename T>
class Stack {
private:
    static const size_t INITIAL_CAPACITY = 10; // Initial capacity of the stack
    size_t current_capacity;   // The current capacity of the stack
    size_t num_items;          // The number of elements currently in the stack
    T* the_data;               // Pointer to dynamically allocated array

public:
    // Constructor
    Stack();

    // Destructor
    ~Stack();

    // Push an element onto the stack
    void push(const T& item);

    // Pop an element from the stack
    T pop();

    // Check if the stack is empty
    bool empty() const;

    // Find the top element of the stack
    T top() const;

    // Calculate the average value of the stack elements
    double average() const;
};