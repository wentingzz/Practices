class BetterSolution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return arr;
        vector<pair<int, int>> tmp;
        for(int i = 0; i < arr.size(); i++) tmp.push_back({arr[i], i});
        sort(tmp.begin(), tmp.end());
        int last = tmp[0].first, rank = 1;
        for(auto it: tmp){
            if(it.first > last){
                last = it.first, arr[it.second] = ++rank;
            }else arr[it.second] = rank;
        }

        return arr;
    }
};

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
