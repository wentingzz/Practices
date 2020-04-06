def merge_sort(arr):
    n = len(arr)
    if n == 1:
        return arr
    else:
        n2 = n//2
        left = merge_sort(arr[:n2])
        right = merge_sort(arr[n2:])
        left_n = len(left)
        right_n = len(right)
        res = ""
        j = 0
        k = 0
        for i in range(n):
            if j == left_n:
                res += right[k]
                k += 1
            elif k == right_n:
                res += left[j]
                j += 1
            else:
                if left[j] < right[k]:
                    res += left[j]
                    j += 1
                else:
                    res += right[k]
                    k += 1
        return res

def groupAnagrams(strs):
    dic = dict()
    for i in range(len(strs)):
        try:
            dic[merge_sort(strs[i])].append(strs[i])
        except:
            dic[merge_sort(strs[i])] = [strs[i]]
    res = []
    for k, vs in dic.items():
        res.append(vs)
    return res
# The following is the solution with better performance (from Leetcode)
#     d = collections.defaultdict(list)
#     for x in strs:
#         xl = ''.join(sorted(x))
#         d[xl].append(x)
#     return d.values()
    

in_str = ["eat", "tea", "tan", "ate", "nat", "bat"]
groupAnagrams(in_str)
# print(merge_sort("eat"))