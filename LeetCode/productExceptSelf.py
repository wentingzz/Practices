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
            
        