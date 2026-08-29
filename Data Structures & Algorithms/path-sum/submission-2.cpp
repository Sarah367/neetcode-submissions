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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = getSum(root, sum, targetSum);

        return ans;
    }

    bool getSum(TreeNode* root, int sum, int& targetSum) {
        if (!root) return false;

        sum += root->val; // 1

        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum) {
                return true;
            }
        }
        bool l = getSum(root->left, sum, targetSum);
        bool r = getSum(root->right, sum, targetSum);


        return l || r;
        //return getSum(root->left, sum, targetSum) || getSum(root->right, sum, targetSum);

    }
};