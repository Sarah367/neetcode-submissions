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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        int sum = 0;
        binarySearch(root, low, high, sum);
        return sum;
    }

    void binarySearch(TreeNode* root, const int& low, const int& high, int& sum) {
        if (!root) return;


        if (root->val < low) {
            binarySearch(root->right, low, high, sum);
        } else if (root->val > high) {
            binarySearch(root->left, low, high, sum);
        } else {
            sum += root->val;
            binarySearch(root->left, low,high,sum);
            binarySearch(root->right, low, high, sum);
        }

        
    }
};