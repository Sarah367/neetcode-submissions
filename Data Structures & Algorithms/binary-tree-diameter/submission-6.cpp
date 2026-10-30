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
        int currentMax = 0;
        findDiameter(root, currentMax);

        return currentMax;
    }

    int findDiameter(TreeNode* root, int& currentMax) {
        if (!root) return 0;


        int left = findDiameter(root->left, currentMax);
        int right = findDiameter(root->right, currentMax);

        currentMax = max(currentMax, right+left);


        return max(left,right)+1;

    }
};
