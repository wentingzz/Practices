class BetterTimeSolution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        k = k % (m * n);
        vector<vector<int>> res(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int tmp = j + k;
                res[(i + (tmp)/m) % n][tmp % m] = grid[i][j];
            }
        }
        return res;
    }
};

class SlightlyBetterSpaceSolution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k = k % (m*n);
        if(k == 0){
            return grid;
        }
        for(int i = 0; i < k; i++){
            for(int j = 0; j < m; j++){
                int tmp = grid[j][n-1];
                rotate(grid[j].begin(), grid[j].begin() + n-1, grid[j].end());
            }
            int tmp = grid[m-1][0];
            for(int j = m-1; j > 0; j--){
                grid[j][0] = grid[j-1][0];
            }
            grid[0][0] = tmp;
        }
        return grid;
    }
};
