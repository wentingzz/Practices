class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int total = 0, n = nums.size(), r = 0, res = n+1;
        for(int l = 0; l < n; l++){
            while(total < target and r < n){
                total += nums[r++];
            }
            if(total >= target) res = min(res, r-l);
            else break;
            total -= nums[l];
        }
        return res == n+1 ? 0 : res;
    }
};
