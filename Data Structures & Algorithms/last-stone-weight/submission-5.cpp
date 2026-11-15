class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> queue;

        for (int stone : stones) {
            queue.push(stone);
        }

        while (queue.size() >= 2) {
            int max1 = queue.top();
            queue.pop();
            int max2 = queue.top();
            queue.pop();

            if (max1 == max2) {
                continue;
            } else {
                int newWeight = abs(max1-max2);
                queue.push(newWeight);
            }
        }

        if (queue.empty()) return 0;

        return queue.top();



    }
};
