class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, m+n));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] - 2;
                }else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};


class SimilarSolution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, m+n));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] - 2;
                }else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                }
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        return dp[n][m];
    }
};
