class QuickerSolution {
public:
    void moveUntilBlocked(int& prev, int& next, vector<int>& blocks){
        int res = next;
        if(prev < next){
            for(int& b: blocks){
                if(b > prev and b <= next) res = min(res, b-1); //block is at b, we stop before that
            }
        }else{
            for(int& b: blocks){
                if(b < prev and b >= next) res = max(res, b+1);
            }
        }
        next = res;
    }
    int dist(vector<int>& pos){
        return pos[0] * pos[0] + pos[1] * pos[1];
    }
    int moves[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    unordered_map<int, int> turn = {{-2, -1}, {-1, 1}};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> pos = {0, 0};
        int face = 0; //moves[face] indicates next move
        unordered_map<int, vector<int>> xblocks;
        unordered_map<int, vector<int>> yblocks;
        for(auto o: obstacles){
            xblocks[o[0]].push_back(o[1]);
            yblocks[o[1]].push_back(o[0]);
        }
        int res = 0;
        for(int& c: commands){
            if(c < 0) face = (face + turn[c] + 4) % 4;
            else{
                int x = pos[0] + c * moves[face][0];
                int y = pos[1] + c * moves[face][1];
                if(x == pos[0]) moveUntilBlocked(pos[1], y, xblocks[pos[0]]); //x not changing
                else moveUntilBlocked(pos[0], x, yblocks[pos[1]]);
                pos = {x, y};
                res = max(res, dist(pos));
            }
            // cout << face << " and " << pos[0] << "," <<pos[1] << endl;
        }
        return res;
    }
};

class SmallerSolution {
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
