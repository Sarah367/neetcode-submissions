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

        left = max(0, left);
        right = max(0,right);

        maximum = max(left+right+root->val, maximum);

        return root->val + max(left, right);

        

    }
};
