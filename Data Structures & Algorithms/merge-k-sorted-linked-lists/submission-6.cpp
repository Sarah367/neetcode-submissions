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
        vector<ListNode*> mergedLists;

        while (lists.size() > 1) {
            mergedLists.clear();
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2;
                if (i+1 < lists.size()) {
                    if (lists[i+1] == nullptr) {
                        l2 = nullptr;
                    } else {
                        l2 = lists[i+1];
                    }
                } else {
                    l2 = nullptr;
                }
                mergedLists.push_back(mergeLists(l1, l2));
            }
            lists = mergedLists;
        }

        return lists[0];
    }

    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
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
