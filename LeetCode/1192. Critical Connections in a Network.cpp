class Solution {
public:
    int time = 0;
    int dfs(vector<vector<int>>& adj, int node, vector<int>& first, vector<int>& low, int p, vector<vector<int>>& res){
        if(first[node] != -1) return low[node];
        first[node] = time++;
        low[node] = min(low[node], first[node]);
        
        for(int& next: adj[node]){
            if(next != p) low[node] = min(low[node], dfs(adj, next, first, low, node, res));
        }
        if(p > -1 and low[node] > first[p]) res.push_back({p, node});
        return low[node];
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> first(n, -1); //first visit time
        vector<int> low(n, INT_MAX); //among all the reachable nodes (except the parent), return the earliest time of those nodes
        vector<vector<int>> adj(n);
        for(auto& c: connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            dfs(adj, i, first, low, -1, res);
        }
        return res;
    }
};
