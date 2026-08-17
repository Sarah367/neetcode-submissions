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

        int traverse = cnt-n;
        int iteration = 0;
        
        ListNode* temp = head;
        ListNode* prev = nullptr;

        if (traverse == 0) {
            head = head->next;
            delete temp;
            return head;

        }
        ListNode* current = head;
        while (current != nullptr) {
            if (iteration == traverse) {
                
                prev->next = prev->next->next;
                return head;
            } else {
                prev = current;
                current = current->next;
                iteration++;
            }
        }

        return head;
    }
};
