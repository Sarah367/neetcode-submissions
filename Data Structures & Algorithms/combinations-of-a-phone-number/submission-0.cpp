class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<vector<char>> differentChars;
        vector<string> combs;
        string currCombs;
        int size = int(digits.size());
        for (char c : digits) {
            if (c == '2') {
                differentChars.push_back({'a', 'b', 'c'});
            } else if (c == '3') {
                differentChars.push_back({'d', 'e', 'f'});
                
            } else if (c == '4') {
                differentChars.push_back({'g', 'h', 'i'});
                
            } else if (c == '5') {
                differentChars.push_back({'j', 'k', 'l'});
            } else if (c == '6') {
                differentChars.push_back({'m', 'n', 'o'});
            } else if (c == '7') {
                differentChars.push_back({'p', 'q', 'r', 's'});                
            } else if (c == '8') {
                differentChars.push_back({'t', 'u', 'v'});                  
            } else if (c == '9') {
                differentChars.push_back({'w','x','y','z'});  
                
            }
        }

        helper(0, currCombs, differentChars, combs, size);

        return combs;
    }

    void helper(int i, string& currCombs, vector<vector<char>>& differentChars, vector<string>& combs, int size) {
        if (currCombs.size() == size) {
            combs.push_back(currCombs);
            return;
        }
        
       
        for (char c : differentChars[i]) {
            currCombs.push_back(c);
            helper(i + 1, currCombs, differentChars, combs,size);
            currCombs.pop_back();
        }
        
        
        

    }


    
};
