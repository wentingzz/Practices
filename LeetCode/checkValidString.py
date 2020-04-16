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