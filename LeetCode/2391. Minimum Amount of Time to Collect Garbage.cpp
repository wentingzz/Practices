class BetterSolution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int last[3] = {0, 0, 0}; //keep track of the last index in garbage
        int res = 0, n = garbage.size();
        for(int i = 0; i < n; i++){
            if(garbage[i].find('M') != std::string::npos) last[0] = i;
            if(garbage[i].find('P') != std::string::npos) last[1] = i;
            if(garbage[i].find('G') != std::string::npos) last[2] = i;
            
            res += garbage[i].size();
        }
        
        int maxIdx = max(last[0], max(last[1], last[2]));
        travel.insert(travel.begin(), 0);
        for(int i = 1; i <= maxIdx; i++) travel[i] += travel[i-1];
        for(int i = 0; i < 3; i++) res += travel[last[i]];
        return res;
    }
};

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char, int> m = {{'M', 0}, {'P', 1}, {'G', 2}};
        int last[3] = {-1, -1, -1}; //keep track of the last index in garbage
        int count[3] = {0, 0, 0}; //total garbage to collect
        int n = garbage.size();
        for(int i = 0; i < n; i++){
            for(char& c: garbage[i]){
                last[m[c]] = i;
                count[m[c]]++;
            }
        }
        int maxIdx = max(last[0], max(last[1], last[2]));
        travel.insert(travel.begin(), 0);
        for(int i = 1; i <= maxIdx; i++){
            travel[i] += travel[i-1];
        }
        int res = 0;
        for(int i = 0; i < 3; i++){
            if(last[i] > -1) res += travel[last[i]] + count[i];
        }
        return res;
    }
};
