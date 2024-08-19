class Solution {
public:
    void place(vector<vector<char>>& res, int& stones, int r, int c){
        for(int i = 0; i < stones; i++){
            res[r-i][c] = '#';
        }
        stones = 0;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> res(m, vector<char>(n, '.'));
        
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < m; j++){
                if(box[i][j] =='#') cnt++;
                else if(box[i][j] == '*'){
                    res[j][n-1-i] = '*';
                    place(res, cnt, j-1, n-1-i);
                }
            }
            if(cnt > 0) place(res, cnt, m-1, n-1-i);
        }
        return res;
    }
};
