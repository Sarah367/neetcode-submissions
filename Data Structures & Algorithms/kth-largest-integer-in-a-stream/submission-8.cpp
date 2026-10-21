class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k = 0;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            minHeap.push(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        while (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
