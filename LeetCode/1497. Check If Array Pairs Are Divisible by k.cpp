class BetterSolution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        for(int& n: arr){
            freq[((n % k) + k) % k]++;
        }
        if(freq[0] % 2 == 1) return false;
        for(int i = 1; i <= k - i; i++){
            if(freq[i] != freq[k-i]) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        for(int& n: arr){
            int key = n % k;
            if(key < 0) key += k;
            // cout << key << endl;
            
            if(key > 0){
                if(freq[k-key] > 0) freq[k-key]--;
                else freq[key]++;
            }
        }
        for(int i = 1; i < k; i++){
            if(freq[i] > 0) return false;
        }
        return true;
    }
};
