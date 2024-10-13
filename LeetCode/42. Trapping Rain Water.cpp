class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxL(height.size(), height[0]);
        vector<int> maxR(height.size(), height.back());
        for(int i = 1; i < height.size(); i++){
            maxL[i] = max(height[i], maxL[i-1]);
            maxR[height.size()-1-i] = max(height[height.size()-1-i], maxR[height.size()-i]);
        }
        int res = 0;
        for(int i = 0; i < height.size(); i++){
            res += min(maxL[i], maxR[i]) - height[i];
        }
        return res;
    }
};

class SlightlyBetterSolution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, maxL = 0, maxR = 0;
        int totalWater = 0;
        while(l < r){
            if(height[l] < height[r]){
                if(maxL > height[l]){
                    totalWater += maxL - height[l];
                }else{
                    maxL = height[l];
                }
                l++;
            }else{
                if(maxR > height[r]){
                    totalWater += maxR - height[r];
                } else {
                    maxR = height[r];
                }
                r--;
            }
            // cout << l << ", " << r << ": " << maxL << " " << maxR << endl;
        }
        return totalWater;
    }
};
