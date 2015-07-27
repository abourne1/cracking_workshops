// Let T be the root of a binary tree in which 
// nodes have an explicit parent field. 
// Design an iterative algorithm that enumerates the nodes inorder 
// and uses 0(1) additional space. 
// Your algorithm cannot modify the tree

// If you want better understanding of trees
// Look at "MorisTraversal.cpp" in the folder "Other"
// it might give some ideas
// (not necesserily the ones that lead to the solution here)

void InOrderTraversal(BinaryTreeNode *r)
{
	if(!r) {
		return;
	}

	BinaryTreeNode *prev = NULL, curr = r, next;
	while(curr) {
		if(!prev || curr == prev->getLeft() || curr == prev->getRight()) {
			// i.e. prev is the parent of curr
			if(curr->getLeft()) {
				// but now consider left subtree of curr before printing
				next = curr->getLeft();
			} else {
				// there is nothing else, so print it
				std::cout<<curr->getData()<<" ";
				// we shall now either go to right subtree
				// or if there is no right node
				// then just return back to the parent
				next = curr->getRight() ? curr->getRight() : curr->getParent();
			}
		} else if(curr->getLeft() == prev) {
			// we considered the left subtree and now got back to the parent
			std::cout<<curr->getData()<<" ";
			// we shall now either go to right subtree
			// or if there is no right node
			// then just return back to the parent
			next = curr->getRight() ? curr->getRight() : curr->getParent();
		} else {
			// i.e. prev is defined but
			// curr != prev->getLeft()
			// curr != prev->getRight()
			// curr->getLeft() != prev
			// we have to go up
			next = curr->getParent();
		}

		prev = curr;
		curr = next;
	}

	std::cout<<std::endl;
}


int main()
{
	return 0;
}