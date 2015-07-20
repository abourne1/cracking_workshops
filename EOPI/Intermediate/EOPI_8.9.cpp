// Given the root node r of a binary tree, 
// print all the keys and levels at r and its descendants. 
// The nodes should be printed in or- der of their level. 
// You cannot use recursion. You may use a single queue, and 
// constant additional storage. 

// TO RUN:
// ______________________________________________
// >> g++ -o 8.9 EOPI_8.9.cpp ../../Data_Structs/BinaryTreeNode.cpp ../../Data_Structs/BinarySearchTree.cpp
// >> ./8.9
// ______________________________________________

#include <iostream>
// See more on queue DT here 
// http://www.cplusplus.com/reference/queue/queue/
#include <queue>
#include "../../Data_Structs/BinarySearchTree.h"

void PrintLevelBT(BinaryTreeNode *root)
{
	if(!root) {
		return;
	}
	std::queue<BinaryTreeNode *> *q = new std::queue<BinaryTreeNode *>();
	q->push(root);

	while(!q->empty()) {
		// so many nodes on level l
		int n = q->size();
		// print and dequeue all of the nodes on level l
		// adding to the back of the queue nodes on level l+1
		for (int i = 0; i < n; i++) {
			BinaryTreeNode *temp = q->front();
			q->pop();
			std::cout<<temp->getData()<< " ";
			if(temp->getLeft()) {
				q->push(temp->getLeft());
			}
			if (temp->getRight()) {
				q->push(temp->getRight());
			}
		}
		std::cout<<std::endl;
	}
}

int main()
{
	BinarySearchTree tree;
	// this is the root so level 1
	tree.insert(10);
	tree.insert(5); // level 2 
	tree.insert(8); // level 3 
	tree.insert(15); // level 2
	tree.insert(3); // level 3 
	tree.insert(4); // level 4 
	tree.insert(17); // level 3
	tree.insert(12); // level 3
	tree.insert(21); // level 4	
	// print normally
	std::cout<<"______________________________"<<std::endl;
	std::cout<<"Binary search tree: "<<std::endl;
	tree.print();
	std::cout<<"______________________________"<<std::endl;
	std::cout<<"Binary search tree by levels: "<<std::endl;
	PrintLevelBT(tree.getRoot());
	return 0;
}