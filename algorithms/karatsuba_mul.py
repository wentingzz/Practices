def kmul(x, y):
    if x < 10 or y < 10:
        return x * y
    else:
        n = min(len(str(x)), len(str(y)))//2
        
        a = x // pow(10, n)
        b = x %  pow(10, n)
        c = y // pow(10, n)
        d = y %  pow(10, n)
        ac = kmul(a, c)
        bd = kmul(b, d)
        return pow(10, n*2) * ac + pow(10, n) * (kmul(a + b, c + d) - ac - bd) + bd
if __name__ == "__main__":
    int1 = 0
    int2 = 0
    while(True):
        in_str = input("Input two integers separated by comma (ex. 14,15):")
        in_str = in_str.replace(" ", "")
        in_str = in_str.split(",")
        try:
            int1 = int(in_str[0])
            int2 = int(in_str[1])
            break
        except:
            print("The input is not integer or is not separated by comma")
    product = kmul(int1, int2)
    print("%d * %d = %d" % (int1, int2, product))

