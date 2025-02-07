class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> pdt;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++) pdt[nums[i] * nums[j]]++;
        }
        int res = 0;
        for(auto it: pdt) res += it.second * (it.second-1) * 4;
        
        return res;
    }
};
