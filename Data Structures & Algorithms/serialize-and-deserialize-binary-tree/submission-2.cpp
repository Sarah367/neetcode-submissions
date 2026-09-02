/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> queue;
        string encode = "";
        if (root) {
            queue.push(root);
        }

        while (queue.size() > 0) {
            int length = queue.size();

            for (int i = 0; i < length; i++) {
                TreeNode* curr = queue.front();
                queue.pop();
                encode += "A" + to_string(curr->val);

                if (curr->left) {
                    queue.push(curr->left);
                    encode += "L" + to_string(curr->left->val);
                } else {
                    encode += "LN";
                }

                if (curr->right) {
                    queue.push(curr->right);
                    encode += "R" + to_string(curr->right->val);
                } else {
                    encode += "RN";
                }
            }
        }

        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* place = new TreeNode(0);
        vector<string> tokens;
        string token = "";
        for (char c : data) {
            if (c != 'L' && c != 'R' && c != 'A') {
                token += c;
            } else {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token = "";
                }
                token += c;
            }
        }
        if (!token.empty()) {
            tokens.push_back(token);
        }
        queue<TreeNode*> queue;
        TreeNode* root = nullptr;
        if (!tokens.empty()) {
            int rootVal = stoi(tokens[0].substr(1));
            root = new TreeNode(rootVal);
            queue.push(root);
        }
        int index = 1;
        while (queue.size() > 0) {
            int length = queue.size();

            for (int i = 0; i < length; i++) {
                TreeNode* curr = queue.front();

                queue.pop();

                string leftToken = tokens[index].substr(1);
                if (leftToken != "N") {
                    int leftVal = stoi(leftToken);
                    TreeNode* leftNode = new TreeNode(leftVal);
                    curr->left = leftNode;
                    queue.push(leftNode);
                }

                string rightToken = tokens[index + 1].substr(1);

                if (rightToken != "N") {
                    int rightVal = stoi(rightToken);
                    TreeNode* rightNode = new TreeNode(rightVal);
                    curr->right = rightNode;
                    queue.push(rightNode);
                }
                index += 3;
            }
        }

        return root;
    }
};
