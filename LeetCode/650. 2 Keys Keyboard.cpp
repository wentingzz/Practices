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
