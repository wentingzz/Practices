class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        int maxVal = -1;
        for(int i = 0; i < arr.size(); i++){
            maxVal = max(arr[i], maxVal);
            if(i == maxVal) res++;
        }
        return res;
    }
};
