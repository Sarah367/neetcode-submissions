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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxEdges = 0;
        maxDepth(root, maxEdges);
        return maxEdges;
    }

    int maxDepth(TreeNode* root, int& maxEdges) {
        if (root == nullptr) {
            return -1;
        }

        int leftHeight = maxDepth(root->left, maxEdges);
        int rightHeight = maxDepth(root->right, maxEdges);

        int calculateDiameter = (leftHeight+1) + (rightHeight+1);

        maxEdges = max(maxEdges, calculateDiameter);

        return 1 + max(leftHeight, rightHeight);
    }
};
