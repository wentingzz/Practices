class Solution {
public:
    long long appealSum(string s) {
        long long total = 0, cur = 0;
        int n = s.size();
        long long last[26];
        for(long long& l: last) l = -1;
        //When adding a new character X at index i, the appeal[i] = appeal[i-1] + appeal(new possible substrings ending at index i)
        //appeal(new possible substrings) = 1 + i - last_index(X)
        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            cur += i - last[idx];
            last[idx] = i;
            total += cur;
            // cout << total << endl;
        }
        
        return total;
    }
};

class SlowSolution {
public:
    unsigned int bitmap(string s){
        unsigned int res = 0;
        for(char& c: s) res |= (1 << (int)(c - 'a'));
        return res;
    }

    int appeal(unsigned int bits){
        int res = 0;
        while(bits > 0){
            res += (bits & 1);
            bits >>= 1;
        }
        return res;
    }

    long long appealSum(string s) {
        long long res = 0;
        unordered_map<string, unsigned int> dp;
        int n = s.size();
        for(int i = 0; i < n; i++){
            string cur = s.substr(i, 1);
            dp[cur] = bitmap(cur);
        }
        res += n;        
        for(int length = 2; length <= n; length++){
            for(int i = 0; i + length <= n; i++){
                string cur = s.substr(i, length);
                dp[cur] = dp[cur.substr(0, 1)] | dp[cur.substr(1, length-1)];
                // cout << cur << " = " << appeal(dp[cur]) << endl;
                res += appeal(dp[cur]);
            }
            
        }
        return res;
    }
};
