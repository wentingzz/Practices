class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> cnt(n, 0);
        for(auto& e: edges){
            cnt[e[1]]++;
        }
        int res = -1;
        for(int i = 0; i < n; i++){
            if(cnt[i] == 0){
                if(res == -1) res = i;
                else return -1;
            }
        }
        return res;
    }
};
