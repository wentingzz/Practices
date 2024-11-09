class Solution {
public:
    long long minEnd(int n, int x) { 
        int left = n-1, shift = 0;
        long long res = x;
        while(left){
            if(((long long)x & (1ll << shift)) == 0){
                res |= ((left & 1ll) << shift);
                left >>= 1;
            }
            shift++;
        }
        return res;
    }
};
