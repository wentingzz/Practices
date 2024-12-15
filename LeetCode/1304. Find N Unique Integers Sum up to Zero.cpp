class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n, 0);
        for(int i = 0; i < n/2; i++){
            res[2*i] = i+1;
            res[2*i+1] = -i-1;
        }
        return res;
    }
};
