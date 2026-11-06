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
        int count = 0;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        int traverse = count - n;


        curr = head;

        ListNode* dummy = new ListNode(0);
        dummy->next = curr;
        
        ListNode* prev = nullptr;
        prev = dummy;
        ListNode* temp = nullptr;
        int cnt = 0;
        while (curr != nullptr) {
            if (cnt == traverse) {
                
                prev->next = curr->next;
                curr = curr->next;
                return dummy->next;
            } else {
                temp = curr;
                curr = curr->next;
                prev = temp;

            }

            cnt++;
        }


        return dummy->next;

    }
};
