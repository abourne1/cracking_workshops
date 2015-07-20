#ifndef BINARYTREENODE_H_INCLUDED
#define BINARYTREENODE_H_INCLUDED

class BinaryTreeNode 
{
	private:
		BinaryTreeNode* left;
		BinaryTreeNode* right;
		int data;

	public:
	    BinaryTreeNode() : left(NULL), right(NULL), data(0)  {};
	    BinaryTreeNode(int d) : left(NULL), right(NULL), data(d)  {};

		int getData();
		void setData(int val);

		BinaryTreeNode* getLeft();
		void setLeft(BinaryTreeNode* lnode);

		BinaryTreeNode* getRight();
		void setRight(BinaryTreeNode* rnode);

		~BinaryTreeNode();
};

#endif // BINARYTREENODE_H_INCLUDED