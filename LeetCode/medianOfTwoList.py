def binary_search(arr, tgt, min_n, max_n):
    if min_n > max_n:
        return max_n
    mid_n = (min_n + max_n)//2
    if arr[mid_n] >= tgt:
        return binary_search(arr, tgt, min_n, mid_n - 1)
    else:
        return binary_search(arr, tgt, mid_n + 1, max_n)


# l1 is longer than l2
def twoMedian(l1, len1, l2, len2, idx):
#     print(l1, len1, l2, len2, idx)
    if not l1:
        return l2[idx]
    if not l2:
        return l1[idx]
    if l1[-1] < l2[0]:
        l = l1 + l2
        return l[idx]
    elif l2[-1] < l1[0]:
        l = l2 + l1
        return l[idx]
    else:
        idx1 = len1//2
        idx2 = binary_search(l2, l1[idx1], 0, len2 - 1) + 1
#         print("Binary search", l1[idx1],"=", idx2)
        count = idx2 + idx1# idx + 1 = length
#         print(idx2 ,"()",l1[idx1], "at", real_idx)
#         print("Count =", count, " Aiming = ", idx)
        if count == idx:
            return l1[idx1]
        elif count < idx: # right side of the array
            len1 -= idx1 + 1
            len2 -= idx2
            idx -= count + 1
            if len1 > len2:
                return twoMedian(l1[idx1 +1 :], len1, l2[idx2:], len2, idx)
            else:
                return twoMedian(l2[idx2:], len2, l1[idx1 + 1:], len1, idx)
        else:
            if idx1 > idx2:
                return twoMedian(l1[:idx1], idx1, l2[:idx2], idx2, idx)
            else:
                return twoMedian(l2[:idx2], idx2, l1[:idx1], idx1, idx)
        
import random

if __name__ == "__main__": 
    sorted_arr = [1,2,3,4,5,6,7,8,9,10,11]
    s1 = []
    s2 = []
    for i in range(len(sorted_arr)):
        if random.uniform(0, 1) < 0.5:
            s1.append(sorted_arr[i])
        else:
            s2.append(sorted_arr[i])
    print(s1)
    print(s2)
#     s1 = [1, 3, 4, 6, 7, 8]
#     s2 = [2, 5, 9, 10]
#     s1 = [4, 5, 6, 8, 10]
#     s2 =[1, 2, 3, 7, 9]

#     in_str = '1,2,5,7,9'
#     s1 = list(map(int, in_str.replace(" ", "").split(","))) 
#     in_str = '2,4,6,8'
#     s2 = list(map(int, in_str.replace(" ", "").split(",")))
    len1 = len(s1)
    len2 = len(s2)
    if (len1 + len2) % 2 == 1:
        if len1 > len2:
            m = twoMedian(s1, len1, s2, len2, (len1 + len2)//2)
        else:
            m = twoMedian(s2, len2, s1, len1, (len1 + len2)//2)
    else:
        if len1 > len2:
            m1 = twoMedian(s1, len1, s2, len2, (len1 + len2)//2 - 1)
            m2 = twoMedian(s1, len1, s2, len2, (len1 + len2)//2)
        else:
            m1 = twoMedian(s2, len2, s1, len1, (len1 + len2)//2 - 1)
            m2 = twoMedian(s2, len2, s1, len1, (len1 + len2)//2)
        m = (m1 + m2) / 2
        
    print("Median is", m)