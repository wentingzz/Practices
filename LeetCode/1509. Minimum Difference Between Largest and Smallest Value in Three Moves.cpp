class BetterSolution {
public:
    int maxTotalInLen(vector<int>& nums, int k){
        int res = 0;
        for(int i = 0; i < k; i++) res += nums[i];
        int cur = res;
        for(int i = k; i < nums.size(); i++){
            cur = cur + nums[i] - nums[i-k];
            res = max(cur, res);
        }
        return res;
    }
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n < 5) return 0;
        sort(nums.begin(), nums.end());
        //maximize the total in a subarray whhose length = 3
        vector<int> tmp = {nums[3] - nums[2], nums[2] - nums[1], nums[1] - nums[0], nums[n-1] - nums[n-2], nums[n-2] - nums[n-3], nums[n-3] - nums[n-4]};
        return nums.back() - nums[0] - maxTotalInLen(tmp, 3);
    }
};

class Solution {
public:
    int maxTotalInLen(vector<int>& nums, int k){
        int res = 0;
        for(int i = 0; i < k; i++) res += nums[i];
        int cur = res;
        for(int i = k; i < nums.size(); i++){
            cur = cur + nums[i] - nums[i-k];
            res = max(cur, res);
        }
        return res;
    }
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3) return 0;
        sort(nums.begin(), nums.end());
        //maximize the total in a subarray whhose length = 3
        vector<int> tmp = {nums[3] - nums[2], nums[2] - nums[1], nums[1] - nums[0], nums[n-1] - nums[n-2], nums[n-2] - nums[n-3], nums[n-3] - nums[n-4]};
        return nums.back() - nums[0] - maxTotalInLen(tmp, 3);
    }
};
