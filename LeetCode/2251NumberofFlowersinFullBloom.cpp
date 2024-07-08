class Solution {
public:
    void prepareMap(map<int, int>& bloom, vector<vector<int>>& flowers){
        bloom[0] = 0;
        for(vector<int>& f: flowers){
            bloom[f[0]]++;
            bloom[f[1]+1]--;
        }

        int preSum = 0;
        for(const auto& entry: bloom){
            preSum += bloom[entry.first];
            bloom[entry.first] = preSum;
        }
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size(), m = people.size();
        map<int, int> bloom;
        vector<int> res(m, 0);
        prepareMap(bloom, flowers);

        for(int i = 0; i < m; i++){
            auto it = bloom.lower_bound(people[i]);
            if(it != bloom.end()){
                if(it->first != people[i]) it--;
                res[i] = it->second;
            }else res[i] = 0;
        }
        return res;
        
    }
};
