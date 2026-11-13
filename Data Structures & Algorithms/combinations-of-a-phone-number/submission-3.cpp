class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> combs;
        string currCombs = "";
        vector<string> mappings = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> trueMap; 
        for (char c : digits) {
            trueMap.push_back(mappings[c-'0']);
        }

        createCombs(0, combs, currCombs, trueMap, digits);
        return combs;
    }


    void createCombs(int i, vector<string>& combs, string currCombs, vector<string>& trueMap, string digits) {
        if (currCombs.size() == digits.size()) {
            combs.push_back((currCombs));
            return;
        }
        if (currCombs.size() > digits.size()) {
            return;
        }

        for (int j = 0; j < trueMap[i].size(); j++) {
            currCombs += trueMap[i][j];

            createCombs(i+1, combs, currCombs, trueMap, digits);

            currCombs.pop_back();


        }
        




    }
};
