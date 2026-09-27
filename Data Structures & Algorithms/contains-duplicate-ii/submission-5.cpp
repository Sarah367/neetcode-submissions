class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left = 0;
        unordered_set<int> window;

        for (int right = 0; right < nums.size(); right++) {
            if (right-left > k) {
                window.erase(nums[left]);
                left++;
            }

            if (window.count(nums[right])) {
                return true;
            }
            window.insert(nums[right]);
        }
        return false;
    }
};