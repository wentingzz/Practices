class BetterSolution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> sorted(n);
        for(int i = 0; i < n; i++) sorted[i] = {nums[i], i};
        sort(sorted.begin(), sorted.end());
        vector<bool> marked(n, false);

        long long res = 0;
        for(int i = 0; i < n; i++){
            int idx = sorted[i].second;
            if(marked[idx]) continue;
            
            res += sorted[i].first; 
            marked[idx] = true;
            if(idx >= 1) marked[idx-1] = true;
            if(idx + 1 < n) marked[idx+1] = true;
        }
        return res;
    }
};

class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = nums.size();
        vector<bool> marked(n, false);
        for(int i = 0; i < n; i++) pq.push({nums[i], i});
        long long res = 0;
        while(!pq.empty()){
            int idx = pq.top().second;
            if(marked[idx]){
                pq.pop();
                continue;
            }
            res += pq.top().first; pq.pop();
            marked[idx] = true;
            if(idx >= 1) marked[idx-1] = true;
            if(idx + 1 < n) marked[idx+1] = true;
        }
        return res;
    }
};
