class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<pair<int, int>> qs;
        int n = queries.size(), m = items.size();
        for(int i = 0; i < n; i++) qs.push_back({queries[i], i});
        sort(qs.begin(), qs.end());
        sort(items.begin(), items.end(), [](const vector<int>& i1, const vector<int>& i2){
            if(i1[0] == i2[0]) return i1[1] > i2[1];
            return i1[0] < i2[0];
        });
        vector<int> res(n, 0);
        int curMax = 0, j = 0;
        for(int i = 0; i < n; i++){
            while(j < m and items[j][0] <= qs[i].first){
                curMax = max(curMax, items[j][1]);
                j++;
            }
            res[qs[i].second] = curMax;
        }
        return res;
    }
};
