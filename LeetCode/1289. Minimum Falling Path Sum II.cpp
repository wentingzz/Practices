class BetterSpaceSolution {
public:
    int n;
    
    void fillMinAtRow(vector<int>& gridRow, vector<int>& minLeft, vector<int>& minRight) {
        int cur = INT_MAX;
        for (int c = 0; c < n; c++) {
            minLeft[c] = cur;
            cur = min(cur, gridRow[c]);
        }

        cur = INT_MAX;
        for (int c = n - 1; c > -1; c--) {
            minRight[c] = cur;
            cur = min(cur, gridRow[c]);
        }
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 1) return grid[0][0];  

        vector<int> minLeft(n);
        vector<int> minRight(n);
        vector<int> dpPrev = grid[0]; // Store the previous row's dp values
        vector<int> dpCur(n, INT_MAX); // Store the current row's dp values
        fillMinAtRow(dpPrev, minLeft, minRight);

        for (int r = 1; r < n; r++) {
            for (int c = 0; c < n; c++) {
                dpCur[c] = grid[r][c] + min(minLeft[c], minRight[c]);
            }
            dpPrev = dpCur; // Move current dp to previous dp for the next iteration
            fillMinAtRow(dpCur, minLeft, minRight);
        }

        int res = dpCur[0];
        for (int c = 1; c < n; c++) {
            res = min(res, dpCur[c]);
        }
        return res;
    }
};

class Solution {
public:
    int n;
    void fillMinAtRow(vector<vector<int>>& grid, vector<vector<int>>& minLeft, vector<vector<int>>& minRight, int r){
        int cur = INT_MAX;
        for(int c = 0; c < n; c++){
            minLeft[r%2][c] = cur;
            cur = min(cur, grid[r][c]);
        }

        cur = INT_MAX;
        for(int c = n-1; c > -1; c--){
            minRight[r%2][c] = cur;
            cur = min(cur, grid[r][c]);
        }
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> minLeft(2, vector<int>(n));
        vector<vector<int>> minRight(2, vector<int>(n));
        vector<vector<int>> dp(n, vector<int>(n, 100));
        for(int c = 0; c < n; c++){
            dp[0][c] = grid[0][c];
        }
        fillMinAtRow(grid, minLeft, minRight, 0);

        for(int r = 1; r < n; r++){
            for(int c = 0; c < n; c++){
                dp[r][c] = grid[r][c] + min(minLeft[(r-1)%2][c], minRight[(r-1)%2][c]);
            }
            fillMinAtRow(dp, minLeft, minRight, r);
        }

        // for(int r = 0; r < n; r++){
        //     for(int c = 0; c < n; c++){
        //         cout << dp[r][c] << " ";
        //     }
        //     cout << endl;
        // }

        int res = dp[n-1][0];
        for(int c = 1; c < n; c++){
            res = min(res, dp[n-1][c]);
        }
        return res;
    }
};
