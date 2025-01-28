class Solution {
public:
    int m, n;
    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 or r >= m or c < 0 or c >= n or grid[r][c] == 0) return 0;
        int res = grid[r][c];
        grid[r][c] = 0;
        return res + dfs(grid, r+1, c) + dfs(grid, r-1, c) + dfs(grid, r, c+1) + dfs(grid, r, c-1);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]) res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
};
