class Solution {
public:
    int stores(vector<int>& qs, int cap){
        int res = 0;
        for(int& q: qs){
            res += q/cap + (q % cap > 0);
        }
        return res;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long l = 0;
        int h = 0;
        for(int& q: quantities){
            l += q;
            h = max(h, q);
        }
        l = max(1ll, l/n);
        int res = h, m;
        while(l <= h){
            m = l + (h-l)/2;
            int cnt = stores(quantities, m);

            if(cnt > n){ //we are using more stores than we have, increase m
                l = m + 1;
            }else{
                res = min(res, m);
                h = m - 1;
            }
        }
        return res;
    }
};
