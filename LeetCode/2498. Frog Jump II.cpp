class Solution {
public:
    int maxJump(vector<int>& stones) {
        //divide into two groups where the adjacent diff is minimized
        int n = stones.size();
        if(n <= 3) return stones.back();
        int res = stones[1];
        for(int i = 3; i < n; i++){
            res = max(res, max(stones[i] - stones[i-2], stones[i-1] - stones[i-3]));
        }
        return res;

        
    }
};
