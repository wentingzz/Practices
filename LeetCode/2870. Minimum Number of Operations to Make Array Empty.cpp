class QuickerSolution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0, res = 0, cur = nums[0];
        for(int& n: nums){
            if(n == cur) count++;
            else{
                if(count == 1) return -1;
                res += count / 3;
                if(count % 3 != 0) res += 1;
                cur = n;
                count = 1;
            }
        }
        if(count == 1) return -1;
        res += count / 3;
        if(count % 3 != 0) res += 1;
        return res;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int& n: nums) freq[n]++;

        int res = 0;
        for(auto& f: freq) {
            int count = f.second;
            if(count == 1) return -1;
            // Calculate the number of operations needed
            res += count / 3;
            if(count % 3 != 0) res += 1;
        }
        return res;
    }
};
