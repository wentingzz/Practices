class Solution {
public:
    int minSwaps(string s) {
        int r = s.size()-1, count = 0, res = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '[') count++;
            else if(count > 0) count--;
            else{
                while(r > i and s[r] == ']') r--;
                swap(s[i], s[r]);
                count++;
                res++;
            }
        }
        return res;
    }
};
