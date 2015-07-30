// Perform in-order traversal of the tree without recursion and 
// additional data strucsts (i.e. O(1) space)

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
			// there is no more left nodes
			// then print this one and go right
			std::cout<<curr->getData()<<" ";
			curr = curr->getRight();
		} else {
			// there is a left child
			// thus check the most right node of the left child
			BinaryTreeNode *pre = curr->getLeft();
			while(pre->getRight() && pre->getRight() != curr) {
				pre = pre->getRight();
			}
			// see below the if-else statement
			// "if" part
			// if it points to the current node
			// then obivously you have previously set it up
			// as there should be no cyclical links like that
			// "else", you did not do it yet
			// so set it

			if(pre->getRight()) {
				// i.e. pre->getRight() is equal to curr
				// that means you have previously modified it
				// so restore the original state of the tree for this node
				// i.e. it should be NULL
				pre->setRight(NULL);
				// we traversed entire left subtree
				// so print current node
				std::cout<<curr->getData()<< " ";
				// and go explore right subtree!
				curr = curr->getRight();
			} else {
				// pre is NULL
				// i.e. we should set up a link 
				// why? because of in-order traversal.
				// After the most right node of the left child
				// you should print current node
				// so here just set up the link ahead of time
				pre->setRight(curr);
				// now that the most right node of the left subtree 
				// knows how to get back on track of in-order traversal
				// (we have set the link)
				// confidently explore the left subtree
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

// inside of a main while loop, there is another while loop
// to see why it is still O(n), 
// see http://stackoverflow.com/questions/6478063/how-is-the-complexity-of-morris-traversal-on
