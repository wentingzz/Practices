class Solution {
public:
    void dfs(int node, unordered_map<int, vector<pair<int, int>>>& adj, vector<vector<long long>>& dist, int limit, long long total, int org){
        if(total > limit) return;
        dist[org][node] = min(dist[org][node], total);
        for(auto& [weight, next]: adj[node]){
            if(dist[org][next] <= total + weight) continue;
            dfs(next, adj, dist, limit, total + weight, org);
        }
        return;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> dist(n, vector<long long>(n, INT_MAX));
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto& e: edges){
            adj[e[0]].push_back({e[2], e[1]});
            adj[e[1]].push_back({e[2], e[0]});
        }
        for(int i = 0; i < n; i++){
            dist[i][i] = 0;
            dfs(i, adj, dist, distanceThreshold, 0, i);
        }
        int cnt = 0, res = 0, minCnt = n;
        for(int i = 0; i < n; i++){
            cnt = 0;
            for(int j = 0; j < n; j++){
                if(dist[i][j] <= distanceThreshold or dist[j][i] <= distanceThreshold) cnt++;
            }
            if(cnt <= minCnt){
                minCnt = cnt;
                res = i;
            }
        }

        return res;
    }
};
