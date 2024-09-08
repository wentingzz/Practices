class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        for(int r = 1; r < nums.size(); r++){
            if(nums[l] != nums[r]){
                l++;
                nums[l] = nums[r];
            }
        }
        return l+1;
    }
};
