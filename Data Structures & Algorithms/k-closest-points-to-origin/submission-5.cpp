class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using T = pair<int, pair<int,int>>;

        priority_queue<T> minHeap;

        for (auto& point : points) {
            int euclidean = point[0] * point[0] + point[1] * point[1];

            minHeap.push({ euclidean , {point[0], point[1]}});

            if (minHeap.size() > k) minHeap.pop();

            
        }

        vector<vector<int>> res;

        while (!minHeap.empty()) {
            vector<int> initialize;
            initialize.push_back(minHeap.top().second.first);
            initialize.push_back(minHeap.top().second.second);
            res.push_back(initialize);
            minHeap.pop();
        }

        return res;
        
    }
};
