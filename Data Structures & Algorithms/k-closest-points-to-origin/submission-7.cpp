class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> maxHeap;
        
        for (auto vec : points) {
            int euclidean = vec[0] * vec[0] + (vec[1] * vec[1]);

            maxHeap.push({euclidean, {vec[0], vec[1]}});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }

        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }
        return res;
    }
};
