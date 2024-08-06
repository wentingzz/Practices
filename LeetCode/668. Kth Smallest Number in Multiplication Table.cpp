class Solution {
public:
    int count(int m, int n, int mid){
        int res = 0;
        for(int i = 1; i <= m; i++){
            res += min(n, mid/i);
        }
        return res;
    }
    int findKthNumber(int m, int n, int k) {
        int l = 1, h = m * n, mid, res;
        while(l <= h){
            mid = l + (h-l)/2;
            int cnt = count(m, n, mid);
            if(cnt < k){
                l = mid + 1;
            }
            else{
                h = mid - 1;
                res = mid;
            }
        }
        return res;
    }
};
