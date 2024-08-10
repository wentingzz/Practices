class BetterSolution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size(), res = 0;
        for(int i = n-1; i >= 0; i--){
            int cnt = n - i;
            res = max(res, min(cnt, citations[i]));
        }
        return res;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size(), res = 0;
        int cnt = n;
        for(int& c: citations){
            res = max(res, min(cnt--, c));
        }
        return res;
    }
};
