// write code to partition a linked list around a value of x such that all nodes less than x come 
// before all nodes greater than or equal to x

// idea: add the node in front if < x
// add the nodes in the back otherwise

// TO RUN:
// ______________________________________________
// >> g++ -o 2.4 CTCI_2.4.cpp ../Data_Structs/Node.cpp  ../Data_Structs/LinkedList.cpp
// >> ./2.4
// ______________________________________________

// Note: there is already a solution provided in C++ in the book
#include <iostream>
#include "../Data_Structs/Node.h"
#include "../Data_Structs/LinkedList.h"
Node* partition(Node* head, int x)
{
    Node *front = head;
    Node *back = head;
    while(head != NULL)
    {
        Node *next = head->getNext();
        if(head->getData() <= x) {
            head->setNext(front);
            front = head;
        } else {
            back->setNext(head);
            back = head;
        }
        head = next;
    }
    
    back->setNext(NULL);
    
    return front;
    
}

int main()
{
    LinkedList ll;
    ll.addFront(10);
    ll.addFront(2);
    ll.addFront(4);
    ll.addFront(6);
    ll.addFront(0);
    ll.addFront(8);
    std::cout<<"Before: ";
    ll.print();
    // Output:
    // Before: 8 0 6 4 2 10 
    // not the best practice to not use LinkedList
    // but that work is not crucial for the udnerstanding of this exercise
    Node *front = partition(ll.getHead(), 4);
    std::cout<<"After: ";
    while(front != NULL) {
        std::cout<<front->getData()<<" ";
        front = front->getNext();
    }
    std::cout<<std::endl;
    // Output:
    // After: 2 4 0 8 6 10 
    // Note it is not sorted* (it is just partitioned as required)
    return 0;

}
