class Solution {
public:
    int MOD = 1000000007;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        dp[0][0] = 1;
        
        return dfs(n, k, target, dp);
    }

    int dfs(int n, int k, int target, vector<vector<int>>& dp) {
        if(n < 0 or target < 0) return 0;
        if(dp[n][target] != -1) return dp[n][target];
        long long res = 0;
        for(int i = 1; i <= k; i++){
            res = (res + dfs(n-1, k, target - i, dp)) % MOD;
        }
        return dp[n][target] = res % MOD;
    }
};

class Solution2 {
public:
    int MOD = 1000000007;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        dp[0][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
                long long res = 0;
                for(int d = 1; d <=k && j-d >= 0; d++){
                    if(dp[i-1][j-d] > 0){
                        res = (res + dp[i-1][j-d]) % MOD;
                    }
                }
                dp[i][j] = res;
            }
        }
        
        return dp[n][target];
    }
};
