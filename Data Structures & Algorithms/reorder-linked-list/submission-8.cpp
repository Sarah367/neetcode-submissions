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
        // reverse list
        // intertwine them
        // 8 6 4 2
        // 8 6, 4 2
        // 2 8 4 6
        // reversing:
        // splitting them in middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;

        ListNode* curr = secondHalf;
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;

        while (curr != nullptr) {
            temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
        }

        // 2 4 | 8 6
        ListNode* first = head;
        ListNode* second = prev;
        // intertwine them. 
        while (second != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            first = temp1;
            second->next = first;
            second = temp2;
        }

    }
};
