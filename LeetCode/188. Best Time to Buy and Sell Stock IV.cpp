class Solution {
public:
    int rec(int trans, int idx, bool canSell, vector<int>& prices, vector<vector<int>>& dp, int k, int& n){
        if(trans >= k or idx >= n) return 0;
        if(dp[trans][idx] != -1) return dp[trans][idx];
        return dp[trans][idx] = max(rec(trans, idx+1, canSell, prices, dp, k, n), (canSell ? 1:-1) * prices[idx] + rec(trans+1, idx+1, !canSell, prices, dp, k, n));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(), res = 0;
        if(k >= n){
            for(int i = 1; i < n; i++) if(prices[i] > prices[i-1]) res += prices[i] - prices[i-1];
            return res;
        }
        vector<vector<int>> dp(2*k, vector<int>(n, -1));
        return rec(0, 0, false, prices, dp, 2*k, n);
        
    }
};
