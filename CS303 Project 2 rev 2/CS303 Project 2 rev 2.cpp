// CS303 Project 2 rev 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Function.h"
#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    cout << "Hello World!\n";
    LinkedList list;
    cout << list.empty() << endl;;
    list.push_front("First");
    list.push_back("Second");
    cout << list.front() << endl;
    cout << list.back() << endl;
    cout << list.find("Second");
    cout << "" << endl;








    Stack<int> myStack; 

    cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    // check to see if empty after add
    cout << "Is the stack empty after pushing elements? " << (myStack.empty() ? "Yes" : "No") << endl;

    // return top element of stack
    cout << "Top element is: " << myStack.top() << endl;

    // remove element of stack
    cout << "Popped element: " << myStack.pop() << endl;

    // return new top element of stack
    cout << "New top element is: " << myStack.top() << endl;

    // calculate average from stack
    cout << "Average value of the stack elements: " << myStack.average() << endl;

    return 0;
}


