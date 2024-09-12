class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string res = "", cur = "";
        for(int i = n-1; i >= 0; i--){
            if(s[i] == ' '){
                if(cur.size() > 0) res += cur + " ";
                cur = "";
            }else cur = s[i] + cur;
        }
        if(cur != "") res += cur + " ";
        return res.substr(0, res.size()-1);

    }
};
