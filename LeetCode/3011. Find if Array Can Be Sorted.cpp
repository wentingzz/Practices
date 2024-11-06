class Solution {
public:
    int bit(int n){
        int res = 0;
        while(n){
            res += (n & 1);
            n >>= 1;
        }
        return res;
    }
    bool canSortArray(vector<int>& nums) {
        int cur_bit = 0, cur_max = 0, cur_min = INT_MAX;
        int pre_max = 0;

        for(int& n: nums){
            int b = bit(n);
            if(b == cur_bit){
                cur_max = max(cur_max, n);
                cur_min = min(cur_min, n);
            }else{
                if(cur_min < pre_max) return false;
                pre_max = cur_max;
                cur_bit = b;
                cur_max = n, cur_min = n;
            }
        }
        return cur_min >= pre_max;
    }
};
