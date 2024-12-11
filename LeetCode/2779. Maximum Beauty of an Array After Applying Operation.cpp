class LessSpaceSolution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 1, l = 0;
        for(int r = 1; r < nums.size(); r++){
            while(nums[r] - nums[l] > 2 * k) l++;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
