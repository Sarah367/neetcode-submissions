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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // left // right

        queue<TreeNode*> queue;
        vector<vector<int>> res;
        if (root) {
            queue.push(root);
            res.push_back({root->val});
        }
        vector<int> levels;
        while (queue.size() > 0) {
            int length = queue.size();
            for (int i = 0; i < length; i++) {
                TreeNode* curr = queue.front();
                queue.pop();

                if (curr->left) {
                    queue.push(curr->left);
                    levels.push_back(curr->left->val);    
                }
                if (curr->right) {
                    queue.push(curr->right);
                    levels.push_back(curr->right->val);
                }

            }
            if (!queue.empty()) {
                res.push_back(levels);
                levels.clear();
            }
        }

        return res;

    }
};
