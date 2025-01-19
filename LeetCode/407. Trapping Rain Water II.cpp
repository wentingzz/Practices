// BFS solution from leetcode
class BestSolution {
public:
    int trapRainWater(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        vector<vector<bool>> seen(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            seen[i][0] = true, seen[i][n-1] = true;
            pq.push({heights[i][0], i, 0});
            pq.push({heights[i][n-1], i, n-1});
        }
        for(int j = 0; j < n; j++){
            seen[0][j] = true, seen[m-1][j] = true;
            pq.push({heights[0][j], 0, j});
            pq.push({heights[m-1][j], m-1, j});
        }
        vector<vector<int>> dir = {{-1,0}, {1, 0}, {0,-1}, {0,1}};
        int res = 0;
        while(!pq.empty()){
            auto [h, r, c] = pq.top(); pq.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dir[i][0], nc = c + dir[i][1];
                if(nr < 0 or nc < 0 or nr >= m or nc >=n or seen[nr][nc]) continue;
                seen[nr][nc] = true;
                res += max(0, h - heights[nr][nc]);
                pq.push({max(h, heights[nr][nc]), nr, nc});
            }
        }
        return res;
    }
    
};
