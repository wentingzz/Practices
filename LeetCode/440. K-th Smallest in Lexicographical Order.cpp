class Solution {
public:
    int count(long start, long n){
        long res = 0, end = start + 1;
        while(start <= n){
            res += min(n+1, end) - start;
            start *= 10;
            end *= 10;
        }
        return res;
    }
    int findKthNumber(int n, int k) {
        long cur = 1, num = 1;
        while(cur < k){
            int tmp = count(num, n);
            if(cur + tmp <= k){
                cur += tmp;
                num++;
            }else{
                cur++;
                num *= 10;
            }
        }
        return num;
    }
};
