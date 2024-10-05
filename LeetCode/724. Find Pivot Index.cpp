class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int r = 0;
        for(int n : nums) r += n;

        int l = 0;
        r -= nums[0];
        if(l == r) return 0;
        for(int i = 1; i < nums.size(); i++){
            l += nums[i-1];
            r -= nums[i];
            // cout << l << " & " << r << endl;
            if(l == r) return i;
        }
        return -1;
    }
};
