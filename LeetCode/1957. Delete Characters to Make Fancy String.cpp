class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        char cur;
        int cnt;
        for(char&c : s){
            if(cur == c){
                if(cnt == 2) continue;
                cnt++;
            }else{
                cur = c;
                cnt = 1;
            }
            res += c;
        }
        return res;
    }
};
