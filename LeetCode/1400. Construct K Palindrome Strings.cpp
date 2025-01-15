class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        bool evenFreq[26];
        for(char& c: s) evenFreq[c-'a'] = 1 - evenFreq[c-'a'];
        int odd = 0;
        for(int i = 0; i < 26; i++) if(evenFreq[i]) odd++;
        return odd <= k;
    }
};
