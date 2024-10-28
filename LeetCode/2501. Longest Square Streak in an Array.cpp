class TimeSolution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // bitset<100001> seen;
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
            // cout << dp[n] << " ";
        }
        return res;
        
    }
};
