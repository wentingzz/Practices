class Solution {
public:
    int minimumLength(string s) {
        int freq[26] {};
        for(char& c: s){
            int idx = c - 'a';
            freq[idx]++;
            if(freq[idx] == 3) freq[idx] = 1;
        }
        int res = 0;
        for(int& f: freq) res += f;
        return res;
    }
};
