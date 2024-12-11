class LessTimeSolution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int freq[100001] {};
        int l = INT_MAX, h = 0;
        for(int& n: nums){
            freq[n]++;
            l = min(l, n), h = max(h, n);
        }
        int maxF = 0, f = 0, j = l;
        for(int i = l; i <= h; i++){
            f += freq[i];
            while(i - j > 2*k) f -= freq[j++];
            maxF = max(maxF, f);
        }
        return maxF;
    }
};

class LessSpaceSolution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 1, l = 0;
        for(int r = 1; r < nums.size(); r++){
            while(nums[r] - nums[l] > 2 * k) l++;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
