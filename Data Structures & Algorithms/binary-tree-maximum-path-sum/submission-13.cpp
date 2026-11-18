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
        // max path sum
        int sum = 0;
        int currMax = INT_MIN;
        getMaxSum(root, currMax);
        return currMax;
    }

    int getMaxSum(TreeNode* root, int& currMax) {
        if (!root) {
            return 0;
        }

        int left = getMaxSum(root->left, currMax);
        int right = getMaxSum(root->right, currMax);

        left = max(0, left);
        right = max(0, right);

        currMax = max(currMax, right+left+root->val);

        return max(left,right)+root->val;

    }
};
