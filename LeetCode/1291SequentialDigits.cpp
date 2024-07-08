class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        vector<int> candidates = {12,23,34,45,56,67,78,89,
            123,234,345,456,567,678,789,
            1234,2345,3456,4567,5678,6789,
            12345,23456,34567,45678,56789,
            123456,234567,345678,456789,
            1234567,2345678,3456789,
            12345678,23456789,
            123456789
        };
        for(int& c: candidates){
            if(low <= c and c <= high){
                res.push_back(c);
            }
        }
        return res;
    }

    vector<int> sequentialDigits2(int low, int high) {
        vector<int> res;
        int cur = 0;
        for(int i = 1; i < 10; i++){
            dfs(low, high, i, cur, res);
        }
        sort(res.begin(), res.end());
        return res;
    }

    void dfs(int& l, int& h, int start, int& cur, vector<int>& res){
        if(cur > h) return;
        if(cur >= l) res.push_back(cur);
        if(start > 9) return;

        cur = cur * 10 + start;
        dfs(l, h, start+1, cur, res);
        cur /= 10;
        
    }
};
