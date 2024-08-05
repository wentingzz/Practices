class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                int sum = 0, cnt = 0;
                for(int dr = -1; dr <= 1; dr++){
                    for(int dc = -1; dc <= 1; dc++){
                        int cr = r + dr, cc = c + dc;
                        if(cr < 0 or cr >= n or cc < 0 or cc >= m) continue;
                        sum += img[cr][cc];
                        cnt++;
                    }
                }
                res[r][c] = floor(1.0*sum/cnt);
            }
        }
        return res;
    }
};
