def maxProfit(self, prices):
    l = len(prices)
    res = 0
    for i in range(1, l):
        diff = prices[i] - prices[i-1]
        if diff > 0:
            res += diff
    return res