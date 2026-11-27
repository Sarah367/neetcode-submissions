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
        getDiameter(root, longestPath);
        return longestPath;
    }

    int getDiameter(TreeNode* root, int& longestPath) {
        if (!root) {
            return 0;
        }

        int left = getDiameter(root->left, longestPath);
        int right = getDiameter(root->right, longestPath);

        longestPath = max(left+right, longestPath);

        return max(left,right)+1;


    }
};
