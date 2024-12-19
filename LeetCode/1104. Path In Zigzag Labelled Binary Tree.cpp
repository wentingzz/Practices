class Solution {
public:
    int getNum(int base, bool reverse, int idx){
        if(!reverse) return base + idx;
        return base * 2 - 1 - idx;
    }
    vector<int> pathInZigZagTree(int label) {
        int lvl = floor(log(label)/log(2)) + 1;
        vector<int> res(lvl, 0);
        res[lvl-1] = label;
        
        bool reverse = (lvl % 2 == 0);
        int base = pow(2, lvl-1), idx = label - base;
        if(reverse) idx = base - 1 - idx;
        for(int i = lvl - 2; i >= 0; i--){
            base /= 2;
            idx /= 2;
            reverse = !reverse;
            res[i] = getNum(base, reverse, idx);
        }
        return res;
    }
};
