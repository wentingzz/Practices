class Solution {
public:
    int dist(vector<int>& pos){
        return pos[0] * pos[0] + pos[1] * pos[1];
    }
    string into(int& x, int& y){
        return to_string(x) + "." + to_string(y);
    }
    int moves[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    unordered_map<int, int> turn = {{-2, -1}, {-1, 1}};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> pos = {0, 0};
        int face = 0; //moves[face] indicates next move
        unordered_set<string> blocks;
        for(auto o: obstacles) blocks.insert(into(o[0], o[1]));
        int res = 0;
        for(int& c: commands){
            if(c < 0) face = (face + turn[c] + 4) % 4;
            else{
                int x = pos[0], y = pos[1];
                for(int i = 0; i < c; i++){
                    x += moves[face][0];
                    y += moves[face][1];
                    if(blocks.find(into(x, y)) != blocks.end()){
                        x -= moves[face][0];
                        y -= moves[face][1];
                        break;
                    }
                }
                pos = {x, y};
                res = max(res, dist(pos));
            }
            // cout << face << " and " << pos[0] << "," <<pos[1] << endl;
        }
        return res;
    }
};
