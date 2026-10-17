class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // choose two maxes each time
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        int stoneWeight = 0;

        while (maxHeap.size() >= 2) {
            int max1 = maxHeap.top();
            maxHeap.pop();
            int max2 = maxHeap.top();
            maxHeap.pop();


            if (max1 == max2) {
                continue;
            } else {
                stoneWeight = abs(max1-max2);
                maxHeap.push(stoneWeight);
            }

        }

        if (maxHeap.size() == 0) {
            return 0;
        }

        return maxHeap.top();



    }
};
