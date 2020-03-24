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
if __name__ == "__main__":
    while(True):
        in_str = input("Input integers separated by comma (ex. 14,15):")
        in_str = in_str.replace(" ", "")
        in_str = in_str.split(",")
        try:
            for i in range(len(in_str)):
                in_str[i] = int(in_str[i])
            break
        except:
            print("The input is not integer or is not separated by comma")
    sort = merge_sort(in_str)