class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool exists = false;
        string currComb = "";

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                char c = board[i][j];
                helper(board, word, i, j, currComb, exists);
                
            }
        }

        return exists;
    }


    void helper(vector<vector<char>>& board, string word, int r, int c, string currComb, bool& exists) {
        if (word == currComb) {
            exists = true;
            return;
        }

        if (r < 0 || r >= board.size() || c >= board[r].size() || c < 0) return; 

        if (word[currComb.size()] != board[r][c]) {
            return;
        } else {
            currComb.push_back(board[r][c]);
            
        }

        char restore = board[r][c];
        board[r][c] = '#';
        helper(board, word, r-1, c, currComb, exists);

        helper(board, word, r+1, c, currComb, exists);
  
        helper(board, word, r, c-1, currComb, exists);

        helper(board, word, r, c+1, currComb, exists);

        board[r][c] = restore;
    }
};
