class Solution {
public:
    int res = 0, k;
    long long dfs(vector<vector<int>>& adj, vector<int>& values, int node, vector<bool>& seen){
        seen[node] = true;
        long long sum = values[node] % k;
        for(int& next: adj[node]){
            if(!seen[next]){
                sum = (sum + dfs(adj, values, next, seen)) % k;
            }
        }
        if(sum == 0){
            res++;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int div) {
        if(div == 1 or n < 2) return n;

        k = div;
        vector<vector<int>> adj(n);
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> seen(n, false);
        dfs(adj, values, 0, seen);
        return res;
    }
};
