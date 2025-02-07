class BestTimeSolution {
public:
    int minSteps(int n) {
        if(n < 2) return 0;
        vector<int> dp(n+1, 1000);
        dp[1] = 0;
        dp[2] = 2;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j += i){
                dp[j] = min(dp[j], dp[i] + j/i);
            }
        }
        return dp[n];
    }
};
class BestSpaceSolution {
public:
    int minSteps(int n) {
        if(n < 2) return 0;
        int dp[n+1];
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = i;
            for(int j = i/2; j > 1; j--){
                if(i % j == 0) dp[i] = min(dp[i], dp[j] + (i/j));
            }
        }
        return dp[n];
    }
};
