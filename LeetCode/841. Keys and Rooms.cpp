class DFSBetterSolution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> seen(n, false);

        dfs(rooms, seen, 0);

        for(bool l: seen) if(!l) return false;
        return true;
    }

    void dfs(vector<vector<int>>& rooms, vector<bool>& seen, int idx){
        if(seen[idx]) return;
        seen[idx] = true;

        for(int& next: rooms[idx]){
            dfs(rooms, seen, next);
        }
    }
};

class BFSSolution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<short> seen(n, -1); //-1 = locked, 0 = unlocked, 1 = visited

        int cnt = 0;
        seen[0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            seen[q.front()] = 1;
            for(int& k: rooms[q.front()]){
                if(seen[k] == -1){
                    q.push(k);
                    seen[k] = 0;
                }
            }
            q.pop();
            cnt++;
        }
        return cnt == n;

    }
};
