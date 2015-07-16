// TO RUN:
// ______________________________________________
// >> g++ -o 7.9 EOPI_7.9.cpp ../../Data_Structs/Node.cpp  ../../Data_Structs/LinkedList.cpp
// >> ./7.9
// ______________________________________________

#include <iostream>
#include "../../Data_Structs/Node.h"
#include "../../Data_Structs/LinkedList.h"

Node* reverseLinkedListHelper(Node *head, Node **n_head)
{
	if(head->getNext() == NULL) {
        // we got to the end
        // return the last node
        // and save it in *n_head
        // since it will be a new head now
        *n_head = head;
        return head;
    }

    // n_node in this case will be a next node 
    // of the current node in the original linkedlist
	Node *n_node = reverseLinkedListHelper(head->getNext(), n_head);
    // now next node should point to the current node
    n_node->setNext(head);
    // this is mostly done for the last node 
    // (first node in original linkedlist)
    // since it should point to NULL
    head->setNext(NULL);
    
    // return current node
    return head;
}

Node* reverseLinkedList(Node *head)
{
    // we should capture the head
    // use a double pointer for that
    Node *n_head = NULL;
    // note we are passing a & of n_head
    reverseLinkedListHelper(head, &n_head);

    // return new head
    return n_head;
}

int main()
{
    LinkedList ll;
    ll.addFront(4);
    ll.addFront(3);
    ll.addFront(2);
    ll.addFront(1);
    std::cout<<"Before: ";
    ll.print();
    // Output:
    // Before: 1 2 3 4
    std::cout<<"Reversed: ";
    ll.setHead(reverseLinkedList(ll.getHead()));
    ll.print();
    return 0;
}
