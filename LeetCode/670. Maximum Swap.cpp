class BetterSolution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size(), cur = n-1;
        int best[2] = {n, n}; 

        for(int i = n-2; i > -1; i--){
            if(str[cur] > str[i]){
                best[0] = i;
                best[1] = cur;
            }else if(str[cur] < str[i]){
                cur = i;
            }
        }
        if(best[0] == -1) return num;
        swap(str[best[0]], str[best[1]]);
        return stoi(str);
    }
};

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
