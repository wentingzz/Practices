import sys
def maxSubArray(nums):
    l = len(nums)
    if l == 1:
        return nums[0]
    else:
        p = l//2
        left = maxSubArray(nums[:p])
        right  = maxSubArray(nums[p:])
        ret = max(left, right)
        tmp = 0
        mtmp = -sys.maxsize - 1
        for i in range(p):
            tmp += nums[p-i -1]
            mtmp = max(tmp, mtmp)
        tmp = mtmp
        for i in range(l - p):
            tmp += nums[p + i]
            mtmp = max(tmp, mtmp)
        ret = max(mtmp, ret)
        return ret
    
if __name__ == "__main__": 
#     in_str = input("Enter an integer: ")
    in_str = [-2,1,-3,4,-1,2,1,-5,4]
    print(maxSubArray(in_str))