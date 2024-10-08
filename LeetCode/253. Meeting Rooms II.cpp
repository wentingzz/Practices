/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> time;
        for(Interval& i: intervals){
            time.push_back({i.start, 1});
            time.push_back({i.end, -1});
        }
        sort(time.begin(), time.end());
        int res = 0, cnt = 0;
        for(auto t: time){
            cnt += t.second;
            res = max(res, cnt);
        }
        return res;
    }
};
