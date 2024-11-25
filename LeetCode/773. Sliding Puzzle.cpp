class Solution {
public:
    string board2string(vector<vector<int>>& board){
        string res = "";
        for(auto b: board){
            for(auto i: b) res += to_string(i);
        }
        return res;
    }
    vector<string> neighbors(string board){
        vector<string> res;
        for(int i = 0; i < 6; i++){
            if(board[i] == '0'){
                string cur = board;
                if(i != 0 and i != 3){
                    swap(cur[i], cur[i-1]);
                    res.push_back(cur);
                }
                cur = board;
                if(i != 2 and i != 5){
                    swap(cur[i], cur[i+1]);
                    res.push_back(cur);
                }
                cur = board;
                swap(cur[i], cur[(i+3)%6]);
                res.push_back(cur);
                return res;
            }
        }
        return res;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        int res = 0;
        queue<string> q;
        unordered_set<string> seen;
        q.push(board2string(board));
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string cur = q.front(); q.pop();
                if(cur == "123450") return res;
                if(seen.find(cur) != seen.end()) continue;
                seen.insert(cur);
                for(string& next: neighbors(cur)){
                    if(seen.find(next) == seen.end()) q.push(next);
                }
            }
            res++;
            
        }
        return -1;
    }
};
