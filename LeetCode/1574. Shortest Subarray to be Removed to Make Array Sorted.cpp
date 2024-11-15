class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), l = 0, r = n-1;
        for(; l < n -1; l++){
            if(arr[l] > arr[l+1]) break;
        }
        if(l == n-1) return 0;
        for(; r > 0; r--){
            if(arr[r-1] > arr[r]) break;
        }
        int res = min(n-1-l, r);
        int i = 0, j = r;
        while(i <= l and j < n){
            if(arr[i] <= arr[j]){
                res = min(res, j-i-1);
                i++;
            }else j++;
        }
        return res;
    }
};
