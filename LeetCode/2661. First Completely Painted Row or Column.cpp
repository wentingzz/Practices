class BestSolution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> num2pos(m*n);
        vector<int> cols(m, n), rows(n, m);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) num2pos[mat[i][j]-1] = {i, j};
        }
        for(int i = 0; i < arr.size(); i++){
            auto [r,c] = num2pos[arr[i]-1];
            rows[c]--, cols[r]--;
            if(rows[c] == 0 or cols[r] == 0) return i;
        }
        return -1;
    }
};

class SimilarBestSolution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> num2pos(m*n+1);
        vector<int> cols(m, n), rows(n, m);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) num2pos[mat[i][j]] = {i, j};
        }
        for(int i = 0; i < arr.size(); i++){
            auto [r,c] = num2pos[arr[i]];
            rows[c]--, cols[r]--;
            if(rows[c] == 0 or cols[r] == 0) return i;
        }
        return -1;
    }
};

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> num2pos;
        vector<int> cols(m, n), rows(n, m);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) num2pos[mat[i][j]] = {i, j};
        }
        for(int i = 0; i < arr.size(); i++){
            auto [r,c] = num2pos[arr[i]];
            rows[c]--, cols[r]--;
            if(rows[c] == 0 or cols[r] == 0) return i;
        }
        return -1;
    }
};
