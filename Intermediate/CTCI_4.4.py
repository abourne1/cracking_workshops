# given a binary tree, 
# design an algorithm which creates a linked ist of all the nodes at each depth


# Idea: BFS 
# We know that at level i, we shall look at level (i-1)'s children
# since (i-1)'s level has been set and considered
# (Indeed, BFS)
def CreateLinkedLists(root):    
    # this will be a list of lists (i.e. of each depth)
    Lists = []
    # a current list considered
    current = []
    
    if root is not None:
        # initial 
        current.append(root)
    
    while len(current) > 0:
        #  add this (current) "depth" list to Lists
        Lists.append(current)
        #  what used to be current is now parents on this level
        Parents = current
        # reset current
        current = []
        for parent in Parents:
            if parent.left is not None:
                current.append(parent.left)
            if parent.right is not None:
                current.append(parent.right)
                
    # Done            
    return Lists
            
# Complexity
# Time O(N) since we traverse through each node only once
# Space is O(N) since we return a list of lists with all the nodes