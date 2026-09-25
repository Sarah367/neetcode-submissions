class FirstUnique {
public:
    vector<int> nums;
    unordered_map<int, int> freq;
    FirstUnique(vector<int>& nums) {
        this->nums = nums;
        for (int num : nums) {
            freq[num]++;
        }
    }
    
    int showFirstUnique() {
        for (int i = 0; i < nums.size(); i++) {
            if (freq[nums[i]] == 1) {
                return nums[i];
            }
        }
        return -1;
    }
    
    void add(int value) {
        freq[value]++;
        nums.push_back(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
