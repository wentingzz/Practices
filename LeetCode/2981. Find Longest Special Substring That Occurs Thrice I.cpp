class Solution {
public:
    int maximumLength(string s) {
        int res = -1, maxL = 0;
        vector<vector<int>> freq(26, vector<int>(1, 0));
        for(int i = 0; i < s.size(); i++){
            int len = 1;
            while(i + 1 < s.size() and s[i] == s[i+1]) len++, i++;
            
            for(int j = 0; j < len; j++){
                if(freq[s[i] - 'a'].size() > j) freq[s[i] - 'a'][j] += len - j;
                else freq[s[i] - 'a'].push_back(len - j);
                if(freq[s[i] - 'a'][j] > 2 and j + 1 > res){
                    res = j + 1;
                }
            }
        }
        return res;
    }
};
