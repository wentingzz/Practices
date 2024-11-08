class BetterSolution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> prev(n+1);
        prev[0] = pow(2, maximumBit) - 1;
        for(int i = 0; i < n; i++){
            prev[i+1] = prev[i] ^ nums[i];
        }
        reverse(prev.begin(), prev.end());
        prev.pop_back();
        return prev;

    }
};

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> prev(n+1, 0);
        for(int i = 0; i < n; i++){
            prev[i+1] = prev[i] ^ nums[i];
        }
        int target = pow(2, maximumBit) - 1;
        for(int& n: prev) n = target ^ n;
        
        reverse(prev.begin(), prev.end());
        prev.pop_back();
        return prev;

    }
};
