class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        // k = max value of nums
        // length of longest subarray (all equal to k)
        int k = 0, l = -1;
        for(int& n: nums) k = max(k, n);
        int res = 1;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == k){
                if(l == -1) l = r;
                else res = max(res, r - l + 1);
            }else l = -1;
        }
        return res;
    }
};
