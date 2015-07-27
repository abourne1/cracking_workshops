# Cracking Workshops
Get ready for tech Interviews!

1. This is an easy way to follow/run/test exercises from the Cracking the Coding Interviews book.

2. There will be more tech books added later.

# Additional Problems 
to do in your free time

>>> Elements of Programming Interviews (EOPI):
———— Beginner:
[ Arrays ]
6.14: Check whether a 9 x 9 grid representing a partially completed
Sudoku is valid. Specifically,check that no row, column, and 3 x 3 2D subarray contains duplicates. A O-value in the 2D array indicates that entry is blank; every other entry is in I1,9].

6.15: Implement a function which takes a 2D array A and prints A in spiral order.

6.16:  Implement a routine that takes a DxD Boolean array A together with an entry (x,y) and flips the color of the region associated with (x,y). See Figure 6.5 for an example of flipping.


[ Strings ]
6.18: Implement run-length encoding and decoding functions. Assume the string to be encoded consists of letters of the alphabet, with no digits, and the string to be decoded is a valid encoding.

6.19: Implement a function for reversing the words in a string. Your function should use 0(1) space.

6.20: Write a function which takes as input a string s, and removes each "b" and replaces each "a" by "dd". Use 0(1) additional storage-assume s is stored in an array that has enough space for the final result.

6.22: Given a cell phone keypad (specified by a mapping M that takes individual digits and returns the corresponding set of characters) and a number se- quence, return all possible character sequences (not just legal words) that correspond to the number sequence.

[ Linked List ]
7.1: Write a function that takes Land F, and returns the merge of L
and F. Your code should use 0(1) additional storage-it should reuse the nodes from the lists provided as input. p63.

7.3: Write a function that takes a sorted circular singly linked list and a pointer to an arbitrary node in this linked list, and returns the median of the linked list.

7.7: Let v be a node in a singly linked list L. Node v is not the tail: delete it in 0(1) time.

[ Binary Tree ]
9.9: Given a binary tree, write a function which forms a linked list from the leaves of the binary tree. The leaves should appear in left-to-right order. For example, when applied to the binary tree in Figure 9.1 on Page 73, your function should return (D,E,H,M,N,P).

———— Beginner/Intermediate:
[ Strings ]
6.9: Write a function that takes two strings representing integers, and returns an integer representing their product.

6.12: Given a permutation p represented as a vector, return the vector corresponding to the next permutation under lexicographic ordering. If p is the last permutation, return empty vector. For example, if p = (1,0,3,2), your function should return (1,2,0,3).

[ Linked List ]
7.6: Write a function that takes a singly linked list L, and reorders the elements of L so that the new list represents even-odd(L). Try to only use 0(1) additional storage.

7.8: Given a singly linked list L and a number k, write a function to remove the k-th last element from L. Your algorithm cannot use more than a few words of storage, regardless of the length of the list. In particular, you cannot assume that it is possible to record the length of the list.

7.11: Let a singly linked list L = [ l1, l2, .., l(n-1), l(n)]. Define zip function ZIP(L) = [l1, l(n-1), l2, l(n-2) … ] Write a function that takes a singly linked list L, and reorders the elements of L to form a new list representing zip(L). Your function should use 0(1) additional storage.

[ Binary Trees ]
9.6: Design a function that efficientlycomputes the k-thnode appearing in an inorder traversal. Specifically,your function should take as input a binary tree T and an integer k. Each node has a size field, which is the number of nodes in the subtree rooted at that node. What is the time complexity of your function?

9.12: Given two nodes in a binary tree T,design an algorithm that computes their LCA (least common ancestor). Assume that each node has a parent pointer. The tree has n nodes and height h. Your algorithm should run in 0(1) space and O(h) time.

———— Intermediate:
[ Stack ]
8.6: Design an algorithm that processes buildings as they are presented to it and tracks the buildings that have a view of the sunset. The number of buildings is not known in advance. Buildings are given in east-to-west order and are specified by their heights. The amount of memory your algorithm uses should depend solely on the number of buildings that have a view; in particular it should not depend on the number of buildings processed.

[ Queue ]
8.10  Implement a queue API using an array for storing elements. Your API should include a constructor function, which takes as argument the capacity of the queue, enqueue and dequeue functions, a size function, which returns the number of elements stored, and implement dynamic resizing.

8.12 How would you implement a queue given two stacks and 0(1) additional storage?Your implementation should be efficient-the time to do a sequence of m combined enqueues and dequeues should be O(m).

———— Intermediate/Advanced:
[ Linked List ]
7.12:  Implement a function which takes as input a pointer to the head of a postings list L, and returns a copy of the postings list. Your function should take O(n) time, where 11 is the length of the postings list and should use 0(1) storage beyond that required for the n nodes in the copy. You can modify the original list, but must restore it to its initial state before returning.

[ Queue ]
8.11  Implement a queue using two unsigned integer-valued variables. Assume that the only elements pushed into the queue are integers in [0,9]. Your program should work correctly when 0 are the only elements in the queue. What is the maximum number of elements that can be stored in the queue for it to operate correctly?
