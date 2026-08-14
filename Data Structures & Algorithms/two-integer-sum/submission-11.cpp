class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            int diff = target-nums[i];

            if (freq[diff] >= 1) {
                for (int j = i+1; j < nums.size(); j++) {
                    if (nums[j] == diff) {
                        return {i,j};
                    }
                }
            }
        }

        return res;
    }
};
