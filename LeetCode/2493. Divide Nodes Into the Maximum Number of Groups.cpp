class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> color(n+1);
        auto bipartiteBFS = [&](int start){
            vector<int> res; //all nodes in a connected graph (bipartite)
            queue<int> q;
            q.push(start);
            color[start] = 1;

            while(!q.empty()){
                int cur = q.front(); q.pop();
                res.push_back(cur);
                for(int next: adj[cur]){
                    if(color[next] == color[cur]) return vector<int>{}; //not bipartite
                    
                    if(color[next] != 0) continue;
                    color[next] = -color[cur];
                    q.push(next);

                }
            }
            return res;
        };

        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(color[i] != 0) continue;
            auto nodes = bipartiteBFS(i);
            if(nodes.empty()) return -1;
            cnt += findMaxLen(adj, nodes, n);
        }
        return cnt;

    }

    int findMaxLen(vector<vector<int>> adj, vector<int> nodes, int& maxN){
        int res = 0;
        for(int& n: nodes){
            vector<int> dist(maxN+1, -1);
            dist[n] = 0;
            queue<int> q;
            q.push(n);
            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(int next: adj[cur]){
                    if(dist[next] == -1){
                        dist[next] = dist[cur] + 1;
                        res = max(dist[next], res);
                        q.push(next);
                    }
                }
            }
        }
        return res + 1;
    }
};
