class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        vector<bool> seen(26, false);
        for(char& c: allowed) seen[c-'a'] = true;
        bool consistent;
        int res = 0;
        for(string& w: words){
            consistent = true;
            for(char& c: w){
                if(!seen[c - 'a']){
                    consistent = false;
                    break;
                }
            }
            res += consistent;
        }
        return res;
    }
};
