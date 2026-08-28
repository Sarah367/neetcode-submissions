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
        int maxHeight = 0;
        getHeight(root, maxHeight);
        if (maxHeight>1) {
            return false;
        }
        return true;
    }


    int getHeight(TreeNode* root, int& maxHeight) {
        if (!root) {
            return 0;
        }

        int left = getHeight(root->left, maxHeight);
        int right = getHeight(root->right, maxHeight);

        maxHeight = max(maxHeight, abs(right-left));

        return 1 + max(left,right);
    }
};
