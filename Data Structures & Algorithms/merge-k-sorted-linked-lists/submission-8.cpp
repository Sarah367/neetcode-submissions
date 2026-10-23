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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int i = 0; i < lists.size(); i+=2) {
                ListNode* list1 = lists[i];
                if (i+1 >= lists.size()) {
                    mergedLists.push_back(list1);
                    continue;
                }
                ListNode* list2 = lists[i+1];
                
                mergedLists.push_back(mergeLists(list1, list2));
            }
            lists = mergedLists;
        }

        return lists[0];
    }

    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* temp1 = curr1;
        ListNode* temp2 = curr2;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (curr1 != nullptr || curr2 != nullptr) {
            if (curr1 == nullptr) {
                tail->next = curr2;
                return dummy->next;
            }
            if (curr2 == nullptr) {
                tail->next = curr1;
                return dummy->next;
            }

            if (curr1->val <= curr2->val) {
                tail->next = curr1;
                tail = curr1;
                curr1 = curr1->next;
            } else {
                tail->next = curr2;
                tail = curr2;
                curr2 = curr2->next;
            }

        }

        return dummy->next;
    }
};
