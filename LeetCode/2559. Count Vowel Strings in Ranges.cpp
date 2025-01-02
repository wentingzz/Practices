class Solution {
public:
    bool isVowel(char c){
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), m = queries.size();
        vector<int> cnt(n+1, 0);
        for(int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i] + (isVowel(words[i][0]) and isVowel(words[i].back()));
        }

        vector<int> res(m, 0);
        for(int i = 0; i < m; i++) res[i] = cnt[queries[i][1] + 1] - cnt[queries[i][0]];

        return res;
    }
};
