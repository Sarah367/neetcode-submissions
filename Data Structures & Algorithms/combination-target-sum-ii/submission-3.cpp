class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combs;
        vector<int> currCombs;
        int sum = 0;
        helper(0, combs, candidates, currCombs, target, sum);
        return combs;
    }

    void helper(int i,vector<vector<int>>& combs, vector<int>& candidates, vector<int>& currCombs, int target, int sum) {
        if (sum == target) {
            combs.push_back(currCombs);
            return;
        }

        if (sum > target) {
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            
            currCombs.push_back(candidates[j]);
            sum += candidates[j];

            
            helper(j+1, combs, candidates, currCombs, target, sum);

            currCombs.pop_back();
            sum -= candidates[j];
            while (j+1 < candidates.size() && candidates[j] == candidates[j+1]) {
                j++;
            }
        }





    }
};
