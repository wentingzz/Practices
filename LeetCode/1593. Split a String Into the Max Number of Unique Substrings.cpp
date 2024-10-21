class Solution {
public:
    int n;
    int dfs(string& s, int idx, unordered_set<string>& seen){
        if(n == idx) return 0;
        string cur = "";
        int res = 0;
        for(int i = 0; i + idx < n; i++){
            //unique substr
            cur += s[idx+i];
            if(seen.find(cur) == seen.end()){
                seen.insert(cur);
                res = max(res, 1 + dfs(s, idx+i+1, seen));
                seen.erase(cur);
            }
        }
        return res;
    }
    int maxUniqueSplit(string s) {
        n = s.size();
        unordered_set<string> seen;
        //dp doesn't work because seen list before ith idx will affect how we pick the substring after ith idx
        return dfs(s, 0, seen);
    }
};
