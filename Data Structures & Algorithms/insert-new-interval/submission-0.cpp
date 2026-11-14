class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int lastSeen = 0;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
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
