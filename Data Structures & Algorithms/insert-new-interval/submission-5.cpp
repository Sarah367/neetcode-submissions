class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // loop 1: find the first interval whose start is not smaller than the new start
        int pos = 0;
        while (pos < intervals.size() && intervals[pos][0] < newInterval[0]) {
            pos++;
        }

        intervals.insert(intervals.begin() + pos, newInterval);

        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (auto vec : intervals) {
            if (res.back()[1] >= vec[0]) {
                int newEndingVal = max(res.back()[1], vec[1]);
                res.back()[1] = newEndingVal;
            } else {
                res.push_back(vec);
            }
        }

        return res;
    }
};
