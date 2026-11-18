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
        bool balanced = true;
        checkBalance(root, balanced);
        
        return balanced;
    }

    int checkBalance(TreeNode* root, bool& balanced) {
        if (!root) {
            return 0;
        }

        int left = checkBalance(root->left, balanced);
        int right = checkBalance(root->right, balanced);

        if (abs(right-left) > 1) balanced = false;


        return max(left,right)+1;
    }
};
