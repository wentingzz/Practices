class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) if(isWater[i][j]) q.push({i, j});
        }
        int height = 0;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            int size = q.size();
            for(int s = 0; s < size; s++){
                auto [r, c] = q.front(); q.pop();
                if(res[r][c] > -1) continue;
                res[r][c] = height;
                for(auto d: dirs){
                    int nr = r + d[0], nc = c + d[1];

                    if(nr < 0 or nr >= m or nc < 0 or nc >= n or res[nr][nc] != -1) continue;
                    
                    q.push({nr, nc});
                }
            }
            height++;
        }
        return res;
    }
};
