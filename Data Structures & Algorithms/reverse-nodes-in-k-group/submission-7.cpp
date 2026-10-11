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
        int cnt = 0;
        int size = 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head;
        ListNode* temp;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }
        ListNode* groupPrev = dummy;
        curr = head;
        int iterations = floor(size/k);
        ListNode* oldHead = nullptr;
        cout << "iterations: " << iterations << endl;
        while (cnt < iterations && curr != nullptr) {

            oldHead=curr;

            for (int i = 0; i < k; i++) {
                temp = curr->next;
                curr->next = prev;
                prev=curr;
                curr = temp;
            }


            groupPrev->next = prev;
            oldHead->next = curr;
            groupPrev = oldHead;

            cnt++;
        }

        return dummy->next;

    }
};
