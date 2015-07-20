#ifndef BINARYSEACRHTREE_H_INCLUDED
#define BINARYSEACRHTREE_H_INCLUDED

#include <iostream>
#include "BinaryTreeNode.h"

class BinarySearchTree 
{
  private:
	BinaryTreeNode* root;
	int count;

	void insertHelper(BinaryTreeNode* node, int i);
	void printHelper(BinaryTreeNode* node);
	void destructorHelper(BinaryTreeNode* node);

  public:
	// Pre:  true
	// Post: binary search tree is empty
	BinarySearchTree() : root(NULL), count(0) {};

	// Pre:  true
	// Post: binary search tree is empty
	BinarySearchTree(BinaryTreeNode *n) : root(n), count(0) {};

	// Pre:  true
	// Post: the value i is added to the tree
	void insert(int d);

	// Pre:  true
	// Post: the root is returned
	BinaryTreeNode *getRoot();

	// Pre:  true
	// Post: number of elements in the tree
	int size();

	// Pre:  true
	// Post: outputs the tree contents in increasing order
	void print();

	// Pre:  true
	// Post: true
	~BinarySearchTree();
};


#endif // BINARYSEACRHTREE_H_INCLUDED