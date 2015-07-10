// Write a program to sort a stack in ascending order (with bigest items on top).
// You may only use one more additional stack.
// Supporting methods: push(), pop(), peek(), empty()


#include <iostream>
#include "../Data_Structs/Stack.h"

// TO RUN:
// ______________________________________________
// >> g++ -o 3.6 CTCI_3.6.cpp ../Data_Structs/Node.cpp ../Data_Structs/Stack.cpp
// >> ./3.6
// ______________________________________________

Stack *SortStack(Stack * stack)
{
    Stack * sorted = new Stack();
    while(!stack->empty()) {
        // save in a temp variable
        int temp = stack->pop();
        // pop items back to stack until we found the rigth place for temp
        while(!sorted->empty() && temp < sorted->peek()) {
            stack->push(sorted->pop());
        }
        // since we found its place, push it.
        sorted->push(temp);
    }
    return sorted;
}


int main()
{
    Stack st;
    st.push(1);
    st.push(7);
    st.push(2);
    st.push(14);
    st.push(3);
    st.print();


    Stack * sorted = SortStack(&st);
    sorted->print();
    return 0;
}

// Time complexity O(n^2)
// Space O(n)