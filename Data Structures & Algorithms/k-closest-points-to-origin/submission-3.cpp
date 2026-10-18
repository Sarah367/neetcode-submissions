class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
std::priority_queue<
    std::pair<double, std::vector<int>>, 
    std::vector<std::pair<double, std::vector<int>>>, 
    std::greater<>
> minHeap;

        for (const auto& point : points) {
            double distance = sqrt(point[0] * point[0] + point[1] * point[1]);

            minHeap.push({distance, point});


        }

        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        
        return res;

    }
};
