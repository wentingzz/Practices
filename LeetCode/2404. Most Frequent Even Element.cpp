class SlightlyBetterSolution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> m;
        int count = 0, res = INT_MAX;
        for(int& n: nums){
            if(n % 2) continue;
            m[n]++;
            count = max(count, m[n]);
        }
        for(auto& it: m){
            if(it.second == count) res = min(res, it.first);
        }
        return res == INT_MAX ? -1 : res;
    }
};

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> m;
        int count = 0, res = -1;
        for(int& n: nums){
            if(n % 2) continue;
            m[n]++;
            if(m[n] > count){
                res = n;
                count = m[n];
            }else if (m[n] == count) res = min(res, n);
        }
        return res;
    }
};
