class BetterSolution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, cur = 0;
        int freq[100001] = {};
        int cnt = 0;
        for(int i = 0; i < k; i++){
            if(freq[nums[i]] == 1) cnt++; //count non-distinct elements
            cur += nums[i];
            freq[nums[i]]++;
        }
        if(cnt == 0) res = max(res, cur);
        for(int i = k; i < nums.size(); i++){
            if(freq[nums[i]] == 1) cnt++;
            freq[nums[i]]++;
            if(freq[nums[i-k]] == 2) cnt--; 
            freq[nums[i-k]]--;
            cur += nums[i] - nums[i-k];

            if(cnt == 0) res = max(res, cur);
        }
        return res;
        
    }
};
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, cur = 0;
        unordered_map<int, int> freq;
        int cnt = 0;
        for(int i = 0; i < k; i++){
            if(freq[nums[i]] == 1) cnt++; //count non-distinct elements
            cur += nums[i];
            freq[nums[i]]++;
        }
        if(cnt == 0) res = max(res, cur);
        for(int i = k; i < nums.size(); i++){
            if(freq[nums[i]] == 1) cnt++;
            freq[nums[i]]++;
            if(freq[nums[i-k]] == 2) cnt--; 
            freq[nums[i-k]]--;
            cur += nums[i] - nums[i-k];

            if(cnt == 0) res = max(res, cur);
        }
        return res;
        
    }
};
