# Solution from Leetcode
class BetterMinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_stack = []
        

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.stack.append(x)
        if len(self.min_stack) == 0 or x <= self.min_stack[-1]:
            self.min_stack.append(x)

    def pop(self):
        """
        :rtype: None
        """
        if len(self.stack):
            cur = self.stack.pop()
            if cur == self.min_stack[-1]:
                self.min_stack.pop()
        

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.min_stack[-1]

class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.head = []
        self.min = []
        
        

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        if self.min:
            self.min.append(min(self.min[-1], x))
        else:
            self.min.append(x)
        self.head.append(x)
        
        

    def pop(self):
        """
        :rtype: None
        """
        self.head.pop()
        self.min.pop()
        

    def top(self):
        """
        :rtype: int
        """
        return self.head[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.min[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()