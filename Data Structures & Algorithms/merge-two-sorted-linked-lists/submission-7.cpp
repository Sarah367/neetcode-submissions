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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (curr1 != nullptr && curr2 != nullptr) {
            
            if (curr1->val <= curr2->val) {
                tail->next = curr1;
                tail = tail->next;
                curr1 = curr1->next;
            } else if (curr2->val < curr1->val) {
                tail->next = curr2;
                tail = tail->next;
                curr2=curr2->next;
            }

        }

        if (curr1 == nullptr) {
            tail->next = curr2;
        } else if (curr2 == nullptr) {
            tail->next = curr1;
        }

        return dummy->next;
    }
};
