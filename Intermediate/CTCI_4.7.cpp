// Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. 
// Avoid storing additional nodes in a data structure.


// First idea
// Simplified: if we have parent links
// Just use a hash table. Iterate upwards and if the entry has been there before, then thats the first common ancestor

#include <iostream>
#include "../Data_Structs/BinarySearchTree.h"

// TO RUN:
// ______________________________________________
// >> g++ -o 4.7 CTCI_4.7.cpp ../Data_Structs/BinaryTreeNode.cpp ../Data_Structs/BinarySearchTree.cpp
// >> ./4.7
// ______________________________________________

// Second Approach
// Say this is your binary tree
// Note: it is not a binary *search* tree
//                 17
//        40                22
//   37        13       22       31
//  -   1    2   15   -   -    14   -
//     9 11        

// Say you need to find an ancestor of Nodes 11 and 15
// The answer is obviously 40
// for Nodes 37 and 22, answer: 17
// For Nodes 22 and 14, thats, 22
// Idea is to iterate until the two nodes are no longer on the same side of the tree
// that means one is on the left, one if on the right, 
// i.e. that intersaction is the common ancestor


// Optimized version
int ContainsNode(BinaryTreeNode *root, BinaryTreeNode *curr)
{
    if (curr == NULL) {
        return 1;
    }
    if (root == NULL) {
        return 0;
    }
    // found it!
    if (root == curr) {
        return 1;
    }
    
    return ContainsNode(root->getLeft(), curr) || ContainsNode(root->getRight(), curr); 
}

// return p if subtree contains only p (1)
// return q if subtree contains only q (2)
// return NULL if it contains neither (3)
// return either one if it contains both (4)

BinaryTreeNode *commonAncestor(BinaryTreeNode *root, BinaryTreeNode *p, BinaryTreeNode *q)
{
    // always check this
    if(root == NULL) {
        return NULL;
    }
    
    // obviously:
    if (root == p && root == q) {
        return root;
    }
    
    // check left subtree
    // remember thats a recursion 
    // so it is going to keep doing that
    BinaryTreeNode *x = commonAncestor(root->getLeft(), p, q);
    
    if (x != NULL && x != p && x != q) {
        // so left subtree contains both
        // but is not case (1) or (2), i.e. it is case (4)
        // found common ancestor somewhere in recursion calls!
        return x;
    }
    
    //similarly
    BinaryTreeNode *y = commonAncestor(root->getRight(), p, q);
    
    if (y != NULL && y != p && y != q) {
        return y;
    }
    
    // otherwise consider cases
    if ( x != NULL && y != NULL) {
        // case (1) and (2): x and y are both equal to either p or q
        // i.e. p and q were found in different subtrees
        // it cannot be that x == y because we considered root->left and root->right
        // so that if left subtree contains p (so x == p), then y cannot be ps  
        // thats what we wanted!
        return root;
    } else if(root == p || root == q) {
        // so root is either p or q
        // but not both
        return root;
    } else {
        // return non-NULL value
        return x == NULL ? y : x;
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
    //              10
    //       5                15
    //  3        8       12        17
    // -  4                      -    21
    // 
    // print normally
    std::cout<<"______________________________"<<std::endl;
    std::cout<<"Binary /search/ tree: "<<std::endl;    
    tree.print();
    std::cout<<"______________________________"<<std::endl;
    BinaryTreeNode *l = tree.getRoot()->getLeft()->getRight(); // 8
    BinaryTreeNode *r = tree.getRoot()->getRight()->getRight(); // 17
    std::cout<<commonAncestor(tree.getRoot(), l, tree.getRoot())->getData()<<std::endl;
    // output: 10
    std::cout<<commonAncestor(tree.getRoot(), r->getRight(), r)->getData()<<std::endl;
    // output: 17
    return 0;
}
