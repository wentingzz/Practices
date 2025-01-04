class Solution {
public:
    int countUnique(string& s, int start, int end){
        bitset<26> cnt;
        for(int j = start; j <= end; j++){
            cnt.set(s[j] - 'a');
            if(cnt.all()) break;
        }
        return cnt.count();
    }
    int countPalindromicSubsequence(string s) {
        int res = 0, n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            if(first[idx] == -1) first[idx] = i;
            last[idx] = i;
        }

        for(int i = 0; i < 26; i++){
            if(last[i] - first[i] < 2) continue;
            res += countUnique(s, first[i] + 1, last[i] - 1);
        }
        return res;
    }
};

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
            }
        }
        return res;
    }
};
