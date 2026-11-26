class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        res.push_back(intervals[0]);

        for (auto vec : intervals) {
            if (res.back()[1] >= vec[0]) {
                int newEnding = max(res.back()[1], vec[1]);
                res.back()[1] = newEnding;
            } else {
                res.push_back(vec);
            }
        }

        return res;
    }
};
