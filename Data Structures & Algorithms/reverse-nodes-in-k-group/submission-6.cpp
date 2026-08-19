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
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        ListNode* temp;
        ListNode* prev = nullptr;
        int cnt = 0;
        while (curr != nullptr) {
            cnt++;
            curr = curr->next;
        }
        curr = head;
        ListNode* prevGroupTail = curr;
        ListNode* oldHead = curr;
        
        int iteration = 0;
        while (curr != nullptr) {

            if (iteration > (cnt - k)) {
                tail->next = curr;
                return dummy->next;
            }
            prev=nullptr;
            oldHead = curr;
            for (int i = 0; i < k; i++) {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            
            if (prevGroupTail != oldHead) {
                prevGroupTail->next = prev;
                prevGroupTail = oldHead;
            }
            tail->next = prev;
            tail = prevGroupTail;

            iteration += k;
        }

        return dummy->next;
    }
};
