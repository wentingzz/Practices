class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = 0;
        while(start or goal){
            res += (start % 2) ^ (goal % 2);
            start /= 2;
            goal /= 2;
        }
        return res;
    }
};
