class Solution {
public:
    vector<vector<int>> pres;
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        pres.resize(n+1);
        for(vector<int>& r: relations){
            pres[r[0]].push_back(r[1]);
        }
        int res = 0;
        vector<int> dp(n+1, -1);
        for(int i = 1; i <= n; i++){
            res = max(res, dfs(time, dp, i));
        }

        return res;
    }

    int dfs(vector<int>& time, vector<int>& dp, int i){
        if(dp[i] != -1) return dp[i];
        int res = 0;
        for(int n: pres[i]){
            res = max(res, dfs(time, dp, n));
        }

        dp[i] = res + time[i-1];
        return dp[i];
    }
};
