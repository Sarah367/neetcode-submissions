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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int digit1;
        int digit2; int sum = 0; long long carry = 0; int output = 0;
        while (curr1 != nullptr || curr2 != nullptr || carry != 0) {
            if (curr1 != nullptr) {
                digit1 = curr1->val;
            } else {
                digit1 = 0;
            }
            if (curr2 != nullptr) {
                digit2 = curr2->val;
            } else {
                digit2 = 0;
            }

            sum = digit1 + digit2 + carry;
            carry = sum / 10;
            output = sum % 10;
            tail->next = new ListNode(output);
            tail = tail->next;
            if (curr1 != nullptr) {
                curr1 = curr1->next;
            }
            if (curr2 != nullptr) {
                curr2=curr2->next;
            }

        }
        return dummy->next;
    
    }
};
