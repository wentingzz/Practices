class Solution {
public:
    int getIdxAfter(vector<int>& heights, int start, int target){
        for(int i = start; i < heights.size(); i++){
            if(heights[i] > target) return i;
        }
        return -1;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> res(m);
        for(int i = 0; i < m; i++){
            if(queries[i][0] > queries[i][1]) swap(queries[i][0], queries[i][1]);
            if(queries[i][0] == queries[i][1] or heights[queries[i][0]] < heights[queries[i][1]]) res[i] = queries[i][1];
            else{
                res[i] = getIdxAfter(heights, queries[i][1], heights[queries[i][0]]);
            }
        }
        return res;
    }
};
