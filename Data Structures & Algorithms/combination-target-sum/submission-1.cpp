class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> currCombs;
        
        vector<vector<int>> combs;
        int sum = 0;
        helper(0, currCombs, combs, nums, sum, target);
        return combs;
    }


    void helper(int i, vector<int>& currCombs, vector<vector<int>>& combs, vector<int>& nums, int sum, int target) {
        if (sum == target) {
            combs.push_back(vector<int>(currCombs));
            return;
        }
        if (sum > target) return;
        


        for (int j = i; j < nums.size(); j++) {
            currCombs.push_back(nums[j]);

            helper(j, currCombs, combs, nums, sum + nums[j], target);
            currCombs.pop_back();
        }



    }
};
