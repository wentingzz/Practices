class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][1] == edges[1][1] or edges[0][1] == edges[1][0]) return edges[0][1];
        return edges[0][0];
    }
};
