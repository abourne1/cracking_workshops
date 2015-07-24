# check if a binary tree is actually a binary search tree

import sys


# Note: remember that it is not only about root being bigger than left node and smaller than right
# anything under root should follow the contraints
# that is why we have a helper function that checks for the bounds.
def CheckBST(root):
    CheckBSTHelper(root, sys.maxint, -sys.maxint-1)
    
def CheckBSTHelper(root, MaxVal, MinVal):
    if root is None:
        return True
    
    if !(root.data <= MaxVal) or !(root.data > MinVal):
        return False
    
    if !CheckBSTHelper(root.left, root.data, MinVal) or !CheckBSTHelper(root.right, MaxVal, root.data):
        return False
    
    return True
    
    
# Complexity
# Time O(N) as we iterate through each node