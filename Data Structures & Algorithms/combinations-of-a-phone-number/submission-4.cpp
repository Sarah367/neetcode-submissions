class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combs;
        vector<string> letters;
        string currCombs;
        if (digits.empty()) return {};
        vector<string> telephone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (char c : digits) {
            letters.push_back(telephone[c-'0']);
        }
        helper(0, letters, combs, currCombs, digits);
        return combs;
    }

    void helper(int i, vector<string>& letters, vector<string>& combs, string& currCombs, string& digits) {
        if (currCombs.size() == digits.size()) {
            combs.push_back(currCombs);
            return;
        }


        for (char c : letters[i]) {
            currCombs.push_back(c);
            helper(i+1, letters, combs, currCombs, digits);
            currCombs.pop_back();
        }


    }
};
