#include <iostream>
#include "BinarySearchTree.h"

void BinarySearchTree::insert(int i) {

	if (root == NULL) {
		root = new BinaryTreeNode(i);
	} else {
		insertHelper(root, i);
	}

	count++;
}

void BinarySearchTree::insertHelper(BinaryTreeNode* node, int i) {

	if (i < node->getData()) {
		if (node->getLeft() == NULL) {
			node->setLeft(new BinaryTreeNode(i));
		} else {
			insertHelper(node->getLeft(), i);
		}
	} else if (i > node->getData()) {
		if (node->getRight() == NULL) {
			node->setRight(new BinaryTreeNode(i));
		} else {
			insertHelper(node->getRight(), i);
		}
	} 
}

BinaryTreeNode *BinarySearchTree::getRoot() {
	return root;
}

int BinarySearchTree::size() {

	return count;
}

void BinarySearchTree::print() {
	printHelper(root);
	std::cout<<std::endl;
}

void BinarySearchTree::printHelper(BinaryTreeNode* node) {

	if (node == NULL) {
		return;
	}
	printHelper(node->getLeft());
	std::cout << node->getData() << " ";
	printHelper(node->getRight());
}

BinarySearchTree::~BinarySearchTree() {
	destructorHelper(root);
}

void BinarySearchTree::destructorHelper(BinaryTreeNode* node) {

	if (node == NULL) {
		return;
	}

	destructorHelper(node->getLeft());
	destructorHelper(node->getRight());

	delete node;
}