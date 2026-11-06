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
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        int runningMax = INT_MIN;
        countGoodNodes(root, cnt, runningMax);
        return cnt;
    }

    int countGoodNodes(TreeNode* root, int& cnt, int runningMax) {
        if (!root) {
            return 0;
        }

        if (root->val >= runningMax) {
            cnt++;
            runningMax = root->val;
        }
        

        return countGoodNodes(root->left,cnt, runningMax) + countGoodNodes(root->right, cnt, runningMax);

    }
};
