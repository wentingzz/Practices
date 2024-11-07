class Solution {
public:
    void addToBits(vector<int>& bits, int c){
        int i = 25;
        while(c){
            bits[i--] += (c & 1);
            c >>= 1;
        }
    }
    int largestCombination(vector<int>& candidates) {
        vector<int> bits(26, 0);
        for(int& c: candidates){
            addToBits(bits, c);
        }
        int res = 0;
        for(int i = 25; i > -1; i--){
            res = max(res, bits[i]);
        }
        return res;
    }
};
