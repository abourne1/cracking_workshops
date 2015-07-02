#ifndef NODE_H
#define NODE_H
#include <stdlib.h>

class Node
{
    private:
        int data;
        Node *next;
    public:
    	Node(): next(NULL) {};
        Node(int data);
        int getData();
        Node *getNext();
        void setNext(Node* n);
};

#endif