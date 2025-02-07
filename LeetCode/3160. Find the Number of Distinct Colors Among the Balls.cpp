class BestSolution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colors, cnt;
        int n = queries.size(), sum = 0;
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            int idx = queries[i][0], color = queries[i][1];
            if(colors[idx] != 0){
                cnt[colors[idx]]--;
                sum -= (cnt[colors[idx]] == 0);
            }
            sum += (cnt[color] == 0);
            colors[idx] = color;
            cnt[color]++;
            res[i] = sum;
        }
        return res;
    }
};

class MoreSpaceSolution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> colors(limit + 1, 0);
        unordered_map<int, int> cnt;
        int n = queries.size(), sum = 0;
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            int idx = queries[i][0], color = queries[i][1];
            if(colors[idx] != 0){
                cnt[colors[idx]]--;
                sum -= (cnt[colors[idx]] == 0);
            }
            sum += (cnt[color] == 0);
            colors[idx] = color;
            cnt[color]++;
            res[i] = sum;
        }
        return res;
    }
};
