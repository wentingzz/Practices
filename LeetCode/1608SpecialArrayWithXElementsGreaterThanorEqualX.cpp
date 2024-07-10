class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(nums[0] >= n) return n;
        for(int i = 1; i <= n; i++){
            if(i + lower_bound(nums.begin(), nums.end(), i) == nums.end()) return i;
        }
        return -1;
    }
};
