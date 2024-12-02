class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> arr; 
        for(int i = 0; i < n; i++){
            long long sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin(), arr.end());
        long long res = 0, MOD = 1000000007;
        for(int i = left - 1; i < right; i++){
            res = (res + arr[i]) % MOD;
        }
        return res;
    }
};
