class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        //we want to assign larger number to cities with more roads connected
        vector<int> count(n, 0);
        for(vector<int>& r: roads){
            count[r[0]]++;
            count[r[1]]++;
        }
        sort(count.begin(), count.end());
        long long res = 0;
        for(long i = 1; i <= n; i++) res += i * count[i-1];
        
        return res;
    }
};
