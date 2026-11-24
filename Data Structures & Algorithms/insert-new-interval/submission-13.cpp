class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;

        int pos = 0;
        while (pos < intervals.size() && intervals[pos][0] < newInterval[0]) {
            pos++;
        }
        intervals.insert(intervals.begin() + pos, newInterval);

   
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
