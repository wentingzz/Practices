class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int res = -1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1] + 1){
                int idx = i-1;
                i++;
                while(i < nums.size() and nums[i] == nums[i-2]){
                    i++;
                }
                res = max(res, i-idx);
                i--;
            }
        }
        return res;
    }
};
