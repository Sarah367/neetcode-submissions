/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;

        findPath(root, p, pathP);
        findPath(root, q, pathQ);
        TreeNode* prev;
        for (int i = 0; i < min(pathP.size(), pathQ.size()); i++) {
            cout << "path p: " << pathP[i]->val << endl;
            cout << "path q: " << pathQ[i]->val << endl;
            if (pathP[i]->val != pathQ[i]->val) {
                return prev;
            }
            prev=pathP[i];
        }
        return prev;
    }

    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root) return false;

        path.push_back(root);

        if (root->val == target->val) return true;

        bool ans = findPath(root->left, target, path) || findPath(root->right, target, path);
        

        if (ans == false) {
            path.pop_back();
            return false;
        }
        return true;


    }
    




};