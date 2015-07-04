// Given a circular linked list, 
// implement an algorithm which returns the node at the beginning of the loop

// Note: read justification in the book

// TO RUN
// ______________________________________________
// >> g++ -o 2.6 CTCI_2.6.cpp ../Data_Structs/Node.cpp  ../Data_Structs/LinkedList.cpp
// >> ./2.6
// ______________________________________________
#include <iostream>
#include "../Data_Structs/Node.h"
#include "../Data_Structs/LinkedList.h"

Node *FindStartCicle(Node *head)
{
    // same starting point
    Node *slow = head;
    Node *fast = head;
    
    while (fast != NULL && fast->getNext() != NULL) {
        slow = slow->getNext();
        // twice speed
        fast = fast->getNext()->getNext();
        if (slow == fast) {
            // meeting point
            break;   
        }
    }
    
    slow = head;
    // each are k nodes away from the start of the loop
    while(slow != fast) {
        slow = slow->getNext();
        fast = fast->getNext();
    }
    
    // both point to the same node
    // return either
    return slow;
}

int main()
{
    LinkedList ll;
    ll.addFront(12);
    ll.addFront(10);
    ll.addFront(8);
    ll.addFront(6);
    ll.addFront(4);
    ll.addFront(2);
    ll.addFront(0);
    ll.print();
    // Output: 0 2 4 6 8 10 12
    // artificially create a circular linked list
    Node *temp = ll.getHead();
    Node *temp2;
    while(temp->getNext() != NULL) {
        // this will be the start of the loop
        if(temp->getData() == 10) {
            temp2 = temp;
        }
        temp = temp->getNext();
    }
    temp->setNext(temp2);
    std::cout<<"Beginning of the loop: "<<FindStartCicle(ll.getHead())->getData()<<std::endl;
    // Output: 6
    // Note try changing code to make the beginning of the loop other nodes
    // except for the last node (guess why?)
    return 0;
}
