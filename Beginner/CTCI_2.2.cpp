// Task
// implement and algorithm to find kth to last element of a singly linked list 

// if we know the size, problem is trivial
// otherwise, assumption: k = 1 would return the last element

// TO RUN:
// ______________________________________________
// >> g++ -o 2.2 CTCI_2.2.cpp ../Data_Structs/Node.cpp  ../Data_Structs/LinkedList.cpp
// >> ./2.2
// ______________________________________________

// Note: there is already a solution provided in C++ in the book
#include <iostream>
#include "../Data_Structs/Node.h"
#include "../Data_Structs/LinkedList.h"

Node *nthToLast(Node *start, int k, int &depth)
{
    if(start == NULL) {
        return NULL;   
    }
    // here since we recusrsively call the function
    // depth is updated by reference on each step
    // until the end (NULL) is reached
    // thats the final value of depth
    Node *nd = nthToLast(start->getNext(), k, depth);
    // include this current call (current node) as well
    depth++;
    
    if(depth == k) {
        return start;   
    }
    
    return nd;
}

int main()
{
    LinkedList ll;
    ll.addFront(10);
    ll.addFront(8);
    ll.addFront(6);
    ll.addFront(4);
    ll.addFront(2);
    ll.addFront(0);
    ll.print();
    int depth = 0;
    // Output: 0 2 4 6 8 10
    std::cout<<nthToLast(ll.getHead(), 4, depth)->getData()<<std::endl;
    // Output: 4
    // Indeed, 4 is the fourth to last element in this linked list
    return 0;
}

// space O(n)
// time O(n)
// Note: there is a preferred non-recusrive solution
// just set two pointers k apart
