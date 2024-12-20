class TimeSolution {
public:
    int n;
    vector<int> LIS(vector<int>& nums){
        vector<int> res(n, 1);
        vector<int> tmp;
        for(int i = 0; i < n; i++){
            auto pos = lower_bound(tmp.begin(), tmp.end(), nums[i]);
            if(pos == tmp.end()) tmp.push_back(nums[i]);
            else *pos = nums[i];
            res[i] = tmp.size();
        }
        return res;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        n = nums.size();
        vector<int> up = LIS(nums);
        reverse(nums.begin(), nums.end());
        vector<int> down = LIS(nums);
        reverse(down.begin(), down.end());
        int res = 0;
        for(int i = 1; i < n - 1; i++){
            if(up[i] > 1 and down[i] > 1) res = max(res, up[i] + down[i]);
        }
        return n - res+1;
    }
};

class SpaceSolution {
public:
    int n;
    vector<int> LIS(vector<int>& nums){
        vector<int> res(n, 1);
        vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) res[i] = max(res[i], res[j] + 1);
            }
        }
        return res;
    }

    vector<int> LDS(vector<int>& nums){
        vector<int> res(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) res[i] = max(res[i], res[j] + 1);
            }
        }
        return res;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        n = nums.size();
        vector<int> up = LIS(nums);
        vector<int> down = LDS(nums);
        int res = 0;
        for(int i = 1; i < n - 1; i++){
            if(up[i] > 1 and down[i] > 1) res = max(res, up[i] + down[i]);
        }
        return n - res + 1;
    }
};
