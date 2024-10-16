class BetterSolution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long total = chalk[0];
        for(int i = 1; i < chalk.size(); i++) total += chalk[i];
        k = (k % total);
        //binary search can be more effective
        for(int i = 0; i < chalk.size(); i++){
            if(chalk[i] > k) return i;
            k -= chalk[i];
        }
        return -1;
    }
};

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long total = 0, n = chalk.size();
        vector<long> sum(n);
        for(int i = 0; i < n; i++){
            total += chalk[i];
            sum[i] = total;
        }
        k = (k % total);
        //binary search i where sum[i] > target and i is the smallest
        int l = 0, r = n, m, res = -1;
        while(l <= r){
            m = l + (r-l)/2;
            if(sum[m] > k){
                res = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return res;
    }
};
