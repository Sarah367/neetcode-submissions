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
    int maxPathSum(TreeNode* root) {
        int sum = 0;
        int maximum = root->val;
        getSum(root, maximum);
        return maximum;
    }

    int getSum(TreeNode* root, int& maximum) {
        if (!root) {
            return 0;
        }
        
        int left = getSum(root->left, maximum);
        int right = getSum(root->right, maximum);

        left = max(left, 0);
        right = max(right, 0);

        maximum = max(root->val + left+right, maximum);

        return root->val + max(left, right);
    }
};
