// TO RUN
// (Can't run it because I have not written Binary Tree struct)

#include <iostream>

template
void TraverseBST(const shared_ptr<BinaryTree<T>> &tree)
{
	shared_ptr<BinaryTree<T>> *curr = tree->getRoot();
	Stack<shared_ptr<BinaryTree<T>> s;
	// the idea here is to keep going left and pushing that onto stack
	// remember that will be in reverse order as we want
	// but what about all the right nodes?
	// once we reach leaves (the bottom) and popping elements from the stack
	// we can explore their right subtrees
	// also we know that everything on the right should be bigger on 
	// the right side but smaller than parent
	while(curr || !s.empty()) {
		if(curr) {
			s.push(curr);
			curr = curr->getLeft();
		} else {
			// we get the node
			curr = s.pop();
			// print it
			std::cout<<curr->getData()<<std::endl;
			// and only then explore right subtree
			// exactly what we want for in-order traversal
			curr = curr->getRight();
		}
	}

	return;
}

// Time complexity O(n)