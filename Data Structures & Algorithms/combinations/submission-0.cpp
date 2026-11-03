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

        // include i
        currCombs.push_back(i);
        helper(i+1, currCombs, combs, n, k);
        currCombs.pop_back();
        // not include i
        helper(i+1, currCombs, combs, n, k);
    }
};