class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int n = routes.size(), maxStop = 0;
        unordered_map<int, vector<int>> stop2bus;
        for(int i = 0; i < n; i++){
            for(int& stop: routes[i]) stop2bus[stop].push_back(i), maxStop = max(maxStop, stop);
        }

        if(source > maxStop or target > maxStop) return -1;

        vector<int> been(maxStop + 1, false);
        vector<int> taken(n, false);
        
        queue<int> q;
        q.push(source);
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            res++;
            for(int i = 0; i < size; i++){
                int cur = q.front(); q.pop(); //current stop
                been[cur] = true;
                for(int& bus: stop2bus[cur]){
                    if(taken[bus]) continue;
                    for(int& stop: routes[bus]){
                        if(stop == target) return res;
                        if(!been[stop]){
                            q.push(stop);
                        }
                    }

                    taken[bus] = true;
                }
            }
        }
        return -1;


    }
};
