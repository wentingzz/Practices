# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root:
            return self.recursSym(root.left, root.right)
        else:
            return True
        
    
    def recursSym(self, l, r):
        if l is None and r is None:
            return True
        if l is None or r is None:
            return False
        if l.val != r.val:
            print(l.val, r.val)
            return False
        return self.recursSym(l.left, r.right) and self.recursSym(l.right, r.left)