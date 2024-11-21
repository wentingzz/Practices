class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int grid[m][n];
        memset(grid, 0, sizeof(grid));
        for(auto& g: guards) grid[g[0]][g[1]] = 2;
        for(auto& w: walls)  grid[w[0]][w[1]] = 2;

        long long res = guards.size() + walls.size();
        vector<vector<int>> deltas = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(auto& g: guards){
            for(auto& d: deltas){
                int x = g[0] + d[0], y = g[1] + d[1];
                while(x >= 0 and y >= 0 and x < m and y < n and grid[x][y] < 2){
                    res += (grid[x][y] == 0);
                    grid[x][y] = 1;
                    x += d[0];
                    y += d[1];
                }
            }
        }
        return m * n - res;
    }
};
