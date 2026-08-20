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
        int minElement = INT_MAX;
        int cnt = 0;
        cout << lists.size() << endl;
        while (cnt < lists.size()) {
            cnt=0;
            minElement=INT_MAX;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == nullptr) {
                    cnt++;
                    continue;
                }
                minElement = min(minElement, lists[i]->val);
            }

            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == nullptr) {
                    continue;
                }

                if (lists[i]->val == minElement) {
                    tail->next = lists[i];
                    tail = lists[i];
                    lists[i] = lists[i]->next;
                }
            }
            //cout << "Cnt: " << cnt << endl;

        }
        return dummy->next;
    }
};
