class BestSolution {
public:
    int numDays(vector<int>& weights, int cap){
        int res = 1, sum = 0;
        for(int& w: weights){
            sum += w;
            if(sum > cap){
                res++;
                sum = w;
            }
        }
        return res;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1, h = 0;
        for(int& w: weights){
            l = max(w, l);
            h += w;
        }
        l = max(l, h/days);
        int m, res = h;
        while(l <= h){
            m = l + (h-l)/2;
            int d = numDays(weights, m);
            if(d > days) l = m + 1;
            else{
                res = min(res, m);
                h = m - 1;
            }
        }
        return res;
    }
};

class SlowerSolution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = weights[0];
        int r = 0;
        for(int& w: weights){
            l = max(l, w);
            r += w;
        }

        int res = -1;
        while(l <= r){
            int m = (l+r) / 2;
            if(shipDays(weights, m) <= days){
                res = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return res;
    }

    int shipDays(vector<int>& weights, int cap){
        int res = 0;
        int cur = 0;
        for(int& w: weights){
            if(cur + w > cap){

                res++;
                cur = 0;
            }
            cur += w;
        }
        res += (cur != 0);
        return res;
    }
};
