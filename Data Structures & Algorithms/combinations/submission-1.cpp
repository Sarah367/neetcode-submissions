class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combs;
        vector<int> currCombs;
        helper(1, currCombs, combs, n, k);
        return combs;
    }

    void helper(int i, vector<int>& currCombs, vector<vector<int>>& combs, int n, int k) {
        if (currCombs.size() == k) {
            combs.push_back(vector<int>(currCombs));
            return;
        }

        if (i > n) return;

        for (int j = i; j < n+1; j++) {
            currCombs.push_back(j);
            helper(j+1, currCombs, combs, n, k);
            currCombs.pop_back();
        }
    }
};