class Solution {
public:
    bool possible(vector<int>& times, long long time, int totalTrips){
        long long cnt = 0;
        for(int& t: times){
            cnt += time/t;
        }
        return totalTrips <= cnt;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = time[0], h = time[0];
        for(int& t: time){
            l = min((long long)t, l);
            h = max((long long)t, h);
        }
        h = totalTrips * h;
        long long m, res = h;
        while(l <= h){
            m = l + (h-l)/2;
            if(possible(time, m, totalTrips)){
                res = min(res, m);
                h = m - 1;
            }else l = m + 1;
        }
        return res;
    }
};
