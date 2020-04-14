class Solution(object):
    def stringShift(self, s, shift):
        """
        :type s: str
        :type shift: List[List[int]]
        :rtype: str
        """
        left_s = 0
        for sh in shift:
            if sh[0]:
                left_s -= sh[1]
            else:
                left_s += sh[1]
        left_s = left_s % len(s)
        return s[left_s:] + s[:left_s]

#Solution from Leetcode
class Solution(object):
    def stringRotation(self, s, rotation):
        """
        :type s: str
        :type rotation: List[List[int]]
        :rtype: str
        """
        ans=s
        for d,a in rotation:
            if d:
                ans=ans[-a:]+ans[:-a]
            else:
                ans=ans[a:]+ans[:a]
        return ans
        