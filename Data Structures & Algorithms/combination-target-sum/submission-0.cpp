class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> combs;
        vector<int> currCombs;
        int sum = 0;
        helper(0, nums, sum, currCombs, combs,target);
        return combs;
    }

    void helper(int i, vector<int>& nums, int& sum, vector<int>& currCombs, vector<vector<int>>& combs, int target) {
        if (sum == target) {
            combs.push_back(vector<int>(currCombs));

            return;
        }
        if (sum > target) return;


        for (int j = i; j < nums.size(); j++) {
            currCombs.push_back(nums[j]);
            sum+= nums[j];
            

            helper(j, nums,sum,currCombs, combs,target);
            sum -= nums[j];
            currCombs.pop_back();
        }



    }

};
