class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for (vector<int> time : times) {
            int s = time[0];
            int d = time[1];
            int w = time[2];
            adj[s].push_back(make_pair(d,w));
        }

        unordered_map<int,int> shortest;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap;
        int minTime = 0;
        minHeap.push({0, k});

        while (!minHeap.empty()) {
            pair<int, int> p = minHeap.top();
            minHeap.pop();
            int w1 = p.first, n1 = p.second;

            if (shortest.count(n1) > 0) {
                continue;
            }
            shortest[n1] = w1;
            cout << "n1: " << n1 << " w1: " << w1 << endl;
            

            for (pair<int,int> p : adj[n1]) {
                int n2 = p.first, w2 = p.second;
                if (shortest.count(n2) == 0) {
                    minHeap.push({w1 + w2, n2});
                }
            }
        }
        if (shortest.size() == n) {
            int maxElement = 0; 
            for (int i = 0; i < shortest.size(); i++) {
                maxElement = max(shortest[i], maxElement);
            }
            return maxElement;
        }

        return -1;
    }

    
};
