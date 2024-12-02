class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int& n: nums) freq[n]++;
        vector<pair<int, int>> sorted;
        for(auto& f: freq) sorted.push_back({f.second, f.first});
        sort(sorted.begin(), sorted.end(), [](const pair<int, int>& s1, const pair<int, int>& s2){
            if(s1.first == s2.first) return s1.second > s2.second;
            return s1.first < s2.first;
        });
        vector<int> res;
        for(auto& [f, v]: sorted){
            for(int i = 0; i < f; i++){
                res.push_back(v);
            }
        }
        return res;
    }
};
