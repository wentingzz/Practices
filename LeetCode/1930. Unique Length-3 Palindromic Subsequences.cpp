class SpacefulSolution {
public:
    int countUniques(vector<int> before, vector<int> total){
        int res = 0;
        for(int i = 0; i < 26; i++){
            if(total[i] - before[i] > 0) res++;
        }
        return res;
    }
    int countPalindromicSubsequence(string s) {
        int res = 0, n = s.size();
        vector<int> first(26, -1), last(26, -1);
        vector<vector<int>> freqs(n);
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            if(first[idx] == -1) first[idx] = i;
            last[idx] = i;
            freq[idx]++;
            freqs[i] = freq;
        }

        for(int i = 0; i < 26; i++){
            if(first[i] != last[i]){
                res += countUniques(freqs[first[i]], freqs[last[i] - 1]);
                // cout << i << " (" << first[i] << " - " << last[i] << ") = " << res << endl;
            }
        }
        return res;
    }
};
