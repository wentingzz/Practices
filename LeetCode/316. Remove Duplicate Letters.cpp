class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<bool> seen(26, false);
        vector<int> lastIdx(26, n);
        for(int i = 0; i < n; i++) lastIdx[s[i] - 'a'] = i;

        string res = "";
        for(int i = 0; i < n; i++){
            if(seen[s[i] - 'a']) continue;
            while(!res.empty() and res.back() > s[i] and lastIdx[res.back() - 'a'] >= i){
                seen[res.back() - 'a'] = false;
                res.pop_back();
            }
            if(!seen[s[i] - 'a']){
                res.push_back(s[i]);
                seen[s[i] - 'a'] = true;
            }
        }
        return res;
    }
};
