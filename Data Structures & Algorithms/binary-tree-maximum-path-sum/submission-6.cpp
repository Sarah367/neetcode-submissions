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
        int maximum = INT_MIN;
        getMaxPath(root, maximum);

        return maximum;
    }

    int getMaxPath(TreeNode* root, int& maximum) {
        if (!root) return 0;

        int left = getMaxPath(root->left, maximum);
        int right = getMaxPath(root->right, maximum);

        left = max(left, 0);
        right = max(right, 0);

        maximum = max(maximum, left+right+root->val);

        return max(left,right)+root->val;
    }


};
