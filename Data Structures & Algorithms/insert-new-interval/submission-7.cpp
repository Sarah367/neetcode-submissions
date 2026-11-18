class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int pos = 0;
        for (auto vec : intervals) {
            if (pos < intervals.size() && newInterval[0] > vec[0]) {
                pos++;
            }
        }
        
        intervals.insert(intervals.begin() + pos, newInterval);

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
