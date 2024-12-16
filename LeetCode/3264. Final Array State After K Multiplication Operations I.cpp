class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //number, idx
        for(int i = 0; i < nums.size(); i++) pq.push({nums[i], i});

        for(int i = 0; i < k; i++){
            auto [val, idx] = pq.top(); pq.pop();
            nums[idx] *= multiplier;
            pq.push({nums[idx], idx});
        }
        return nums;
    }
};
