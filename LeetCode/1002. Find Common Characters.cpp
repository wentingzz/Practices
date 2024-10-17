class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> freq(26, 10000);
        for(int i = 0; i < n; i++){
            vector<int> cur(26, 0);
            for(char& c: words[i]) cur[c-'a']++;
            for(int i = 0; i < 26; i++) freq[i] = min(freq[i], cur[i]);
        }
        vector<string> res;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < freq[i]; j++){
                res.push_back(string(1, 'a' + i));
            }
        }
        return res;
    }
};
