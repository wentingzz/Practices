def isHappy(n):
    sq = []
    while(True):
        n = str(n)
        square = 0
        for dig in n:
            square += pow(int(dig), 2)
        if square == 1:
            return True
        if square in sq:
            return False
        else:
            sq.append(square)
            n = square
        
if __name__ == "__main__": 
    in_str = input("Enter an integer: ")
    print(isHappy(int(in_str)))