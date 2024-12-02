class Solution {
public:
    int mapped(vector<int> & mapping, int val){
        if(val < 10) return mapping[val];
        int res = 0, power = 1;
        while(val){
            res += mapping[val % 10] * power;
            val /= 10;
            power *= 10;
        }
        return res;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<tuple<int, int, int>> sorted;
        for(int i = 0; i < nums.size(); i++) sorted.push_back({mapped(mapping, nums[i]), i, nums[i]});
        stable_sort(sorted.begin(), sorted.end());
        vector<int> res;
        for(auto& [m, i, v]: sorted) res.push_back(v);
        return res;
    }
};
