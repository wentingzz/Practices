class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b){
            int d1 = a[1] - a[0], d2 = b[1] - b[0];
            if(d1 == d2) return a[1] < b[1];
            return d1 < d2;
        });

        int res = 0;
        for(auto& t: tasks){
            res = max(res + t[0], t[1]);
        }
        return res;
    }
};
