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

class HeapSolution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> lines;
        for(auto& b: buildings){
            lines.push_back({b[0], -b[2]});
            lines.push_back({b[1], b[2]});
        }
        sort(lines.begin(), lines.end());
        priority_queue<int> added;
        added.push(0);
        priority_queue<int> toDelete;
        vector<vector<int>> res;
        for(auto p: lines){
            if(p.second < 0){ //start of a new line
                if(added.top() + p.second < 0){
                    res.push_back({p.first, -p.second});
                }
                added.push(-p.second);
            }else{//end of a line
                if(added.top() == p.second){
                    added.pop();
                    while(!toDelete.empty() and added.top() == toDelete.top()) toDelete.pop(), added.pop();
                    if(added.top() != p.second) res.push_back({p.first, added.top()});
                }else{
                    toDelete.push(p.second);
                }
            }
        }
        return res;
    }
};
