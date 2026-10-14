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
        // 2 1 1 3 null 1 5
        int goodNodes = 0;
        int maximum = INT_MIN;
        countGoodNodes(goodNodes, root, maximum);
        return goodNodes;
    }

    int countGoodNodes(int& goodNodes,TreeNode* root, int maximum) {
        if (!root) {
            return 0;
        }

        maximum = max(maximum, root->val);

        if (root->val >= maximum) {
            goodNodes++;
        } 

        // goodNodes += countGoodNodes(goodNodes, root->left, maximum);
        // goodNodes += countGoodNodes(goodNodes, root->right, maximum);


        return countGoodNodes(goodNodes, root->left, maximum) + countGoodNodes(goodNodes, root->right, maximum);
    }
};
