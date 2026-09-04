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
        int maxDiameter = 0;
        diameterOfBinaryTree(root, maxDiameter);

        return maxDiameter;    
    }

    int diameterOfBinaryTree(TreeNode* root, int& maxDiameter) {
        if (!root) return 0;

        int left=diameterOfBinaryTree(root->left, maxDiameter);
        int right=diameterOfBinaryTree(root->right, maxDiameter);

        maxDiameter = max(left+right, maxDiameter);

        return 1 + max(left,right);


    }



};
