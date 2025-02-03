class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1, cur = 1;
        bool dec = false;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] < nums[i]){
                if(dec){
                    cur = 2;
                    dec = false;
                }else cur++;
            }else if(nums[i-1] > nums[i]){
                if(dec) cur++;
                else{
                    dec = true;
                    cur = 2;
                }
            }else cur = 1;
            res = max(res, cur);
        }
        return res;
    }
};
