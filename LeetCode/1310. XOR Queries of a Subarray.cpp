class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n = arr.size();
        vector<int> pre(n + 1, 0);
        for(int i = 0; i < n; i++) pre[i+1] = pre[i] ^ arr[i];
        vector<int> res;
        for(auto& q: queries){
            res.push_back(pre[q[1] + 1] ^ pre[q[0]]);
        }
        return res;
    }
};
