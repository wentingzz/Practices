class BetterSolution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> times(1440, false);
        int start = 1440;
        for(string& s: timePoints){
            int idx = ((s[0]-'0') * 10 + s[1]-'0') * 60 + (s[3]-'0') * 10 + s[4] - '0';
            if(times[idx]) return 0;
            times[idx] = true;
            start = min(idx, start);
        }

        int res = 1440, l = start;
        for(int i = l + 1; i < 1440; i++){
            if(times[i]){
                int diff = i - l;
                res = min(res, min(diff, 1440-diff));
                l = i;
            }
        }
        int diff = l - start;
        if(l != start) return min(res, min(diff, 1440 - diff));
        return res;
    }
};

class Solution {
public:
    int timeDiff(string& early, string& late){
        int hour = (late[0] - early[0]) * 10 + (late[1] - early[1]);
        int minu = (late[3] - early[3]) * 10 + late[4] - early[4];
        int res = abs(hour * 60 + minu);
        return min(res, 1440-res);
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int res = timeDiff(timePoints[0], timePoints.back());
        for(int i = 1; i < timePoints.size(); i++){
            res = min(res, timeDiff(timePoints[i-1], timePoints[i]));
        }
        return res;
    }
};
