class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        int res = 0, i = 0, m = banned.size(), sum = 0;
        for(int j = 1; j <= n && j + sum <= maxSum; j++){
            if(i < m and j == banned[i]){
                while(i < m and j == banned[i]) i++;
                continue;
            }
            
            sum += j, res++;
        }
        return res;
    }
};
