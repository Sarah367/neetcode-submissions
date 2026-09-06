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
        // find the middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }   

        // split into two lists
        ListNode* second = slow->next;
        slow->next = nullptr;

        // reverse the second half
        ListNode* curr = second;
        ListNode* temp; 
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
        }
        
        // weave/merge lists together
        ListNode* keep;
        ListNode* curr1 = head;
        while (prev != nullptr) {
            curr1 = curr1->next;
            keep = curr1;
            
            head->next = prev;
            head = prev;
            prev=prev->next;
            head->next = keep;
            head=keep;
        }

        

    }
};
