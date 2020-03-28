def twoSumAll(nums, target):
    res = dict()
    for i in range(len(nums)):
        key = min(nums[i], target - nums[i])
        try:
            res[key].append(i)
        except KeyError:
            res[key] = [i]
    for key in res:
        if len(res[key]) == 2:
            yield [key, target - key], res[key]

def twoSum(nums, target):
    res = dict()
    for i in range(len(nums)):
        key = min(nums[i], target - nums[i])
        try:
            res[key].append(i)
            return [key, target-key], res[key]
        except KeyError:
            res[key] = [i]
            
if __name__ == "__main__":
    val, idx = twoSumAll([1,2, 7, 11, 15, -2], 9)
    print(val, idx)

    val, idx = twoSum([1,2, 7, 11, 15, -2], 9)
    print(val, idx)