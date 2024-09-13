class Solution {
public:
    bool lessThanTarget(unordered_map<char, int> & m){
        for(auto f: m) if(f.second > 0) return false;
        return true;
    }
    int balancedString(string s) {
        int target = s.size()/4, l = 0, res = s.size();
        unordered_map<char, int> m = {{'Q', -target}, {'W', -target}, {'E', -target}, {'R', -target}};
        for(char& c: s) m[c]++; // positive means it's more than n/4
        for(int r = 0; r < s.size(); r++){
            m[s[r]]--;
            while(lessThanTarget(m)){
                res = min(r - l + 1, res);
                m[s[l++]]++;
            }
        }
        return res;
    }
};
