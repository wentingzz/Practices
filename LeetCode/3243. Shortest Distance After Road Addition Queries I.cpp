class Solution {
public:
    void updateDist(vector<int> &dist, vector<vector<int>> &neighbor, int from, int to){
        if(dist[to] <= dist[from] + 1) return;
        dist[to] = dist[from] + 1;

        for(int& next: neighbor[to]){
            updateDist(dist, neighbor, to, next);
        }
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dist(n, 0);
        vector<vector<int>> neighbor(n);
        for(int i = 0; i < n-1; i++){
            neighbor[i].push_back(i+1);
            dist[i] = i;
        }
        dist.back() = n-1;
        vector<int> res;
        for(vector<int>& q: queries){
            neighbor[q[0]].push_back(q[1]);
            updateDist(dist, neighbor, q[0], q[1]);
            res.push_back(dist.back());
        }
        return res;
    }
};
