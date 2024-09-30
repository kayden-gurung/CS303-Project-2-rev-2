#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
	Node* nextNode = nullptr;
	string data;

};

class LinkedList {
private:
	Node* headNode = nullptr;

	string data;
	int num_items = 0;

public:
	void push_front(string data);
	void push_back(string data);
	string pop_front();
	string pop_back();

	string front();
	string back();

	bool empty();

	void insert(int index, const string data);

	bool remove(int index);

	int find(const string data);

};








template <typename T>
class Stack {
private:
    static const size_t INITIAL_CAPACITY = 10; 
    size_t current_capacity;   
    size_t num_items;           
    T* the_data;

public:
    // constructor
    Stack();

    // destructor
    ~Stack();

    // push onto stack
    void push(const T& item);

    // pop from stack
    T pop();

    // is stack empty
    bool empty() const;

    // return top element
    T top() const;

    // average value of stack
    double average() const;
};