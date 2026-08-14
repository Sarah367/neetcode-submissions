class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (const auto& pair : freq) {
            if (pair.second > 1) {
                return true;
            }
        }

        return false;
    }
};