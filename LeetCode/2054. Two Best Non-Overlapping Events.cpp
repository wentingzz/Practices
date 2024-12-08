class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<tuple<int, bool, int>> eve;
        for(auto& e: events){
            eve.push_back({e[0], false, e[2]});
            eve.push_back({e[1], true, e[2]});
        }
        sort(eve.begin(), eve.end());
        int res = 0, maxV = 0;
        for(auto& [time, isEnd, val]: eve){
            if(isEnd) maxV = max(maxV, val);
            else res = max(res, val + maxV);
        }
        return res;
    }
};
