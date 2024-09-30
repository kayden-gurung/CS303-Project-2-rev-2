#include "Vector.h"

// Constructor: Initializes the stack with the default initial capacity
template <typename T>
Stack<T>::Stack() {
    current_capacity = INITIAL_CAPACITY;
    num_items = 0;
    the_data = new T[current_capacity];
}

// Destructor: Frees the allocated memory
template <typename T>
Stack<T>::~Stack() {
    delete[] the_data;
}

// Push an element onto the stack
template <typename T>
void Stack<T>::push(const T& item) {
    if (num_items == current_capacity) {
        // If the stack is full, double the capacity
        current_capacity *= 2;
        T* new_data = new T[current_capacity];

        // Copy old elements to the new array
        for (size_t i = 0; i < num_items; ++i) {
            new_data[i] = the_data[i];
        }

        delete[] the_data;  // Free old memory
        the_data = new_data;  // Assign to new array
    }
    the_data[num_items++] = item;  // Add the new element
}

// Pop an element from the stack
template <typename T>
T Stack<T>::pop() {
    if (num_items == 0) {
        throw out_of_range("Stack is empty!");  // Throw exception if empty
    }
    return the_data[--num_items];  // Return the top element and decrement count
}

// Check if the stack is empty
template <typename T>
bool Stack<T>::empty() const {
    return num_items == 0;
}

// Get the top element of the stack
template <typename T>
T Stack<T>::top() const {
    if (num_items == 0) {
        throw out_of_range("Stack is empty!");  // Throw exception if empty
    }
    return the_data[num_items - 1];  // Return the top element
}

// Calculate the average value of stack elements
template <typename T>
double Stack<T>::average() const {
    if (num_items == 0) {
        throw out_of_range("Stack is empty! Cannot calculate average.");
    }

    T sum = 0;  // Sum of all elements in the stack
    for (size_t i = 0; i < num_items; ++i) {
        sum += the_data[i];
    }

    return static_cast<double>(sum) / num_items;  // Return average as double
}

// Explicit instantiation for int type
template class Stack<int>;