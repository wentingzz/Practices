class Solution {
public:
    long long coloredCells(int n) {
        long long res = 1;
        for(int i = 1; i <= n; i++){
            res += (i-1)*4;
        }
        return res;
    }
};
