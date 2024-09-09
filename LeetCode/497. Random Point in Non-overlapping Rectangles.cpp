class Solution {
public:
    vector<vector<int>> rs;
    Solution(vector<vector<int>>& rects) {
        rs = rects;
    }
    
    vector<int> pick() {
        int sum_area = 0;
        vector<int> selected;
        
        for (auto r : rs) {
            int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            sum_area += area;
            
            if (rand() % sum_area < area)
                selected = r;
        }
        vector<int> res = {0, 0};
        res[0] = rand() % (selected[2] - selected[0] + 1) + selected[0];
        res[1] = rand() % (selected[3] - selected[1] + 1) + selected[1];
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
