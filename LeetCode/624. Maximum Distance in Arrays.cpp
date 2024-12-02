class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size(), res = 0, l = arrays[0][0], r = arrays[0].back();
        for(int i = 1; i < n; i++){
            res = max(res, max(abs(arrays[i][0] - r), abs(arrays[i].back() - l)));
            l = min(arrays[i][0], l);
            r = max(arrays[i].back(), r);
        }
        return res;
    }
};
