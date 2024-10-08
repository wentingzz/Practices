class TimeGoodSolution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> time; 
        for(auto& it: intervals){
            time.push_back({it[0], 0});
            time.push_back({it[1], 1});
        }
        sort(time.begin(), time.end());
        vector<vector<int>> res;
        int start = 10000, cnt = 0;
        for(auto t: time){
            if(t.second == 0) { //start of a interval
                if(cnt == 0) start = t.first;
                cnt++;
            }else{ //end of a interval
                cnt--;
                if(cnt == 0) res.push_back({start, t.first});
            }
        }
        
        return res;
    }
};

class SpaceGoodSolution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int l = intervals[0][0], r = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if (l == -1){
                l = intervals[i][0];
                r = intervals[i][1];
                continue;
            }
            if(r >= intervals[i][0]){
                l = min(l, intervals[i][0]);
                r = max(r, intervals[i][1]);
            } else {
                res.push_back(vector<int>{l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        if (l != -1){
            res.push_back(vector<int>{l, r});
        }
        return res;
    }
};
