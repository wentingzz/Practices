class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        prod = 1
        zeros = []
        for idx, n in enumerate(nums):
            if n:
                prod *= n
            else:
                zeros.append(idx)
        if len(zeros):
            output = [0 for n in nums]
            if len(zeros) == 1:
                output[zeros[0]] = prod
        else:
            output = [prod/n for n in nums]
        return output
#The following is from LeetCode
 class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
    # @param {integer[]} nums
    # @return {integer[]}
        p = 1
        n = len(nums)
        output = []
        for i in range(0,n):
            output.append(p)
            p = p * nums[i]
        p = 1
        for i in range(n-1,-1,-1):
            output[i] = output[i] * p
            p = p * nums[i]
        return output

        