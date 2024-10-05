class Solution {
public:
    int MOD = 1000000007;
    int countTexts(string keys) {
        vector<int> numOfLetters = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
        int n = keys.size();
        vector<int> dp(n+1, 1);
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1];
            if(keys[i-1] == keys[i-2]) dp[i] = (dp[i] + dp[i-2]) % MOD;
            else continue;
            if(i > 2 and keys[i-1] == keys[i-3]) dp[i] = (dp[i] + dp[i-3]) % MOD;
            else continue;
            if(i > 3 and numOfLetters[keys[i-1]-'0'] == 4 and keys[i-1] == keys[i-4]) dp[i] = (dp[i] + dp[i-4]) % MOD;
        }
        // for(int& d: dp) cout << d << " ";
        return dp[n];
    }
};
