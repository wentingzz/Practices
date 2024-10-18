class Solution {
public:
    int n;
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        n = nums.size();
        for(int& x: nums) target |= x;
        int res = 0;
        dfs(nums, 0, 0, target, res);
        return res;
    }

    void dfs(vector<int>& nums, int cur, int idx, int& target, int& res){
        if(idx >= n or cur == target){
            if(cur == target) res += pow(2, n-idx); 
            return;
        }
        //don't include current idx
        dfs(nums, cur, idx+1, target, res);
        //include current idx
        cur |= nums[idx];
        dfs(nums, cur, idx+1, target, res);
    }
};
