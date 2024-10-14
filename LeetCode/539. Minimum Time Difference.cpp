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
