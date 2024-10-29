class SpaceSolution {
public:
    int n, m;
    int move(vector<vector<int>>& grid, vector<vector<int>>& dp, int r1, int c1, int r0, int c0){
        if(r0 >= 0 and c0 >= 0 and r0 < n and c0 < m and grid[r0][c0] < grid[r1][c1] and dp[r0][c0%2] > -1) return dp[r0][c0%2] + 1;
        return -1;
    }
    int maxMoves(vector<vector<int>>& grid) {
        //alwasy move to right cell
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        int res = 0;
        for(int j = 1; j < m; j++){
            //column traversal
            int idx = j % 2;
            for(int i = 0; i < n; i++){
                dp[i][idx] = max({
                    move(grid, dp, i, j, i-1, j-1),
                    move(grid, dp, i, j, i, j-1),
                    move(grid, dp, i, j, i+1, j-1),
                });
                res = max(res, dp[i][idx]);
            }
        }
        return res;
    }
};
