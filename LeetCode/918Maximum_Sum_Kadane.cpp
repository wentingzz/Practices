class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_cur = nums[0], max_all = nums[0], min_cur = nums[0], min_all = nums[0], total = nums[0];

        for(int i = 1; i < nums.size(); i++){
            int n = nums[i];
            max_cur = max(max_cur + n, n);
            max_all = max(max_cur, max_all);
            min_cur = min(min_cur + n, n);
            min_all = min(min_cur, min_all);
            total += n;
        }
        return max(max_all, total == min_all ? max_all : total - min_all);
    }

    int maxSubarray(std::vector<int>& nums) {
        if (nums.empty()) return 0; // Or handle the case as needed

        int max_current = nums[0], max_global = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            max_current = max(nums[i], max_current + nums[i]);
            max_global = max(max_current, max_global);
        }

        return max_global;
    }
};
