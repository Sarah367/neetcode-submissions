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
    int sumNumbers(TreeNode* root) {
        string sum = "";
        vector<int> nums;
        rootToLeaf(root,sum,nums);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += nums[i];
        }
        return ans;
    }

    void rootToLeaf(TreeNode* root, string sum, vector<int>& nums) {
        if (!root) return;

        sum += to_string(root->val);
        
        if (root->left==nullptr && root->right==nullptr) {
            nums.push_back(std::stoi(sum));
        }

        rootToLeaf(root->left, sum, nums);
        rootToLeaf(root->right,sum,nums);

        
        
    }
};