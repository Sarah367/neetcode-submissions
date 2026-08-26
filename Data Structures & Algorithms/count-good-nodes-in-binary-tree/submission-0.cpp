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
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int maximum = root->val;

        int count = goodNodesCount(root, maximum);
        return count;
    }

    int goodNodesCount(TreeNode* root, int maximum) {
        if (!root) {
            return 0;
        }

        int cnt = 0;
        if (root->val >= maximum) {
            cnt = 1;
            maximum = root->val;
        }

        cnt += goodNodesCount(root->left, maximum);
        cnt += goodNodesCount(root->right, maximum);
        return cnt;
    }
};
