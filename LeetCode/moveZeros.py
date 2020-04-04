def moveZeroes(nums):
    l = len(nums)
    for i in range(l - 1):
        if nums[i] == 0:
            for k in range(i + 1, l):
                if nums[k] != 0:
                    nums[i] = nums[k]
                    nums[k] = 0
                    break
    return nums
    
if __name__ == "__main__": 
#     in_str = input("Enter an integer: ")
    in_str = [0,1,0,3,12]
    print(moveZeroes(in_str))