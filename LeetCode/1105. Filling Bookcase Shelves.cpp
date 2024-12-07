class Solution {
public:
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int dp[1001] {};
        int n = books.size();
        for(int i = 0; i < n; i++){
            int t = books[i][0], h = books[i][1];
            dp[i+1] = dp[i] + h;
            for(int j = i-1; j >= 0; j--){
                t += books[j][0];
                if(t > shelfWidth) break;
                h = max(h, books[j][1]);
                dp[i+1] = min(dp[i+1], dp[j] + h);
            }
        }
        return dp[n];
    }
};
