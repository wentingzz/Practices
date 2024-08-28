class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int,int>> groups;
        for(auto& i: intervals){
            groups.push_back({i[0], -1});
            groups.push_back({i[1], 1});
        }
        sort(groups.begin(), groups.end());
        int res = 0, cnt = 0;
        for(auto& g: groups){
            cnt -= g.second;
            res = max(res, cnt);
        }
        return res;
    }
};
