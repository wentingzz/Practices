class Solution {
public:
    bool moreThan60(string& p){
        if(p[11] > '6') return true;
        if(p[11] == '6') return p[12] > '0';
        return false;
    }
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(string& p: details){
            res += moreThan60(p);
        }
        return res;
    }
};
