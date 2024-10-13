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
