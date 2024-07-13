class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> freq(101, 0);
        int res = 0;
        for(int& n: nums){
            res += freq[n]++;
        }
        return res;
    }
};
