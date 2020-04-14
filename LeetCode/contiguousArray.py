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
# The following code is from LeetCode
class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = {}
        d[0] = -1
        count = 0
        result = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                count -= 1
            else: 
                count += 1
            if count in d:
                if (i - d[count]) > result:
                    result = i - d[count]
            else:
                d[count] = i
        return result
