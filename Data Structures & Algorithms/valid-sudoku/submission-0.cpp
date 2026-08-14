class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> freq;




        for (int i = 0; i < board.size(); i++) {
            freq.clear();
            for (char c : board[i]) {
                // find duplicates;
                if (c == '.') {
                    continue;
                }

                freq[c]++;

                if (freq[c] > 1) {
                    return false;
                }
            }
            
        }
        freq.clear();
        for (int cols = 0; cols < board[0].size(); cols++) {
            for (int rows = 0; rows < board.size(); rows++) {
                cout << "COLUMNS: " << board[rows][cols] << ",";
                char c = board[rows][cols];

                if (c == '.') {
                    continue;
                }
                freq[c]++;
                if (freq[c] > 1) {
                    return false;
                }
                
            }
            freq.clear();
            cout << endl;
        }
        freq.clear();
        for (int rows = 0; rows < 9; rows += 3) {
            for (int cols = 0; cols < 9; cols += 3) { // [0,0]
                freq.clear();
                for (int innerRow = rows; innerRow < rows+3; innerRow++) {
                    for (int innerCol = cols; innerCol < cols+3; innerCol++) {
                        char c = board[innerRow][innerCol];
                        if (c == '.') continue;

                        freq[c]++;
                        if (freq[c] > 1) {
                            return false;
                        }
                    }
                } 



            }
        }




    

        




        return true;
    }
};
