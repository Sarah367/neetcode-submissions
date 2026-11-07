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
        if (lists.empty()) return {};
        vector<ListNode*> mergedLists;
        ListNode* secondList = nullptr;
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int i = 0; i < lists.size(); i+=2) {
                ListNode* firstList = lists[i];
                if (i+1 < lists.size()) {
                    secondList = lists[i+1];
                } else {
                    secondList = nullptr;
                }
                

                mergedLists.push_back(mergeLists(firstList, secondList));
            }
            lists = mergedLists;
        }
        
        return lists[0];
    }

    ListNode* mergeLists(ListNode* firstList, ListNode* secondList) {
        ListNode* curr1 = firstList;
        ListNode* curr2 = secondList;
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
                tail = tail->next;
                curr1 = curr1->next;

            } else if (curr2->val < curr1->val) {
                tail->next = curr2;
                tail=tail->next;
                curr2 = curr2->next;
            }

        }

        return dummy->next;



    }
};
