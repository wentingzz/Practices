class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0, match = 0;
        while(n > 1){
            match = ceil((n-1)/2.0);
            res += match;
            n -= match;
        }
        return res;
    }
};

class QuickerSolution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while(n > 1){
            if(n % 2 == 0){
                res += n/2;
                n = n/2;
            }else{
                res += (n-1)/2;
                n = (n-1)/2 + 1;
            }
        }
        return res;
    }
};
