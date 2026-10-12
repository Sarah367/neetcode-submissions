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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxEdges = 0;
        getDiameter(root, maxEdges);
        return maxEdges; 
    }
    
    int getDiameter(TreeNode* root, int& maxEdges) {
        if (!root) return 0;

        int left = getDiameter(root->left, maxEdges);
        int right = getDiameter(root->right, maxEdges);

        maxEdges = max(left+right, maxEdges);

        return max(left, right)+1;
    }


};
