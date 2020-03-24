def binary_search(arr, tgt, min_n = 0, max_n = len(arr)-1):
    if min_n == max_n:
        if arr[min_n] == tgt:
            return min_n
        return -1
    else:
        mid_n = (min_n + max_n)//2
        if arr[mid_n] == tgt:
            return mid_n
        elif arr[mid_n] > tgt:
            return binary_search(arr, tgt, min_n, mid_n - 1)
        else:
            return binary_search(arr, tgt, mid_n + 1, max_n)
if __name__ == "__main__":
    while(True):
        array = input("Enter a sorted list of integers separatd by comma (ex. 1,2,3,4,5):")
        array = array.replace(" ", "")
        array = array.split(",")
        try:
            for i in range(len(array)):
                array[i] = int(array[i])
        except:
            print("The list contains non-integer element or is not separated by comma")
        try:
            target = int(input("Enter the target integer you want to find the index of:"))
            break
        except:
            print("The target number is not integer")
    idx = binary_search(array, target)
    if idx == -1:
        print("The target not fount")
    else:
        print("The index of", target, "is",idx)