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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> queue;

        if (root) {
            queue.push(root);
        }

        int level = 0;
        while (queue.size() > 0) {
            int length = queue.size();
            for (int i = 0; i < queue.size(); i++) {
                TreeNode* curr = queue.front();
                queue.pop();
                if (curr->left) {
                    queue.push(curr->left);
                }
                if (curr->right) {
                    queue.push(curr->right);
                }
                swap(curr->left, curr->right);
            }
            
        }

        return root;
        



    }
};
