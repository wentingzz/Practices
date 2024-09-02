class Solution {
public:
    bool check(string& s, string& locked, int start, int end, int inc, char char2check){
        int cnt = 0;
        for(int i = start; i != end; i += inc){
            if(locked[i] == '1'){
                if(s[i] == char2check){
                    if(cnt == 0) return false;
                    cnt--;
                } else cnt++;
            }else cnt++;
        }
        return true;
    }
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n % 2) return false;

        bool res = check(s, locked, 0, n, 1, ')');
        if(res) res = check(s, locked, n-1, -1, -1, '(');
        return res;
    }
};
