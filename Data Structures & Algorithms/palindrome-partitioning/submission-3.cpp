class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> combs;
        vector<string> currCombs;
        // palindromic strings 
        helper(0, combs, currCombs, s);
        return combs;
    }
    void helper(int i, vector<vector<string>>& combs, vector<string>& currCombs, string& s) {
        if (i == s.size()) {
            combs.push_back(currCombs);
            return;
        }

        string create = "";
        for (int j = i; j < s.size(); j++) {
            create.push_back(s[j]);
            string compare = create;
            reverse(compare.begin(), compare.end());
            if (compare == create) {
                currCombs.push_back(create);
                helper(j+1, combs,currCombs,s);
                currCombs.pop_back();
            }
        }
    }
};
