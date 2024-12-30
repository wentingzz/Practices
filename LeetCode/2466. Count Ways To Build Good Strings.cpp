class BestSolution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int dp[100001] {};
        dp[0] = 1;
        int MOD = 1e9 + 7;
        for(int i = 1; i < low; i++){
            if(i - zero >= 0) dp[i] = (dp[i] + dp[i-zero]) % MOD;
            if(i - one >= 0) dp[i] = (dp[i] + dp[i-one]) % MOD;
        }
        long long res = 0;
        for(int i = low; i <= high; i++){
            if(i - zero >= 0) dp[i] = (dp[i] + dp[i-zero]) % MOD;
            if(i - one >= 0) dp[i] = (dp[i] + dp[i-one]) % MOD;
            res = (res + dp[i]) % MOD;
        }
        return res;
    }
};

class SlowerSolution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high+1, 0);
        dp[0] = 1;
        int MOD = 1000000007;
        for(int i = 1; i < low; i++){
            if(i - zero >= 0) dp[i] = (dp[i] + dp[i-zero]) % MOD;
            if(i - one >= 0) dp[i] = (dp[i] + dp[i-one]) % MOD;
        }
        long long res = 0;
        for(int i = low; i <= high; i++){
            if(i - zero >= 0) dp[i] = (dp[i] + dp[i-zero]) % MOD;
            if(i - one >= 0) dp[i] = (dp[i] + dp[i-one]) % MOD;
            res = (res + dp[i]) % MOD;
        }
        return res;
    }
};
