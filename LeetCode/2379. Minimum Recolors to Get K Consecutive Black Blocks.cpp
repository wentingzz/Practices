class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cur = 0;
        for(int i = 0; i < k; i++) cur += (blocks[i] == 'W');
        
        int n = blocks.size(), res = cur;
        for(int i = k; i < n; i++){
            cur += (blocks[i] == 'W') - (blocks[i-k] == 'W');
            res = min(cur, res);
        }
        return res;
    }
};
