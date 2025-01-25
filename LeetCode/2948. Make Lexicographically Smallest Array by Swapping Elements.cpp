class BetterSolution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> sorted;
        for(int i = 0; i < n; i++) sorted.push_back({nums[i], i});
        sort(sorted.begin(), sorted.end());

        vector<int> res(n, 0);
        int i = 0;
        while(i < n){
            int j = i+1;
            vector<int> idx = {sorted[i].second};
            while(j < n and sorted[j].first - sorted[j-1].first <= limit){
                idx.push_back(sorted[j].second);
                j++;
            }
            sort(idx.begin(), idx.end());
            for(int k = 0; k < idx.size(); k++, i++){
                res[idx[k]] = sorted[i].first;
            }
            
        }
        return res;
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> sorted(n);
        for(int i = 0; i < n; i++) sorted[i] = {nums[i], i};
        sort(sorted.begin(), sorted.end());
        vector<int> index = {sorted[0].second};
        for(int i = 1; i < n; i++){
            if(sorted[i].first - sorted[i-1].first > limit){
                //set value of this group
                sort(index.begin(), index.end());
                int m = index.size();
                for(int j = 0; j < m; j++) nums[index[m-1-j]] = sorted[i-1-j].first;
                index.clear();
            }
            index.push_back(sorted[i].second);
        }
        if(!index.empty()){
            sort(index.begin(), index.end());
            int m = index.size();
            for(int j = 0; j < m; j++) nums[index[m-1-j]] = sorted[n-1-j].first;
        }
        return nums;
    }
};
