/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool sortIntervals(Interval& a, Interval& b) {
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), sortIntervals);
        for (auto vec : intervals) {
            if (res.empty()) {
                res.push_back(vec);
            } else if (res.back().end > vec.start) {
                return false;
            } else {
                res.push_back(vec);
            }
        }

        return true;
    }
};
