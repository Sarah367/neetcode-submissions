class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> currSet;
        vector<vector<int>> subsets;
        helper(0, nums, currSet, subsets);
        return subsets;
    }

    void helper(int i, vector<int>& nums, vector<int>& currSet, vector<vector<int>>& subsets) {
        if (i >= nums.size()) {
            subsets.push_back(vector<int>(currSet));
            return;
        }

        // decision to include nums[i]
        currSet.push_back(nums[i]);
        helper(i+1, nums, currSet, subsets);
        currSet.pop_back();

        while (i+1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }
        helper(i+1, nums, currSet, subsets);
    }
};
