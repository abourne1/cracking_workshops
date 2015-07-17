// Let hl and h2 be the heads of lists ll1  and ll2, respectively.
//  Assume that ll1 and ll2  are well-formed, 
// that is each consists of a finite sequence of nodes. 
// (In particular, neither list has a cycle.) 
// How would you determine if there exists a node r reachable from both
// hl and h2 by following the next fields? If such a node exists, 
// find the node that appears earliest when traversing the lists. 
// You are constrained to use no more than constant additional storage.


// say first linked list ll1 is of size m
// say second linked list ll2 is of size n
/*

I was too lazy to type it up, but if you are here I am guessing you need some ideas?
1. Brute force search should be obvious and should take O(nm)
Not great

2. If descrtuctive updates are possible, you can alter the method for reversing 
linked list and track down the common node

3. If not, a better solution is to note that since there are no cycles
and two linked lists share sequence of nodes, then  that sequence must be at the end.
if m > n , Advance pointer  of ll1 by (m-n) nodes, and then
start advancing pointers of both lists simultenenously comparing them
if they are the same, then we found a first shared node!

*/