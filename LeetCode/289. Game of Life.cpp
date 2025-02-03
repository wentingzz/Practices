class Solution {
public:
    int m, n;
    vector<vector<int>> adjs = {{-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},        {0, 1},
        {1, -1}, {1, 0}, {1, 1}};
    bool willLive(vector<vector<int>>& board, int r, int c){
        int live = 0;
        for(auto adj: adjs){
            int nr = r + adj[0], nc = c + adj[1];
            if(nr >= 0 and nr < m and nc >= 0 and nc < n){
                live += board[nr][nc];
            }
        }
        if(board[r][c] == 1){
            return live >= 2 and live <= 3; //otherwise, die
        }else{
            return live == 3;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();
        vector<vector<int>> tmp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(willLive(board, i, j)) tmp[i][j] = 1;
            }
        }
        board = tmp;
    }
};
