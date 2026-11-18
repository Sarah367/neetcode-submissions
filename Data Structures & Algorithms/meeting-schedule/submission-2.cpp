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
static bool compareByStart(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        // (0,30) (5,10) (15,20)
        sort(intervals.begin(), intervals.end(), compareByStart);
        vector<Interval> res;
      
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
