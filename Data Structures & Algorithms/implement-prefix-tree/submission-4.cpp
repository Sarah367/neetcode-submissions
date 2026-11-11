class PrefixTree {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> mapping;
        bool word = false;
    };
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            if (curr->mapping.find(c) == curr->mapping.end()) {
                curr->mapping[c] = new TrieNode();
            }
            curr = curr->mapping[c];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->mapping.find(c) == curr->mapping.end()) {
                return false;
            }
            curr = curr->mapping[c];
        }
        return curr->word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (curr->mapping.find(c) == curr->mapping.end()) {
                return false;
            }
            curr = curr->mapping[c];
        }
        return true;
    }
};
