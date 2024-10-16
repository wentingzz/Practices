class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long total = chalk[0], n = chalk.size();
        for(int i = 1; i < n; i++) total += chalk[i];
        k = (k % total);
        //binary search can be more effective
        total = 0;
        for(int i = 0; i < n; i++){
            total += chalk[i];
            if(total > k) return i;
        }
        return -1;
    }
};
