class Solution {
public:
    //map is time-efficient
    bool isPathCrossing(string path) {
        map<pair<int, int>, bool> seen;
        pair<int, int> cur = {0, 0};
        seen[cur] = true;
        for(char& c: path){
            if(c == 'N'){
                cur.second++;
                if(seen.find(cur) != seen.end()) return true;
            }else if(c == 'S'){
                cur.second--;
                if(seen.find(cur) != seen.end()) return true;
            }else if(c == 'E'){
                cur.first++;
                if(seen.find(cur) != seen.end()) return true;
            }else{
                cur.first--;
                if(seen.find(cur) != seen.end()) return true;
            }
            seen[cur] = true;
        }

        return false;
    }

    // set is space-efficient
    bool isPathCrossing2(string path) {
        set<pair<int, int>> seen;
        pair<int, int> cur = {0, 0};
        seen.insert(cur);
        for(char& c: path){
            if(c == 'N'){
                cur.second++;
                if(seen.count(cur) > 0) return true;
            }else if(c == 'S'){
                cur.second--;
                if(seen.count(cur) > 0) return true;
            }else if(c == 'E'){
                cur.first++;
                if(seen.count(cur) > 0) return true;
            }else{
                cur.first--;
                if(seen.count(cur) > 0) return true;
            }
            seen.insert(cur);
        }

        return false;
    }
    
};
