class MultiSetSolution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> points;
        for(auto &b: buildings){
            points.emplace_back(b[0], -b[2]);
            points.emplace_back(b[1], b[2]);
        }
        sort(points.begin(), points.end());
        multiset<int, greater<int>> sky;
        sky.insert(0);
        vector<vector<int>> res;
        int curH = 0;
        for(auto &p: points){
            if(p.second < 0){
                sky.insert(-p.second);
            } else {
                sky.erase(sky.find(p.second));
            }
            if(curH != *sky.begin()){
                curH = *sky.begin();
                res.push_back({p.first, curH});
            }
        }
        
        return res;
    }
};
