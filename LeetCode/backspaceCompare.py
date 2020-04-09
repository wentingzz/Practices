class Solution(object):
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        ress = ""
        for i in range(len(S)):
            if S[i] == '#':
                ress = ress[:-1]
            else:
                ress += S[i]
        rest = ""
        for i in range(len(T)):
            if T[i] == "#":
                rest = rest[:-1]
            else:
                rest += T[i]
        return rest == ress
    
# "Best" Solution      
# class Solution(object):
#     def backspaceCompare(self, S, T):
#         """
#         :type S: str
#         :type T: str
#         :rtype: bool
#         """
#         def bsp(s):
#             bcount = 0
#             fin = []
#             for i in range(len(s)-1, -1, -1):
#                 if s[i] == "#":
#                     bcount += 1
#                 else:
#                     if bcount > 0:
#                         bcount -= 1
#                         continue
#                     else:
#                         fin.append(s[i])
#             return "".join(fin)
        
#         return bsp(S) == bsp(T)