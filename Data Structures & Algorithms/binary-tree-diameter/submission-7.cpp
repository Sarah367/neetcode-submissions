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
        int longestPath = 0;
        calculateDiameter(longestPath, root);

        return longestPath;
    }

    int calculateDiameter(int& longestPath, TreeNode* root) {
        if (!root) return 0;

        int left = calculateDiameter(longestPath, root->left);
        int right = calculateDiameter(longestPath, root->right);

        longestPath = max(left+right, longestPath);


        return max(left,right)+1;
    }
};
