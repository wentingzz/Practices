class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int first[26];
        for(int& f: first) f = -1;

        int res = -1, idx = 0;
        for(int i = 0; i < s.size(); i++){
            idx = s[i] - 'a';
            if(first[idx] == -1) first[idx] = i;
            else res = max(res, i - first[idx] - 1);
        }
        return res;
    }
};
