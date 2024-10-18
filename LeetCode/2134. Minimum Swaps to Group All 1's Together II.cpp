class Solution {
public:
    int minSwaps(vector<int>& nums) {
        nums.insert(nums.end(), nums.begin(), nums.end());
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + nums[i-1];
        int target = pre[n/2], res = target, j = 0;
        for(int i = target; i <= n; i++){
            res = min(res, target - (pre[i] - pre[j++]));
        }

        return res;
    }
};
