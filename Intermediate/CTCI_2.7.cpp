// Implement a function to check if a linked is a palindrome

// TO RUN:
// ______________________________________________
// >> g++ -o 2.7 CTCI_2.7.cpp ../Data_Structs/Node.cpp  ../Data_Structs/LinkedList.cpp
// >> ./2.7
// ______________________________________________

#include <iostream>
#include "../Data_Structs/Node.h"
#include "../Data_Structs/LinkedList.h"

// where return value is 0 or 1
// Recursive approach
// Recommendation: To understand better how this works,add some print statements and see 
// how the (Node *next) changes
int isPalindrome(Node *head, int length, Node **next)
{
    if(head == NULL || length == 0) {
        // basis case
        return 1;
    }
    else if (length == 1) {
        // if linked list has odd length
        // That is actually where we set *next for the first time
        // remember up until this it was NULL
        *next = head->getNext();
        return 1;
    }
    else if (length == 2) {
        // if linked list has even length
        // That is actually where we set *next for the first time
        // remember up until this it was NULL
        *next = head->getNext()->getNext();
        // we got to the middle of the linked list
        // compare the elements
        return head->getData() == head->getNext()->getData();
    }
    
    int res = isPalindrome(head->getNext(), length - 2, next);
    if (res == 0 || *next == NULL) {
        return res;
    }

    res = (head->getData() == (*next)->getData());
    // we have set (*next) in if statements above
    // so now we just need to keep moving (*next) by one
    *next = (*next)->getNext();
    
    return res;
}


int main()
{
    LinkedList ll;
    ll.addFront(10);
    ll.addFront(8);
    ll.addFront(6);
    ll.addFront(4);
    ll.addFront(4);
    ll.addFront(6);
    ll.addFront(8);
    ll.addFront(10);
    std::cout<<"Before: ";
    ll.print();
    // Output:
    // Before: 8 0 6 4 2 10 
    Node *next = NULL;
    std::cout<<"Is planidrome? "<<isPalindrome(ll.getHead(), ll.size(), &next)<<std::endl;
    //____________________________________________________________________________________
    ll.addFront(10);
    std::cout<<"Adding one in the front: ";
    ll.print();
    std::cout<<"Is planidrome? "<<isPalindrome(ll.getHead(), ll.size(), &next)<<std::endl;
    //____________________________________________________________________________________
    ll.addBack(10);
    std::cout<<"Adding one in the back: ";
    ll.print();
    std::cout<<"Is planidrome? "<<isPalindrome(ll.getHead(), ll.size(), &next)<<std::endl;
    return 0;
}


