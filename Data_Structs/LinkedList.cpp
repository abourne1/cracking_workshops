#include <iostream>

#include "LinkedList.h"

LinkedList::LinkedList()
{   
    head = NULL;
}

LinkedList::LinkedList(int d)
{   
    head= new Node(d);
}

Node* LinkedList::addFront(int d)
{
    Node *temp = new Node(d);
    temp->setNext(head);
    head = temp;
    
    return head;
}

Node* LinkedList::addBack(int d)
{
    Node *node = new Node(d);
    
    if (head == NULL) {
        head = node;   
    }
    
    Node *temp = head;
    while(temp->getNext() != NULL) {
        temp = temp->getNext();
    }
    temp->setNext(node);
    return node;
}

// efficient since we have a pointer to the head
// const time
bool LinkedList::removeFront()
{
    if(head != NULL) {
        Node *temp = head;
        head = head->getNext();
        delete temp;

        return true;
    }

    return false;
}

// not very efficient since we do NOT have a pointer to the head
// O(N)
bool LinkedList::removeBack()
{
    // empty list
    if(head == NULL) {
        return false;
    } 

    Node *tmp = head;
    // case of one element
    if (head->getNext() == NULL) {
        delete tmp;
        head = NULL;

        return true;
    }

    while(tmp->getNext()->getNext() != NULL) {
        tmp = tmp->getNext();
    }

    Node *tmp2 = tmp->getNext();
    tmp->setNext(NULL);

    delete tmp2;
    return true;
}

int LinkedList::size()
{
    int counter = 0;
    Node *temp = head;
    while(temp != NULL) { 
        temp = temp->getNext();
        counter++; 
    }
    return counter;
}


void LinkedList::print()
{
    Node *temp = head;
    while(temp != NULL) {
        std::cout<<temp->getData()<<" "; 
        temp = temp->getNext();
    }
    std::cout<<std::endl;
    
}
