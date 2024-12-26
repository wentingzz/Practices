class Solution {
public:
    int n;
    int res = 0;
    int rec(vector<int>& nums, vector<vector<int>>& dp, int idx, int target){
        if(idx == n or target > 1000){ //base case
            res += (target == 0);
            return target == 0;
        }
        if(dp[idx][target + 1000] != -1){ //access memory
            res += dp[idx][target + 1000];
            return dp[idx][target + 1000];
        }

        dp[idx][target + 1000] = rec(nums, dp, idx+1, target + nums[idx]) + rec(nums, dp, idx+1, target - nums[idx]);
        return dp[idx][target + 1000];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        // -1000 to 0 stores at dp[0] to dp[1000]
        // 1 to 1000 stores at dp[1001] to dp[2000]
        // idx = num + 1000
        int sum = 0;
        for(int& n: nums) sum += n;
        if(sum < abs(target)) return 0;
        
        vector<vector<int>> dp(n, vector<int>(2001, -1));
        return rec(nums, dp, 0, target);
        
    }
};
