class Solution {
public:
    bool check(vector<vector<int>>& adj, vector<int>& group, int i){
        queue<int> q;
        group[i] = 1;
        q.push(i);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            int g = group[cur];
            for(int next: adj[cur]){
                if(group[next] == g) return false;
                if(group[next] == 0){
                    group[next] = 3 - g;
                    q.push(next);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto& d: dislikes){
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        vector<int> group(n+1, 0);
        for(int i = 1; i <= n; i++){
            if(group[i] == 0){
                if(!check(adj, group, i)) return false;
            }
        }
        return true;
    }
};
