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
    bool isValidBST(TreeNode* root) {
        long minimum = LONG_MIN;
        long maximum = LONG_MAX;
        
        return isValid(root, minimum, maximum);
    }

    bool isValid(TreeNode* root, long minimum, long maximum) {
        if (!root) return true;

        if (!(root->val > minimum && root->val < maximum)) {
            return false;
        }

        return isValid(root->left, minimum, root->val) && isValid(root->right, root->val, maximum);
        
    }
};


