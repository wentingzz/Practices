class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> minRows(m, INT_MAX);
        vector<int> maxCols(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                minRows[i] = min(minRows[i], matrix[i][j]);
                maxCols[j] = max(maxCols[j], matrix[i][j]);
            }
        }

        vector<int> res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == minRows[i] and matrix[i][j] == maxCols[j]) res.push_back(matrix[i][j]);
            }
        }
        
        return res;
    }
};
