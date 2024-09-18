class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> postMin(n, nums.back());
        for(int i = n - 2; i > -1; i--) postMin[i] = min(postMin[i+1], nums[i]);

        int preMax = nums[0];
        for(int i = 0; i < n-1; i++){
            if(preMax <= postMin[i+1]) return i+1;
            preMax = max(preMax, nums[i]);
        }
        return n;
    }
};
