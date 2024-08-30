class Solution {
public:
    int MOD = 1000000007;
    int countHousePlacements(int n) {
        long long dp[2][3] = {1,2,1}; //dp[0] = empty, dp[1] = one house, dp[2] = two houses
        for(int i = 1; i < n; i++){
            int idx = i % 2;
            int prev = 1-idx;
            dp[idx][0] = (dp[prev][0] + dp[prev][1] + dp[prev][2]) % MOD;
            dp[idx][1] = (dp[prev][1] + 2 * dp[prev][0]) % MOD;
            dp[idx][2] = dp[prev][0];
        }
        n = (n-1) % 2;

        return (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
    }
};
