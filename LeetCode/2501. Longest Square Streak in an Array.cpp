class TimeSolution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(100001, -1);
        int res = -1;
        for(int& n: nums){
            dp[n] = 1;
            int rt = sqrt(n);
            if(rt * rt == n and dp[rt] > -1){
                dp[n] = dp[rt] + 1;
                res = max(res, dp[n]);
            }
        }
        return res;
        
    }
};

class SpaceSolution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int res = -1;
        for(int& n: nums){
            dp[n] = 1;
            int rt = sqrt(n);
            if(rt * rt == n and dp.find(rt) != dp.end()){
                dp[n] = dp[rt] + 1;
                res = max(res, dp[n]);
            }
        }
        return res;
        
    }
};
