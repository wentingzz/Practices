class SpaceBetterSolution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0, cur = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] < nums[i]) cur += nums[i];
            else{
                res = max(res, cur);
                cur = nums[i];
            }
            
        }
        return max(cur, res);
    }
};
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0, cur = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] >= nums[i]){
                res = max(res, cur);
                cur = 0;
            }
            cur += nums[i];
        }
        return max(cur, res);
    }
};
