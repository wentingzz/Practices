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