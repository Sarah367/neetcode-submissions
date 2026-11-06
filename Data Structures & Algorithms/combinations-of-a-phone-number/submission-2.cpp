class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> differentChars = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> combs;
        string currCombs;
        int size = int(digits.size());
        

        helper(0, currCombs, digits, differentChars, combs, size);

        return combs;
    }

    void helper(int i, string& currCombs, string& digits, vector<string>& differentChars, vector<string>& combs, int size) {
        if (currCombs.size() == size) {
            combs.push_back(currCombs);
            return;
        }
        
       
        for (char c : differentChars[digits[i] - '0']) {
            currCombs.push_back(c);
            helper(i + 1, currCombs, digits, differentChars, combs,size);
            currCombs.pop_back();
        }
        
        
        

    }


    
};
