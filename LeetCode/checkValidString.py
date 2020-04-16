class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        idxL = []
        idxS = []
        
        for i in range(len(s)):
            if s[i] == "(":
                idxL.append(i)
            elif s[i] == "*":
                idxS.append(i)
            else:
                if idxL:
                    idxL.pop()
                elif idxS:
                    idxS.pop()
                else:
                    return False
        if len(idxL) > len(idxS):
            return False
        while(idxL and idxS):
            if(idxL.pop() > idxS.pop()):
                return False
        return True

# Solution from Leetcode
class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        if len(s) == 0:
            return True
        
        low = 0
        high = 0
        
        for s_ in s:
            
            if s_ == '(':
                low += 1
            else:
                low -= 1
            
            if s_ != ')':
                high += 1
            else:
                high -= 1
            
            if high < 0:
                break
            low = max(low, 0)
            
        return low == 0