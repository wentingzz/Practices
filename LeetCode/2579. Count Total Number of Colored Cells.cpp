class BetterSolution {
public:
    long long coloredCells(int n) {
        return 1ll + 4ll * (n-1) * n / 2;
    }
};

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
