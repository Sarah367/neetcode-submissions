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
        int maximum = root->val;
        int cnt = 0;
        countGoodNodes(root, maximum, cnt);
        return cnt;
    }

    void countGoodNodes(TreeNode* root, int maximum, int& cnt) {
        if (!root) {
            return;
        }

        
        if (root->val >= maximum) {
            maximum = root->val;
            cnt++;
            
        }

        countGoodNodes(root->left, maximum, cnt);
        countGoodNodes(root->right, maximum,cnt);
        
        
    }
};
