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
        int sum = 0, digit1 = 0, digit2 = 0, carry = 0, res=0;
        while (curr1 != nullptr || curr2 != nullptr || carry > 0) {
            if (curr1 == nullptr) {
                digit1 = 0;
            } else {
                digit1 = curr1->val;
            }

            if (curr2 == nullptr) {
                digit2=0;
            } else {
                digit2 = curr2->val;
            }


            sum = digit1 + digit2 + carry;
            
            res = sum % 10; 

            carry = (sum / 10);
            cout << "carry: " << sum / 10 << endl;
            ListNode* newNode = new ListNode(res);
            tail->next = newNode;
            tail=newNode;
            if (curr1 != nullptr) {
                curr1=curr1->next;
            }
            if (curr2 != nullptr) {
                curr2=curr2->next;
            }
            //curr1 = curr1->next;
            //curr2=curr2->next;

        }


        return dummy->next;
    }
};
