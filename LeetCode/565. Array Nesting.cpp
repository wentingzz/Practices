class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n, false);
        int res = 0;
        for(int i = 0; i < n; i++){
            if(!seen[i]) res = max(res, dfs(nums, seen, i));
        }
        return res;
    }

    int dfs(vector<int>& nums, vector<bool>& seen, int idx){
        if(seen[idx]) return 0;
        seen[idx] = true;
        int res = dfs(nums, seen, nums[idx]);
        return res + 1;
    }
};
