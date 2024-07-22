class SlightlyQuickerSolution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> preSum;
        preSum[0] = -1;
        int count[2] = {0, 0};
        int sum = 0, res = 0;
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
            sum = count[1] - count[0];
            if(preSum.find(sum) != preSum.end()) res = max(res, i - preSum[sum]);
            else  preSum[sum] = i;
        }
        return res;
    }
};

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> preSum;
        preSum[0] = -1;
        int sum = 0, res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) sum += -1;
            else sum += 1;
            
            if(preSum.find(sum) != preSum.end()) res = max(res, i - preSum[sum]);
            else  preSum[sum] = i;
        }
        return res;
    }
};
