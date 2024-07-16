class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res = 0;
        int count = 0, min_xor = INT_MAX;
        for(int& n: nums){
            int val = n ^ k;
            if(val > n){
                res += val;
                count++;
                min_xor = min(min_xor, val - n);
            }else{
                res += n;
                min_xor = min(min_xor, n - val);
            }
        }

        return count % 2 > 0 ? res - min_xor : res;
    }
};
