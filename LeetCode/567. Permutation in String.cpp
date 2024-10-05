class Solution {
public:
    bool isPermutation(int (&freq)[26]){
        for(int& f: freq){
            if(f != 0) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int freq[26];
        memset(freq, 0, sizeof(freq));
        for(char&c: s1) freq[c-'a']++;

        int m = s1.size();
        for(int i = 0; i < m; i++){
            int idx = s2[i]-'a';
            freq[idx]--;
        }
        for(int i = m; i < s2.size(); i++){
            if(isPermutation(freq)) return true;
            freq[s2[i-m] - 'a']++;
            freq[s2[i] - 'a']--;
        }

        return isPermutation(freq);
    }
};
