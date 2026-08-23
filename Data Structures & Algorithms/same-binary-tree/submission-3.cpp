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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> queueP;
        queue<TreeNode*> queueQ;
        if (!p && q) {
            return false;
        }
        if (!q && p) {
            return false;
        }
        if (!q && !p) {
            return true;
        }
        if (p) {
            queueP.push(p);
        }
        if (q) {
            queueQ.push(q);
        }

        while (queueP.size() > 0 && queueQ.size() > 0) {
            int length = queueP.size();

            for (int i = 0; i < length; i++) {
                TreeNode* curr = queueP.front();
                queueP.pop();
                TreeNode* compare = queueQ.front();
                queueQ.pop();
                if (curr == nullptr && compare != nullptr) {
                    return false;
                }
                if (compare == nullptr && curr != nullptr) {
                    return false;
                }
                if (compare == nullptr && curr == nullptr) {
                    continue;
                }
                
                cout << "curr->val: " << curr->val << endl;
                cout << "compare->val: " << compare->val << endl;

                if (curr->val != compare->val) {
                    cout << "im here" << endl;
                    return false;
                } else {
                    if (curr->left) {
                        queueP.push(curr->left);
                        //queueP.push(nullptr);
                        cout << "curr->left: " << curr->left->val << endl;
                    } else {
                        queueP.push(nullptr);
                    }
                    if (curr->right) {
                        queueP.push(curr->right);
                        cout << "curr->right: " << curr->right->val << endl;
                    } else {
                        queueP.push(nullptr);
                    }
                    if(compare->left){
                        queueQ.push(compare->left);
                        cout << "compare->left: " << compare->left->val << endl;
                    } else {
                        queueQ.push(nullptr);
                    }
                    if (compare->right) {
                        queueQ.push(compare->right);
                        cout << "compare->right: " << compare->right->val << endl;
                    } else {
                        queueQ.push(nullptr);
                    }
                }
            }
        }

        return true;
    }
};
