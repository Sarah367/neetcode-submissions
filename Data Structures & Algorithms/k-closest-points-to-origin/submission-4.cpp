class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
            int distanceA = a[0] * a[0] + a[1] * a[1];
            int distanceB = b[0] * b[0] + b[1] * b[1];

            return distanceA < distanceB;
        });
        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            res.push_back(points[i]);
        }

        return res;
    }
};
