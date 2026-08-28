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
        int maximum = 0;
        getDiameter(maximum, root);
        return maximum;
    }

    int getDiameter(int& maximum, TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left = getDiameter(maximum, root->left);
        int right = getDiameter(maximum, root->right);

        maximum = max(maximum, left+right);

        return 1 + max(left,right);



    }
};
