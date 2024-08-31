class BetterSolution {
public:
    int n, m;
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        
        // vector<vector<bool>> seen(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0] and dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int r, int c, string& word, int idx){
        if(r >= n  or r < 0 or c >= m or c < 0 or board[r][c] == '-' or board[r][c] != word[idx]) return false;

        if(idx == word.size() - 1) return true;

        char tmp = board[r][c];
        board[r][c] = '-';

        bool res = dfs(board, r+1, c, word, idx+1) 
            or dfs(board, r-1, c, word, idx+1) 
            or dfs(board, r, c+1, word, idx+1) 
            or dfs(board, r, c-1, word, idx+1);
        // cout << "[" << r << "]" << "[" << c <<"] = " << res << endl; 
        board[r][c] = tmp;
        return res;
    }
};

class Solution {
public:
    int n, m;
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0] and dfs(board, seen, i, j, word, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& seen, int r, int c, string& word, int idx){
        if(r >= n  or r < 0 or c >= m or c < 0 or seen[r][c] or board[r][c] != word[idx]) return false;

        if(idx == word.size() - 1) return true;

        seen[r][c] = true;

        bool res = dfs(board, seen, r+1, c, word, idx+1) or dfs(board, seen, r-1, c, word, idx+1) or dfs(board, seen, r, c+1, word, idx+1) or dfs(board, seen, r, c-1, word, idx+1);
        // cout << "[" << r << "]" << "[" << c <<"] = " << res << endl; 
        seen[r][c] = false;
        return res;
    }
};
