class FirstUnique {
public:
    queue<int> queue;
    unordered_map<int, int> freq;
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            add(num);
        }
    }
    
    int showFirstUnique() {
        while (true) {
            if (queue.empty()) {
                break;
            }
            int frontNum = queue.front();

            if (freq[frontNum] > 1) {
                queue.pop();
            } else {
                break;
            }
        }
        if (queue.empty()) {
            return -1;
        }
        return queue.front();
        
    }
    
    void add(int value) {
        freq[value]++;
        if (freq[value] == 1) {
            queue.push(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
