class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long res = 0, total = 0;
        unordered_map<int, int> freq;
        for(int& n: skill){
            total += n;
            freq[n]++;
        }
        int n = skill.size()/2;
        if(total % n > 0) return -1;
        total /= n;
        // cout << "Target skill = " << total << endl;
        for(auto& it: freq){
            if(it.second > 0){
                // cout << it.first << " ";
                if(freq.find(total - it.first) == freq.end() or freq[total - it.first] != it.second){
                    return -1;
                }
                if(it.first == total - it.first) it.second /= 2;
                res += it.first * (total - it.first) * it.second;
                it.second = 0;
                freq[total-it.first] = 0;
            }
        }
        return res;
    }
};
