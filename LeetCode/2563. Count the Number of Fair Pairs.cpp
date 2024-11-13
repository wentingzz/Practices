class Solution {
public:
    void insertInSortedVector(std::vector<int>& vec, int element) {
        auto pos = std::lower_bound(vec.begin(), vec.end(), element);
        vec.insert(pos, element);
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0;
        
        vector<int> tmp;
        int n = nums.size();
        for(int i = n-1; i > -1; i--){
            res += (upper_bound(tmp.begin(), tmp.end(), upper - nums[i]) - lower_bound(tmp.begin(), tmp.end(), lower - nums[i]));
            insertInSortedVector(tmp, nums[i]);
        }
        return res;
    }
};
