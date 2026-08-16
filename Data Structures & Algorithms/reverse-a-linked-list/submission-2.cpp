/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// BRUTE FORCE SOLUTION
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        // take all the data and put it into the stack
        while (temp != nullptr) {
            st.push(temp->val);
            temp=temp->next;
        }
        // replace with whatever is on top of the stack (that is in reverse order naturally)
        temp = head;
        while (temp != nullptr) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};
