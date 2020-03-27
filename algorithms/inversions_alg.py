def inversion_count(arr):
    n = len(arr)
    if n == 1:
        return arr, 0, []
    else:
        n2 = n//2
        left, l_c, l_i = inversion_count(arr[:n2])
        right, r_c, r_i = inversion_count(arr[n2:])
        
        left_n = len(left)
        right_n = len(right)
        sort = [0 for i in range(n)]
        res = l_i + r_i
        j = 0
        k = 0
        count = 0
        for i in range(n):
            if j == left_n:
                sort[i] = right[k]
                k += 1
            elif k == right_n:
                sort[i] = left[j]
                j += 1
            else:
                if left[j] < right[k]:
                    sort[i] = left[j]
                    j += 1
                else:
                    sort[i] = right[k]
                    count += left_n - j
                    for p in range(left_n - j):
                        res.append([left[j + p], right[k]])
                    k += 1
        return sort, l_c + r_c + count, res
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
    _, count, inversions = inversion_count(in_str)
    print("There are", count, "inversions in the given list: ", inversions)