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
    bool isBalanced(TreeNode* root) {
        int edges = 0; 
        dfs(root, edges);
        if (edges > 1) {
            return false;
        }
        return true;
    }

    int dfs(TreeNode* root, int& edges) {
        if (!root) {
            return 0;
        }

        int left = dfs(root->left, edges);
        int right = dfs(root->right, edges);

        edges = max(edges, abs(right-left));

        return 1 + max(right,left);
    }
};
