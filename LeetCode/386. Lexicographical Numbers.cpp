class SlowerSolution {
public:
    void addNumberLessThan(vector<int>& res, int upper, int start){
        if(start > upper) return;
        res.push_back(start);
        start *= 10;
        for(int i = 0; i < 10; i++) addNumberLessThan(res, upper, start + i);
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i = 1; i < 10; i++) addNumberLessThan(res, n, i);
        return res;
    }
};

class SpaceBestSolution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n, 0);
        int idx = 0;
        for(int i = 0; i < 10; i++){
            dfs(i+1, idx, n, res);
        }
        return res;
    }

    void dfs(int cur, int& idx, int n, vector<int>& res){
        if(idx >= n or cur > n) return;
        res[idx++] = cur;
        cur *= 10;


        for(int i = 0; i < 10; i++){
            dfs(cur + i, idx, n, res);
        }
    }
};
