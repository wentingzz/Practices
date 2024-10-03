class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return arr;
        vector<int> tmp(arr);
        sort(tmp.begin(), tmp.end());
        unordered_map<int, int> m;
        int last = tmp[0], rank = 1;
        for(int& n: tmp){
            if(n > last){
                last = n, m[n] = ++rank;
            }else m[n] = rank;
        }

        for(int& n: arr) n = m[n];
        return arr;
    }
};
