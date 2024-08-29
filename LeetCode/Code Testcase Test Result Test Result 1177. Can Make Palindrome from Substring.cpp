class Solution {
public:

    int paliDiff(vector<vector<int>>& freqs, int l, int h){
        int res = 0;
        for(int i = 0; i < 26; i++){
            res += ((freqs[h][i] - (l > 0 ? freqs[l-1][i] : 0)) % 2);
        }

        return res / 2;
    }
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<vector<int>> freqs(1, vector<int>(26, 0));
        freqs[0][s[0] - 'a']++;
        for(int i = 1; i < n; i++){
            freqs.push_back(freqs[i-1]);
            freqs[i][s[i] - 'a']++;
        }

        vector<bool> res;
        for(auto& q: queries) res.push_back(paliDiff(freqs, q[0], q[1]) <= q[2]);
        return res;
    }
};
