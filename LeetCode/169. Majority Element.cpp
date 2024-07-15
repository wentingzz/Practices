class BetterSolution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0, freq = 0;
        for(int& n: nums){
            if(freq == 0) majority = n;
            if(majority == n) freq++;
            else freq--;
        }
        return majority;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int& n: nums) freq[n]++;
        int maxF = 0, res = 0;
        for(auto& it: freq){
            if(it.second > maxF){
                maxF = it.second;
                res = it.first;
            }
        }
        return res;
    }
};
