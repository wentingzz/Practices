class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long right = 0, left = nums[0];
        for(int i = 1; i < n; i++) right += nums[i];
        int res = (left >= right);
        for(int i = 1; i < n-1; i++){
            left += nums[i];
            right -= nums[i];
            res += (left >= right);
        }
        return res;
    }
};
