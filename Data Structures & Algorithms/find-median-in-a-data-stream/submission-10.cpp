class MedianFinder {
public:
    priority_queue<int> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);

        if (!smallHeap.empty() && !largeHeap.empty() && smallHeap.top() > largeHeap.top()) {
            int val = smallHeap.top();
            smallHeap.pop();
            largeHeap.push(val);
        } 

        if (smallHeap.size() > largeHeap.size()) {
            int val = smallHeap.top();
            smallHeap.pop();
            largeHeap.push(val);
        }

        if (largeHeap.size() > smallHeap.size()) {
            int val = largeHeap.top();
            largeHeap.pop();
            smallHeap.push(val);
        }
    }
    
    double findMedian() {
        if (smallHeap.size() > largeHeap.size()) {
            return smallHeap.top();
        }
        if (largeHeap.size() > smallHeap.size()) {
            return largeHeap.top();
        }
        return double((smallHeap.top() + largeHeap.top()) / 2.0);
    }
};
