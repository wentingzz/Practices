class Solution {
public:
    void next(int& r, int& c, int& rows, int& cols, int step, int rdir, int cdir, vector<vector<int>>& res){
        for(int i = 0; i < step; i++){
            r += rdir, c += cdir;
            if(r >= 0 and r < rows and c >= 0 and c < cols){
                res.push_back({r, c});
            }
        }

    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int cnt = 4, step = 1;
        res.push_back({rStart, cStart});
        int limit = max(max(rStart, rows-rStart), max(cStart, cols - cStart));
        for(int i = 0; i <= limit; i++){
            next(rStart, cStart, rows, cols, step, 0, 1, res);
            next(rStart, cStart, rows, cols, step, 1, 0, res);
            step++;
            next(rStart, cStart, rows, cols, step, 0, -1, res);
            next(rStart, cStart, rows, cols, step, -1, 0, res);
            step++;
        }
        
        return res;
    }
};
