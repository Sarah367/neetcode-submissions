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
        vector<vector<int>> treeLevels;
        vector<int> level;
        queue<TreeNode*> queue;

        if (root) {
            queue.push(root);
            treeLevels.push_back({root->val});
        }

        while (queue.size() > 0) {
            int length = queue.size();

            for (int i = 0; i < length; i++) {
                TreeNode* curr = queue.front();
                
                queue.pop();

                if (curr->left) {
                    queue.push(curr->left);
                    level.push_back(curr->left->val);
                }
                if (curr->right) {
                    queue.push(curr->right);
                    level.push_back(curr->right->val);
                }
                
                
                
            }
            treeLevels.push_back(level);
            level.clear();
            
        }
        if (!treeLevels.empty()) {
            treeLevels.pop_back();
        }
        //treeLevels.pop_back();
        return treeLevels;

    }
};
