class BetterSolution {
public:
    int numberOfSpecialChars(const string &word) {
    bitset<26> lo = {}, up = {};
    for (char ch : word)
        if (islower(ch)) 
            lo[ch - 'a'] = true;
        else
            up[ch - 'A'] = true;
    return (lo & up).count();
}
};

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int up[26];
        int low[26];
        for(int i = 0; i < 26; i++){
            up[i] = 0;
            low[i] = 0;
        }

        for(char& c: word){
            if(c >= 'a') up[c-'a']++;
            else low[c - 'A']++;
        }
        int res = 0;
        for(int i = 0; i < 26; i++) if(up[i] > 0 and low[i] > 0) res++;
        return res;
    }
};
