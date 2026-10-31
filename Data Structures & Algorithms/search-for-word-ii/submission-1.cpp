class Solution {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> mapping;
        bool word = false;
    };
    vector<string> res;
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            populateTrie(words[i], root);
        }
        string ans = "";

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                char c = board[i][j];
                dfs(root, board, i, j, ans);
            }
        }

        return res;

    }

    void populateTrie(string word, TrieNode* root) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->mapping.find(c) == curr->mapping.end()) {
                curr->mapping[c] = new TrieNode();
            }
            curr = curr->mapping[c];
        }
        curr->word = true;

    }

    void dfs(TrieNode* curr, vector<vector<char>>& board, int r, int c, string ans) {
        if (r < 0 || r >= board.size() || c >= board[r].size() || c < 0) return;
        
        if (curr->mapping.find(board[r][c]) == curr->mapping.end()) {
            return;
        } else {
            curr = curr->mapping[board[r][c]];
            ans += board[r][c];
            
        }
        if (curr->word) {
            res.push_back(ans);
            curr->word = false;
        }
        char restore = board[r][c];
        board[r][c] = '#';
        dfs(curr, board, r-1, c, ans);
        dfs(curr, board, r+1, c, ans);
        dfs(curr, board, r, c-1, ans);
        dfs(curr, board, r, c+1, ans);
        board[r][c] = restore;
    }
    
};
