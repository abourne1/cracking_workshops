// how would you design a stack which in addition to push and pop also has a function min 
// which returns the minimum element? 
// Push, pop, and min should all operate in O(1) time
#include <iostream>
#include <limits>
#include "../Data_Structs/Node.h"
#include "../Data_Structs/Stack.h"

// TO RUN:
// ______________________________________________
// >> g++ -o 3.2 CTCI_3.2.cpp ../Data_Structs/Node.cpp  ../Data_Structs/Stack.cpp
// >> ./3.2
// ______________________________________________

// Idea: have a second stack that would store minimum elements up until this point

int min()
{   
    if(s2.empty()) {
        // error case
        return std::numeric_limits<int>::max();
    }

    return s2.peek();
}

public void push(int value)
{
    if(value <= min()) {
        s2.push(value);   
    }
    
    super.push(value);
}

public int pop() 
{
    int value = super.pop();
    if(value == min()) {
        s2.pop();
    }
    
    return value;
}


