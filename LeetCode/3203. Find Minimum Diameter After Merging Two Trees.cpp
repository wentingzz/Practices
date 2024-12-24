class Solution {
public:
    void dfs(vector<vector<int>>& adj, int cur, int from, vector<int>& dist, int& res){
        dist[cur] = dist[from] + 1;
        if(res == -1 or dist[res] < dist[cur]) res = cur;
        for(int next: adj[cur]){
            if(next != from) dfs(adj, next, cur, dist, res);
        }
    }
    int getD(vector<vector<int>>& edges){
        int n = edges.size()+1;
        vector<vector<int>> adj(n);
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int node1 = -1;
        vector<int> dist(n, -1);
        dfs(adj, 0, 0, dist, node1);
        fill(dist.begin(), dist.end(), -1);
        int node2 = -1;
        dfs(adj, node1, node1, dist, node2);
        return dist[node2];
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = getD(edges1), d2 = getD(edges2);
        int r1 = max(d1/2, d1 - d1/2), r2 = max(d2/2, d2-d2/2);
        return max(r1 + r2 + 1, max(d1, d2));
        
    }
};
