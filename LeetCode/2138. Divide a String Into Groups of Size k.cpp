class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int extra = s.size() % k;
        s += string(extra == 0 ? 0 : k - extra, fill);

        vector<string> res;
        int i = 0;
        while(i < s.size()){
            res.push_back(s.substr(i, k));
            i += k;
        }
        return res;
    }
};
