class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles, exchange, left;
        while(numBottles >= numExchange){
            exchange = numBottles / numExchange;
            left = numBottles % numExchange;
            res += exchange;
            numBottles = exchange + left;
        }
        return res;
    }
};
