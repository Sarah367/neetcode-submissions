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
        int goodNodes = 0;
        int max = root->val;
        countGoodNodes(root, max, goodNodes);
        
        return goodNodes;
    }

    void countGoodNodes(TreeNode* root, int max, int& goodNodes) {
        if (!root) {
            return;
        }

        if (root->val >= max) {
            goodNodes += 1;
            max = root->val;
        }


        countGoodNodes(root->left, max, goodNodes);
        countGoodNodes(root->right,max,goodNodes);
        
    }
};
