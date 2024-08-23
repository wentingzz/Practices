class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        if(n == 1) return "";
        for(int i = 0; i < n; i++){
            if(s[i] != 'a' and i * 1.0 != (n-1)/2.0){
                s[i] = 'a';
                return s;
            }
        }
        s.back() = 'b';
        return s;
    }
};
