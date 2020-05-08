class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cur = 0
        for i in range(1, len(nums)):
            if nums[cur] != nums[i]:
                nums[cur + 1] = nums[i]
                cur = cur + 1
        return cur + 1
                