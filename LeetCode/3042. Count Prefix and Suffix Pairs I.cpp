class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2){
        int n = str1.size(), m = str2.size();
        if(n > m) return false;
        for(int i = 0; i < n; i++){
            if(str1[i] != str2[i]) return false;
            if(str1[n-1-i] != str2[m-1-i]) return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0, n = words.size();
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                res += isPrefixAndSuffix(words[i], words[j]);
            }
        }
        return res;
    }
};
