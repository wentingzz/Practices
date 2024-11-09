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

class SimilarSolution {
public:
    long long minEnd(int n, int x) { 
        // 2 = 10 (replace all 0s to n bits in order)
        // x (100) => (1)10
        // 14 = 1110
        // x (100) => 11(1)10
        bitset<64> res(x);
        bitset<64> cnt(n-1);
        int bit = 0;
        for(int i = 0; i < 64; i++){
            if(res[i] == 0){
                res[i] = cnt[bit];
                bit++;
            }
        }
        return res.to_ullong();
    }
};
