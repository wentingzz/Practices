class BetterSolution {
public:
    bool endsWithAtIndex(const string& s, const string& x, size_t i) {
        if (i + 1 < x.size()) return false; 
        return s.substr(i + 1 - x.size(), x.size()) == x;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i-1] + 1;
            for(string& d: dictionary){
                if(endsWithAtIndex(s, d, i-1)) dp[i] = min(dp[i], dp[i-d.size()]);
            }
        }

        return dp[n];
    }
};


class SlowerSolution {
public:
    bool startsWithAtIndex(const string& s, const string& x, size_t i) {
        if (i + x.size() > s.size())  return false;
        return s.substr(i, x.size()) == x;
    }

    unordered_map<int, int> dp;
    int minExtraChar(string s, vector<string>& dictionary, int idx = 0) {
        if(dp.find(idx) != dp.end()) return dp[idx];
        if(idx == s.size()) return 0;
        dp[idx] = minExtraChar(s, dictionary, idx + 1) + 1;
        
        for(string& d: dictionary){
            if(startsWithAtIndex(s, d, idx)){
                dp[idx] = min(dp[idx], minExtraChar(s, dictionary, idx + d.size()));
            }
        }

        return dp[idx];
    }
};
