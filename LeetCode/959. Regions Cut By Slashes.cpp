class Solution {
public:
    void mark(vector<vector<bool>>& grid, int r, int c, int n){
        if(r >= 0 and r < n and c >= 0 and c < n and grid[r][c] == false){
            grid[r][c] = true;
            mark(grid, r+1, c, n);
            mark(grid, r-1, c, n);
            mark(grid, r, c+1, n);
            mark(grid, r, c-1, n);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<bool>> map(3*n, vector<bool>(3*n, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '/'){
                    map[i*3][j*3+2] = true;
                    map[i*3+1][j*3+1] = true;
                    map[i*3+2][j*3] = true;
                }else if (grid[i][j] == '\\'){
                    map[i*3][j*3] = true;
                    map[i*3+1][j*3+1] = true;
                    map[i*3+2][j*3+2] = true;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < 3*n; i++){
            for(int j = 0; j < 3*n; j++){
                if(map[i][j] == false){
                    mark(map, i, j, 3*n);
                    res++;
                }
            }
        }
        return res;
    }
};
