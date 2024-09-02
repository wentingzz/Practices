class Solution {
public:
    int modPow(int base, int power, int mod){
        int res = 1;
        for(int i = 0; i < power; i++) res = (res * base) % mod;
        return res;
    }
    bool check(vector<int>& vec, int target){
        return modPow(modPow(vec[0], vec[1], 10), vec[2], vec[3]) == target;
    }
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        int n = variables.size();
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(check(variables[i], target)) res.push_back(i);
        }
        return res;
    }
};
