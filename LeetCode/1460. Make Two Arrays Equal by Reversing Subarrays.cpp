class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int freq[1001] {};
        for(int& n: target) freq[n]++;
        for(int& n: arr){
            if(freq[n] == 0) return false;
            freq[n]--;
        }
        return true;
    }
};
