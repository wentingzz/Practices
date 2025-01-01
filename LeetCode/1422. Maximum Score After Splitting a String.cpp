class Solution {
public:
    int maxScore(string s) {
        int l = 0, r = 0, n = s.size();
        for(int i = 1; i < n; i++) r += (s[i] == '1');
        l = s[0] == '0';

        int res = l + r;
        for(int i = 1; i < n-1; i++){
            l += (s[i] == '0');
            r -= (s[i] == '1');
            res = max(res, l + r);
        }
        return res;
    }
};
