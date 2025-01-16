class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // A xor A = 0
        int res = 0;
        if(nums2.size() % 2) for(int& n: nums1) res ^= n;
        if(nums1.size() % 2) for(int&n: nums2) res ^= n;
        return res;
    }
};
