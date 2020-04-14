class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sumNums = dict()
        curSum = 0
        res = 0
        l = len(nums)
        
        for idx, val in enumerate(nums):
            curSum += 2 * val - 1
            if curSum == 0:
                res = max(res, idx + 1)
            else:
                if curSum in sumNums:
                    res = max(res, idx - sumNums[curSum])
                else:
                    sumNums[curSum] = idx
                # print(sumNums)
        return res