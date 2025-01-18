class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> costs(m, vector<int>(n, m*n));
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        costs[0][0] = 0;
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        while(!dq.empty()){
            auto [r, c] = dq.front(); dq.pop_front();
            for(int i = 0; i < 4; i++){
                int nr = r + dir[i][0], nc = c + dir[i][1];
                if(nr < 0 or nc < 0 or nr >= m or nc >= n) continue;
                int curCost = (grid[r][c] != i+1);
                if(costs[nr][nc] <= curCost + costs[r][c]) continue;
                costs[nr][nc] = curCost + costs[r][c];
                if(curCost == 0){
                    dq.push_front({nr, nc});
                }
                else{
                    dq.push_back({nr, nc});
                }
            }
        }
        
        return costs[m-1][n-1];
    }
};
