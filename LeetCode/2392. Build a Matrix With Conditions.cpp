class Solution {
public:
    int n;
    bool dfs(vector<vector<int>>& order, vector<int>& seen, int idx, vector<int>& res){
        if(seen[idx] == 0 or idx >= n) return false;
        if(seen[idx] == 1) return true;
        seen[idx] = 0;
        for(int& next: order[idx]){
            if(!dfs(order, seen, next, res)) return false;
        }
        seen[idx] = 1;
        res.push_back(idx);
        return true;
    }

    vector<int> topological(vector<vector<int>>& order){
        vector<int> seen(n, -1);
        vector<int> res;
        for(int i = 1; i < n; i++){
            if(seen[i] == 1) continue;
            if(!dfs(order, seen, i, res)) return {};
        }

        return res;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        n = k + 1;
        vector<vector<int>> rowOrder(n);
        vector<vector<int>> colOrder(n);
        for(auto rc: rowConditions) rowOrder[rc[1]].push_back(rc[0]);
        for(auto cc: colConditions) colOrder[cc[1]].push_back(cc[0]);

        
        vector<int> r = topological(rowOrder);
        vector<int> c = topological(colOrder);
        if(r.empty() or c.empty()) return {};
        unordered_map<int, int> m;
        for(int i = 0; i < c.size(); i++) m[c[i]] = i;
        
        vector<vector<int>> res(k, vector<int>(k, 0));
        for(int i = 0; i < r.size(); i++){
            res[i][m[r[i]]] = r[i];
        }
        return res;
    }
};
