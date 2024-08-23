class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> seen(n, false);
        int res = 0;
        for(int i = 0; i < n; i++){
            if(!seen[i]){
                int nodes = 0, edges = 0;
                findConnected(i, adj, seen, nodes, edges);
                if(nodes * (nodes - 1) == edges) res++;
            }
        }
        return res;
    }

    void findConnected(int node, vector<int> adj[], vector<bool>& seen, int& nodes, int& edges){
        if(seen[node])return;
        seen[node] = true;
        nodes++;
        edges+=adj[node].size();
        for(int& next: adj[node]){
            findConnected(next, adj, seen, nodes, edges);
        }
        
    }
};
