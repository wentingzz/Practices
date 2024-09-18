class Solution {
public:
    void process(string& s, unordered_map<string, int>& m){
        string cur = "";
        for(char& c: s){
            if(c == ' '){
                m[cur]++;
                cur = "";
            }else cur += c;
        }
        if(cur != " ") m[cur]++;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        process(s1, freq);
        process(s2, freq);

        vector<string> res;
        for(auto f: freq) if(f.second == 1) res.push_back(f.first);
        return res;
    }
};
