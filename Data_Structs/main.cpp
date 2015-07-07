#include <iostream>
#include "LinkedList.h"
#include "Stack.h"

int main()
{
	std::cout<<"LinkedList check:\n";
	LinkedList ll;
	ll.size(); // should be empty
	// some checks
	std::cout<<"Removing from the front of an empty list: "<<ll.removeFront()<<std::endl; 
	std::cout<<"Removing from the back of an empty list: "<<ll.removeBack()<<std::endl; 
	ll.addFront(3);
	ll.addFront(2);
	ll.addFront(1);
    ll.addBack(5);
    ll.print();
    // output: 1 2 3 5
    ll.removeFront();
    std::cout<<"Removing from the front: "; ll.print();
    ll.removeBack();
    std::cout<<"Removing from the back: "; ll.print();

    ll.removeFront();
    std::cout<<"Removing from the front: "; ll.print();
    ll.removeBack();
    std::cout<<"Removing from the back: "; ll.print();

    // some checks
	std::cout<<"Removing from the front of an empty list: "<<ll.removeFront()<<std::endl; 
	std::cout<<"Removing from the back of an empty list: "<<ll.removeBack()<<std::endl; 
	//___________________________________________________________________________________
	//___________________________________________________________________________________

	std::cout<<"Stack check:\n";
	Stack st;
	st.size();
	try {
		st.pop();
	}
	catch (const std::invalid_argument& e) {
		std::cout<<"Exception: Indeed, cannot pop from an empty stack"<<std::endl;
	}

	st.push(5);
	st.push(3);
	st.push(1);
	std::cout<<"Stack of size "<< st.size() <<" and elements: "<<std::endl;
	st.print();
	std::cout<<"Pop from stack: "<<st.pop()<<std::endl;
	std::cout<<"Pop from stack: "<<st.pop()<<std::endl;
	std::cout<<"Pop from stack: "<<st.pop()<<std::endl;
	// should be no elements anymore
	std::cout<<"Stack of size "<< st.size() <<" and elements: "<<std::endl;
	st.print();
	return 0;
}