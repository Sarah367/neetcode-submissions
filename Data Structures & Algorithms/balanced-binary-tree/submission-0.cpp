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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        dfs(root, height);
        if (height > 1) {
            return false;
        }
        return true;
    }

    int dfs(TreeNode* root, int& height) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = dfs(root->left, height);
        int rightHeight = dfs(root->right, height);
        cout << "root: " << root->val << endl;
        cout << "left height: " << leftHeight << endl;
        cout << "right height: " << rightHeight << endl;
        cout << "calc: " << abs(rightHeight-leftHeight) << endl;
        height = max(height, abs(rightHeight-leftHeight));
        

        return 1 + max(leftHeight,rightHeight);

    }
};
