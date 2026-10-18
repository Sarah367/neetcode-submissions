class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (int num : stones) {
            maxHeap.push(num);
        }

        while (maxHeap.size() >= 2) {
            int max1 = maxHeap.top();
            maxHeap.pop();
            int max2 = maxHeap.top();
            maxHeap.pop();

            if (max1 == max2) {
                continue;
            } else {
                int newMax = abs(max2 - max1);
                maxHeap.push(newMax);
            }

        }

        if (maxHeap.size() == 0) {
            return 0;
        }

        return maxHeap.top();

        
    }
};
