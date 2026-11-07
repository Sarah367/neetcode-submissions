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
        int sum = root->val;

        getMaxPath(root, sum);
        return sum;
    }

    int getMaxPath(TreeNode* root, int& sum) {
        if (!root) return 0;

        
        //cout << "sum: " << sum << endl;
        int left = getMaxPath(root->left, sum);

        int right = getMaxPath(root->right, sum);

        left = max(0, left);
        right = max(0, right);
        sum = max(left+right+root->val, sum);
       

        return max(left,right) + root->val;


    }
};
