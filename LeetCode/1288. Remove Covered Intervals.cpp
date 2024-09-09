class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), res = 0, l = -1, r = -1;
        for(int i = 0; i < n; i++){
            if(intervals[i][0] > l and intervals[i][1] > r){
                l = intervals[i][0];
                res++;
            }
            r = max(r, intervals[i][1]);
        }
        return res;
    }
};
