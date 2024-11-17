class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; //(preSum, index)
        int res = n+1;
        long long sum = 0;
        for(int r = 0; r < n; r++){
            sum += nums[r];
            if(sum >= k) res = min(res, r+1);
            
            while(!pq.empty() and sum - pq.top().first >= k){
                res = min(res, r - pq.top().second);
                pq.pop();
            }
            pq.push({sum, r});
        }
        return res == n + 1 ? -1 : res;
    }
};
