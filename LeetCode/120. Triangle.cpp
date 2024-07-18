class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 1; i < triangle.size(); i++){
            int n = triangle[i].size();
            triangle[i][0] += triangle[i-1][0];
            for(int j = 1; j < n - 1; j++){
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
            triangle[i][n-1] += triangle[i-1][n-2];
        }
        int res = triangle.back()[0];
        for(int& n: triangle.back()) res = min(res, n);
        return res;
    }
};
