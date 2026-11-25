class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> combs;
        vector<int> currCombs;
        helper(0, combs, currCombs, nums);
        return combs;
    }

    void helper(int i, vector<vector<int>>& combs, vector<int>& currCombs, vector<int>& nums) {
        if (i == nums.size()) {
            combs.push_back(currCombs);
            return;
        }

        currCombs.push_back(nums[i]);
        helper(i+1, combs, currCombs, nums);

        currCombs.pop_back();

        helper(i+1, combs, currCombs, nums);


    }
};
