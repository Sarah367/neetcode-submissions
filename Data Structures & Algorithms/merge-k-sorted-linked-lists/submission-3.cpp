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
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int i = 0;
        int minVal = INT_MAX; int cnt = 0;
        while (cnt < lists.size()) {
            cnt=0;
            for (int i = 0; i < lists.size(); i++) {
                //cout << "lists[i]: " << lists[i] << endl;
                if (lists[i] == nullptr) {
                    cnt++;
                    continue;
                }
                minVal = min(minVal, lists[i]->val);
            }

            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == nullptr) {
                    //cnt++;
                    continue;
                }
                if (lists[i]->val == minVal) {
                    tail->next = lists[i];
                    tail = lists[i];
                    lists[i] = lists[i]->next;
                }
            }
            minVal = INT_MAX;
            
        }

        return dummy->next;
    }
};
