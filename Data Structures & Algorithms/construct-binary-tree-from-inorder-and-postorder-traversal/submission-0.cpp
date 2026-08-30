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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        int inStart = 0;
        int inEnd = inorder.size()-1;
        int postStart = 0;
        int postEnd = postorder.size()-1;
        TreeNode* root;
        return build(root, inorder, postorder, inStart, inEnd, postStart, postEnd, inMap);

    }

    TreeNode* build(TreeNode* root, vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int,int>& inMap) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;


        root = new TreeNode(postorder[postEnd]);
        int rootIndex = inMap[root->val];

        int leftSide = rootIndex - inStart;

        root->left = build(root->left, inorder, postorder, inStart, rootIndex-1, postStart, postStart + leftSide-1, inMap);
        root->right = build(root->right, inorder, postorder, rootIndex+1, inEnd, postStart+leftSide, postEnd-1, inMap);

        return root;



    }
};