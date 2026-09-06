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
        ListNode* secondList = slow->next;
        slow->next = nullptr;

        // reverse the second half
        ListNode* curr = secondList;
        ListNode* temp; 
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
        }
        
        // weave/merge lists together
        ListNode* first = head;
        ListNode* second = prev;
        ListNode* temp1;
        ListNode* temp2;
        while (second != nullptr) {
            temp1 = first->next;
            temp2 = second->next;

            first->next = second;
            
            second->next = temp1;

            first = temp1;
            second=temp2;


        }

        

    }
};
