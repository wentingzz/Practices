class Solution {
public:
    int diff = 'A' - 'a';
    bool isBad(char & a, char & b){
        return a - b == diff or b - a == diff;
    }
    string makeGood(string s) {
        string res;
        for(char& c: s){
            if(!res.empty() and isBad(c, res.back())){
                res.pop_back();
            }else{
                res.push_back(c);
            }
        }
        return res;
    }
};
