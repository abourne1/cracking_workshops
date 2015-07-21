



// TO RUN:
// ______________________________________________
// >> g++ -o Morris MorrisTraversal.cpp ../Data_Structs/BinaryTreeNode.cpp ../Data_Structs/BinarySearchTree.cpp
// >> ./Morris
// ______________________________________________


#include <iostream>
#include <memory>
#include "../Data_Structs/BinarySearchTree.h"

// Seriously, this is a quite tricky
// so for better understading I would recommend looking here 
// http://geeksquiz.com/threaded-binary-tree/
// Not the updates to the poiters in the tree
// which are later re-set back

// note this is not thread safe
void MorrisTraversal(BinaryTreeNode *root)
{	
	BinaryTreeNode *curr = root;
	while(curr) {

		if(!curr->getLeft()) {
			std::cout<<curr->getData()<<" ";
			curr = curr->getRight();
		} else {
			BinaryTreeNode *pre = curr->getLeft();
			while(pre->getRight() && pre->getRight() != curr) {
				pre = pre->getRight();
			}

			if(pre->getRight()) {
				// i.e. pre->getRight() is equal to curr
				pre->setRight(NULL);
				std::cout<<curr->getData()<< " ";
				curr = curr->getRight();
			} else {
				// pre is NULL
				pre->setRight(curr);
				curr = curr->getLeft();
			}
		}
	}
	std::cout<<std::endl;
}

// meanwhile answer this question:
// Why is this better than recursion version?

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
	std::cout<<"Binary search tree by recursion: "<<std::endl;
	tree.print();
	std::cout<<"______________________________"<<std::endl;
	std::cout<<"Binary search tree by MorrisTraversal: "<<std::endl;
	MorrisTraversal(tree.getRoot());
	return 0;
}

// Time complexity O(n)
// so thats not really a win 
// this approach is better because recursion implicitly uses O(h) additional space complexity,
// while here it is O(1)!
