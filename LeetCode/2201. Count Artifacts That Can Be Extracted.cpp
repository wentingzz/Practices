class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int m = artifacts.size();
        int sizes[m];
        int grid[n][n];
        memset(grid, -1, sizeof(grid));
        for(int i = 0; i < m; i++){
            auto a = artifacts[i];
            sizes[i] = (a[2] - a[0] + 1) * (a[3] - a[1] + 1);
            for(int r = a[0]; r <= a[2]; r++){
                for(int c = a[1]; c <= a[3]; c++){
                    grid[r][c] = i;
                }
            }
        }

        int res = 0;
        for(vector<int>& d: dig){
            int a = grid[d[0]][d[1]];
            if(a != -1){
                sizes[a]--;
                if(sizes[a] == 0) res++;
                grid[d[0]][d[1]] = -1;
            }
        }
        return res;
    }
};
