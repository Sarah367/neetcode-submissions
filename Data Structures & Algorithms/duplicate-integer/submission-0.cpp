class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        bool flag = false;

        // 1 2 3 3 -- > true
        std::unordered_map<int, int> unique;

        for (int num : nums) {
            unique[num]++;
        }

        for (const auto& pair : unique) {
            if (pair.second > 1) {
                return true;
            }
        }

        return false;
    }
};