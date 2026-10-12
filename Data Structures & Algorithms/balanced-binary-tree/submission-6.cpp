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
    bool balanced = true;
    bool isBalanced(TreeNode* root) {
        check(root);
        return balanced;
    }

    int check(TreeNode* root) {
        if (!root || !balanced) return 0;

        int left = check(root->left);
        int right = check(root->right);
        if (abs(right-left) > 1) balanced = false;

        return max(left,right)+1;
    }

};
