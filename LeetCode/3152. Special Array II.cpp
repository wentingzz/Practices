class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int* pre = new int[n];
        pre[0] = 0;
        for(int i = 1; i < n; i++) pre[i] = pre[i-1] + ((nums[i-1] % 2) == (nums[i] % 2));
        
        vector<bool> res;
        for(auto& q: queries) res.push_back(pre[q[1]] - pre[q[0]] == 0);
        

        return res;
    }
};
