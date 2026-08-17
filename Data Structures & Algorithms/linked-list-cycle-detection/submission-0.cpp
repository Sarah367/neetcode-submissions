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
    bool hasCycle(ListNode* head) {
        int index = -1;

        unordered_set<ListNode*> visitedNodes;

        ListNode* current = head;

        while (current != nullptr) {
            if (visitedNodes.find(current) != visitedNodes.end()) {
                return true;
            }

            visitedNodes.insert(current);
            current=current->next;
        }

        return false;
    }
};
