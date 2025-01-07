class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        sort(words.begin(), words.end(), [](const string& w1, const string& w2){
            return w1.size() < w2.size();
        });
        int n = words.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(words[j].find(words[i]) != std::string::npos){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
