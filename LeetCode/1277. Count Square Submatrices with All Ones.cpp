class Solution {
public:

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> preSum(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++) preSum[i][1] = preSum[i-1][1] + matrix[i-1][0];
        for(int i = 1; i <= m; i++) preSum[1][i] = preSum[1][i-1] + matrix[1][i-1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                preSum[i][j] = preSum[i][j-1] + preSum[i-1][j] - preSum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int k = 1; k <= min(i, j); k++){
                    if(k*k == preSum[i][j] - preSum[i-k][j] - preSum[i][j-k] + preSum[i-k][j-k]){
                        res++;
                    } else break;
                }
            }
        }
        return res;
    }
};
