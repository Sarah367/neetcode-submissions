class MedianFinder {
public:
    // two heaps: large, small, minHeap, maxHeap
    // heaps should be approximately equal size (with +1/-1 difference)
    priority_queue<int> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);
        // adding and removing in a heap is O(logn)
        // make sure every num in small heap is <= every num in large heap
        if (!smallHeap.empty() && !largeHeap.empty() && smallHeap.top() > largeHeap.top()) {
            int val = smallHeap.top();
            smallHeap.pop();
            largeHeap.push(val);
        }
        // uneven size?
        // if length of small heap is greater than large heap
        if (smallHeap.size() > largeHeap.size()+1) {
            int smallVal = smallHeap.top();
            smallHeap.pop();
            largeHeap.push(smallVal);
        }

        // if length of large heap is greater than small heap
        if (largeHeap.size() > smallHeap.size()+1) {
            int largeVal = largeHeap.top();
            largeHeap.pop();
            smallHeap.push(largeVal);
        }
    }
    
    double findMedian() {
        if (smallHeap.size() > largeHeap.size()) {
            return smallHeap.top();
        }
        if (largeHeap.size() > smallHeap.size()) {
            return largeHeap.top();
        }
        return ((smallHeap.top() + largeHeap.top()) /2.0);
    }
};
