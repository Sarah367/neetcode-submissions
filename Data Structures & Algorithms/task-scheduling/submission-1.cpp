class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);

        for (char c : tasks) {
            count[c-'A']++;
        }


        priority_queue<int> maxHeap;

        for (int cnt : count) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }

        queue<pair<int,int>> q;

        int time = 0;

        while (!maxHeap.empty() || !q.empty()) {
            time++;
            if (!maxHeap.empty()) {
                int iterations = maxHeap.top();
                maxHeap.pop();
                iterations -= 1;
                if (iterations != 0) {
                    q.push({iterations, time+n});
                }
            }
            

            if (!q.empty() && time == q.front().second) {
                maxHeap.push(q.front().first);
                q.pop();
            }

        }

        return time; 

    }
};
