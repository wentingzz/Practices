class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int res = 0, n = nums.size();
        // for i: either value is small or i is small => decreasing stack
        stack<int> desc; //0, 1
        for(int i = 0 ; i < n; i++){
            if(desc.empty() or nums[desc.top()] > nums[i]) desc.push(i);
        }
        for(int j = n-1; j > -1; j--){
            while(!desc.empty() and nums[desc.top()] <= nums[j]){
                res = max(res, j - desc.top());
                desc.pop();
            }
        }
        return res;
    }
};
