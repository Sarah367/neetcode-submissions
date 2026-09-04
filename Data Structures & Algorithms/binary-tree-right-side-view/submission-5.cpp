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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        //bfs
        queue<TreeNode*> queue;

        if (root) {
            queue.push(root);
            res.push_back(root->val);
        }

        while (queue.size() > 0) {
            int length = queue.size();

            for (int i = 0; i < length; i++) {
                TreeNode* curr = queue.front();
                queue.pop();

                if (curr->left) {
                    queue.push(curr->left);
                }

                if (curr->right) {
                    queue.push(curr->right);
                }


            }
            if (!queue.empty()) {
                TreeNode* rightSide = queue.back();
                cout << "rightSide: " << rightSide->val << endl;
                res.push_back(rightSide->val);

            }
        }


        return res;
    }
};
