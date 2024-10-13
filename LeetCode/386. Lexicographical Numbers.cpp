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
