class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if(k == 0) return res;
        int sum = 0, abs_k = abs(k), j = (k < 0 ? (-k)%n: n-1);
        for(int i = 0; i < abs_k; i++) sum += code[i];
        for(int i = 0; i < n; i++){
            res[j] = sum;
            j = (j+1) % n;
            sum += code[(i+abs_k)%n] - code[i];
        }
        return res;
    }
};
