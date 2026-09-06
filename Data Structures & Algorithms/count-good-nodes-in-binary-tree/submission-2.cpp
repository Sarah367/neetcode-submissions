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
        
        int maxVal = root->val;
        return countGoodNodes(root, maxVal);
       
    }

    int countGoodNodes(TreeNode* root, int maxVal) {
        if (!root) return 0;

        int cnt = 0;
        if (root->val >= maxVal) {
            maxVal = root->val;
            cnt++;
        }

        return cnt + countGoodNodes(root->left, maxVal) + countGoodNodes(root->right, maxVal);
    }
};
