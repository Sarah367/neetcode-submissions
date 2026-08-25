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

        queue<TreeNode*> queue;
        vector<int> res;
        if (root) {
            queue.push(root);
            res.push_back(root->val);
        }
        // [1, 2,3, null, 4]
        while (queue.size() > 0) {
            int length = queue.size();
            for (int i = 0; i < length; i++) {
                TreeNode* curr = queue.front();
                cout << "curr: " << curr->val << endl;
                queue.pop();
                
                
                if (curr->left) {
                    queue.push(curr->left);
                    
                }
                if (curr->right) {
                    queue.push(curr->right);
                    
                } 
                
            }
            if (!queue.empty()) {
                TreeNode* rightMost = queue.back();
                res.push_back(rightMost->val);
            }


        }
        // if (!res.empty()) {
        //     res.pop_back();
        // }
        //res.pop_back();
        return res;

    }


};
