class Solution {
public:
    int n;
    bool hasPairs(vector<int>& nums, int diff, int target){
        int res = 0;
        for(int i = 0; i < n; i++){
            res += distance(nums.begin() + i, upper_bound(nums.begin(), nums.end(), nums[i] + diff)) - 1;
            if(res >= target) return true;
        }
        return res >= target;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        int l = 0, h = nums.back() - nums[0];
        int m, res;
        while(l <= h){
            m = l + (h - l) / 2;
            if(hasPairs(nums, m, k)){
                res = m;
                h = m - 1;
            }else{
                l = m + 1;
            }
        }
        return res;
    }
};
