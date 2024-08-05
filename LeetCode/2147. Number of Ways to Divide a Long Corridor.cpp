class Solution {
public:
    int numberOfWays(string corridor) {
        int cnt = 0, cur = 0;
        long res = 1;
        for(char& c: corridor){
            if(c == 'S'){
                if(cur > 0){
                    if (cnt > 0) res = (res * (cur + 1)) % 1000000007;
                    cur = 0;
                }
                cnt++;
            }
            if(c == 'P' and cnt % 2 == 0) cur++;
        }
        if(cnt % 2 == 1 or cnt < 2) return 0;
        return res % 1000000007;
    }
};
