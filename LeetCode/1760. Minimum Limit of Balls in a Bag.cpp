class Solution {
public:
    bool possible(vector<int>& nums, int balls, int limit){
        int cnt = 0;
        for(int& x: nums){
            cnt += (x / balls) + (x % balls > 0) - 1;
            if(cnt > limit) {
                return false;
            }
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size(), l = 1, h = 0;
        for(int& x: nums) h = max(h, x);

        int m, res = h;
        while(l <= h){
            m = l + (h-l)/2;
            if(possible(nums, m, maxOperations)){
                res = min(res, m);
                h = m-1;
            }else l = m+1;
            
        }
        return res;
    }
};
