class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int last = 0;
        int res = 0;

        for(string& b: bank){
            int cur = 0;
            for(char&c: b){
                cur += (c == '1');
            }
            if(cur > 0){
                res += (cur * last);
                last = cur;
            }
        }

        return res;
    }
};
