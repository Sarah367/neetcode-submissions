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
    int kthSmallest(TreeNode* root, int k) {
        int smallest = 0; int cnt = 0;
        findSmallest(root, k, smallest, cnt);
        return smallest;
    }

    void findSmallest(TreeNode* root, int& k, int& smallest, int& cnt) {
        if (!root) return;

        
        findSmallest(root->left, k, smallest, cnt);
        cnt++;
        if (cnt == k) smallest = root->val;


        findSmallest(root->right, k, smallest,cnt);



    }
};
