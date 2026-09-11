class KthLargest {
private:
    vector<int> heap;
    int k;
    vector<int> nums;
public:
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;

        for (int num : nums){
            processVal(num);
        }
    }

    void processVal(int val) {
        if (heap.size() < k) {
            heap.push_back(val);
            minHeapifyUp(heap,heap.size()-1);
        } else {
            if (val > heap[0]) {
                heap[0] = val;
                minHeapifyDown(heap, 0);
            }
        }
    }

    void minHeapifyDown(vector<int>& heap, int i) {
        while (true) {
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < heap.size() && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < heap.size() && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest == i) {
                break;
            }

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

    void minHeapifyUp(vector<int>& heap, int index) {
        while (index > 0) {
            int parent = (index-1)/2;

            if (heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }
    
    int add(int val) {
        processVal(val);
        return heap[0];
    }
};
