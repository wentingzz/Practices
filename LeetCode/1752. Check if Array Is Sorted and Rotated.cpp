class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool firstJump = false;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]){
                if(firstJump) return false;
                firstJump = true;
            }
        }

        return !firstJump or nums[0] >= nums.back();
    }
};
