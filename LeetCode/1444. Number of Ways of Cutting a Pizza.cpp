class Solution {
public:
    int MOD = 1000000007, rows, cols;
    int ways(vector<string>& pizza, int k) {
        rows = pizza.size(), cols = pizza[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(k + 1, -1)));
        vector<vector<int>> suSum(rows + 1, vector<int>(cols + 1, 0));
        for(int i = rows-1; i > -1; i--){
            for(int j = cols-1; j > -1; j--){
                suSum[i][j] = suSum[i][j+1] + suSum[i+1][j] - suSum[i+1][j+1] + (pizza[i][j] == 'A');
            }
        }

        return rec(dp, suSum, k, 0, 0);
    }

    int rec(vector<vector<vector<int>>>& dp, vector<vector<int>>& suSum, int k, int r, int c){
        if(k == 1) return suSum[r][c] > 0;
        if(dp[r][c][k] != -1) return dp[r][c][k];
        long long res = 0;
        for(int i = r + 1; i < rows; i++){
            if(suSum[r][c] - suSum[i][c] > 0) res = (res + rec(dp, suSum, k-1, i, c)) % MOD;
        }

        for(int i = c + 1; i < cols; i++){
            if(suSum[r][c] - suSum[r][i] > 0) res = (res + rec(dp, suSum, k-1, r, i)) % MOD;
        }
        return dp[r][c][k] = res;
    }
};
