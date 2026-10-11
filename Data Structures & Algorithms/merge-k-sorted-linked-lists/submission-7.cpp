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
        if (lists.empty()) return nullptr;
        ListNode* list2;
        while (lists.size() > 1) {
            vector<ListNode*> merged;
            for (int i = 0; i < lists.size(); i+=2) {
                ListNode* list1 = lists[i];
                if (i+1 < lists.size()) {
                    list2 = lists[i+1];
                } else {
                    list2 = nullptr;
                }
                merged.push_back(mergeLists(list1, list2));
            }
            lists = merged;
        }



        return lists[0];
    }

    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
        // merge the lists here
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
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
                tail->next=curr1;
                tail = curr1;
                curr1=curr1->next;
            } else if (curr1->val > curr2->val) {
                tail->next = curr2;
                tail = curr2;
                curr2=curr2->next;
            }

        }

        return dummy->next;
    }
};
