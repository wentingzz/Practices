class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3) return false;
        int cnt = 0;
        for(int i = 0; i < 3; i++){
            arr[i] = arr[i] % 2;
            cnt += arr[i];
        }
        if(cnt == 3) return true;
        for(int i = 3; i < arr.size(); i++){
            arr[i] = arr[i] % 2;
            cnt += arr[i] - arr[i-3];
            if(cnt == 3) return true;
        }
        return false;
    }
};
