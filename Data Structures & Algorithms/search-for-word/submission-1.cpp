class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // CAT
        int cnt = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (helper(board, word, i, j, cnt)) return true;
            }
        }
        return false;
        
    }

    bool helper(vector<vector<char>>& board, string& word, int r, int c, int cnt) {
        if (cnt == word.size()) return true;

        if (r < 0 || r >= board.size() || c >= board[r].size() || c < 0) return false;

        if (word[cnt] == board[r][c]) {
            cnt++;
        } else {
            return false;
        }

        char restore = board[r][c];
        board[r][c] = '#';
        if (helper(board, word, r-1, c, cnt)) {
            return true;
        }
        if (helper(board, word, r+1, c, cnt)) return true;
        if (helper(board, word, r, c-1, cnt)) return true;
        if (helper(board, word, r, c+1, cnt)) return true;

        board[r][c] = restore;

        return false;
    }



};
