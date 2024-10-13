class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int k = nums.size(), upper = -100000;
        for(int i = 0; i < k; i++) pq.push({nums[i][0], i}), upper = max(upper, nums[i][0]);
        vector<int> index(k, 0);
        vector<int> res = {-100000, 100000};
        int range = res[1] - res[0];
        
        while(pq.size() == k){
            if(upper - pq.top().first < range){
                res = {pq.top().first, upper};
                range = res[1] - res[0];
            }
            int idx = pq.top().second;
            if(index[idx] < nums[idx].size() - 1){
                index[idx]++;
                pq.push({nums[idx][index[idx]], idx});
                upper = max(upper, nums[idx][index[idx]]);
                pq.pop();
            }else break; //one of the k list ends (cannot covered anymore)
        }
        return res;
    }
};
