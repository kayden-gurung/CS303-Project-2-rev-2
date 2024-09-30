#include "Function.h"
#include <string>
#include <iostream>

// push item to front of list
void LinkedList::push_front(string data) {
	if (num_items == 0) {
		this->headNode = new Node;
		headNode->data = data;
		// if items already in list
	} else {
		Node* newNode = headNode;
		newNode->data = data;
		newNode->nextNode = headNode;
		headNode = newNode;
	}
	
	num_items++;
}
// push items onto back of list
void LinkedList::push_back(string data) {
	if (num_items == 0) {
		push_front(data);
		// add item to back if items in list
	} else {
		Node* currNode = headNode;
		Node* newNode = new Node;
		newNode->data = data;
		while (currNode->nextNode != nullptr) {
			currNode = currNode->nextNode;
		}
		currNode->nextNode = newNode;

		num_items++;
	}

}
// pop the front of the list
string LinkedList::pop_front() {
	if (num_items == 0) {
		return "List is empty";
// dont really need this line
	} else if (num_items == 1) {
		string word = headNode->data;
		delete headNode;
		headNode = nullptr;
		num_items--;
		return word;
		// deleting
	} else {
		Node* tempNode = headNode;
		string word = headNode->data;

		headNode = headNode->nextNode;

		delete tempNode;
		tempNode = nullptr;

		num_items--;
		return word;

	}
}

// pop the last item of list
string LinkedList::pop_back() {
	if (num_items == 0) {
		pop_front();
		// loop to back and delete
	} else {
		Node* currNode = headNode;
		while (currNode->nextNode != nullptr) {
			currNode = currNode->nextNode;
		}
		// return popped value
		string word = currNode->data;
		delete currNode;
		currNode = nullptr;

		num_items--;
		return word;
	}
}

// return front item data
string LinkedList::front() {
	if (num_items == 0) {
		return "List empty.";
	} else {
		string word = headNode->data;
		return word;
	}
}

// return back item data
string LinkedList::back() {
	if (num_items == 0) {
		front();
	} else {
		Node* currNode = headNode;
		while (currNode->nextNode != nullptr) {
			currNode = currNode->nextNode;
		}
		string word = currNode->data;
		return word;
	}
}

// is list empty
bool LinkedList::empty() {
	if (num_items == 0) {
		return true;
	} return false;
}

//insert item at position
void LinkedList::insert(int index, string data) {
	if (num_items == 0 && index == 0) {
		push_front(data);

	} else if (index >= num_items) {
		push_back(data);

	} else {
		Node* currNode = headNode;
		Node* newNode = new Node;
		newNode->data = data;
		for (int i = 0;i < index - 1; i++) {
			currNode = currNode->nextNode;
		}
		newNode->nextNode = currNode->nextNode;
		currNode->nextNode = newNode;

		num_items++;

	}
}

// remove item at location
bool LinkedList::remove(int index) {
	if (num_items == 0) {
		return false;

	} else if (index >= num_items) {
		pop_back();

	} else {
		Node* currNode = headNode;
		Node* prevNode = headNode;
		for (int i = 0; i < index; i++) {
			prevNode = currNode;
			currNode = currNode->nextNode;
		}
		// change next nodes and delete node
		prevNode->nextNode = currNode->nextNode;
		delete currNode;
		currNode = nullptr;

		num_items--;
		return true;

	}
}

// find item with name
int LinkedList::find(const string data) {
	if (num_items == 0) {
		return -1;
	}
	Node* currNode = headNode;
	int i = 0;
	while (currNode->data != data || currNode->nextNode != nullptr) {
		i++;
		currNode = currNode->nextNode;
	}
	if (currNode->data == data) {
		return i;
	} else if (currNode->nextNode == nullptr) {
		return -1;
	} else {
		return 99999999;
	}

}







//construct
template <typename T>
Stack<T>::Stack() {
	current_capacity = INITIAL_CAPACITY;
	num_items = 0;
	the_data = new T[current_capacity];
}

// destruct
template <typename T>
Stack<T>::~Stack() {
	delete[] the_data;
}

// push onto stack
template <typename T>
void Stack<T>::push(const T& item) {
	if (num_items == current_capacity) {
		// if stack full, double capacity
		current_capacity *= 2;
		T* new_data = new T[current_capacity];

		// copy old elements to new one.
		for (size_t i = 0; i < num_items; ++i) {
			new_data[i] = the_data[i];
		}

		delete[] the_data; 
		the_data = new_data;  // assign new array
	}
	the_data[num_items++] = item; 
}

// pop element
template <typename T>
T Stack<T>::pop() {
	if (num_items == 0) {
		throw out_of_range("Stack is empty!");  
	}
	return the_data[--num_items];  // return and decrease
}
// is stack empty
template <typename T>
bool Stack<T>::empty() const {
	return num_items == 0;
}

// get tpp element
template <typename T>
T Stack<T>::top() const {
	if (num_items == 0) {
		throw out_of_range("Stack is empty!");  
	}
	return the_data[num_items - 1];  
}

// calc average
template <typename T>
double Stack<T>::average() const {
	if (num_items == 0) {
		throw out_of_range("Stack is empty! Cannot calculate average.");
	}

	T sum = 0;  
	for (size_t i = 0; i < num_items; ++i) {
		sum += the_data[i];
	}

	return static_cast<double>(sum) / num_items;  
}


template class Stack<int>;