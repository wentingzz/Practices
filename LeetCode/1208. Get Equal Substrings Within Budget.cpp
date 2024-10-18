class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int diff[n+1];
        diff[0] = 0;
        for(int i = 1; i <= n; i++) diff[i] = abs(s[i-1] - t[i-1]) + diff[i-1];
        int res = 0, l = 0;
        for(int r = 1; r <= n; r++){
            while(diff[r] - diff[l] > maxCost) l++;
            res = max(r-l, res);
        }
        return res;
    }
};
