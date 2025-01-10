class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int res = 0;
        for(int i = 1; i < n; i++){
            int pre = 0, post = 0; 
            for(int j = 0; j < i; j++) pre += (rating[j] < rating[i]);
            for(int j = i + 1; j < n; j++) post += (rating[i] < rating[j]);
            res += (pre * post) + ((i-pre) * (n-i-1-post));
        }
        return res;
    }
};
