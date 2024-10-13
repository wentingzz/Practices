class Solution {
public:
    //1-9 (1*9)
    //10-99 (10*9)
    //100-999 (100*9)
    int findNthDigit(int n) {
        long long len = 1, l = 1, cnt = 9;
        while(n > len * cnt){
            n -= len * cnt;
            len++;
            l *= 10;
            cnt *= 10;
        }

        int cur = l + (n - 1)/len;
        return to_string(cur)[(n-1) % len] - '0';
    }
};
