class TrieNode {
    public: 
        vector<TrieNode*> children;
        bool word = false;
        TrieNode() : children(26, nullptr), word(false) {}
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            if (curr->children[c-'a'] == nullptr) {
                curr->children[c-'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        return dfs(0, root,word);

        
    }
    bool dfs(int i, TrieNode* root, const string& word) {
        if (i == word.size()) return root->word;

        if (word[i] == '.') {
            for (TrieNode* child : root->children) {
                if (child != nullptr && dfs(i+1, child, word)) {
                    return true;
                }
                
            }
            return false;
        }
        if (root->children[word[i]-'a'] == nullptr) return false;
        return dfs(i+1, root->children[word[i] - 'a'], word);
        
    }


};
