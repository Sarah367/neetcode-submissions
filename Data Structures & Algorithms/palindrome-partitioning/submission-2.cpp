class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> combs;
        vector<string> currComb;

        helper(0, combs, currComb, s);
        return combs;
    }


    void helper(int i, vector<vector<string>>& combs, vector<string>& currComb,  string& s) {
        if (i == s.size()) {
            combs.push_back(currComb);
            return;
        }

        string create = "";
        for (int j = i; j < s.size(); j++) {
            create.push_back(s[j]);
            string compare = create;
            reverse(compare.begin(), compare.end());
            if (compare == create) {
                currComb.push_back(create);
                helper(j+1, combs, currComb, s);
                currComb.pop_back();
            }
        }


    }
};
