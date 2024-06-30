class Solution {
public:
//quicker execution time + less space used
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1) return matrix[0][0];

        for(int i = 1; i < n-1; i++){
            for(int j = 0; j < n; j++){
                int cur = matrix[i-1][j];
                if(j > 0) cur = min(cur, matrix[i-1][j-1]);
                if(j < n-1) cur = min(cur, matrix[i-1][j+1]);

                matrix[i][j] += cur;
            }
        }

        int res = INT_MAX;
        for(int j = 0; j < n; j++){
            int cur = matrix[n-2][j];
            if(j > 0) cur = min(cur, matrix[n-2][j-1]);
            if(j < n-1) cur = min(cur, matrix[n-2][j+1]);

            res = min(res, matrix[n-1][j] + cur);
        }

        return res;
    }

//more intuitive (similar to 935 implementation)
    int minFallingPathSum2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1) return matrix[0][0];
        int res[n][2];
        for(int i = 0; i < n; i++) res[i][0] = matrix[0][i];

        for(int i = 1; i < n; i++){
            int c = i % 2;
            res[0][c] = min(res[0][1-c], res[1][1-c]) + matrix[i][0];
            for(int j = 1; j < n-1; j++){
                res[j][c] = min(min(res[j-1][1-c], res[j][1-c]), res[j+1][1-c]) + matrix[i][j];
            }
            res[n-1][c] = min(res[n-2][1-c], res[n-1][1-c]) + matrix[i][n-1];
        }
        int finalColumn = (n + 1) % 2;
        int ret = INT_MAX;
        for(int i = 0; i < n; i++){
            ret = min(res[i][finalColumn], ret);
        }
        return ret;
    }
};

