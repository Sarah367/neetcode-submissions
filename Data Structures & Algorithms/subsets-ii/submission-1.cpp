class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> combs;
        vector<int> currCombs;
        helper(0, nums, combs, currCombs);
        return combs; 
    }

    void helper(int i, vector<int>& nums, vector<vector<int>>& combs, vector<int>& currCombs) {
        if (i >= nums.size()) {
            combs.push_back(vector<int>(currCombs));
            return;
        }

        currCombs.push_back(nums[i]);
        helper(i+1, nums, combs, currCombs);

        currCombs.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }

        helper(i+1, nums, combs, currCombs);




    }

};
