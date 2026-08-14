class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target-nums[i];
            auto it = find(nums.begin()+i+1, nums.end(), diff);
            if (it != nums.end()) {
                int index = distance(nums.begin(),it);
                return {i, index};
            }
        }

        return res;
    }
};
