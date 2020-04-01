def singleNumber(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    elements = []
    total2 = 0
    total = 0
    for num in nums:
        if num not in elements:
            elements.append(num)
            total2 += num
        total += num
    return 2 * total2 - total
if __name__ == "__main__": 
    in_str = input("Enter the comma-separated integers (1,2,3): ")
    in_str = in_str.replace(" ", "").split(",")
    in_str = [int(i) for i in in_str]
    print(singleNumber(in_str))