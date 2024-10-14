class QuickerSolution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size(), res = 0;
        vector<int> preSum(n, 0);
        vector<int> first(32, -2);
        first[0] = -1;
        vector<int> v2i(26, -1);
        v2i['a' - 'a'] = 0;
        v2i['e' - 'a'] = 1;
        v2i['i' - 'a'] = 2;
        v2i['o' - 'a'] = 3;
        v2i['u' - 'a'] = 4;

        int cur = 0;
        for(int i = 0; i < n; i++){
            if(v2i[s[i]-'a'] != -1) cur ^= 1 << (v2i[s[i]-'a']);
            preSum[i] = cur;
            if(first[cur] == -2) first[cur] = i;
            else res = max(res, i - first[cur]);
            
        }
        return res;
    }
};

class SlowerSolution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        vector<int> preSum(n, 0);
        vector<int> first(32, -2);
        first[0] = -1;
        unordered_map<char, int> v2i = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        int cur = 0;
        for(int i = 0; i < n; i++){
            if(v2i.find(s[i]) != v2i.end()){
                cur ^= 1 << (v2i[s[i]]);
            }
            preSum[i] = cur;
            if(first[cur] == -2) first[cur] = i;
            else res = max(res, i - first[cur]);
            
        }
        return res;
    }
};
