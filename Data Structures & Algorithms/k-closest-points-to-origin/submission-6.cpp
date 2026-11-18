class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, pair<int,int>>> maxHeap;
        // priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> minHeap;
        for (auto& vec : points) {
            int distance = (vec[0] * vec[0]) + (vec[1] * vec[1]); // 5

            maxHeap.push({distance, {vec[0], vec[1]} });

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }

        }

        while (maxHeap.size() > 0) {
            res.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }

        return res;
    }
};
