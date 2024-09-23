class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if(n * m != r * c) return mat;
        vector<vector<int>> res(r, vector<int>(c));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int tmp = i * c + j;
                res[i][j] = mat[tmp / m][tmp % m];
            }
        }
        return res;
    }
};
