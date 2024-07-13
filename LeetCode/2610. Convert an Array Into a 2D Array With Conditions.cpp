class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int maxF = 0;
        unordered_map<int, int> freq;
        for(int& n: nums) {
            maxF = max(maxF, ++freq[n]);
        }
        vector<vector<int>> res(maxF);

        for(auto& f: freq){
            for(int i = 0; i < f.second; i++){
                res[i].push_back(f.first);
            }
        }

        return res;
    }
};
