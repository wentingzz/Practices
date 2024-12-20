class BetterSolution {
public:
    bool isPrime(int n){
        if(n <= 1) return false;
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    int getPrime(int l, int h){
        for(int i = l; i < h; i++){
            if(isPrime(i)) return i;
        }
        return -1;
    }
    bool primeSubOperation(vector<int>& nums) {
        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i] >= nums[i+1]){
                int p = getPrime(nums[i] - nums[i+1] + 1, nums[i]);
                if(p == -1) return false;
                nums[i] -= p;
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

    int findPrimeLessThan(int k){
        int l = 0, h = primes.size()-1, res = 0;
        int m;
        while(l <= h){
            m = l + (h-l)/2;
            if(primes[m] < k){
                res = primes[m];
                l = m + 1;
            }else{
                h = m - 1;
            }
        }
        return res;
    }
    bool primeSubOperation(vector<int>& nums) {
        int last = 0;
        for(int& n: nums){
            if(last >= n) return false;
            last = n - findPrimeLessThan(n - last);
        }
        return true;
    }
};


class CompleteSolution {
public:
    int findPrimeLessThan(vector<int> primes, int k){
        int l = 0, h = primes.size()-1, res = 0;
        int m;
        while(l <= h){
            m = l + (h-l)/2;
            if(primes[m] < k){
                res = primes[m];
                l = m + 1;
            }else{
                h = m - 1;
            }
        }
        return res;
    }

    vector<int> findPrimes(int h){
        vector<bool> isPrime(h + 1, true);
        for(int i = 2; i * i <= h; i++){
            if(isPrime[i]){
                for(int j = i*i; j <= h; j += i){
                    isPrime[j] = false;
                }
            }
        }

        vector<int> res;
        for(int i = 2; i <= h; i++){
            if(isPrime[i]) res.push_back(i);
        }
        return res;
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes = findPrimes(1000);

        int last = 0;
        for(int& n: nums){
            if(last >= n) return false;
            last = n - findPrimeLessThan(primes, n - last);
        }
        return true;
    }
};
