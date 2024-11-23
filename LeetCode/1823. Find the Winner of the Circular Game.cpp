class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> keep;
        for(int i = 1; i <= n; i++) keep.push_back(i);
        
        int idx = 0;
        while(keep.size() > 1){
            idx = ((idx + k-1) % keep.size());
            keep.erase(keep.begin() + idx);
            idx %= keep.size();
        }
        return keep[0];
    }
};
