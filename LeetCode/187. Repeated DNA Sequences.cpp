class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map;
        vector<string> res;
        for(int i = 0; i < s.size(); i++){
            string cur = s.substr(i, 10);
            if(map.find(cur) != map.end()){
                if(map[cur] == 1) res.push_back(cur);
                map[cur]++;
            }else{
                map[cur] = 1;
            }
        }
        return res;
    }
};
