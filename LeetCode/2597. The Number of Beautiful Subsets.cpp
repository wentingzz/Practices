class Solution {
public:
    int n;
    int dfs(vector<int>& nums, int idx, unordered_map<int, int>& m, int& k){
        if(idx == n) return 1;
        int res = dfs(nums, idx + 1, m, k);
        if(m[nums[idx] - k] == 0){
            m[nums[idx]]++;
            res += dfs(nums, idx+1, m, k);
            m[nums[idx]]--;
        }
        return res;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for(int& n: nums) m[n] = 0;
        int res = dfs(nums, 0, m, k);
        return res-1; //substract the empty subset
    }
};
