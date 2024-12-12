class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
        for(vector<int>& p: points){
            pq.push({(long long)p[0]*p[0] + (long long)p[1]*p[1], p[0], p[1]});
        }
        vector<vector<int>> res;
        for(int i = 0; i < k && !pq.empty(); i++){
            auto [_, x, y] = pq.top();pq.pop();
            res.push_back({x, y});
        }
        return res;
    }
};
