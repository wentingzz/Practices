class Solution {
public:
    int checkRecord(int n) {
        int MOD = 1000000007; //all attend
        int state[6] {1,1,0,1,0,0}; 
        int tmp[6] {};
        for(int i = 1; i < n; i++){
            for(int i = 0; i < 6; i++) tmp[i] = state[i];
            state[0] = ((long long)tmp[0] + tmp[1] + tmp[2]) % MOD; //
            state[1] = tmp[0] % MOD; //L1 = P
            state[2] = tmp[1] % MOD; //L2 = L1
            state[3] = ((long long)tmp[0] + tmp[1] + tmp[2] + tmp[3] + tmp[4] + tmp[5]) % MOD; //A1 = P + L1 + L2 + A1 + AL1 + AL2
            state[4] = tmp[3] % MOD;
            state[5] = tmp[4] % MOD;
        }
        int res = 0;
        for(int& s: state) res = ((long long)res + s) % MOD;
        return res;
    }
};
