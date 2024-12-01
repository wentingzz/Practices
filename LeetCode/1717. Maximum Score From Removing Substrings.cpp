class Solution {
public:
    void remove(string& s, string sub, int& score, int& x){
        string res = "";
        for(int i = 0; i < s.size(); i++){
            if(!res.empty() and res.back() == sub[0] and s[i] == sub[1]){
                res.pop_back();
                score += x;
            }else{
                res.push_back(s[i]);
            }
        }
        s = res;
    }
    int maximumGain(string s, int x, int y) {
        int res = 0;
        if(x > y){
            remove(s, "ab", res, x);
            remove(s, "ba", res, y);
        }else{
            remove(s, "ba", res, y);
            remove(s, "ab", res, x);
        }
        return res;
    }
};
