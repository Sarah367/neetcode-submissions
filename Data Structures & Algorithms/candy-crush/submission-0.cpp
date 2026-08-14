class Solution {
   public:
    bool crushIt(vector<vector<int>>& board) {
        bool complete = true;
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (col + 2 < board[0].size()) {
                    if (abs(board[row][col]) != 0) {
                        if (abs(board[row][col]) == abs(board[row][col + 1]) &&
                            abs(board[row][col]) == abs(board[row][col + 2])) {
                            board[row][col] = -abs(board[row][col]);
                            board[row][col + 1] = -abs(board[row][col + 1]);
                            board[row][col + 2] = -abs(board[row][col + 2]);
                            complete = false;
                        }
                    }
                }

                if (row + 2 < board.size()) {
                    if (abs(board[row][col]) != 0) {
                        if (abs(board[row][col]) == abs(board[row + 1][col]) &&
                            abs(board[row][col]) == abs(board[row + 2][col])) {
                            board[row][col] = -abs(board[row][col]);
                            board[row + 1][col] = -abs(board[row + 1][col]);
                            board[row + 2][col] = -abs(board[row + 2][col]);
                            complete = false;
                        }
                    }
                }
            }
        }
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] <= 0) {
                    board[row][col] = 0;
                }
            }
        }
        return complete;
    }
    void drop(vector<vector<int>>& board) {
        int temp = 0;
        for (int col = 0; col < board[0].size(); col++) {
            int row = board.size() - 1;
            int r = board.size() - 1;
            while (row >= 0) {
                if (board[row][col] == 0) {
                    r = row - 1;
                    while (r >= 0) {
                        if (board[r][col] > 0) {
                            temp = board[r][col];
                            board[r][col] = 0;
                            board[row][col] = temp;
                            break;
                        }
                        r--;
                    }
                }
                row--;
            }
        }
    }
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        while (!crushIt(board)) {
            drop(board);
        }

        return board;
    }

};
