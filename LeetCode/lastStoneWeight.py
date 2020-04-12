# This is the solution from Leetcode
class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        h = [-x for x in stones]
        heapq.heapify(h)
        
        while len(h) >1 and h[0] != 0:
            heapq.heappush(h, heapq.heappop(h)- heapq.heappop(h))
        
        return -h[0]

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
        res = [0 for i in range(n)]
        j = 0
        k = 0
        for i in range(n):
            if j == left_n:
                res[i] = right[k]
                k += 1
            elif k == right_n:
                res[i] = left[j]
                j += 1
            else:
                if left[j] < right[k]:
                    res[i] = left[j]
                    j += 1
                else:
                    res[i] = right[k]
                    k += 1
        return res  

class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        ss = merge_sort(stones)
        
        while(1):
            l = len(ss)
            if l == 0:
                return 0
            elif l == 1:
                return ss[0]
            else:
                newS = ss[-1] - ss[-2]
                print("New = ", newS, ss)
                ss = ss[:-2]
                if newS:
                    bisect.insort(ss, newS)
                print(ss)
                
                
        