class Solution {
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
