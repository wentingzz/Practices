class Solution {
public:
    void skipSpaces(string& text, int& i, int& n){
        while(i < n and text[i] == '_') i++;
    }
    bool canChange(string start, string target) {
        int i = 0, j = 0, n = start.size();
        //L is more right in start
        //R is more left in start
        while(i < n and j < n){
            skipSpaces(start, i, n);
            skipSpaces(target, j, n);
            if(i == n or j == n) break;
            if(start[i] == 'L'){
                if(target[j] == 'L' and j <= i){
                    j++;
                    i++;
                } else return false;
            }else{
                if(target[j] == 'R' and j >= i){
                    j++;
                    i++;
                }else return false;
            }
        }

        skipSpaces(start, i, n);
        skipSpaces(target, j, n);
        return i == j;
    }
};
