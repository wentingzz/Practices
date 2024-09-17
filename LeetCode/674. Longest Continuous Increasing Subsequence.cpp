class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int l = 0, n = nums.size(), res = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i-1]){
                res = max(i-l, res);
                l = i;
            }
        }
        return max(n-l, res);
    }
};
