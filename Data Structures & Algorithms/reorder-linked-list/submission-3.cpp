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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // split the list into two; keep prev in order to split the list (prev is one node before
        // slow)
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev != nullptr) {
            prev->next = nullptr;
        

        // reverse the second half.
        ListNode* temp = slow->next;
        ListNode* previous = nullptr;
        while (slow != nullptr) {
            temp = slow->next;
            slow->next = previous;
            previous = slow;
            slow = temp;
        }
        // alternate and take from the first and second "lists"
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (head != nullptr) {
            tail->next = head;
            tail = head;
            head = head->next;
            tail->next = previous;
            tail = previous;
            previous = previous->next;
        }
        }
    }
};
