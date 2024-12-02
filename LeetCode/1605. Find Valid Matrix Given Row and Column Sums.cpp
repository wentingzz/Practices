class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        int i = 0, j = 0;
        vector<vector<int>> res(n, vector<int>(m, 0));
        while(i < n and j < m){
            if(rowSum[i] < colSum[j]){
                res[i][j] = rowSum[i];
                colSum[j] -= rowSum[i];
                rowSum[i] = 0;
            }else{
                res[i][j] = colSum[j];
                rowSum[i] -= colSum[j];
                colSum[j] = 0;
            }
            if(rowSum[i] == 0) i++;
            if(colSum[j] == 0) j++;
        }
        return res;
    }
};
