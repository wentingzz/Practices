class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i-1] == nums[i]){
                nums[i-1] *= 2;
                nums[i] = 0;
            }
        }
        int j = 0;
        while(j < n and nums[j] != 0) j++;
        for(int i = j; i < n; i++){
            if(nums[i] != 0) swap(nums[i], nums[j++]);
        }
        return nums;
    }
};
