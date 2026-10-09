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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int cnt = 0;
        while (curr != nullptr) {
            cnt++;
            curr = curr->next;
        }

        int traverse = cnt - n;
        int iteration = 0;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;
        while (current != nullptr) {
            if (iteration == traverse) {
                prev->next = current->next;
                return dummy->next;
            } else {
                prev = current;
                current = current->next;
                iteration++;
            }
        }

        return dummy->next;
    }
};
