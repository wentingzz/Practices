class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0, res = 0;
        for(char& c: s){
            if(c == '(') count++;
            else{
                if(count == 0) res++;
                else count--;
            }
        }
        return res + count;
    }
};
