class Solution {
public:
    void doOR(vector<int>& cnt, int val, int& cur){
        cur |= val;
        for(int i = 0; i < 32; i++){
            if((1ll << i) & val) cnt[i]++;
        }
    }

    void undo(vector<int>& cnt, int val, int& cur){
        int res = 0;
        for(int i = 0; i < 32; i++){
            if((1ll << i) & val) cnt[i]--;
            if(cnt[i] > 0) res += (1ll << i);
        }
        cur = res;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k == 0) return 1;
        vector<int> cnts(32, 0);
        int l = 0, cur = 0, res = INT_MAX;
        
        for(int r = 0; r < nums.size(); r++){
            doOR(cnts, nums[r], cur);
            while(cur >= k){
                res = min(res, r-l+1);
                undo(cnts, nums[l], cur);
                l++;
            }
        }
        if(res == INT_MAX) return -1;
        return res;
    }
};
