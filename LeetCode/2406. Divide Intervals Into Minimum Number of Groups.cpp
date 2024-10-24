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


class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        for(auto& i: intervals){
            starts.push_back(i[0]);
            ends.push_back(i[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int end_ptr = 0, cur = 0;
        for(int& s: starts){
            if(s > ends[end_ptr]) end_ptr++;
            else cur++;
        }
        return cur;
    }
};
