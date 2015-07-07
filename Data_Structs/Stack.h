#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <string>
#include <iostream>
#include "Node.h"

class Stack {

private:

	Node* top;
	int sSize;

public:
	// Pre:  true
	// Post: stack is empty
	Stack() : top(NULL), sSize(0) {};

	// Pre:  true
	// Post: the value i is added to the top of stack
	void push(int i);

	// Pre:  stack is not empty
	// Post: a value x is removed from the top of the stack
	//   AND the value x is returned
	int pop();

	// Pre:  stack is not empty
	// Post: stack is unchanged
	//   AND the value at the top of the stack is returned
	int peek();

	// Pre:  true
	// Post: size of stack is returned
	int size();

	// Pre:  true
	// Post: outputs the contents of the stack
	void print();
	// Pre:  true
	// Post: true
	~Stack();
};


#endif // STACK_H_INCLUDED