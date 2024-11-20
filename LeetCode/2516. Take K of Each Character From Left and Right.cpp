class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        int freq[3] = {-k, -k, -k}; //characters we don't need to pop
        for(char& c: s) freq[c-'a']++;
        if(freq[0] < 0 or freq[1] < 0 or freq[2] < 0) return -1;

        int n = s.size(), res = n, l = 0;
        for(int r = 0; r < n; r++){
            freq[s[r] - 'a']--;
            while(freq[0] < 0 or freq[1] < 0 or freq[2] < 0) freq[s[l++] - 'a']++;
            res = min(n - (r - l + 1), res);
        }
        return res;
    }
};
