class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[startRow][startColumn] = 1;

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        long long res = 0; 
        int MOD = 1000000007;
        for(int i = 0; i < maxMove; i++) {
            vector<vector<int>> temp(m, vector<int>(n, 0));
            for(int r = 0; r < m; r++) {
                for(int c = 0; c < n; c++) {
                    if(dp[r][c] == 0) {
                        continue;
                    }
                    for(auto& [dr, dc] : dirs) {
                        int nr = r + dr, nc = c + dc;
                        if(nr < 0 || nc < 0 || nr >= m || nc >= n) {
                            res = (res + dp[r][c]) % MOD;
                        } else {
                            temp[nr][nc] = (temp[nr][nc] + dp[r][c]) % MOD;
                        }
                    }
                }
            }
            dp = temp;
        }
        return res;
    }
};
