class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets; 
        vector<int> currSet;

        helper(0, subsets, currSet, nums);

        return subsets;
    }


    void helper(int i, vector<vector<int>>& subsets, vector<int>& currSet, vector<int>& nums) {
        if (i >= nums.size()) {
            subsets.push_back(vector<int>(currSet));
            return;
        }

        currSet.push_back(nums[i]);
        helper(i+1, subsets, currSet, nums);
        currSet.pop_back();


        helper(i+1, subsets, currSet, nums);

    }
};
