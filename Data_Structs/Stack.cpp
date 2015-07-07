#include <iostream>
#include <stdexcept>
#include "Stack.h"

void Stack::push(int i) 
{
	Node* node = new Node(i);
	node->setNext(top);
	top = node;
	sSize++;

	return;
}

int Stack::pop() 
{
	if(top == NULL) {
		throw std::invalid_argument( " cannot remove from an empty stack" );
	}
	Node* toRemove = top;
	top = top->getNext();
	int val = toRemove->getData();
	delete toRemove;
	sSize--;

	return val;
}

int Stack::peek() 
{
	return top->getData();
}

int Stack::size() {

	return sSize;
}

void Stack::print() 
{
	Node* cursor = top;
	while (cursor != NULL) {
		std::cout << cursor->getData() << " ";
		cursor = cursor->getNext();
	}
	std::cout << std::endl;

	return;
}

Stack::~Stack() 
{

	Node* cursor = top;
	while (cursor != NULL) {
		Node* next = cursor->getNext();
		delete cursor;
		cursor = next;
	}

	return;
}