class Solution {
public:
    void dfs(vector<vector<int>>& stones, unordered_map<int, vector<int>>& rows, unordered_map<int, vector<int>>& cols, vector<bool>& seen, int idx){
        if(seen[idx]) return;
        seen[idx] = true;
        for(int next: rows[stones[idx][0]]){
            dfs(stones, rows, cols, seen, next);
        }
        for(int next: cols[stones[idx][1]]){
            dfs(stones, rows, cols, seen, next);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> rows;
        unordered_map<int, vector<int>> cols;
        int n = stones.size();
        for(int i = 0; i < n; i++){
            rows[stones[i][0]].push_back(i);
            cols[stones[i][1]].push_back(i);
        }
        
        vector<bool> seen(n, false);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!seen[i]){
                count++;
                dfs(stones, rows, cols, seen, i);
            }
        }
        return n - count;
    }
};
