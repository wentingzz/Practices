class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n*n, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) freq[grid[i][j]-1]++;
        }
        vector<int> res = {0,0};
        for(int i = 0; i < n*n; i++){
            if(freq[i] == 1) res[0] = i+1;
            else if(freq[i] == -1) res[1] = i+1;
        }
        return res;
    }
};
