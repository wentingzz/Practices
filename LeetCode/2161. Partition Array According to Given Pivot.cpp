class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less = 0, eql = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot) less++;
            else if(nums[i] == pivot) eql++;
        }
        vector<int> res(n);
        int l = 0, m = less, r = less + eql;
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot) res[l++] = nums[i];
            else if(nums[i] == pivot) res[m++] = nums[i];
            else res[r++] = nums[i];
        }
        return res;
    }
};
