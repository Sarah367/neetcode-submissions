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
        int cnt = 0;
        while (curr != nullptr) {
            if (cnt == traverse) {
                ListNode* deleteNode = curr;
                prev->next = curr->next;
                delete deleteNode;
                return dummy->next;
            } else {
                prev = curr;
                curr = curr->next;
                

            }

            cnt++;
        }


        return dummy->next;

    }
};
