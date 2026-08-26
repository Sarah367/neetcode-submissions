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
        int height = 0;
        maxHeight(root, height);
        if (height > 1) {
            return false;
        }

        return true;
    }
    
    int maxHeight(TreeNode* root, int& height) {
        if (!root) {
            return 0;
        }

        int left = maxHeight(root->left, height);
        int right = maxHeight(root->right, height);

        height = max(height, abs(right-left));

        return 1 +max(left,right);
    }

};
