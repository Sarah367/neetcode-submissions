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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if (root) {
            q.push(root);
            res.push_back({root->val});
        }
        vector<int> current;
        while (q.size() > 0) {
            int length = q.size();
            for (int i = 0; i < length; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left) {
                    q.push(curr->left);
                    current.push_back(curr->left->val);
                }

                if (curr->right) {
                    q.push(curr->right);
                    current.push_back(curr->right->val);
                }
            }

            if (!q.empty()) {

                res.push_back(current);
                current.clear();
            }
        }

        return res;



    }
};
