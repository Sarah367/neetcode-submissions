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
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sort(intervals.begin(), intervals.end(), sortIntervals);

        for (auto vec : intervals) {
            if (minHeap.empty()) {
                minHeap.push(vec.end);
            } else if (minHeap.top() <= vec.start) {
                minHeap.pop();
                minHeap.push(vec.end);
            } else {
                minHeap.push(vec.end);
            }


        }
        
        return minHeap.size();
    }
};
