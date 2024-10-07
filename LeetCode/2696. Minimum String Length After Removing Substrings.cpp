class Solution {
public:
    
    int minLength(string s) {
        string res = "";
        for(char& c: s){
            if(c == 'B' and !res.empty() and res.back() == 'A'){
                res.pop_back();
                continue;
            }
            if(c == 'D' and !res.empty() and res.back() == 'C'){
                res.pop_back();
                continue;
            }
            res.push_back(c);
        }
        return res.size();
    }
};
