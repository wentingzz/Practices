class BetterSolution {
public:
    int findParent(int n, int parents[]){
        if(parents[n] != n){
            parents[n] = findParent(parents[n], parents);
        }
        return parents[n];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        
        if(m < n-1) return -1;
        int parents[n];
        int rank[n];
        fill(rank, rank + n, 0);
        for(int i = 0; i < n; i++) parents[i] = i;
        
        int res = n-1;
        
        for(auto c: connections){
            int p1 = findParent(c[0], parents), p2 = findParent(c[1], parents);
            if(p1 != p2){
                if(rank[p1] > rank[p2]){
                    parents[p1] = p2;
                    rank[p2]++;
                }
                else{
                    parents[p2] = p1;
                    rank[p1]++;
                }
                res--;
            }
        }
        return res;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n-1) return -1;
        
        vector<vector<int>> adj(n);
        for(auto& c: connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<bool> seen(n, false);
        int res = -1;
        for(int i = 0; i < n; i++){
            if(!seen[i]) res += dfs(i, adj, seen);
        }
        return res;
    }

    int dfs(int node, vector<vector<int>>& adj, vector<bool>& seen){
        if(seen[node]) return 0;

        seen[node] = true;
        for(int next: adj[node]){
            dfs(next, adj, seen);
        }
        return 1;
    }
};
