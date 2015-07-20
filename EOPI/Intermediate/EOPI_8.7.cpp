// Design an algorithm to sort a stack S of numbers in descending order.
// The only operations allowed are push, pop, top 
// (which returns the top of the stack without a pop), and empty. 
// You cannot explicitly allocate memory outside of a few words.


// TO RUN:
// ______________________________________________
// >> g++ -o 8.7 EOPI_8.7.cpp ../../Data_Structs/Node.cpp  ../../Data_Structs/Stack.cpp
// >> ./8.7
// ______________________________________________

#include <iostream>
#include "../../Data_Structs/Node.h"
#include "../../Data_Structs/Stack.h"

// node that in this solution I am using just int's
// (because I have written Stack only in terms of ints
// and for simplicity)
// it is a better practice to write this using templates
// and pass Nodes instead of data
void insertInOrder(Stack *s, int n)
{
	if(s->empty() || s->peek() <= n) {
		s->push(n);
		return;
	}

	int temp = s->pop();
	insertInOrder(s, n);
	s->push(temp);
}

void sortStack(Stack *s)
{
	if(s->empty()) {
		return;
	}

	int curr = s->pop();
	sortStack(s);
	insertInOrder(s, curr);
}


// Meanwhile think of a time complexity
int main()
{
	Stack *s = new Stack();
	s->push(3);
	s->push(5);
	s->push(10);
	s->push(2);
	s->push(4);
	s->print();
	// Before:
	// output: 3 4 10 2 4
	// After:
	sortStack(s);
	s->print();
	// output: 10 5 4 3 2 
	return 0;
}

// Time complexity:
// O(n^2) at worst
// Why? The worst case is when stack is in ascending order
// so then InsertInorder would take O(n) time 
// but we have to run InsertInorder for each n
// thus, it would take O(n^2)
