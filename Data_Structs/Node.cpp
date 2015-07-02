#include "Node.h"
    
    
Node::Node(int d)
{
    data = d;
    next = NULL;
}

int Node::getData()
{
    return data;    
}

Node* Node::getNext()
{
    return next;
}


void Node::setNext(Node* n)
{
    next = n;   
}
