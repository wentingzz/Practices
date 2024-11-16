class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1) return nums;
        
        vector<int> res(n-k+1, -1);
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1] + 1) cnt++;
            else cnt = 1;
            if(cnt >= k) res[i-k+1] = nums[i];
        }
        return res;
    }
};
