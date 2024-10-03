class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long target = 0;
        for(int& n: nums) target += n;
        if(target < p) return -1;
        target = target % p; //smallest sum we want to substract from total
        if(target == 0) return 0;
        
        long long sum = 0;
        int n = nums.size(), res = n;
        unordered_map<int, int> mod;
        mod[0] = -1;
        // (prefix[i] - prefix[complement]) % p = target
        // ((sum2 % p) - (sum1 % p) + p)% p == target

        for(int i = 0; i < n; i++){
            sum += nums[i];
            int cur = sum % p, com = (cur-target+p)%p;
            if(mod.find(com) != mod.end()) res = min(res, i - mod[com]);
            mod[cur] = i;
        }
        if(res == n) return -1;
        return res;
    }
};
