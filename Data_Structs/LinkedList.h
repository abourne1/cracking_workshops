#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList  
{
    private:
        Node* head;
    
    public:
        LinkedList();
        LinkedList(int data);
        Node *getHead();
        void setHead(Node *n_head);
        Node *addFront(int data);
        Node *addBack(int data);
        bool removeFront();
        bool removeBack();
        int size();
        void print();
};

#endif