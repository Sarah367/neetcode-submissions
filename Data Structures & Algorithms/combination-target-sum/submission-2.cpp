class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> combs;
        vector<int> currCombs;
        int sum = 0;
        helper(0, combs, currCombs, nums, target, sum);
        return combs;
    }

    void helper(int i, vector<vector<int>>& combs, vector<int>& currCombs, vector<int>& nums, int target, int& sum) {
        if (sum == target) {
            combs.push_back(vector<int>(currCombs));
            return;
        }
        if (sum > target) {
            return;
        }
        
        

        for (int j = i; j < nums.size(); j++) {
            currCombs.push_back(nums[j]);
            sum += nums[j];
            helper(j, combs, currCombs, nums, target,sum);

            currCombs.pop_back();
            sum -= nums[j];

            
            
            //helper(j+1, combs, currCombs,nums,target,sum);
            
            
        }


    }
};
