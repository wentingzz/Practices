class Solution {
public:
    int n;
    int binarySearch(vector<pair<int, int>>& jobs, int diff){
        if(diff < jobs[0].first) return 0;
        if(diff >= jobs.back().first) return jobs.back().second;
        int l = 0, h = n-1, mid, res = 0;
        
        while(l <= h){
            mid = l + (h-l)/2;
            if(jobs[mid].first == diff) {
                //if neighbors have the same difficulty level, we want to get the max value among all those neighbors
                for(int i = mid; i >= 0 && jobs[i].first == diff; i--) res = max(res, jobs[i].second);
                for(int i = mid + 1; i < n && jobs[i].first == diff; i++) res = max(res, jobs[i].second);
                return res;
            }else if(jobs[mid].first < diff){
                res = jobs[mid].second;
                l = mid + 1;
            }
            else h = mid - 1;
        }
        return res;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        n = difficulty.size();
        // sort the jobs by difficulty and update profit to be the max profit if the worker can complete this difficulty level
        for(int i = 0; i < n; i++) jobs.push_back({difficulty[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        for(int i = 1; i < n; i++) jobs[i].second = max(jobs[i-1].second, jobs[i].second);

        int res = 0;
        for(int& w: worker)res += binarySearch(jobs, w);
        return res;
    }
};
