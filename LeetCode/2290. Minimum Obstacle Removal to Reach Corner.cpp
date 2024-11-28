class Solution {
public:
    int n, m;
    void addAdj(vector<vector<int>>& grid, deque<pair<int, int>>& q, int step, vector<vector<int>>& removes, int x, int y){
        if(x >= 0 and y >= 0 and x < n and y < m){
            int rmv = step + grid[x][y];
            if(rmv < removes[x][y]){
                removes[x][y] = rmv;
                if(grid[x][y] == 0) q.push_front({x,y});
                else q.push_back({x, y});
            }
        }
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> removes(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> q;
        q.push_front({0, 0});
        removes[0][0] = 0;
        while(!q.empty()){
            auto cur = q.front(); q.pop_front();
            addAdj(grid, q, removes[cur.first][cur.second], removes, cur.first - 1, cur.second);
            addAdj(grid, q, removes[cur.first][cur.second], removes, cur.first + 1, cur.second);
            addAdj(grid, q, removes[cur.first][cur.second], removes, cur.first, cur.second - 1);
            addAdj(grid, q, removes[cur.first][cur.second], removes, cur.first, cur.second + 1);
        }
        return removes.back().back();
    }
};
