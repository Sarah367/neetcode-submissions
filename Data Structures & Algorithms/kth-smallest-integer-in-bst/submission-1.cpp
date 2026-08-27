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
        if (!root) {
            return 0;
        }   
    

        int count = 0; int res = 0;
        traverse(root,k,count, res);
        return res;
    }

    void traverse(TreeNode* root, int& k , int& count, int& res) {
        if (!root) {
            return;
        }
        

        traverse(root->left, k, count, res);
        
        //cout << "VALUE: " <<  root->val << endl;
        count++;
        if (count==k) {
            res = root->val;
        }
        //cout << "COUNT: " << count << endl;

        traverse(root->right,k, count, res);
        
    }




};
