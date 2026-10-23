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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int cnt = 0;
        while (curr != nullptr) {
            cnt++;
            curr = curr->next;
        }
        curr = head;
        int iterations = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        ListNode* prev = nullptr;
        ListNode* oldHead = nullptr;
        while (curr != nullptr) {
            if (iterations >= (cnt/k)) {
                return dummy->next;
            }

            oldHead = curr;
            

            for (int i = 0; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = prev;

                prev = curr;
                curr = temp; 

            }

            tail->next = prev;
            oldHead->next = curr;
            tail = oldHead;


            iterations++;
        }

        return dummy->next;
    }
};
