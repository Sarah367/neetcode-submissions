class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int minIntervals = 0;
        vector<vector<int>> res;
        for (auto vec : intervals) {
            if (res.empty()) {
                res.push_back(vec);
            } else if (res.back()[1] > vec[0]) {
                int newEnding = min(res.back()[1], vec[1]);
                res.back()[1] = newEnding;
                minIntervals++;
            } else {
                res.push_back(vec);
            }
        }

        return minIntervals;
    }
};
