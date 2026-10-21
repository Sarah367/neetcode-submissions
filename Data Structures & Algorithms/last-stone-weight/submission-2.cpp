class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> maxHeap;
        for (int stone : stones) {
            maxHeap.push(stone);
        }
        while (maxHeap.size() >= 2) {
            int max1 = maxHeap.top();
            maxHeap.pop(); 
            int max2 = maxHeap.top();
            maxHeap.pop();

            if (max1 == max2) {
                continue;
            } else {
                int newWeight = abs(max2 - max1);
                maxHeap.push(newWeight);
            }

        }

        if (maxHeap.empty()) {
            return 0;
        }

        return maxHeap.top();
    }
};
