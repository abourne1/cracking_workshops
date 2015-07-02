#include <iostream>
#include "LinkedList.h"

int main()
{
	std::cout<<"LinkedList program\n";
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

	return 0;
}