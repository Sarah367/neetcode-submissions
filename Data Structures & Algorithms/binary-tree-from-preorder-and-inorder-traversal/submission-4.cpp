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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }


        int preStart = 0;
        int preEnd = preorder.size()-1;
        int inStart = 0;
        int inEnd = inorder.size()-1;
        return build(preorder, inorder, preStart, preEnd, inStart, inEnd, inMap);
        
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int,int>& inMap) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootIndex = inMap[root->val];

        int leftSide = rootIndex - inStart; // 

        root->left = build(preorder, inorder, preStart + 1, preStart + leftSide, inStart, rootIndex-1, inMap);
        root->right = build(preorder, inorder, preStart+leftSide+1, preEnd, rootIndex+1, inEnd, inMap);

        return root;

    }

};
