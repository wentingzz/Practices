# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


    
class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res = 1
        def recus(node):
            if node == None:
                return 0
            l = recus(node.left)
            r = recus(node.right)
            
            self.res = max(self.res, l + r + 1)
            print(node.val, l, r, self.res)
            return max(l, r) + 1
        recus(root)
        return self.res - 1
        
        