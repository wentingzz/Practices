class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long total = 0, smallest = abs(matrix[0][0]);
        int n = matrix.size(), cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                long long a = abs(matrix[i][j]);
                total += a;
                smallest = min(smallest, a);
                
                if(matrix[i][j] < 0) cnt = (cnt + 1) % 2;
            }
        }
        
        return cnt == 0 ? total : total - 2 * smallest;
    }
};
