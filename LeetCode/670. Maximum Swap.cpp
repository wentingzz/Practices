class Solution {
public:
    int maximumSwap(int num) {
        vector<int> nums;
        while(num){
            nums.emplace_back(num % 10);
            num /= 10;
        } 
        int n = nums.size(), cur = 0;
        vector<int> swapCandidate(n, -1); //index of the largest swap
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[cur]){ //update current best candidate
                cur = i;
            }else if (nums[i] < nums[cur]){ //
                swapCandidate[i] = cur;
            }
        }
        for(int i = n-1; i >=0; i--){
            if(swapCandidate[i] >= 0){
                swap(nums[i], nums[swapCandidate[i]]);
                break;
            }
        }
        int res = 0;
        for(int i = n-1; i >=0; i--){
            res = res * 10 + nums[i];
        }
        return res;
    }
};
