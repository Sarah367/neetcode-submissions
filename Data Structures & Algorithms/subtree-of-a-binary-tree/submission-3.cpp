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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        // traverse root
        if (!subRoot) {
            return false;
        }
        if (!root && !subRoot) {
            return true;
        }
        
        
        bool ans;
        if (root->val == subRoot->val) {
            ans = isSameTree(root, subRoot);
        } 
        if (!ans) {
            ans= isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

        }
        

        return ans;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (p && q && p->val == q->val) {
            return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
        } else {
            return false;
        }
    }
};
