class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        vector<vector<int>> des(n);

        for(vector<int>& e: edges) des[e[0]].push_back(e[1]);
        for(int i = 0; i < n; i++){
            vector<bool> done(n, false);
            dfs(des, res, done, i, i);
        }
        
        return res;
    }

    void dfs(vector<vector<int>>& des, vector<vector<int>>& res, vector<bool>& done, int cur, int node2add){
        done[cur] = true;
        for(int d: des[cur]){
            if(res[d].empty() or res[d].back() != node2add) res[d].push_back(node2add);
            if(!done[d]) dfs(des, res, done, d, node2add);
        }
    }


};
