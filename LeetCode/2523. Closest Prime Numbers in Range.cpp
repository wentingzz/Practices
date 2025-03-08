class Solution {
public:
    bool isPrime(int val){
        if(val == 1) return false;
        for(int i = 2; i <= sqrt(val); i++){
            if(val % i == 0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        if(left <= 2 and right >= 3) return {2, 3};
        vector<int> res = {-1, -1};
        int last = -1;
        for(int i = left; i <= right; i++){
            if(isPrime(i)){
                if(res[0] == -1) res[0] = i;
                else if(res[1] == -1) res[1] = i;
                else if(last > -1 and i - last < res[1] - res[0]) res[0] = last, res[1] = i;
                last = i;
            }
        }
        if(res[1] == -1) return {-1, -1};
        return res;
    }
};
