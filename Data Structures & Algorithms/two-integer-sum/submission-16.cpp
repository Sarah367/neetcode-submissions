class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int diff = (target - nums[i]);
            auto it = find(nums.begin()+i+1, nums.end(), diff);
            if (it != nums.end()) {
                int indx = it - nums.begin();
                return {i,indx};
            }
        }

        return {};
    }
};
