class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> count;
        int n = nums.size();
        for(int i = 0; i < n; i++) count[nums[i]-i]++;
        long long res = 0;
        for(auto & it: count) res += (n - it.second) * it.second;
        
        return res/2;
    }
};
