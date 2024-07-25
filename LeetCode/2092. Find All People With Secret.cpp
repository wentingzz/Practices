class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int, int>> adj[n];
        meetings.push_back({0, firstPerson, 0});
        for(auto& m: meetings){
            adj[m[0]].push_back({m[1], m[2]});
            adj[m[1]].push_back({m[0], m[2]});
        }

        vector<int> minTime(n, INT_MAX);
        minTime[0] = 0;
        dfs(0, 0, adj, minTime);
        
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(minTime[i] != INT_MAX) res.push_back(i);
        }
        return res;
    }

    void dfs(int node, int time, vector<pair<int, int>> adj[], vector<int>& minTime){
        for(auto& [next, t]: adj[node]){
            //screte is shared before this meeting and this person doesn't know before this meeting
            if(t >= time and minTime[next] > t){
                minTime[next] = t;
                dfs(next, t, adj, minTime);
            }
        }
    }
};
