class Solution {
public:
    int n, m;
    long long rec(vector<int>& robot, vector<int>& factory, int i, int j, vector<vector<long long>>& dp){
        if(i == n) return 0;
        if(j == m) return 1000000000000;
        if(dp[i][j] != -1) return dp[i][j];
        long long skip = rec(robot, factory, i, j+1, dp);
        long long here = abs(robot[i] - factory[j]) + rec(robot, factory, i+1, j+1, dp);
        dp[i][j] = min(skip, here);
        return dp[i][j];
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> oneFac;
        for(auto& f: factory){
            for(int i = 0; i < f[1]; i++) oneFac.push_back(f[0]);
        }
        n = robot.size(), m = oneFac.size();
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, -1));
        rec(robot, oneFac, 0, 0, dp);
        return dp[0][0];
    }
};
