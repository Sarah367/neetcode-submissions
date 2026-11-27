class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> freq;
        for (int rows = 0; rows < board.size(); rows++) {
            for (int cols = 0; cols < board[rows].size(); cols++) {
                if (board[rows][cols] == '.') {
                    continue;
                }
                freq[board[rows][cols]]++;
                if (freq[board[rows][cols]] > 1) {
                    return false;
                }

            }
            freq.clear();
        }
        freq.clear();
        for (int cols = 0; cols < board[0].size(); cols++) {
            for (int rows = 0; rows < board.size(); rows++) {
                if (board[rows][cols] == '.') {
                    continue;
                }

                freq[board[rows][cols]]++;
                if (freq[board[rows][cols]] > 1) {
                    return false;
                }
            }
            freq.clear();
        }
        
        for (int rows = 0; rows < board.size(); rows+=3) {
            for (int cols = 0; cols < board[0].size(); cols+=3) {
                freq.clear();        
                for (int innerrows = rows; innerrows < rows+3; innerrows++) {
                    for (int innercols = cols; innercols < cols+3; innercols++) {
                        char c = board[innerrows][innercols];
                        if (c == '.') continue;
                        freq[c]++;
                        if (freq[c] > 1) return false;
                    }
                }

            }
        }

        return true;

    }
};
