#include <iostream>
#include "BinaryTreeNode.h"

int BinaryTreeNode::getData() {
	return data;
}

void BinaryTreeNode::setData(int d) {
	data = d;
}

BinaryTreeNode* BinaryTreeNode::getLeft() {
	return left;
}

void BinaryTreeNode::setLeft(BinaryTreeNode* lnk) {
	left = lnk;
}

BinaryTreeNode* BinaryTreeNode::getRight() {
	return right;
}

void BinaryTreeNode::setRight(BinaryTreeNode* lnk) {
	right = lnk;
}

BinaryTreeNode::~BinaryTreeNode() {
	//cout << "--Destructing node with value " << value << endl;
}